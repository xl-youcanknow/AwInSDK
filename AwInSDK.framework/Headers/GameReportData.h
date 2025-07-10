//
//  GameReportData.h
//  AWSDKDemo
//
//  Created by admin on 2020/12/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GameReportData : NSObject
//注：单机类游戏接入  非单机游戏数据由服务端上报
@property(nonatomic,strong)NSString *reportType;        //上报类型（（"entersvr"- 进入游戏事件，上报节点为进入游戏时 / "userset"-角色属性变动事件，上报节点为等级、战力、关卡变化，昵称改变等 / "newrole"-创角事件，上报节点为创建角色时

//newrole,entersvr必传

@property(nonatomic,strong)NSString *time;              //当前时间
@property(nonatomic,strong)NSString *regTime;    //创建角色时间，没有的话传当前时间

@property(nonatomic,strong)NSString *serverId;          //区服ID
@property(nonatomic,strong)NSString *roleId;            //角色ID
@property(nonatomic,strong)NSString *nickName;          //角色名


@property(nonatomic,assign)int level;             //当前等级\关卡，比如：大中小关对应000，101，或者对应000000，010101
@property(nonatomic, strong)NSString *server_name;          //区服名称
@property(nonatomic,assign)int power;             //战
@property(nonatomic,assign)int stage;             //当前关卡

@end

NS_ASSUME_NONNULL_END
