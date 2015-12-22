//
//  TGDMainViewController.m
//  TontronGreenlandDemo
//
//  Created by penghuiping on 14-9-17.
//  Copyright (c) 2014 joinsoft. All rights reserved.
//

#import "TGDMainViewController.h"
#import "TGDCamera.h"




//82680400000001    bo7kf31d aaf98f8948f34b1b0148f358d13d0012  edeb77ce841f4a5b9f1149e1f6dbe338
//82680400000002    jwixivuz aaf98f8948f34b1b0148f358d14c0013  73d07e93b73f456dbe36e683b5ce22c3
//appid    aaf98f8948f34b1b0148f358d1170011

//#define APP_ID              @"8a48b5514d32a2a8014d8e07d76640c8"

//#define USER_ACCOUNT        @"82680400000002"
//#define USER_PASSWORD       @"jwixivuz"
//#define ACCOUNT_SID         @"aaf98f8948f34b1b0148f358d14c0013"
//#define ACCOUNT_TOKEN       @"73d07e93b73f456dbe36e683b5ce22c3"
//#define USER_ID             @"2"



@implementation TGDMainViewController {
    TGDCamera *camera;
   
    
    
    NSString *_callid;
    //TGDVideoConfView *_videoConfView;
    BOOL _isCreator;
    NSString *_memberIds;
    NSString *_callType;
    NSTimer *_requestInvitationTimer;
    NSString *_userId;
    NSString *_userAccount;
    NSString *_userPassword;
    NSString *_accountSid;
    NSString *_accountToken;
}

+ (NSOperationQueue*)getQueue
{
    static NSOperationQueue* queue = NULL;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        queue = [[NSOperationQueue alloc] init];
    });
    return queue;
}

-(void)viewDidLoad{
    
    self.view.backgroundColor=[UIColor blueColor];
    
        
    
    if (camera == nil) {
        
        
        //viewCamera.frame =self.view.bounds;
        
        UIView *cameraView=[[UIView alloc] initWithFrame:CGRectMake(30, 84, 960, 642)];
        
        
        
       
        
        //cameraView.frame =self.view.bounds;
        
        [self.view addSubview:cameraView];
        
        camera = [TGDCamera cameraWithView:cameraView];
    }
    [camera loginWithIpAddress:@"192.168.1.241" userName:@"admin" password:@"admin123"];
    
    
    
    UIButton *btn=[[UIButton alloc] initWithFrame:CGRectMake(30, 350, 70, 40)];
    
    [btn setTitle:@"放大" forState:UIControlStateNormal];
    
    btn.backgroundColor=[UIColor redColor];
    [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    
    //[self.view addSubview:btn];
    
    
    UIButton *btn1=[[UIButton alloc] initWithFrame:CGRectMake(130, 350, 70, 40)];
    
    [btn1 setTitle:@"缩小" forState:UIControlStateNormal];
    
    btn1.backgroundColor=[UIColor redColor];
    [btn1 addTarget:self action:@selector(btnClick1:) forControlEvents:UIControlEventTouchUpInside];
    
    //[self.view addSubview:btn1];
    
    
    
    
}

-(void)btnClick:(UIButton *)btn{
    
    NSLog(@"click");
    
    [camera cameraController];
    
    
    
}

-(void)btnClick1:(UIButton *)btn{
    
    NSLog(@"click1");
    
    [camera cameraController1];
    
    
    
}






@end