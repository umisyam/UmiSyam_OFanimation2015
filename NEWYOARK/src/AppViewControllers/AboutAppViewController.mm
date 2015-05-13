//
//  AboutAppViewController.mm
//  Created by Umi Syam on 5/1/15.
//

#import "AboutAppViewController.h"
#import "ofxiOSExtras.h"

@implementation AboutAppViewController

- (id) initWithFrame:(CGRect)frame app:(ofxiOSApp *)app {
    ofxiOSGetOFWindow()->setOrientation( OF_ORIENTATION_DEFAULT );   //-- default portait orientation.
    return self = [super initWithFrame:frame app:app];
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return NO;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    //setting up background image
    self.view.backgroundColor = [UIColor clearColor];
    UIImageView* backgroundView;
    backgroundView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"AboutBG2@2x~iphone.png"]] autorelease];
    [self.view addSubview: backgroundView];

    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    
    CGRect scrollViewFrame = CGRectMake(0.f,
                                        0.f,
                                        screenRect.size.width,
                                        screenRect.size.height);
    
    UIScrollView* containerView = [[[UIScrollView alloc] initWithFrame:scrollViewFrame] autorelease];
    containerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    containerView.showsHorizontalScrollIndicator = NO;
    containerView.showsVerticalScrollIndicator = YES;
    containerView.alwaysBounceVertical = NO;
    [self.view addSubview:containerView];
    
    
    //header title "About New Yoark"
    UILabel *header = [[UILabel alloc] initWithFrame:CGRectMake(20, 60, screenRect.size.width-40, 30)];
    header.textColor = [UIColor colorWithRed:255/256.0 green:77/256.0 blue:90/256.0 alpha:1.0];
    header.font = [UIFont fontWithName:@"Helvetica-BoldOblique" size:26];
    header.text=@"ABOUT NEW YOARK";
    
    //Main Explanation
    UILabel *text1 = [[UILabel alloc] initWithFrame:CGRectMake(20, header.frame.origin.y+40, screenRect.size.width-40, 300)];
    text1.textColor = [UIColor whiteColor];
    text1.font = [UIFont fontWithName:@"HelveticaNeue-Light" size:13];
    text1.lineBreakMode = NSLineBreakByWordWrapping;
    text1.numberOfLines = 0;
    text1.text=@"New York City is widely known as a melting pot where people all over the world come together from different cultures and blend into the city. These characteristics are what makes the beauty of New York, highlighting its multicultural aspect and the colorful faces of the city. \n\nNEW YOARK is an experiential mobile app to explore the urban city vibe based on the mapping between Top 20 Foreign-born Population vs. Top 20 Most Spoken Languages in NYC.* It explores augmented reality as a live direct view of a physical, real-world environment whose elements are augmented by computer-generated graphics accompanied by real voices of New Yorkers. \n\n\nMade in New York with Love. \n2015. Umi Syam. Parsons School of Design.";
    
    //Credits
    UILabel *text2 = [[UILabel alloc] initWithFrame:CGRectMake(20, text1.frame.origin.y+290, screenRect.size.width-40, 200)];
    text2.textColor = [UIColor colorWithRed:255/256.0 green:77/256.0 blue:90/256.0 alpha:1.0];
    text2.font = [UIFont fontWithName:@"HelveticaNeue" size:8];
    text2.lineBreakMode = NSLineBreakByWordWrapping;
    text2.numberOfLines = 0;
    text2.text=@"Voice credit thanks to: Isabella Cruz Chong, Daniel Mastretta, Luobin Wang, Yunqi Zhou, Olga Yakoff, Nobonita Bhowmik, Gabor Tankovic, Carl Jadaa, Udit Mahajan, Shakti Mb, Jaskirat Randhawa, Enrica Beccalli, Minnie Kang, Yeyoung Cho, Lama Shehadeh, Nadine Razzouk, Dana Avesar, Mehdi Salehi,  Hang Do Thi Duc, Kiyo Yamazaki, Camilla Gernhardt Nakamura, Heloise Cullen, Vicky Yadid,  Nima Behrawan, Saman Tehrani, Nitcha Tothong, Santi Smbn, Lucy Bonner, Joanna China, Ava Burke, Charles Saidel, Caroline V. Nelson, Eric Jiang, Christina Lafontaine, Chris Fussner, Kyle Li,  Jesse Contour, Katherine L. Boehm, Saima Mohammad, Boris Yu, Dylan Shad, Ben Miller, Wesley Henrie, Sven Travis, Joy Peng, Sarah Page, Miri Park, Bryan Collinsworth, Peiying Feng, Rosalind Paradis. \n\n*Data based on US Census American Community Survey 2011.";
    
    [containerView addSubview:header ];
    [containerView addSubview:text1 ];
    [containerView addSubview:text2 ];
    
    containerView.contentSize = CGSizeMake(scrollViewFrame.size.width, scrollViewFrame.size.height);
    
    [self.view addSubview:containerView];
    
}

@end
