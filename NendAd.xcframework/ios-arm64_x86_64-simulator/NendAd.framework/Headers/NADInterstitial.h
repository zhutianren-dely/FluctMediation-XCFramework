//
//  NADInterstitial.h
//  NendAd
//
//  インタースティシャル広告クラス

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

///-----------------------------------------------
/// @name Constants
///-----------------------------------------------

/**
 NADInterstitialClickType
 */
typedef NS_ENUM(NSInteger, NADInterstitialClickType) {
    DOWNLOAD,
    CLOSE,
    INFORMATION
};

/**
 NADInterstitialStatusCode
 */
typedef NS_ENUM(NSInteger, NADInterstitialStatusCode) {
    SUCCESS,
    INVALID_RESPONSE_TYPE,
    FAILED_AD_REQUEST,
    FAILED_AD_DOWNLOAD,
};

/**
 NADInterstitialShowAdResult
 */
typedef NS_ENUM(NSInteger, NADInterstitialShowResult) {
    AD_SHOW_SUCCESS,
    AD_LOAD_INCOMPLETE,
    AD_REQUEST_INCOMPLETE,
    AD_DOWNLOAD_INCOMPLETE,
    AD_FREQUENCY_NOT_REACHABLE,
    AD_SHOW_ALREADY,
    AD_CANNOT_DISPLAY
};

/**
 A delegate object for each event of Interstitial-AD.
 */

@protocol NADInterstitialLoadingDelegate <NSObject>
/**
Notify the results of the ad load.
*/
@optional
- (void)didFinishLoadInterstitialAdWithStatus:(NADInterstitialStatusCode)status;
- (void)didFinishLoadInterstitialAdWithStatus:(NADInterstitialStatusCode)status spotID:(NSInteger)spotID;

@end

@protocol NADInterstitialClickDelegate <NSObject>
/**
Notify the event of the ad click.
*/
@optional
- (void)didClickWithType:(NADInterstitialClickType)type;
- (void)didClickWithType:(NADInterstitialClickType)type spotID:(NSInteger)spotID;

@end

/**
 The management class of Interstitial-AD.
 */
@interface NADInterstitial : NSObject

/**
 Set the delegate object.
 */
@property (nonatomic, weak, readwrite) id<NADInterstitialLoadingDelegate> loadingDelegate;
@property (nonatomic, weak, readwrite) id<NADInterstitialClickDelegate> clickDelegate;

/**
 Reload the interstitial ad when close.
 Defaults to YES
 */
@property (nonatomic) BOOL enableAutoReload;

///-----------------------------------------------
/// @name Creating and Initializing Nend Instance
///-----------------------------------------------

/**
 Creates and returns a `NADInterstitial` object.

 @return NADInterstitial
 */
+ (instancetype)sharedInstance;

///------------------------
/// @name Loading AD
///------------------------

/**
 Load the Interstitial-AD.

 @warning　Please call this when the application starts.

 for example:

 `- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions`
 */
- (void)loadAdWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;

///----------------------------
/// @name Showing / Closing AD
///----------------------------

/**
 Show the Interstitial-AD on the specified UIViewController.
 
 @return NADInterstitialShowResult
 */
- (NADInterstitialShowResult)showAdFromViewController:(UIViewController *)viewController;
- (NADInterstitialShowResult)showAdFromViewController:(UIViewController *)viewController spotID:(NSInteger)spotID;

/**
 Dismiss the Interstitial-AD.

 @return `YES` AD will be closed, otherwise `NO`.
 */
- (BOOL)dismissAd;

@end
