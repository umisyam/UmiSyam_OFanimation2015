#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxOpenCv.h"
#include "ofxTriangle.h"

class nycApp : public ofxiOSApp {
	
public:
    
    nycApp ();
    ~nycApp ();
    
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);

	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
    
    // -------------------------AUDIO SETUP
    ofSoundPlayer audio0_All, audio1_Spanish, audio2_Chinese, audio3_Russian, audio4_French, audio5_Hindi, audio6_Italian, audio7_Korean, audio8_Arabic, audio9_Hebrew, audio10_Greek, audio11_German, audio12_Japanese, audio13_Portuguese, audio14_Persian, audio15_Vietnamese, audio16_Thai;
    vector<ofSoundPlayer> allAudio;
    
    int audioIndex, audioIndexTotal;
    
    // -------------------------CAMERA SETUP
    ofVideoGrabber vidGrabber;
    float width, height;
    
    ofxCvContourFinder contourFinder;
    ofxCvColorImage	colorImg;
    
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    int threshold;
    
    int mode, modeTotal;
    void changeCameraMode(int mode);
    
    ofxTriangle triangle;
    
    // -------------------------FLAG COLORS SETUP
    // All are named based on their Pantone color code
    ofColor red_186C, red_200C, red_206C, red_199C;
    ofColor green_7728C, green_7731C, green_7739C, green_350C, green_361C, green_348C;
    ofColor blue_534C, blue_7683C, blue_2735C, blue_2736C, blue_2756C, blue_2718C, blue_2766C, blue_286C, blue_285C;
    ofColor yellow_107C, yellow_7405C, yellow_603C, yellow_165C, yellow_130C;
    ofColor black, white;
    
    // For color interpolation
    int millisNow, timePeriod, millisSinceLastCheck, colorsIndex;
    vector<ofColor> colors;
    ofColor colorT;
    
    void interpolateColors();
    void changeLangColors(int lang);
    int lang, langTotal;
    
    //where the magic happens!
    void augmentThings();
    
    //for description panel at the bottom of the vidGrabber
    ofImage flagSpanish, flagChinese, flagRussian, flagFrench, flagHindi, flagItalian, flagKorean, flagArabic, flagHebrew, flagGreek, flagGerman, flagJapanese, flagPortuguese, flagPersian, flagVietnamese, flagThai;
    
    //SHADER
    ofImage brushAll, brushSpanish, brushChinese, brushRussian, brushFrench, brushHindi, brushItalian, brushKorean, brushArabic, brushHebrew, brushGreek, brushGerman, brushJapanese, brushPortuguese, brushPersian, brushVietnamese, brushThai;
    ofImage     brushImg;
    
    ofFbo       maskFbo;
    ofFbo       fbo;
    
    int nearThreshold;
    int farThreshold;
    
    ofShader    shader;
    
    bool        bBrushDown;

    void changeBrush(int brushIndex);
    int brushIndex, brushIndexTotal;
    
};


