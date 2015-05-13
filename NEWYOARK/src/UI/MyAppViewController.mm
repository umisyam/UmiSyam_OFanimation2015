//
//  MyAppViewController.mm
//  Created by Umi Syam on 5/1/15.
//

#import "MyAppViewController.h"

#import "nycAppViewController.h"
#import "nycApp.h"

#import "AboutAppViewController.h"
#import "AboutApp.h"

@implementation MyAppViewController

- (void)loadView {
    [self.navigationController setNavigationBarHidden:NO];
    [super loadView];
    
    //setting up background image
    self.view.backgroundColor = [UIColor clearColor];
    UIImageView* backgroundView;
    backgroundView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"bgNYC3@2x~iphone.png"]] autorelease];
    [self.view addSubview: backgroundView];
    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    
    //making an array of buttons
    NSArray *buttonTitles;
    buttonTitles = [NSArray arrayWithObjects: @"Let's Go!", @"About", nil];
    
    NSInteger buttonY = 425;     // Y distance from the top screen
    NSInteger buttonGap = 5;
    NSInteger buttonHeight = 65;
    CGRect buttonRect = CGRectMake(0, 0, screenRect.size.width, buttonHeight);
    
    for (int i = 0; i < [buttonTitles count]; i++) {
        UIButton *button;
        button = [self makeButtonWithFrame:CGRectMake(20, buttonY, buttonRect.size.width, buttonRect.size.height)
                                   andText:[buttonTitles objectAtIndex:i]];
        //add each button to the self-container
        [self.view addSubview:button];
        
        if (i== 0)
            [button addTarget:self action:@selector(LetsGoBtnPressed:) forControlEvents:UIControlEventTouchUpInside];
        else if (i==1)
            [button addTarget:self action:@selector(AboutBtnPressed:) forControlEvents:UIControlEventTouchUpInside];

        buttonY += buttonRect.size.height;
        buttonY += buttonGap;
    }
    
}

- (UIButton*) makeButtonWithFrame:(CGRect)frame
                          andText:(NSString*)text {
    UIFont *font;
    font = [UIFont fontWithName:@"Helvetica-Oblique" size:24];
    
    UILabel *label;
    label = [[[ UILabel alloc] initWithFrame:CGRectMake(0, 0, frame.size.width, frame.size.height)] autorelease];
    label.backgroundColor = [UIColor colorWithWhite:0 alpha:0.15];
    label.textColor = [UIColor colorWithWhite:1 alpha:1];
    label.text = [text uppercaseString];
    label.textAlignment = UITextAlignmentLeft;
    label.font = font;
    label.userInteractionEnabled = NO;
    label.exclusiveTouch = NO;
    
    UIButton* button = [[[UIButton alloc] initWithFrame:frame] autorelease];
    [button setBackgroundColor:[UIColor clearColor]];
    [button addSubview:label];
    
    return button;
}

- (void)LetsGoBtnPressed:(id)sender {
    NSLog(@"Button Let's Go clicked.");
    
    //this is where the OF class "nycApp" gets called
    nycAppViewController *viewController;
    viewController = [[[nycAppViewController alloc] initWithFrame:[[UIScreen mainScreen] bounds]
                                                              app:new nycApp()] autorelease];
    
    [self.navigationController pushViewController:viewController animated:YES];
}

- (void)AboutBtnPressed:(id)sender {
    NSLog(@"Button About clicked.");
    
    //this is where the OF class "AboutApp" gets called
    AboutAppViewController *viewController;
    viewController = [[[AboutAppViewController alloc] initWithFrame:[[UIScreen mainScreen] bounds]
                                                                app:new AboutApp()] autorelease];
    
    [self.navigationController pushViewController:viewController animated:YES];
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    BOOL bRotate = NO;
    bRotate = bRotate || (toInterfaceOrientation == UIInterfaceOrientationPortrait);
    bRotate = bRotate || (toInterfaceOrientation == UIInterfaceOrientationPortraitUpsideDown);
    return bRotate;
}

@end
