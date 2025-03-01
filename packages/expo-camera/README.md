# expo-camera

A React component that renders a preview for the device's either front or back camera. Camera's parameters like zoom, auto focus, white balance and flash mode are adjustable. With expo-camera, one can also take photos and record videos that are saved to the app's cache. Morever, the component is also capable of detecting faces and bar codes appearing on the preview.

# API documentation

- [Documentation for the master branch](https://github.com/expo/expo/blob/master/docs/pages/versions/unversioned/sdk/camera.md)
- [Documentation for the latest stable release](https://docs.expo.io/versions/latest/sdk/camera/)

# Installation

This package is pre-installed in [managed](https://docs.expo.io/versions/latest/introduction/managed-vs-bare/) Expo projects. You may skip the rest of the installation guide if this applies to you.

For bare React Native projects, you must ensure that you have [installed and configured the `react-native-unimodules` package](https://github.com/react-native-unimodules) before continuing.

### Add the package to your npm dependencies

```
npm install expo-camera
```

### Configure for iOS

Run `pod install` in the ios directory after installing the npm package.

### Configure for Android

1. Adjust the `android/build.gradle` to add the `maven` block as described below:
```gradle
allprojects {
    repositories {
        // * Your other repositories here *
        maven {
            // expo-camera bundles a custom com.google.android:cameraview
            url "$rootDir/../node_modules/expo-camera/android/maven"
        }
    }
}
```

2. In `MainApplication.java`, import the package and add it to the `ReactModuleRegistryProvider` list:
```java
import expo.modules.camera.CameraPackage;
```
```java
private final ReactModuleRegistryProvider mModuleRegistryProvider = new ReactModuleRegistryProvider(Arrays.<Package>asList(
  // Your other packages will be here
  new CameraPackage()
), Arrays.<SingletonModule>asList());
```

# Contributing

Contributions are very welcome! Please refer to guidelines described in the [contributing guide]( https://github.com/expo/expo#contributing).
