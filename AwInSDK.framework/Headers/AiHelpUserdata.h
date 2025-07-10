//
//  AWOrderModel.h
//  AWSDKDemo
//
//  Created by admin on 2020/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface AiHelpUserdata : NSObject
@property(nonatomic,strong)NSString *nickName;           //游戏角色名称
@property(nonatomic,strong)NSString *serverId;       //区服id
@property(nonatomic,strong)NSString *roleId;           //角色id
@property(nonatomic,strong)NSString *userTag;           //用户标签
@property(nonatomic,strong)NSString *customJson;         //自定义用户json数据

@end

NS_ASSUME_NONNULL_END
