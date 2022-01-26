//
//  KBMDisplaySettings.h
//  BrandMessenger
//

#import <Foundation/Foundation.h>

/**
 *  @abstract horizontal image aspect ratio
 */
extern NSString* _Nonnull const KBMImageAspectRatioHorizontal;

/**
 *  @abstract squared image aspect ratio
 */
extern NSString* _Nonnull const KBMImageAspectRatioSquare;

/**
 *  @abstract Settings to adjust a carousel layout
 */
@interface KBMDisplaySettings : NSObject

/*
 * @abstract Specifies how to display all carousel images
 *
 * @discussion Valid values are horizontal and square. May be nil
 */
@property (nullable, copy) NSString *imageAspectRatio;

@end
