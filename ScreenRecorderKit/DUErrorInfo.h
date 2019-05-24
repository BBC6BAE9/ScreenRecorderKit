//
//  DUErrorInfo.h
//  Duobiao
//
//  Created by 黄洪 on 2018/8/13.
//  Copyright © 2018年 北京夺镖文化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DUErrorInfo : NSObject
{
    NSInteger   code;
    NSString    *msg;
    BOOL        isError;
}

/**
 错误码
 */
@property (nonatomic, assign) NSInteger  code;

/**
 错误信息
 */
@property (nonatomic, copy) NSString *msg;

/**
 是否有错误
 */
@property (nonatomic, assign) BOOL isError;

- (id)initWithDic:(NSDictionary *)dic;

- (instancetype)initWithDefault;

@end
