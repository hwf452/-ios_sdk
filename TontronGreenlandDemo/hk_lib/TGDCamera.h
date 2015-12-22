//
// Created by penghuiping on 14/10/25.
// Copyright (c) 2014 joinsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IOSPlayM4.h"
#import "hcnetsdk.h"

@interface TGDCamera : NSObject

@property(strong, nonatomic) UIView *carmeraView;

+ (instancetype)cameraWithView:(UIView *)view;

- (instancetype)initWithView:(UIView *)view;

- (void)loginWithIpAddress:(NSString *)ipAddress userName:(NSString *)userName password:(NSString *)password;

- (void)logout;

- (void)startPlayer;

-(void)cameraController;

-(void)cameraController1;


@end