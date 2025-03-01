# expo-intent-launcher

Provides a way to launch Android intents, e.g. opening a specific activity.

# API documentation

- [Documentation for the master branch](https://github.com/expo/expo/blob/master/docs/pages/versions/unversioned/sdk/intent-launcher.md)
- [Documentation for the latest stable release](https://docs.expo.io/versions/latest/sdk/intent-launcher/)

# Installation

This package is pre-installed in [managed](https://docs.expo.io/versions/latest/introduction/managed-vs-bare/) Expo projects. You may skip the rest of the installation guide if this applies to you.

For bare React Native projects, you must ensure that you have [installed and configured the `react-native-unimodules` package](https://github.com/react-native-unimodules) before continuing.

### Add the package to your npm dependencies

```
npm install expo-intent-launcher
```

### Configure for iOS

This package does not make sense on iOS as there is no equivalent API, so it is not supported.

### Configure for Android

1. Append the following lines to `android/settings.gradle`:

```gradle
include ':expo-intent-launcher'
project(':expo-intent-launcher').projectDir = new File(rootProject.projectDir, '../node_modules/expo-intent-launcher/android')
```

2. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
```gradle
api project(':expo-intent-launcher')
```

3. In `MainApplication.java`, import the package and add it to the `ReactModuleRegistryProvider` list:
```java
import expo.modules.intentlauncher.IntentLauncherPackage;
```
```java
private final ReactModuleRegistryProvider mModuleRegistryProvider = new ReactModuleRegistryProvider(Arrays.<Package>asList(
  // Your other packages will be here
  new IntentLauncherPackage()
), Arrays.<SingletonModule>asList());
```

# Contributing

Contributions are very welcome! Please refer to guidelines described in the [contributing guide]( https://github.com/expo/expo#contributing).
