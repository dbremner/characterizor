//
//  ZPFlipsideViewController.h
//  Characterizor
//
//  Created by Pierre Lebeaupin on 20/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ZPFlipsideViewController;

@protocol ZPFlipsideViewControllerDelegate
- (void)flipsideViewControllerDidFinish:(ZPFlipsideViewController *)controller;
@end

@interface ZPFlipsideViewController : UIViewController

@property (weak, nonatomic) id <ZPFlipsideViewControllerDelegate> delegate;

- (IBAction)done:(id)sender;

@end
