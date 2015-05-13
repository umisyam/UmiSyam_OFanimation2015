//
//  nycAppViewController.mm
//  Created by Umi Syam on 5/1/15.
//

#import "nycAppViewController.h"
#import "ofxiOSExtras.h"
#import <AVFoundation/AVFoundation.h>

@implementation nycAppViewController
// this is a global variable for our camera-shutter.wav sound effect
SystemSoundID SoundID;

- (id) initWithFrame:(CGRect)frame app:(ofxiOSApp *)app {
    ofxiOSGetOFWindow()->setOrientation( OF_ORIENTATION_DEFAULT );   //-- default portait orientation.
    return self = [super initWithFrame:frame app:app];
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return NO;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    
    //load the camera-shutter.wav file
    NSURL *buttonURL = [NSURL fileURLWithPath:[[NSBundle mainBundle] pathForResource:@"camera-shutter" ofType:@"wav"]];
    AudioServicesCreateSystemSoundID((__bridge CFURLRef)buttonURL, &SoundID);
    
    //make the button
    UIButton* scrshotBtn = [[UIButton alloc] initWithFrame:CGRectMake(screenRect.size.width-70, 25, 55, 55)];
    [scrshotBtn addTarget:self action:@selector(saveScreenshot:) forControlEvents:UIControlEventTouchUpInside];
//    scrshotBtn.userInteractionEnabled = YES;
//    [scrshotBtn setExclusiveTouch:YES];
    
    UIImage *buttonImageNormal = [UIImage imageNamed:@"icon-scrshot@2x.png"];
    [scrshotBtn setBackgroundImage:buttonImageNormal forState:UIControlStateNormal];
    UIImage *buttonImagePressed = [UIImage imageNamed:@"icon-scrshot2@2x.png"];
    [scrshotBtn setBackgroundImage:buttonImagePressed forState:UIControlStateHighlighted];
    
    [self.view addSubview:scrshotBtn];
}

- (void)saveScreenshot:(id)sender {
    //play the camera-shutter.wav file
    AudioServicesPlaySystemSound(SoundID);
    
    NSLog(@"Button Scrshot clicked.");
    
    UIImage *image = [self glToUIImage];
    UIImageWriteToSavedPhotosAlbum(image, self, nil, nil);
    
    NSLog(@"Screen grabbed YAY!");
}

//Saving Screenshots to Photo Album
//Converting Open GL ES content to Image, with slight modification for iPhone 6
//Algorithm taken from here: http://www.bit-101.com/blog/?p=1861
-(UIImage *) glToUIImage {
    
    //iphone 6 has slightly different resolution -- change 568 to 480 if the device is iPhone 4.
    NSInteger myDataLength = 320 * 568 * 4;
    
    // allocate array and read pixels into it.
    GLubyte *buffer = (GLubyte *) malloc(myDataLength);
    glReadPixels(0, 0, 320, 568, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    
    // gl renders "upside down" so swap top to bottom into new array.
    GLubyte *buffer2 = (GLubyte *) malloc(myDataLength);
    for(int y = 0; y < 568; y++)
    {
        for(int x = 0; x < 320 * 4; x++)
        {
            buffer2[(567 - y) * 320 * 4 + x] = buffer[y * 4 * 320 + x];
        }
    }
    
    // make data provider with data.
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer2, myDataLength, NULL);
    
    // prep the ingredients
    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = 4 * 320;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
    
    // make the cgimage
    CGImageRef imageRef = CGImageCreate(320, 568, bitsPerComponent, bitsPerPixel, bytesPerRow, colorSpaceRef, bitmapInfo, provider, NULL, NO, renderingIntent);
    
    // then make the uiimage from that
    UIImage *myImage = [UIImage imageWithCGImage:imageRef];
    return myImage;
}

@end
