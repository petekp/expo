// Copyright 2017-present 650 Industries. All rights reserved.

#import <AVFoundation/AVFoundation.h>

#import <UMCore/UMModuleRegistryConsumer.h>
#import <UMCore/UMAppLifecycleListener.h>
#import <UMCore/UMExportedModule.h>
#import <UMCore/UMEventEmitter.h>
#import <EXAV/EXAVObject.h>

typedef NS_OPTIONS(NSUInteger, EXAudioInterruptionMode)
{
  EXAudioInterruptionModeMixWithOthers = 0,
  EXAudioInterruptionModeDoNotMix      = 1,
  EXAudioInterruptionModeDuckOthers    = 2
};

typedef NS_OPTIONS(NSUInteger, EXAudioRecordingOptionBitRateStrategy)
{
  EXAudioRecordingOptionBitRateStrategyConstant            = 0,
  EXAudioRecordingOptionBitRateStrategyLongTermAverage     = 1,
  EXAudioRecordingOptionBitRateStrategyVariableConstrained = 2,
  EXAudioRecordingOptionBitRateStrategyVariable            = 3
};

@protocol EXAVScopedModuleDelegate

- (void)scopedModuleDidBackground:(id)scopedModule;
- (void)scopedModuleDidForeground:(id)scopedModule;
- (void)scopedModuleWillDeallocate:(id)scopedModule;
- (NSError *)setActive:(BOOL)active forScopedModule:(id)scopedModule;
- (NSError *)setCategory:(NSString *)category withOptions:(AVAudioSessionCategoryOptions)options forScopedModule:(id)scopedModule;

@end

@protocol EXAVScopedModule

- (NSString *)experienceId;

@end

@protocol EXAVInterface

- (NSError *)promoteAudioSessionIfNecessary;

- (NSError *)demoteAudioSessionIfPossible;

- (void)registerVideoForAudioLifecycle:(NSObject<EXAVObject> *)video;

- (void)unregisterVideoForAudioLifecycle:(NSObject<EXAVObject> *)video;

@end

@interface EXAV : UMExportedModule <UMEventEmitter, EXAVScopedModule, UMAppLifecycleListener, UMModuleRegistryConsumer, EXAVInterface>

- (void)handleMediaServicesReset:(NSNotification *)notification;
- (void)handleAudioSessionInterruption:(NSNotification *)notification;

@end
