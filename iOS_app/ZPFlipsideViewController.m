//
//  ZPFlipsideViewController.m
//  Characterizor
//
//  Created by Pierre Lebeaupin on 20/01/14.
//  Copyright (c) 2014 Pierre Lebeaupin. All rights reserved.
//

#import "ZPFlipsideViewController.h"

@interface ZPFlipsideViewController ()

@end

@implementation ZPFlipsideViewController

- (void)awakeFromNib
{
    self.preferredContentSize = CGSizeMake(320.0, 480.0);
    [super awakeFromNib];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)done:(id)sender
{
    [self.delegate flipsideViewControllerDidFinish:self];
}

@end
