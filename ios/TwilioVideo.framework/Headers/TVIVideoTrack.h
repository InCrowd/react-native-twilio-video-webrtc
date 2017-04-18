//
//  TVIVideoTrack.h
//  TwilioVideo
//
//  Copyright © 2016-2017 Twilio, Inc. All rights reserved.
//

#import "TVITrack.h"

#import <UIKit/UIKit.h>

#import "TVIVideoCapturer.h"
#import "TVIVideoRenderer.h"

/**
 *  `TVIVideoTrack` represents video, and provides an interface to render frames from the track.
 */
@interface TVIVideoTrack : TVITrack

/**
 *  @brief Developers shouldn't initialize this class directly.
 *
 *  @discussion Tracks cannot be created explicitly.
 */
- (null_unspecified instancetype)init __attribute__((unavailable("Tracks cannot be created explicitly.")));

/**
 *  @brief An array of renderers that are currently attached to the video track.
 *
 *  @note Use the 'addRenderer:' and 'removeRenderer:' methods to manipulate this collection.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<id<TVIVideoRenderer>> *renderers;

/**
 *  @brief Adds a renderer to the video track. Renderers provide fine control over how video is displayed.
 *
 *  @discussion Use this method instead of `attach` to add your own renderer to `TVIVideoTrack`.
 *
 *  @param renderer An object or swift struct that implements the `TVIVideoRenderer` protocol.
 */
- (void)addRenderer:(nonnull id<TVIVideoRenderer>)renderer;

/**
 *  @brief Removes a renderer from the video track.
 *
 *  @param renderer An object or swift struct that implements the `TVIVideoRenderer` protocol.
 */
- (void)removeRenderer:(nonnull id<TVIVideoRenderer>)renderer;

@end

@class TVIVideoConstraints;

/**
 * `TVILocalVideoTrack` represents local video produced by a `TVIVideoCapturer`.
 */
@interface TVILocalVideoTrack : TVIVideoTrack

/**
 *  @brief Indicates if track is enabled.
 */
@property (nonatomic, assign, getter = isEnabled) BOOL enabled;

/**
 *  @brief The capturer that is associated with this track.
 */
@property (nonatomic, strong, readonly, nonnull) id<TVIVideoCapturer> capturer;

/**
 *  @brief The video constraints.
 */
@property (nonatomic, strong, readonly, nonnull) TVIVideoConstraints *constraints;

/**
 *  @brief Developers shouldn't initialize this class directly.
 *
 *  @discussion Tracks cannot be created explicitly
 */
- (null_unspecified instancetype)init __attribute__((unavailable("Tracks cannot be created explicitly.")));

@end
