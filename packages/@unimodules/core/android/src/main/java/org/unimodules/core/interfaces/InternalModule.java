package org.unimodules.core.interfaces;

import java.util.List;

import org.unimodules.core.ModuleRegistry;

/**
 * Interface for "Expo" modules -- modules available over {@link ModuleRegistry},
 * implementing some external-package interface.
 *
 * Eg. `com.filesystem.FileSystem` could implement `org.unimodules.interfaces.filesystem.FileSystem`
 * and export this interface in {@link #getExportedInterfaces()}. This way {@link ModuleRegistry}
 * will be able to pick it up and register as a provider for this interface, in case some other module
 * asks for `org.unimodules.interfaces.filesystem.FileSystem` provider.
 */
public interface InternalModule {
  List<Class> getExportedInterfaces();
}
