//
//  MyAppDelegate.mm
//  Created by Umi Syam on 5/1/15.
//

#import "MyAppDelegate.h"
#import "MyAppViewController.h"

@implementation MyAppDelegate

@synthesize navigationController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [super applicationDidFinishLaunching:application];
    //make the splash screen stays a bit longer!
    [NSThread sleepForTimeInterval:2.0];
    
    self.navigationController = [[[UINavigationController alloc] init] autorelease];
    [self.window setRootViewController:self.navigationController];
    
    [self.navigationController pushViewController:[[[MyAppViewController alloc] init] autorelease]
                                         animated:YES];
    
    //--- style the UINavigationController
//    self.navigationController.navigationBar.topItem.title = @"Welcome, New Yorker!";
//    [self.navigationController.navigationBar setHidden:YES];
    [self.navigationController.navigationBar setTranslucent:YES];
    self.navigationController.navigationBar.shadowImage = [UIImage new];
    self.navigationController.view.backgroundColor = [UIColor clearColor];
    [self.navigationController.navigationBar setBackgroundImage:[[UIImage alloc] init] forBarMetrics:UIBarMetricsDefault];
    self.navigationController.navigationBar.shadowImage = [[UIImage alloc] init];
    self.navigationController.navigationBar.backgroundColor = [UIColor clearColor];
    
    return YES;
}

- (void) dealloc {
    self.navigationController = nil;
    [super dealloc];
}

@end
