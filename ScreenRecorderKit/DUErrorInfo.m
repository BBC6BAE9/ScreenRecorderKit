//
//  DUErrorInfo.m
//  Duobiao
//
//  Created by 黄洪 on 2018/8/13.
//  Copyright © 2018年 北京夺镖文化有限公司. All rights reserved.
//

#import "DUErrorInfo.h"

@implementation DUErrorInfo
@synthesize code;
@synthesize msg;
@synthesize isError;

- (id)initWithDic:(NSDictionary *)dic
{
    if (self = [super init]) {
        self.code = [[dic objectForKey: @"error_code"] integerValue];
        self.msg  = [dic objectForKey: @"error_msg"];
        if (self.code == 0) {
            isError = NO;
        }
        else{
            isError = YES;
        }
    }
    return self;
}

- (instancetype)initWithDefault
{
    if (self = [super init]) {
        self.msg = @"一般错误";
        self.code = 1;
    }
    return self;
}


@end
