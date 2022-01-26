//
//  KBMMessage.h
//  BrandMessenger
//

#import <UIKit/UIKit.h>
#import "KBMCoordinates.h"
#import "KBMDisplaySettings.h"

/**
 *  @abstract Notification that is fired when a message fails to upload.
 */
extern NSString* _Nonnull const KBMMessageUploadFailedNotification;

/**
 *  @abstract Notification that is fired when a message uploads successfully.
 */
extern NSString* _Nonnull const KBMMessageUploadCompletedNotification;

/**
 *  @abstract A type of message that contains an image, text, and/or action buttons
 */
extern NSString* _Nonnull const KBMMessageTypeImage;

/**
 *  @abstract A type of message that contains text and/or action buttons
 */
extern NSString* _Nonnull const KBMMessageTypeText;

/**
 *  @abstract A type of message that contains a location
 */
extern NSString* _Nonnull const KBMMessageTypeLocation;

/**
 *  @abstract A type of message that contains a file and/or text
 */
extern NSString* _Nonnull const KBMMessageTypeFile;

/**
 *  @abstract A type of message that contains a horizontally scrollable set of items
 */
extern NSString* _Nonnull const KBMMessageTypeCarousel;

/**
 *  @abstract A type of message that contains a vertically scrollable set of items
 */
extern NSString* _Nonnull const KBMMessageTypeList;

/**
 *  @abstract A type of message that requests form data
 */
extern NSString* _Nonnull const KhorosMessageTypeForm;

/**
 *  @abstract A type of message that is a response to form request
 */
extern NSString* _Nonnull const KhorosMessageTypeFormResponse;



/**
 *  @discussion Upload status of an KBMMessage.
 *
 *  @see KBMMessage
 */
typedef NS_ENUM(NSInteger, KBMMessageUploadStatus) {
    /**
     *  A user message that has not yet finished uploading.
     */
    KBMMessageUploadStatusUnsent,
    /**
     *  A user message that failed to upload.
     */
    KBMMessageUploadStatusFailed,
    /**
     *  A user message that was successfully uploaded.
     */
    KBMMessageUploadStatusSent,
    /**
     *  A message that did not originate from the current user.
     */
    KBMMessageUploadStatusNotUserMessage
};

@interface KBMMessage : NSObject <NSSecureCoding>

/**
 *  @abstract Create a message with the given text. The message will be owned by the current user.
 */
-(nonnull instancetype)initWithText:(nonnull NSString*)text;

/**
 *  @abstract Create a message with the given text, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithText:(nonnull NSString *)text payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract Create a message with the given coordinates, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithCoordinates:(nonnull KBMCoordinates *)coordinates payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract Create a message with the given fields, quotedMessageId and metadata. The message will be owned by the current user. This if for failed form responses.
 */
- (nonnull instancetype)initWithFields:(nullable NSArray *)fields quotedMessageId:(nonnull NSString*)quotedMessageId metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract The unique identifier of the message. May be nil if a unique identifier has not been generated for this message
 */
@property(readonly, nullable) NSString* messageId;

/**
 *  @abstract The text content of the message. May be nil if mediaUrl or actions are provided
 */
@property(nullable) NSString* text;

/**
 *  @abstract The text fallback to display for message types not supported by the SDK. May be nil
 */
@property(nullable) NSString* textFallback;

/**
 *  @abstract The displayName of the author. This property may be nil if no displayName could be determined.
 */
@property(nullable) NSString* displayName;

/**
 *  @abstract The url for the author's avatar image. May be nil
 */
@property(nullable) NSString* avatarUrl;

/**
 *  @abstract The date and time the message was sent
 */
@property(nullable) NSDate *date;

/**
 *  @abstract Returns YES if the message originated from the user, or NO if the message comes from the app team.
 */
@property (nonatomic) BOOL isFromCurrentUser;

/**
 *  @abstract The upload status of the message.
 *
 *  @see KBMMessageStatus
 */
@property KBMMessageUploadStatus uploadStatus;

/**
 *  @abstract An array of KBMMessageAction objects representing the actions associated with this message (if any)
 *
 *  @discussion This array may be nil or empty, so check the length of the array to know if a message has actions or not.
 *
 *  @see KBMMessageAction
 */
@property(readonly, nullable) NSArray* actions;

/**
 *  @abstract An array of KBMMessageItem objects representing the items associated with this message
 *
 *  @discussion Only messages of type `KBMMessageTypeCarousel` and `KBMMessageTypeList` contain items.
 *
 *  @see KBMMessageItem
 */
@property(readonly, nullable) NSArray* items;

/**
 *  @abstract The url to the media asset, if applicable. Returns nil if the message is not an image or file message.
 */
@property(nullable) NSString* mediaUrl;

/**
 *  @abstract The size of the media asset in bytes. May be nil.
 */
@property(nullable) NSNumber* mediaSize;

/**
 *  @abstract The type the message.
 *
 *  @discussion Valid types include KBMMessageTypeText, KBMMessageTypeImage, and KBMMessageTypeLocation
 */
@property(nullable) NSString* type;

/**
 *  @abstract Coordinates for a location for a message of type KBMMessageTypeLocation
 */
@property(readonly, nullable) KBMCoordinates *coordinates;

/**
 *  @abstract Settings to adjust the layout of a message of type KBMMessageTypeCarousel
 *
 *  @see KBMDisplaySettings
 */
@property(readonly, nullable) KBMDisplaySettings *displaySettings;

/**
 *  @abstract The role of the message.
 *
 *  @discussion Valid roles include `appUser`, `business`, and `whisper`. Messages created with -initWithText: have role of `appUser`.
 */
@property(readonly, nullable) NSString* role;

/**
 *  @abstract Metadata associated with the message.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nonatomic, nullable, getter=getMetadata) NSDictionary* metadata;

/**
 *  @abstract The payload of an action with type KBMMessageActionTypeReply
 *
 *  @discussion The payload of a KBMMessageActionTypeReply, if applicable. May be nil
 */
@property(nullable) NSString* payload;

/**
 *  @abstract An array of KhorosMessageField objects representing the fields associated with this form message
 *
 *  @discussion Only messages of type `KhorosMessageTypeForm` contain fields.
 *
 *  @see KhorosMessageField
 */
@property(readonly, nullable) NSArray* fields;

/**
 *  @abstract The messageId of the form request this formResponse message is responding to.
 *
 *  @discussion Only messages of type `KhorosMessageTypeForm` contain quotedMessageId. May not be nil if type is KhorosMessageTypeForm or the API call will fail.
 */
@property(readonly, nullable) NSString* quotedMessageId;

@end
