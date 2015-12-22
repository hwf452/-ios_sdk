//
//  OneViewController.m
//  TontronGreenlandDemo
//
//  Created by skyinno on 15/10/21.
//  Copyright (c) 2015年 SkyInno. All rights reserved.
//

#import "OneViewController.h"

@interface OneViewController ()

@end

@implementation OneViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)btnClick:(UIButton *)sender {
    
    TGDMainViewController *main=[[TGDMainViewController alloc] init];
    
    [self.navigationController pushViewController:main animated:YES];
    
}

@end
