//
//  SRErrorInfo.h
//  Duobiao
//
//  Created by huang on 2019/5/25.
//  Copyright © 2019 北京夺镖文化有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SRErrorInfo : NSObject
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

NS_ASSUME_NONNULL_END
