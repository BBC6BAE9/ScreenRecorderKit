//
//  ScreenRecordManager.h
//  录制屏幕框架
//
//  Created by huang on 2019/5/24.
//  Copyright © 2019 huang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DUErrorHandle.h"
#import "DUErrorInfo.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
// 录屏状态
typedef NS_ENUM(NSInteger, RecState) {
    
    RecState_Rec = 0,
    RecState_Stop = 1
    
};
@protocol ScreenRecordDelegate <NSObject>

@optional

/**
 保存到相册的代理方法

 @param image 路径，好像没什么用
 @param error 错误信息
 @param contextInfo 额外信息
 */
- (void)savedPhotoImage:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;

/**
 生成视频的二进制文件
 
 @param data 二进制数据
 @param isError 是否有错误
 */
- (void)savedVideoData:(NSData*)data didFinishSavingWithError:(BOOL)isError;

/**
 录制状态变化的代理方法

 @param state 状态
 @param error 错误信息
 */
-(void)recStateDidChange:(RecState)state withError:(NSError *__nullable)error;

@end

typedef void(^errorinfo)(DUErrorHandle *error);
@interface ScreenRecordManager : NSObject

+ (instancetype)shareManager;

@property(nonatomic,weak)id<ScreenRecordDelegate>  screenRecordDelegate;

/**
 是否正在录制中
 */
@property(nonatomic, assign) BOOL isRecording;

/**
 录制屏幕

 @param suc 成功回调
 @param errorInfo 错误信息
 */
- (void)screenRecSuc:(void (^)(void))suc failure:(errorinfo)errorInfo;

/**
 停止录制屏幕

 @param suc 成功回调
 @param errorInfo 错误信息
 */
- (void)stopRecSuc:(void (^)(void))suc failure:(errorinfo)errorInfo;

@end

NS_ASSUME_NONNULL_END
