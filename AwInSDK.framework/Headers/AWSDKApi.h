//
//  AWSDKApi.h
//  AWSDKDemo
//
//  Created by admin on 2020/12/1.
//

//#ifndef HFILENAME_USED
//#define HFILENAME_USED
//#import "PayData.h"
//#import "AWAdReportModel.h"
//#import "GameReportData.h"
//#import "AiHelpUserdata.h"
//#endif


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PayData.h"
#import "AWAdReportModel.h"
#import "GameReportData.h"
#import "AiHelpUserdata.h"

NS_ASSUME_NONNULL_BEGIN

@class AWSDKApi;
typedef NS_ENUM(NSInteger, AdType) {
    REWARDED = 1,
    INTERSTITIAL = 2,
    BANNER = 3,
    OPENAD = 4,
};

@protocol AWSDKDelegate <NSObject>

@optional
-(void)initSDKSuccess;
-(void)initSDKFail;
-(void)aiHelpInitSuccessed;
-(void)aiHelpInitFailed;
//登录成功
-(void)onLoginSuccess:(NSDictionary *)loginResultBean;
//登录失败
-(void)onLoginFail:(NSString *)msg;

//注销回调
-(void)onLogout:(int)logoutType;

//#pragma mark - 用户绑定查询
//-(void)userBindCheck;


-(void)onBindResult:(NSDictionary *)loginResultBean;

//支付成功
-(void)onPaySuccessCpOrderId:(NSString *)cpOrderId andSDKOrderId:(NSString *)sdkOrderId andPayType:(NSString *)payType;
//支付失败
-(void)onPayFailCpOrderId:(NSString *)cpOrderId andSDKOrderId:(NSString *)sdkOrderId andPayType:(NSString *)payType andErrMsg:(NSString *)errMsg;
//取消支付
-(void)onPayCancelCpOrderId:(NSString *)cpOrderId;

//FB分享成功
-(void)onFacebookShareSuccess;
//取消FB分享
-(void)onFacebookShareCancel;
//FB分享失败
-(void)onFacebookShareError:(NSString *)error;

//查询本地价格
-(void)localPriceResult:(NSDictionary *)localPirceDict;

//同意隐私协议
-(void)onAgree;


-(void)getFBFriendsList:(NSDictionary *)friendsListDic;


//广告
-(void)initAdSuccess;//广告可以加载回调
-(void)initAdFailed:(NSString *)error;//广告可以加载回调

//banner广告回调
-(void)onBannerLoadedSuccess;//banner加载成功
-(void)onBannerLoadFailed:(NSString *)error;//banner加载失败
-(void)onBannerClicked;//banner广告点击
-(void)onBannerExpanded;//banner广告开始播放;
//-(void)adBannerShowFail;//banner广告播放失败;
-(void)onBannerDisplayFailed:(NSString *)errorCode;//banner广告播放失败;

-(void)onBannerCollapsed;//Banner广告折叠 ---新增





//插屏广告回调
-(void)onInterstitialLoadSuccess;//插屏广告加载成功
-(void)onInterstitialLoadFailed:(NSString *)error;//插屏加载失败
-(void)onInterstitialDisplayed;//插屏广告开始播放
-(void)onInterstitialDisplayFailed:(NSString *)errorCode;//插屏广告播
-(void)onInterstitialClicked;//插屏广告点击
-(void)onInterstitialClosed;//插屏关闭广告

//激励广告回调
-(void)onRewardedLoaded;   // 广告加载成功
-(void)onRewardedLoadFailed:(NSString *) errorCode;    // 广告加载失败
-(void)onRewardedStart;    // 激励视频广告开始播放
-(void)onRewardedClicked;//激励广告点击
-(void)onRewardedClosed;     // 激励视频关闭广告页面
-(void)onRewardedVerify;    // 播放成功，可下发奖励
-(void)onRewardedDisplayFailed:(NSString *)msg;//激励广告播放失败;

//开屏广告回调
-(void)onOpenAdLoaded;   // 广告加载成功
-(void)onOpenAdLoadFailed:(NSString *) errorCode;    // 广告加载失败
-(void)onOpenAdStart;    // 开屏视频广告开始播放
-(void)onOpenAdClicked;//开屏广告点击
-(void)onOpenAdClosed;     // 开屏关闭广告页面

-(void)onOpenAdDisplayFailed:(NSString *)msg;//开屏广告播放失败;


//AIhelp未读消息数
-(void)aiHelpunReadMsgCount:(int)msgCount;



-(void)startLoading;
-(void)stopLoading;


//查询是否有优惠回调
-(void)fetchProductPrice:(BOOL )isEligible;//商品是否有优惠

//恢复购买回调回调
-(void)reStorePurchase:(NSDictionary *)dataDict;//商品是否有优惠

//-(void)onRewardedCompleted;//激励广告播放完成----新增

@end

@interface AWSDKApi : NSObject

@property(nonatomic, copy)NSString *url;
@property(nonatomic, strong)UIImage *image;

@property(nonatomic, weak)id<AWSDKDelegate> delegate;
+(instancetype)shareInstance;
+(void)initSDK;
+(void)startLogin;
/**
 SWITCH_ACCOUNT = 1; // 切换账号(SDK页面调用)
 NEED_RELOGIN = 2; // 需要重新登录
 FROM_GAME = 3;  // 游戏调用
 DELETE_ACCOUNT = 4;  // 账号删除
 SWITCH_GOOGLE = 5;  // 切换谷歌登录
 SWITCH_FB = 6;  // 切换FB登录
 SWITCH_EMAIL = 7;  // 切换邮箱登录
 SWITCH_APPLE = 8;  // 切换苹果登录
  SWITCH_GAMECENTER = 9;//切换gamecenter
  SWITCH_VK = 10； //切换VK
 
 
 */

+(void)logout:(BOOL)isShow; //注销后是否自动调登录

+(void)loginPlatform:(int)type;//1 - facebook / 2 - Google/3-Apple /4.email //5.gamecenter

#pragma mark - 加载/保存进度
+(void)saveProgress;

+(void)saveProgressOnly:(int)type;//1.Facebook 2.Google 3. Email 4.Apple 5.gamecenter，6.VK

+(void)switchAccount;       //切换账号

#pragma mark - AF邀请
+(void)user_Invite:(NSString *)extraInfo;

#pragma mark - AF互导
+(void)crossPromotionWithAppId:(NSString *)app_id andCross_cid:(NSString *)cross_cid andExtraInfo:(NSString *)extraInfo onSuccess:(void(^)(NSString * json))success onFailed:(void (^)(NSString * msg))failure;




/**
 SWITCH_GOOGLE = 5;  // 切换谷歌登录
 SWITCH_FB = 6;  // 切换FB登录
 SWITCH_EMAIL = 7;  // 切换邮箱登录
 SWITCH_APPLE = 8;  // 切换苹果登录
 SWITCH_GameCenter = 9;  // 切换gamecenter登录
 SWITCH_VK = 10； //切换VK
 */
+(void)switchPlatform:(int)type;

#pragma mark - 星火切换账号  1 - Facebook / 2 - Google / 3 - Email / 4 - VK 5.gameCenter  6.Apple

+(void)switchFirePlatform:(int)type;


//绑定账号
+(void)bindAccount;
+(void)bindPlatform:(int) type;      // 绑定 1-Facebook / 2-Google 3.email / 4.Apple /5.gameCenter /6.VK
+(void)unbindPlatform:(int)type;

+(void)openAccountManage;//账号管理界面
+(void)accountDelete; //删除账号
+(void)pay:(PayData *)orderInfo;                        //支付接口
#pragma mark - 查询本地商品价格
+(void)queryLocalPriceInapp:(NSArray *)inappList;

+(void)localPriceInapp:(NSArray *)inappList;
+(void)localPriceSubs:(NSArray *)inappList;




+(void)shareFacebookUrl:(NSString *)url;//FaceBook分享链接
+(void)shareFacebookImage:(UIImage *)shareImage; //FaceBook分享图片
+(void)shareFacebookImageUrl:(NSString *)imgurl; //FaceBook分享图片链接


+(void)enterGameMain;       //游戏进入游戏主界面调用（通知到SDK）

//typedef NS_ENUM(NSInteger, AdType) {
//    REWARDED = 1,
//    INTERSTITIAL = 2,
//    BANNER = 3,
//};
+(void)loadAd:(NSString *)sceneId andAdType:(AdType)adType andAdData:(NSString *)adData andBannerY:(NSInteger)bannerY;  // 加载广告
+(void)showAd:(AdType)adType andAdPlace:(NSString *)adPlace andAdData:(NSString *)adData;  // 展示广告  // 展示广告
+(void)hideBanner;//隐藏banner

+(void)eventReportToTDAttribute:(int)eventName andparamMap:(NSDictionary *)dict;//eventName:1 用户属性  2 公共事件属性--数数上报
//自定义事件上报
+(void)platformEventReport:(NSString *)eventName paramters:(NSDictionary *)paramter;

#pragma mark - 退出游戏
+(void)exitGame;
//+(void)openFacebookService; // 跳转到Facebook
+(void)getFacebookFriends;//facebook好友列表

//检查对应广告类型是否就绪
+(BOOL)isReadyAD:(AdType)type;
+(void)gameReport:(GameReportData *)roleInfo;                                  //角色信息上报
+(void)aihelpInitSMethod;

+(void)aihelpInitFMethod;

//数据存取
+(void)saveUserGameData:(NSString *)json_userInfo onSuccess:(void(^)(NSString * json))success onFailed:(void (^)(NSString * msg))failure;  //用户数据保存（需要登录之后调用）

+(void)getUserGameDataonSuccess:(void(^)(NSString * json))success onFailed:(void (^)(NSString * msg))failure; //用户数据读取（需要登录之后调用）

+(NSString *)dictToJson:(NSDictionary *)dict;//字典转json


+(void)saveGameConfigData:(NSString *)value andKey:(NSString *)key onSuccess:(void(^)(NSString * json))success onFailed:(void (^)(NSString * msg))failure; //自定义key存储（不需要登录）

+(void)getGameConfigData:(NSString *)key onSuccess:(void(^)(NSString * json))success onFailed:(void (^)(NSString * msg))failure; //自定义key读取（不需要登录）
#pragma mark - 查单
+(void)queryGameIndent:(NSString *)gameOrderNum onResult:(void(^)(int status))result;//0-请求超时  1-支付成功  2-支付失败




+(void)autoRefreshBannerMethod;//自动刷新

#pragma mark - AF卸载均衡
//+(void)registUninstall:(NSData *)deviceToken;





+(void)exchangeGameProp:(NSString *)exChangeStr andExt:(NSString *)extData result:(void(^)(NSString *resultjson))result;//兑换码

//审核模式
+(void)getExtraGameConfig:(void(^)(NSString *resultjson))callback;


#pragma mark - AIHelper
+(void)showAIHelper;

+(void)AIHelpfetchUnreadMessageCount;




+(void)toastWithStr:(NSString *)toastS;//sdk提示



//强制退出游戏回调
+(void)listenFourceLogoutGame:(void(^)(void))logoutBlock;
//快速登录 不需要登录界面直接游客登录调用
+(void)faseLogin;







#pragma mark -didFinishLaunchingWithOptions
+(void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
+(void)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
+(void)applicationDidBecomeActive:(UIApplication *)application;
+(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;
#pragma mark - 通知
+(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+(void)application:(UIApplication *)application
didReceiveRemoteNotification:(NSDictionary *)userInfo
fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
#pragma mark - 推送接口
+(void)pushNotificationWithTitle:(NSString *)title andContent:(NSString *)content;





+(void)applicationDidEnterBackground:(UIApplication *)application;
+(void)applicationWillEnterForeground:(UIApplication *)application;


//SDK参数 需要的自取
+(NSString *)getUUID;             //设备唯一标识(首次自己生成的，存到钥匙串，下次从钥匙串里取，卸载或者换bundleID都不会改变)
+(NSString *)getChannelID;          //渠道号
+(NSString *)getAppID;              //APPID
+(NSString *)getAppKey;             //APPkey


+(void)setDebugLog:(BOOL)debug;



//订阅查单
+(void)subsCheckOrder:(void(^)(id dict))result;
+(void)clearSDKCasch;



#pragma mark - SDK版本
+(NSString *)sdkVersion;



+(void)userBanView;


#pragma mark - 用户标签
+(void)exeCmd:(NSString *)cmd andBody:(NSString *)body ifSuccess:(void(^)(id response))success failure:(void (^)(NSError *error))failure;


#pragma mark - 应用内评分
+(void)StoreReview;

#pragma mark - AIHelp更新用户信息
+(void)updateAiHelperUserInfo:(AiHelpUserdata *)data;

+(NSString *)getIdFA;
#pragma mark - 查询是否有优惠
+(void)fetchProductPriceWithProductId:(NSString *)productId;
+(void)restorePurchases;//恢复购买
@end

NS_ASSUME_NONNULL_END
