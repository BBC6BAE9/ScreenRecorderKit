//
//  SRErrorHandle.h
//  Duobiao
//
//  Created by huang on 2019/5/25.
//  Copyright © 2019 北京夺镖文化有限公司. All rights reserved.
//

#import "SRErrorInfo.h"

@interface SRErrorHandle : SRErrorInfo

- (instancetype)initWithError:(NSError *)error;

@end

