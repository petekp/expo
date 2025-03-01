import './polyfillNextTick';
import zipObject from 'lodash.zipobject';
import { Platform } from 'react-native';
import { NativeModulesProxy } from '@unimodules/core';
import customOpenDatabase from '@expo/websql/custom';
const { ExponentSQLite } = NativeModulesProxy;
class SQLiteDatabase {
    constructor(name) {
        this._closed = false;
        this._name = name;
    }
    exec(queries, readOnly, callback) {
        if (this._closed) {
            throw new Error(`The SQLite database is closed`);
        }
        ExponentSQLite.exec(this._name, queries.map(_serializeQuery), readOnly).then(nativeResultSets => {
            callback(null, nativeResultSets.map(_deserializeResultSet));
        }, error => {
            // TODO: make the native API consistently reject with an error, not a string or other type
            callback(error instanceof Error ? error : new Error(error));
        });
    }
    close() {
        this._closed = true;
        ExponentSQLite.close(this._name);
    }
}
function _serializeQuery(query) {
    return [query.sql, Platform.OS === 'android' ? query.args.map(_escapeBlob) : query.args];
}
function _deserializeResultSet(nativeResult) {
    let [errorMessage, insertId, rowsAffected, columns, rows] = nativeResult;
    // TODO: send more structured error information from the native module so we can better construct
    // a SQLException object
    if (errorMessage !== null) {
        return { error: new Error(errorMessage) };
    }
    return {
        insertId,
        rowsAffected,
        rows: rows.map(row => zipObject(columns, row)),
    };
}
function _escapeBlob(data) {
    if (typeof data === 'string') {
        /* eslint-disable no-control-regex */
        return data
            .replace(/\u0002/g, '\u0002\u0002')
            .replace(/\u0001/g, '\u0001\u0002')
            .replace(/\u0000/g, '\u0001\u0001');
        /* eslint-enable no-control-regex */
    }
    else {
        return data;
    }
}
const _openExpoSQLiteDatabase = customOpenDatabase(SQLiteDatabase);
export function openDatabase(name, version = '1.0', description = name, size = 1, callback) {
    if (name === undefined) {
        throw new TypeError(`The database name must not be undefined`);
    }
    return _openExpoSQLiteDatabase(name, version, description, size, callback);
}
export default {
    openDatabase,
};
//# sourceMappingURL=SQLite.js.map