//
//  ZPMainViewController.h
//  Characterizor
//
//  Created by Pierre Lebeaupin on 20/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#import "ZPFlipsideViewController.h"

@interface ZPMainViewController : UIViewController <ZPFlipsideViewControllerDelegate, UIPopoverControllerDelegate>

@property (strong, nonatomic) UIPopoverController *flipsidePopoverController;

@end
