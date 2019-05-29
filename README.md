<p align="center" >
  <img src="https://s2.ax1x.com/2019/05/25/VkQ63T.jpg" title="ScreenRecoderKit">
</p>

[![Platform](https://img.shields.io/cocoapods/p/RTRootNavigationController.svg?style=flat)](http://www.bbc6bae9.com/)

# ScreenRecorderKit

## 注意
现已支持cocoasPods 
```objective-c
pod "ScreenRecorderKit"
```

* 注意在开始录屏之前要先获取“图片”的权限，否则回导致，所有接口回调都会正常，但是回调方法中的NSData为空。后续的将权限的判断和索取加入到框架中
* 如果最近有时间的画也会把录屏直播的东西加入进来

## 介绍

ScreenRecorderKit是一个基于ReplayKit封装的轻量级录屏框架。
WWDC关于Replaykit的部分参考：[Go Live with ReplayKit](https://developer.apple.com/videos/play/wwdc2016/601/)


本框架帮助开发者以一种更简单的方式处理App间的录屏冲突，App与系统之间的录屏冲突，以及其他异常的提示。并且可以保存到系统相册，代理方法里面可以获取到录屏视频的NSData数据，方便沙盒存储或者上传服务器。

## 特点

* 轻松的处理App与App的录屏冲突、App与系统录屏的冲突、
* 录屏中的异常问题。
* 开始和结束录屏的方法均有成功和失败的回调。

## 使用

1. 引用
在你需要调用录屏功能的地方`ScreenRecordManager.h`

设置 ScreenRecordDelegate 代理`[ScreenRecordManager shareManager];
    mgr.screenRecordDelegate = self;`

2. 开始和结束方法

开始录制

```objective-c
     [[ScreenRecordManager shareManager] screenRecSuc:^{
            
            NSLog(@"录制启动成功");
            [weakself showToast:@"录制启动成功"];
            
        } failure:^(DUErrorHandle *error) {
            
            NSLog(@"%@", error.msg);
            [weakself showToast: error.msg];
            
        }];      
```

 
结束录制

```objective-c
    [[ScreenRecordManager shareManager] stopRecSuc:^{
            
            
            
        } failure:^(DUErrorHandle *error) {
        
            if (error.code == -2) { // -2是没有可以结束的录屏幕的进程
            
            }else{
                
                [weakself showToast: error.msg];
                
            }
            
        }];     
```

3. 代理方法
`ScreenRecordManager`的录制状态发生了改变

```objective-c
-(void)recStateDidChange:(RecState)state withError:(NSError *)error{
    if (error) {
        
        [self showToast:[error localizedDescription]];
        
    }else{
        
        if (state == RecState_Rec) {
            
            self.recBtn.selected = YES;
            
        }else{
            
            [self showToast:@"录屏结束"];
            self.recBtn.selected = NO;
            
        }
        
    }
    
}
```

`ScreenRecordManager`保存录屏视频到相册成功的代理方法

```objective-c
-(void)savedPhotoImage:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo{
    
    if(error){
        
        [self showToast:[error localizedDescription]];
        
    }else{
        
        [self showToast:@"保存相册成功"];
        
    }
    
}
```

`ScreenRecordManager`录屏视频的二进制文件获取，在这里你可以选择将二进制数转成.mp4文件或者将数据上传至服务器等等。

```objective-c
-(void)savedVideoData:(NSData *)data didFinishSavingWithError:(BOOL)isError{
    
    if (isError) {
        
        [self showToast:@"生成二进制文件错误"];
        
    }else{
        
        [self showToast:@"生成二进制文件成功"];
        
    }
    
}
```



## Requirements

* **iOS 9.0** and up
* **Xcode 7.0** and up

## Installation

ScreenRecorderKit is not available through [CocoaPods](http://cocoapods.org) currently. 

## Author

Huanghong, chinahuanghong@gmail.com

## Apps Integrated

* [夺镖体育](https://itunes.apple.com/cn/app/%E5%A4%BA%E9%95%96/id1294273600?mt=8)

## License

ScreenRecorderKit is available under the MIT license. See the LICENSE file for more info.
