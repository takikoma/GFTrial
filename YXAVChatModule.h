//
//  YXAVChatModule.h
//  YXAVChatFramework
//
//  Created by fenric on 13-11-19.
//  Copyright (c) 2013年 yixin.dev. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    YXAVCHAT_INCOMPATIBLE_LOW = 0, //本端版本太低
    YXAVCHAT_INCOMPATIBLE_HIGH,    //本端版本太高
}YXAVChatIncompatibleReason;

typedef enum
{
    YXAVCHAT_OS_UNKNOWN = 0,
    YXAVCHAT_OS_ANDROID = 1,
    YXAVCHAT_OS_IOS     = 2,
    YXAVCHAT_OS_WP      = 3,
    YXAVCHAT_OS_PC      = 4,
    YXAVCHAT_OS_CAM     = 5,
}YXAVChatOSType;

typedef enum
{
    YXAVCHAT_NET_UNKNOWN = 0,
    YXAVCHAT_NET_3G      = 1,
    YXAVCHAT_NET_WIFI    = 2,
    YXAVCHAT_NET_2_5G    = 11,
    YXAVCHAT_NET_4G      = 12,
}YXAVChatNetType;


typedef enum
{
    YXAVCHAT_CLIENT_YIXIN = 0, //易信客户端
    YXAVCHAT_CLIENT_SUPERCALL = 1, //超级电话客户端
    YXAVCHAT_CLIENT_NIM = 2, //云信SDK
    YXAVCHAT_CLIENT_HS = 101, //恒生视频开户项目客户端
    YXAVCHAT_CLIENT_CAMERA = 201, //易信摄像头
}YXAVChatClientType;

typedef enum
{
    YXAVCHAT_SEND_FREQUENCY_CONTROL_REDUCE   = -1, //降低发送频率：增大包长
    YXAVCHAT_SEND_FREQUENCY_CONTROL_INCREASE = 1, //提高发送频率：减小包长
}YXAVChatSendFrequencyControl;

typedef enum
{
    YXAVCHAT_LEAVE_REASON_TIMEOUT = -1,
    YXAVCHAT_LEAVE_REASON_NORMAL  = 0,
}YXAVChatLeaveReason;


@interface YXAVChatParams : NSObject {
}
@property (nonatomic, strong) NSString *clientName;  //节点描述名
@property (nonatomic, assign) uint64_t clientID;     //节点id
@property (nonatomic, assign) uint64_t channelID;    //频道id
@property (nonatomic, strong) NSString *proxyAddr;   //代理服务器地址
@property (nonatomic, strong) NSString *turnAddr;    //turn服务器地址
@property (nonatomic, assign) uint16_t proxyPolicy;  //客户端是否通过代理服务器
@property (nonatomic, assign) uint32_t stun;         //是否进行stun探测
@property (nonatomic, strong) NSString *stunAddr1;   //stun服务器地址1
@property (nonatomic, strong) NSString *stunAddr2;   //stun服务器地址2
@property (nonatomic, assign) uint16_t logLevel;     //log输出等级
@property (nonatomic, assign) uint16_t pullPolicy;   //客户端是否拉包
@property (nonatomic, assign) uint32_t lostRate;     //模拟丢包率
@property (nonatomic, assign) uint32_t punching;     //是否进行udp打洞操作
@property (nonatomic, strong) NSString *logPath;     //log输出路径

@property (nonatomic, strong) NSString *encryptToken; //加密的频道id
@property (nonatomic, assign) uint16_t encryptType;   //加密方式

@property (nonatomic, assign) uint32_t bandwidthThreshold;  //带宽要求阀值
@property (nonatomic, assign) uint16_t packetlossThreshold; //丢包要求阀值

@property (nonatomic, assign) uint16_t audioParameter;  //音频聊天参数
@property (nonatomic, assign) uint16_t videoResolution; //视频聊天分辨率参数
@property (nonatomic, assign) uint16_t videoParameter;  //视频聊天参数采用编码方式
@property (nonatomic, assign) uint16_t voipMode;        //voip模式
@property (nonatomic, assign) uint16_t clientType;      //客户端类型 YXAVChatClientType
@property (nonatomic, assign) uint16_t peerClientType;  //对端客户端类型 YXAVChatClientType

@property (nonatomic, assign) uint16_t netType;         //网络类型 YXAVChatNetType
@property (nonatomic, assign) uint16_t ispType;         //运营商类型: 国内运营商传MNC，国外运营商传255
@property (nonatomic, assign) uint32_t codecRateMaxThreshold;  //码率上限阀值
@property (nonatomic, assign) uint32_t codecRateMinThreshold;  //码率下限阀值
@property (nonatomic, assign) uint32_t rttMaxThreshold;        //rtt上限阀值
@property (nonatomic, assign) uint32_t rttMinThreshold;        //rtt下限阀值
@property (nonatomic, assign) uint16_t rateUpWeight;           //码率上调权重
@property (nonatomic, assign) uint16_t rateDownWeight;         //码率下调权重


@end

@interface YXAVChatReport : NSObject {
    
}
@property (nonatomic, assign) uint64_t totalTxBytes;
@property (nonatomic, assign) uint64_t totalRxBytes;
@property (nonatomic, assign) uint64_t sessionTotalTime;
@property (nonatomic, assign) uint64_t audioSendCount;

@end

@interface YXAVChatConnectParam : NSObject {
}

@property (nonatomic, assign) uint64_t clientID;     //用户id
@property (nonatomic, assign) uint32_t mode;         //voip模式(音频/视频)
@property (nonatomic, assign) uint32_t resolution;   //视频聊天分辨率
@property (nonatomic, assign) uint32_t vparam;       //视频聊天参数
@property (nonatomic, assign) uint32_t aparam;       //语音聊天参数
@property (nonatomic, assign) uint32_t myVersion;    //本端底层协议版本号
@property (nonatomic, assign) uint32_t otherVersion; //对端底层协议版本号
@property (nonatomic, assign) uint16_t otherNetType; //对端网络类型

@end

@interface YXAVChatLogoutParam : NSObject {
}
@property (nonatomic, assign) uint32_t freezeSessionRate;    //卡播比
@property (nonatomic, assign) uint32_t jitterGap;            //jitter gap
@property (nonatomic, assign) uint32_t jitterPacketTimetout; //jitter 超时包

@end

@interface YXAVChatNetParam : NSObject {
}
@property (nonatomic, assign) uint32_t maxRate;
@property (nonatomic, assign) uint32_t minRate;
@property (nonatomic, assign) uint32_t maxRTT;
@property (nonatomic, assign) uint32_t minRTT;
@end

@interface YXAVChatVideoBitrateParam : NSObject {
}
@property (nonatomic, assign) uint32_t videoMaxBitrate; //视频码率调整上限
@property (nonatomic, assign) uint32_t videoMinBitrate; //视频码率调整下限
@property (nonatomic, assign) uint32_t videoCurrentBitrate; //当前视频码率

-(id)initWithMaxBitrate:(uint32_t)maxBitrate
             minBitrate:(uint32_t)minBitrate
         currentBitrate:(uint32_t)currentBitrate;

@end


/*
 Delegate to receive event notification
 */
@protocol YXAVChatModuleDelegate <NSObject>

@optional

-(void) onLoginResponse:(uint32_t)authResult;  //登陆服务器结果。成功：200

-(void) onPeerDisconnect; //与对端用户断开连接

-(void) onServerDisconnect; //与服务器断开连接

-(void) onPeopleJoin:(uint64_t)clientID; //用户加入房间

-(void) onPeopleLeave:(uint64_t)clientID forReason:(YXAVChatLeaveReason)reason;  //用户离开房间

-(void) onAudioKeyChanged:(uint64_t) clientID toKey:(uint16_t)key; //0:对方声音关闭 1：开启
-(void) onVideoKeyChanged:(uint64_t) clientID toKey:(uint16_t)key;

-(void) onConnect:(YXAVChatConnectParam *)param; //除本人以外的另一个用户进入房间，第一对用户连接建立，可以开始收发数据包了

-(void) onModeChanged:(uint16_t)mode; //模式切换(音频/视频)
-(void) onNetstatChanged:(uint16_t)stat rate:(uint32_t)aRate;//网络状态变化 0:最好, 1 ,2 ,3:最差

-(void) onReceiveAudioPacket:(const char *)packet dataSize:(uint16_t)size from:(uint64_t)clientID withPacketID:(uint32_t)packetID;   //收到一个语音包

-(void) onReceiveVideoPacket:(const char *)packet dataSize:(uint16_t)size from:(uint64_t)clientID withPacketID:(uint32_t)packetID;   //收到一个视频包

-(void) onP2PStat:(uint32_t)msgType;   //p2p调试统计用，可不实现

-(void) onProtocalIncompatible:(YXAVChatIncompatibleReason)reason;  //客户端间网络层协议版本不兼容

-(void) onOtherNetTypeChanged:(YXAVChatNetType)netType;  //对方网络类型变化

-(uint32_t) onChangeSendFrequency:(YXAVChatSendFrequencyControl)control; //请求改变发包频率

-(void) onChangeVideoBitrate:(uint32_t)bitrate; //调整视频码率

-(void) onReceiveNotification:(NSString *)info from:(uint64_t)clientID; //收到对端从网络库发来的通知


@end


@interface YXAVChatModule : NSObject {
}

@property (nonatomic, strong) YXAVChatParams *avChatParams;
@property (nonatomic, assign) id<YXAVChatModuleDelegate> delegate;
@property (nonatomic, assign) BOOL isRelogin;

+ (YXAVChatModule*)sharedInstance;

- (bool)startClient;
- (uint16_t)logout:(YXAVChatReport *)report;
- (uint16_t)logout:(YXAVChatLogoutParam *)param report:(YXAVChatReport *)report;
- (uint32_t)sendAudioPacket:(const char *)data dataSize:(uint16_t)size;
- (uint32_t)sendVideoPacket:(const char *)data dataSize:(uint16_t)size isKeyFrame:(BOOL)keyFrame;
- (void)sendNotitication:(NSString *)info to:(uint64_t)client;

- (bool) isOnline;

- (void) setAudioKey:(uint16_t) key;
- (void) setVideoKey:(uint16_t) key;
- (void) setChatMode:(uint16_t) mode;

- (void) setNetType:(uint32_t) netType;
- (void) setNetParam:(YXAVChatNetParam *) netParam;
- (void) setVideoBitrateParam:(YXAVChatVideoBitrateParam *)bitrateParam;

- (uint16_t)relogin;

@end
