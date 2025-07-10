//
//  AWOrderModel.h
//  AWSDKDemo
//
//  Created by admin on 2020/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//typedef NS_ENUM(NSInteger, OrderType) {
//    SUBS = 0,
//    INAPP = 1,
//};


@interface PayData : NSObject
@property(nonatomic,strong)NSString *timeStr;           //10位时间戳
@property(nonatomic,assign)double amount;                //金额
//@property(nonatomic,assign)double amount_usd;            //转换成美元的金额
@property(nonatomic,assign)int role_level;            //角色等级
@property(nonatomic,strong)NSString *amount_unit;       //金额类型 国内传  @”CNY“
@property(nonatomic,strong)NSString *ext;           //扩展字段json格式
@property(nonatomic,strong)NSString *product_id;           //商品ID
@property(nonatomic,strong)NSString *product_name;         //商品名
@property(nonatomic,strong)NSString *notify_url;        //回调地址
@property(nonatomic,strong)NSString *orderNum;      //游戏订单号
@property(nonatomic,strong)NSString *site_uid;          //SDK uid  不用传
@property(nonatomic,strong)NSString *orderType;      //商品类型 例如：元宝 、月卡
@property(nonatomic,strong)NSString *server_id;         //区服ID
@property(nonatomic,strong)NSString *role_id;           //角色ID
//@property(nonatomic,strong)NSString *productID;         //商品ID 内购用的

@property(nonatomic,strong)NSString *pay_type;          //支付方式


@end

NS_ASSUME_NONNULL_END
