# expo-image-manipulator

Provides functions that let you manipulation images on the local file system, eg: resize, crop.

# API documentation

- [Documentation for the master branch](https://github.com/expo/expo/blob/master/docs/pages/versions/unversioned/sdk/imagemanipulator.md)
- [Documentation for the latest stable release](https://docs.expo.io/versions/latest/sdk/imagemanipulator/)

# Installation

This package is pre-installed in [managed](https://docs.expo.io/versions/latest/introduction/managed-vs-bare/) Expo projects. You may skip the rest of the installation guide if this applies to you.

For bare React Native projects, you must ensure that you have [installed and configured the `react-native-unimodules` package](https://github.com/react-native-unimodules) before continuing.

### Add the package to your npm dependencies

```
npm install expo-image-manipulator
```

### Configure for iOS

Run `pod install` in the ios directory after installing the npm package.

### Configure for Android

In `MainApplication.java`, import the package and add it to the `ReactModuleRegistryProvider` list:
```java
import expo.modules.imagemanipulator.ImageManipulatorPackage;
```
```java
private final ReactModuleRegistryProvider mModuleRegistryProvider = new ReactModuleRegistryProvider(Arrays.<Package>asList(
  // Your other packages will be here
  new ImageManipulatorPackage()
), Arrays.<SingletonModule>asList());
```

# Contributing

Contributions are very welcome! Please refer to guidelines described in the [contributing guide]( https://github.com/expo/expo#contributing).
