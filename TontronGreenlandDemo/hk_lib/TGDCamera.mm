//
// Created by penghuiping on 14/10/25.
// Copyright (c) 2014 joinsoft. All rights reserved.
//

#import "TGDCamera.h"

@implementation TGDCamera {
    long userId;
    int previewPort;
    long realPlayID;
    int channel;
}

void fRealDataCallBack_V30(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser) {
    TGDCamera *camera = (__bridge TGDCamera *) pUser;
    
    //NSLog(@"dwBufSize:%zi",dwBufSize);
    
    switch (dwDataType) {
        case NET_DVR_SYSHEAD:
            if (dwBufSize > 0 && camera->previewPort != -1) {
                if (!PlayM4_SetStreamOpenMode(camera->previewPort, STREAME_REALTIME)) {
                    NSLog(@"error no: %d", NET_DVR_GetLastError());
                    break;
                }
                if (!PlayM4_OpenStream(camera->previewPort, pBuffer, dwBufSize, 2 * 1024 * 1024)) {
                    NSLog(@"error no: %d", NET_DVR_GetLastError());
                    break;
                }
                
//                UIImage *image=[UIImage imageWithData:<#(NSData *)#>];
//                
//                UIImageWriteToSavedPhotosAlbum(viewImage, nil, nil, nil);//然后将该图片保存到图片图
                
                
                
                [camera startPlayer];
                
            }
            break;
        case NET_DVR_STD_AUDIODATA:
        case NET_DVR_STD_VIDEODATA:
            
            
            
            
            break;
            
        case NET_DVR_STREAMDATA:
            if (dwBufSize > 0 && camera->previewPort != -1) {
                if (!PlayM4_InputData(camera->previewPort, pBuffer, dwBufSize)) {
                    break;
                }
            }
            break;
        default:
            break;
    }
}

- (void)startPlayer {
    
    
    
    [self performSelectorOnMainThread:@selector(playerPlay)
                           withObject:nil
                        waitUntilDone:NO];
    
    
    
}

- (void)playerPlay {
    
    int nRet = PlayM4_Play(previewPort, (__bridge void *) self.carmeraView);
    
    
    
    
    
    if (nRet != 1) {
        NSLog(@"PlayM4_Play fail");
        NSLog(@"error no: %d", NET_DVR_GetLastError());
        [self stopPlay];
        return;
    }
    NSLog(@"nRet = %d", nRet);
}

- (void)stopPlay {
    if (realPlayID != -1) {
        NET_DVR_StopRealPlay(realPlayID);
        realPlayID = -1;
    }

    if (previewPort >= 0) {
        if (!PlayM4_Stop(previewPort)) {
            NSLog(@"PlayM4_Stop failed");
        }
        if (!PlayM4_CloseStream(previewPort)) {
            NSLog(@"PlayM4_CloseStream failed");
        }
        if (!PlayM4_FreePort(previewPort)) {
            NSLog(@"PlayM4_FreePort failed");
        }
        previewPort = -1;
    }
}

-(void)cameraController{
    
    BOOL isCon = NET_DVR_PTZControl(realPlayID,
                                    IRIS_OPEN,
                                    0);
    
    NSLog(@"isCon:%zi",isCon);
    
//    BOOL su= NET_DVR_RebootDVR(userId);
//
//    NSLog(@"su:%zi",su);
    
}

-(void)cameraController1{
    
    BOOL isCon = NET_DVR_PTZControl(realPlayID,
                                    IRIS_OPEN,
                                    1);
    
    NSLog(@"isCon:%zi",isCon);
    
    
}

- (instancetype)initWithView:(UIView *)view {
    self = [super init];
    if (self) {
        self.carmeraView = view;
    }

    return self;
}

+ (instancetype)cameraWithView:(UIView *)view {
    return [[self alloc] initWithView:view];
}

- (void)loginWithIpAddress:(NSString *)ipAddress userName:(NSString *)userName password:(NSString *)password {
       
    BOOL r = NET_DVR_Init();
    NSLog(@"%d", r);
    
    
    NET_DVR_DEVICEINFO_V30 deviceInfo = {0};
    userId = NET_DVR_Login_V30((char *) [ipAddress UTF8String], 8000,
            (char *) [userName UTF8String], (char *) [password UTF8String],
            &deviceInfo);
    if (userId == -1) {
        UIAlertView *alert = [[UIAlertView alloc]
                initWithTitle:@"错误"
                      message:@"登录失败"
                     delegate:nil
            cancelButtonTitle:@"确定"
            otherButtonTitles:nil];
        [alert show];
    } else {
        NSLog(@"摄像头登录成功");
        NET_DVR_IPPARACFG_V40 struIPPara = {0};
        
        //
        
        DWORD dwRet = 0;
        NET_DVR_GetDVRConfig(userId, NET_DVR_GET_IPPARACFG_V40, 0, &struIPPara, sizeof(struIPPara), &dwRet);
        
        NSLog(@"%zi",struIPPara.dwAChanNum);
        
        if (struIPPara.dwAChanNum > 0) {
            channel = 1;
        } else {
            channel = struIPPara.dwStartDChan;
        }
        if (channel <= 0) {
            channel = 1;
        }
        if (PlayM4_GetPort(&previewPort) != 1) {
            NSLog(@"PlayM4_GetPort failed:%d", NET_DVR_GetLastError());
        }
        NSLog(@"previewPort %d", previewPort);
        NET_DVR_CLIENTINFO clientInfo = {0};
        clientInfo.lChannel = channel;
        clientInfo.lLinkMode = (1 << 31);
        clientInfo.hPlayWnd = (__bridge void *) self.carmeraView;
        
        
        
       realPlayID = NET_DVR_RealPlay_V30(userId, &clientInfo, fRealDataCallBack_V30, (__bridge void *) self);
        
       // BOOL isPic =NET_DVR_CaptureJPEGPicture_NEW(userId,channel,4, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);
        
        
        
        //NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser) = NULL, void *pUser = NULL, BOOL bBlocked = FALSE);
        
        
        
        
        NSLog(@"error no: %d", NET_DVR_GetLastError());
        if (realPlayID == -1) {
            UIAlertView *alert = [[UIAlertView alloc]
                    initWithTitle:@"错误"
                          message:@"获取realPlayID失败"
                         delegate:nil
                cancelButtonTitle:@"确定"
                otherButtonTitles:nil];
            [alert show];
        }
        NSLog(@"realPlayID %ld", realPlayID);
    }
}

- (void)dealloc {
    [self logout];
    
       
    self.carmeraView = nil;
}

- (void)logout {
    if(userId>-1){
        
        NSLog(@"logout");
       
        NET_DVR_Logout(userId);
        
        NET_DVR_Cleanup();
        userId=-1;
    }
}

@end