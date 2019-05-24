//
//  DUErrorHandle.h
//  Duobiao
//
//  Created by 黄洪 on 2018/7/17.
//  Copyright © 2018年 北京夺镖文化有限公司. All rights reserved.
//

#import "DUErrorInfo.h"

@interface DUErrorHandle : DUErrorInfo

- (instancetype)initWithError:(NSError *)error;

@end
