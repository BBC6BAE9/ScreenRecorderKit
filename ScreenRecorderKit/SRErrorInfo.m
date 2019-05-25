//
//  SRErrorInfo.m
//  Duobiao
//
//  Created by huang on 2019/5/25.
//  Copyright © 2019 北京夺镖文化有限公司. All rights reserved.
//

#import "SRErrorInfo.h"

@implementation SRErrorInfo
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
