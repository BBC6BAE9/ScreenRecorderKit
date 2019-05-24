//
//  DUErrorHandle.m
//  Duobiao
//
//  Created by 黄洪 on 2018/7/17.
//  Copyright © 2018年 北京夺镖文化有限公司. All rights reserved.
//

#import "DUErrorHandle.h"

@implementation DUErrorHandle

- (id)initWithDic:(NSDictionary *)dic {
    self = [super initWithDic:dic];
    if (self) {
        
//        if (code == 10042 || code == 10008 || code == 10012 || code == 10016) { // 未登录
//
//        }else if(code == 10069){ // 账户被冻结
//
//        }else if(code == 10004){
//            // 服务器暂时无法响应，请稍后再试
//        }
    }
    return self;
}

- (instancetype)initWithError:(NSError *)error {
    if (self = [super init]) {
        self.code = error.code;
    
        if (error.code == -5807) { // -5807的错误是因为上一个extension没有关闭没办法重新打开，经试验，在applicationWillTerminate中退出也不起作用，主要精力放在避免崩溃，而不是放在Replaykit处理这个异常
            
            self.msg = [NSString stringWithFormat:@"%@,请尝试重新启动手机解决", [error localizedDescription]];
            
        }else{
            
            self.msg = [error localizedDescription];
            
        }
        
    }
    return self;
}

@end
