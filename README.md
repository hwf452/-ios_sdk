# ios_sdk
32位sdk 不能上传到appstore，只能用企业版发布。如果需要传到appstore请下载64位版本。
核心代码有：
if (isInit) {
        isInit=NO;
        
        if (camera == nil) {
            
            
            
            self.cameraView.touchViewDelegate=self;
            
            //视频预览页面增加手势识别，使摄像头能够上，下，左，右，变焦。
            
            UIPinchGestureRecognizer  *pinch = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchAction:)];
            [self.cameraView addGestureRecognizer:pinch];
            
            //视频预览页面需要一个view来接收
            
            camera = [TGDCamera cameraWithView:self.cameraView];
            
            
            
            
        }
        

        //登录到摄像头，获取取视频流
        [camera loginWithIpAddress:@"192.168.1.245" userName:@"admin" password:@"skyinno1"];

        
        
    }

