#include "nycApp.h"

//--------------------------------------------------------------
nycApp :: nycApp () {
    cout << "creating nycApp" << endl;
}

//--------------------------------------------------------------
nycApp :: ~nycApp () {
    cout << "destroying nycApp" << endl;
}

//--------------------------------------------------------------
void nycApp::setup() {
    ofBackground(0);
    ofSetOrientation(OF_ORIENTATION_DEFAULT);
    ofEnableAlphaBlending();
    
    ofSetFrameRate(8);
//    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableTextureEdgeHack();
    
    // -------------------------CAMERA SETUP
    width = ofGetWindowHeight();
    height = ofGetWindowHeight();
    
    vidGrabber.initGrabber(width, height);
    width = vidGrabber.getWidth();
    height = vidGrabber.getHeight();
    
    colorImg.allocate(width,height);
    grayImage.allocate(width,height);
    grayBg.allocate(width,height);
    grayDiff.allocate(width,height);
    
    threshold = 80;
    
    mode = 0;
    modeTotal = 4;
    lang = 0;
    langTotal = 17;
    
    timePeriod = 1.5f;
    
    // -------------------------SHADER BRUSH SETUP
    brushAll.loadImage("brush/flags.png");
    brushSpanish.loadImage("brush/brushSpanish.png");
    brushChinese.loadImage("brush/brushChinese.png");
    brushRussian.loadImage("brush/brushRussian.png");
    brushFrench.loadImage("brush/brushFrench.png");
    brushHindi.loadImage("brush/brushHindi.png");
    brushItalian.loadImage("brush/brushItalian.png");
    brushKorean.loadImage("brush/brushKorean.png");
    brushArabic.loadImage("brush/brushArabic.png");
    brushHebrew.loadImage("brush/brushHebrew.png");
    brushGreek.loadImage("brush/brushGreek.png");
    brushGerman.loadImage("brush/brushGerman.png");
    brushJapanese.loadImage("brush/brushJapanese.png");
    brushPortuguese.loadImage("brush/brushPortuguese.png");
    brushPersian.loadImage("brush/brushPersian.png");
    brushVietnamese.loadImage("brush/brushVietnamese.png");
    brushThai.loadImage("brush/brushThai.png");
    
    brushImg.loadImage("brush.png");
    
    nearThreshold = 230;
    farThreshold = 70;
    
    brushIndex = 0;
    brushIndexTotal = 17;
    
    int shaderWidth = brushAll.getWidth();
    int shaderHeight = brushAll.getHeight();
    
    maskFbo.allocate(shaderWidth,shaderHeight);
    fbo.allocate(shaderWidth,shaderHeight);
    
    shader.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    bBrushDown = false;
    
    // -------------------------AUDIO SETUP
    audioIndex = 0;
    audioIndexTotal = 17;
    
    audio0_All.loadSound("audio/NY-All-English2.mp3");
    audio1_Spanish.loadSound("audio/Spanish-IsabellaDaniel.mp3");
    audio2_Chinese.loadSound("audio/China-LuobinJoe.mp3");
    audio3_Russian.loadSound("audio/Russian-Olga.mp3");
    audio4_French.loadSound("audio/French-GaborCarl.mp3");
    audio5_Hindi.loadSound("audio/Hindi-JasUdit.mp3");
    audio6_Italian.loadSound("audio/Italian-EnricaB.mp3");
    audio7_Korean.loadSound("audio/Korean-MinnieYeyoung.mp3");
    audio8_Arabic.loadSound("audio/Arabic-LamaNadine.mp3");
    audio9_Hebrew.loadSound("audio/Hebrew-Dana.mp3");
    audio10_Greek.loadSound("audio/Greek-Mehdi.mp3");
    audio11_German.loadSound("audio/German-Hang.mp3");
    audio12_Japanese.loadSound("audio/Japanese-Kiyo.mp3");
    audio13_Portuguese.loadSound("audio/Portuguese-CamillaHeloise.mp3");
    audio14_Persian.loadSound("audio/Farsi-NimaSaman.mp3");
    audio15_Vietnamese.loadSound("audio/Vietnamese-Hang.mp3");
    audio16_Thai.loadSound("audio/Thai-FameSanti.mp3");
    
    allAudio.push_back(audio0_All);
    allAudio.push_back(audio1_Spanish);
    allAudio.push_back(audio2_Chinese);
    allAudio.push_back(audio3_Russian);
    allAudio.push_back(audio4_French);
    allAudio.push_back(audio5_Hindi);
    allAudio.push_back(audio6_Italian);
    allAudio.push_back(audio7_Korean);
    allAudio.push_back(audio8_Arabic);
    allAudio.push_back(audio9_Hebrew);
    allAudio.push_back(audio10_Greek);
    allAudio.push_back(audio11_German);
    allAudio.push_back(audio12_Japanese);
    allAudio.push_back(audio13_Portuguese);
    allAudio.push_back(audio14_Persian);
    allAudio.push_back(audio15_Vietnamese);
    allAudio.push_back(audio16_Thai);
    allAudio[0].play();
    
    // -----------------------------COUNTRY FLAG SETUP
    red_186C.set(206, 17, 38, 150);     // dominican/china/mexico/guyana/haiti/T&T/russia/bangladesh/korea/colombia/poland/philippines/italy/ red
    red_200C.set(200, 16, 46, 255);    // UK red
    red_206C.set(216, 28, 63, 255);    // ecuador red
    red_199C.set(213, 0, 50, 255);    //syrian & lebanese red
    
    green_7728C.set(0, 104, 71, 150);    //mexican green
    green_7731C.set(0, 132, 61, 255);    //india/italy green
    green_7739C.set(0, 158, 73, 255);    //guyana green
    green_350C.set(44, 82, 52, 255);    //pakistan/bangladesh green
    green_361C.set(0, 177, 64, 255);    //jamaica green
    green_348C.set(0, 132, 61, 255);    //syrian & lebanese green
    
    blue_534C.set(0, 56, 107, 255);    //dominican blue
    blue_7683C.set(0, 114, 198, 255);    //ecuador blue
    blue_2735C.set(12, 28, 140, 255);    //haiti/el salvador blue
    blue_2756C.set(1, 33, 105, 255);    //india blue
    blue_2736C.set(0, 51, 160, 255);    //russia/korea/colombia blue
    blue_2718C.set(65, 143, 222, 255);    //ukraine blue
    blue_2766C.set(7, 29, 73, 255);    //philippines/UK blue
    blue_286C.set(0, 51, 160, 255);    //israel blue
    blue_285C.set(0, 114, 206, 255);    //greece blue
    
    yellow_107C.set(254, 219, 0, 255);    //china/jamaica yellow
    yellow_7405C.set(252, 209, 22, 255);    //guyana/el salvador yellow
    yellow_603C.set( 249, 226, 76, 255);    //ecuador yellow
    yellow_165C.set(255, 103, 31, 255);    //india yellow
    yellow_130C.set(255, 163, 0, 255);    //colombia/ukraine yellow
    
    white.set(255, 255, 255, 255);
    black.set(0,0,0);

    //Flag images for description blurb
    flagSpanish.loadImage("flags/flagSpanish.png");
    flagChinese.loadImage("flags/flagChinese.png");
    flagRussian.loadImage("flags/flagRussian.png");
    flagFrench.loadImage("flags/flagFrench.png");
    flagHindi.loadImage("flags/flagHindi.png");
    flagItalian.loadImage("flags/flagItalian.png");
    flagKorean.loadImage("flags/flagKorean.png");
    flagArabic.loadImage("flags/flagArabic.png");
    flagHebrew.loadImage("flags/flagHebrew.png");
    flagGreek.loadImage("flags/flagGreek.png");
    flagGerman.loadImage("flags/flagGerman.png");
    flagJapanese.loadImage("flags/flagJapanese.png");
    flagPortuguese.loadImage("flags/flagPortuguese.png");
    flagPersian.loadImage("flags/flagPersian.png");
    flagVietnamese.loadImage("flags/flagVietnamese.png");
    flagThai.loadImage("flags/flagThai.png");
}

//--------------------------------------------------------------
void nycApp::update(){
    
    ofSoundUpdate();
    vidGrabber.update();

    bool bNewFrame = false;
    bNewFrame = vidGrabber.isFrameNew();
    
    if (bNewFrame){
        if( vidGrabber.getPixels() != NULL ){
            colorImg.setFromPixels(vidGrabber.getPixels(), width, height);
            grayImage = colorImg;
            
            grayDiff.absDiff(grayBg, grayImage);
            grayDiff.threshold(threshold);
            
            unsigned char * pix = vidGrabber.getPixels();
            
            int numPixels = grayDiff.getWidth() * grayDiff.getHeight();
            for(int i = 0; i < numPixels; i++) {
                if(pix[i] < nearThreshold && pix[i] > farThreshold) {
                    pix[i] = 255;
                } else {
                    pix[i] = 0;
                }
            }
            
            //SHADER
            // MASK (frame buffer object)
            maskFbo.begin();
            if (bBrushDown){
                brushImg.draw(mouseX, mouseY,60,60);
            }
            maskFbo.end();
            
            // HERE the shader-masking happends
            fbo.begin();
            ofClear(0, 0, 0, 0);
            
            shader.begin();
            shader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1 );
            
            //load different flag brushes depending on the Audio being played
            changeBrush(brushIndex);
            
            shader.end();
            fbo.end();
        }
        
        grayDiff.flagImageChanged();
        contourFinder.findContours(grayDiff, 20, (width*height), 10, true);
    }
    
}

//--------------------------------------------------------------
void nycApp::draw() {

//if this gets commented & the gesture for double tap is being changed to changeCameraMode instead, it will load different video state: Color, Grayscale, Tinted Red, and Black&White.
//    ofSetColor(255, 255);
//    ofDrawBitmapString("DOUBLE TAP TO CHANGE CAMERA MODE", 20, ofGetHeight()-20);
//    changeCameraMode(mode);
    
    vidGrabber.draw(0,0);
    augmentThings();
    
//    ofEnableAlphaBlending();
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    fbo.draw(0,0);
//    ofDisableAlphaBlending();
    
}

void nycApp::augmentThings() {
    
    ofPushMatrix();
    
    for (int i = 1; i < contourFinder.nBlobs; i++){
        
        colors.clear();
        changeLangColors(lang);
        interpolateColors();
        
        ofxCvBlob b = contourFinder.blobs[i];
        vector<ofPoint> points = b.pts;
        
        //draw the vertex - show SOLID COLOR FILL
        ofBeginShape();
        for (int i=0; i<points.size(); i++) {
            ofVertex(points[i].x, points[i].y);
            
        }
        ofEndShape();
        
        //prepare to create meshes by triangulating each node from ofxTriangle
        triangle.clear();
        triangle.triangulate(b.pts);
        
        ofMesh m;
        m.clear();
        m.setMode(OF_PRIMITIVE_TRIANGLES);
        
        for (int k = 0; k < triangle.nTriangles; k++){
            ofVec2f a = triangle.triangles[k].a;
            ofVec2f b = triangle.triangles[k].b;
            ofVec2f c = triangle.triangles[k].c;
            
            m.addVertex(a);
            m.addVertex(b);
            m.addVertex(c);
            
            m.addTexCoord(a);
            m.addTexCoord(b);
            m.addTexCoord(c);
        }
        
        ofSetLineWidth(1.5f);
        ofSetColor(0);
        m.drawWireframe();
//        m.draw();
        ofSetColor(255);
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void nycApp::exit() {
    audio0_All.unloadSound();
    audio1_Spanish.unloadSound();
    audio2_Chinese.unloadSound();
    audio3_Russian.unloadSound();
    audio4_French.unloadSound();
    audio5_Hindi.unloadSound();
    audio6_Italian.unloadSound();
    audio7_Korean.unloadSound();
    audio8_Arabic.unloadSound();
    audio9_Hebrew.unloadSound();
    audio10_Greek.unloadSound();
    audio11_German.unloadSound();
    audio12_Japanese.unloadSound();
    audio13_Portuguese.unloadSound();
    audio14_Persian.unloadSound();
    audio15_Vietnamese.unloadSound();
    audio16_Thai.unloadSound();
}

//--------------------------------------------------------------
void nycApp::touchDown(ofTouchEventArgs &touch){
    if( touch.id != 0 ){
        return;
    }
    
    //activate shader's brush
    bBrushDown = true;
}

//--------------------------------------------------------------
void nycApp::touchMoved(ofTouchEventArgs &touch){
    
}

//--------------------------------------------------------------
void nycApp::touchUp(ofTouchEventArgs &touch){
    bBrushDown = false;
}

//--------------------------------------------------------------
void nycApp::touchDoubleTap(ofTouchEventArgs &touch){
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    //increment to the next Language/Colors
    if(++lang > langTotal - 1){
        lang = 0;
    }
    changeLangColors(lang);
    
    //increment to the next brush flag (loading different shader source)
    if(++brushIndex > brushIndexTotal - 1){
        brushIndex = 0;
    }
    
    //increment to the next Audio files
    if(++audioIndex > audioIndexTotal - 1){
        audioIndex = 0;
    }
    //if it's the 1st index, make the last song stop playing too
    if (audioIndex == 0) {
        allAudio[audioIndex].play();
        allAudio[audioIndexTotal-1].stop();
    }
    //play the current index, stop the previous index
    if(audioIndex > 0 && audioIndex < audioIndexTotal) {
        allAudio[audioIndex].play();
        allAudio[audioIndex-1].stop();
    }
    
    cout << brushIndex << endl;
}

//--------------------------------------------------------------
void nycApp::lostFocus(){
    
}

//--------------------------------------------------------------
void nycApp::gotFocus(){
    
}

//--------------------------------------------------------------
void nycApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void nycApp::deviceOrientationChanged(int newOrientation){
    
}


//--------------------------------------------------------------
void nycApp::touchCancelled(ofTouchEventArgs& args){
    
}


//switch between different colors visual
void nycApp::changeLangColors(int lang) {
    
    switch (lang) {
            //all languages played together + all flag colors shown
        case 0:
            colors.push_back(black);
            colors.push_back(white);
            colors.push_back(red_186C);
            colors.push_back(red_200C);
            colors.push_back(red_206C);
            colors.push_back(red_199C);
            colors.push_back(green_348C);
            colors.push_back(green_350C);
            colors.push_back(green_361C);
            colors.push_back(green_7728C);
            colors.push_back(green_7731C);
            colors.push_back(green_7739C);
            colors.push_back(blue_285C);
            colors.push_back(blue_286C);
            colors.push_back(blue_534C);
            colors.push_back(blue_7683C);
            colors.push_back(blue_2735C);
            colors.push_back(blue_2736C);
            colors.push_back(blue_2756C);
            colors.push_back(blue_2766C);
            colors.push_back(blue_2718C);
            colors.push_back(yellow_107C);
            colors.push_back(yellow_603C);
            colors.push_back(yellow_130C);
            colors.push_back(yellow_165C);
            colors.push_back(yellow_7405C);
            
            ofSetColor(255);
            ofDrawBitmapString("51% of New Yorkers (almost 4 million \npeople) speak only English at home. \nTune in for 50 secs to hear honest \nopinions about New York. Try pointing \nat city's skyline or faces!", 12, height+20);
            
            break;
            
            //Spanish Language: Dominican Rep, Mexico, Ecuador, Colombia, El Salvador
        case 1:
            colors.push_back(red_186C);
            colors.push_back(red_206C);
            colors.push_back(blue_534C);
            colors.push_back(blue_7683C);
            colors.push_back(blue_2736C);
            colors.push_back(blue_2735C);
            colors.push_back(green_7728C);
            colors.push_back(yellow_603C);
            colors.push_back(yellow_130C);
            colors.push_back(yellow_7405C);
            colors.push_back(white);
            
            ofDrawBitmapString("1. SPANISH (24.6% ~ 1,87 million) \nDominican Republic, Mexico, Ecuador, \nColombia, El Salvador", 20, height+20);
            flagSpanish.draw(20, height+60);
            break;
            
            //Chinese Language: China
        case 2:
            colors.push_back(red_186C);
            colors.push_back(yellow_107C);
            
            ofDrawBitmapString("2. CHINESE (5.5% ~ 420K)", 20, height+20);
            flagChinese.draw(20, height+30);
            ofDrawBitmapString("China", 25+flagChinese.getWidth(), height+43);
            ofDrawBitmapString("Also spoken by: Taiwanese, HK", 20, ofGetWindowHeight()-20);
            break;
            
            //Russian Language: Russia
        case 3:
            colors.push_back(white);
            colors.push_back(blue_2736C);
            colors.push_back(red_186C);
            
            ofDrawBitmapString("3. RUSSIAN (2.4% ~ 187K)", 20, height+20);
            flagRussian.draw(20, height+30);
            ofDrawBitmapString("Russia", 25+flagRussian.getWidth(), height+43);
            break;

            //French Language: France, Haiti, Canada
        case 4:
            colors.push_back(white);
            colors.push_back(blue_2735C);
            colors.push_back(red_186C);
            
            ofDrawBitmapString("4. French/French Creole (2.4% ~ 185K)", 20, height+20);
            flagFrench.draw(20, height+30);
            ofDrawBitmapString("Haiti", 25+flagFrench.getWidth(), height+43);
            ofDrawBitmapString("Also spoken by: Canadian, French", 20, ofGetWindowHeight()-20);
            break;
            
            //Other Indic Languages (Hindi, Urdu, Bengali): India, Bangladesh, Pakistan
        case 5:
            colors.push_back(white);
            colors.push_back(yellow_165C);
            colors.push_back(green_7731C);
            colors.push_back(blue_2756C);
            colors.push_back(green_350C);
            colors.push_back(red_186C);
            
            ofDrawBitmapString("5. Indic Languages (Hindi, Urdu, \nBengali) India, Bangladesh, Pakistan \n(1.5% ~ 200K)", 20, height+20);
            flagHindi.draw(20, height+60);
            break;
          
            //Italian: Italy
        case 6:
            colors.push_back(white);
            colors.push_back(green_7731C);
            colors.push_back(red_186C);
            
            ofDrawBitmapString("6. ITALIAN (~94K)", 20, height+20);
            flagItalian.draw(20, height+30);
            ofDrawBitmapString("Italy", 25+flagItalian.getWidth(), height+43);
            break;

            //Korean: Korea
        case 7:
            colors.push_back(white);
            colors.push_back(blue_2736C);
            colors.push_back(red_186C);
            colors.push_back(black);
            
            ofDrawBitmapString("7. KOREAN (~81K)", 20, height+20);
            flagKorean.draw(20, height+30);
            ofDrawBitmapString("Korea", 25+flagKorean.getWidth(), height+43);
            break;
            
            //Arabic: Lebanese, Syrian
        case 8:
            colors.push_back(white);
            colors.push_back(green_348C);
            colors.push_back(red_199C);
            colors.push_back(black);
            
            ofDrawBitmapString("8. ARABIC (~53K) \nLebanon, Syria", 20, height+20);
            flagArabic.draw(20, height+40);
            break;
            
            //Hebrew: Israeli, Jewish American
        case 9:
            colors.push_back(white);
            colors.push_back(blue_286C);
            
            ofDrawBitmapString("9. HEBREW (~47K)", 20, height+20);
            flagHebrew.draw(20, height+30);
            ofDrawBitmapString("Israel", 25+flagHebrew.getWidth(), height+43);
            break;
            
            //Greek: Greece - Mehdi
        case 10:
            colors.push_back(white);
            colors.push_back(blue_285C);
            
            ofDrawBitmapString("10. GREEK (~46K)", 20, height+20);
            flagGreek.draw(20, height+30);
            ofDrawBitmapString("Greece", 25+flagGreek.getWidth(), height+43);
            break;
            
            //German: Germany
        case 11:
            colors.push_back(red_199C);
            colors.push_back(yellow_130C);
            colors.push_back(black);
            
            ofDrawBitmapString("11. GERMAN (~22K)", 20, height+20);
            flagGerman.draw(20, height+30);
            ofDrawBitmapString("Germany", 25+flagGerman.getWidth(), height+43);
            break;
            
            //Japanese: Japan
        case 12:
            colors.push_back(red_199C);
            colors.push_back(white);
            
            ofDrawBitmapString("12. JAPANESE (~22K)", 20, height+20);
            flagJapanese.draw(20, height+30);
            ofDrawBitmapString("Japan", 25+flagJapanese.getWidth(), height+43);
            break;
            
            //Portuguese: Brazil
        case 13:
            colors.push_back(blue_286C);
            colors.push_back(green_348C);
            colors.push_back(yellow_107C);
            
            ofDrawBitmapString("13. PORTUGUESE (~16K)", 20, height+20);
            flagPortuguese.draw(20, height+30);
            ofDrawBitmapString("Brazil", 25+flagPortuguese.getWidth(), height+43);
            break;
            
            //Persian: Iran, Afghanistan
        case 14:
            colors.push_back(red_186C);
            colors.push_back(red_199C);
            colors.push_back(green_348C);
            colors.push_back(white);
            colors.push_back(black);
            
            ofDrawBitmapString("14. PERSIAN (~12K) \nIran, Afghanistan", 20, height+20);
            flagPersian.draw(20, height+40);
            break;
            
            //Vietnamese: Vietnam
        case 15:
            colors.push_back(red_199C);
            colors.push_back(yellow_130C);
            
            ofDrawBitmapString("15. VIETNAMESE (~10K)", 20, height+20);
            flagVietnamese.draw(20, height+30);
            ofDrawBitmapString("Vietnam", 25+flagVietnamese.getWidth(), height+43);
            break;
            
            //Thai: Thailand
        case 16:
            colors.push_back(red_199C);
            colors.push_back(blue_2766C);
            colors.push_back(white);
            
            ofDrawBitmapString("16. THAI (~5K)", 20, height+20);
            flagThai.draw(20, height+30);
            ofDrawBitmapString("Thailand", 25+flagThai.getWidth(), height+43);
            break;
            
        default:
            break;
    }
    
}

void nycApp::interpolateColors() {
    millisNow = ofGetElapsedTimeMillis();
    millisSinceLastCheck = millisNow % timePeriod;
    colorsIndex = (millisNow / timePeriod) % (colors.size());
        
    float p = (float)(millisSinceLastCheck) / (float)(timePeriod);
    
    colorT.r = colors[colorsIndex+1].r * p + ( colors[colorsIndex].r * ( 1.0 - p ) );
    colorT.g = colors[colorsIndex+1].g * p + ( colors[colorsIndex].g * ( 1.0 - p ) );
    colorT.b = colors[colorsIndex+1].b * p + ( colors[colorsIndex].b * ( 1.0 - p ) );
    colorT.normalize();
    
    ofSetColor(colorT);
}

void nycApp::changeCameraMode(int mode) {
    switch (mode) {
        case 0:
            ofSetColor(255);
            vidGrabber.draw(0,0);
            break;
            
        case 1:
            ofSetColor(255, 0, 0);
            colorImg.draw(0,0);
            break;
            
        case 2:
            ofSetColor(255);
            grayImage.draw(0,0);
            break;
            
        case 3:
            ofSetColor(255);
            grayDiff.draw(0,0);
            break;
            
        default:
            break;
    }
}

void nycApp::changeBrush(int brushIndex) {
    switch (brushIndex) {
        case 0:
            brushAll.draw(0,0);
            break;
            
        case 1:
            brushSpanish.draw(0,0);
            break;
            
        case 2:
            brushChinese.draw(0,0);
            break;
            
        case 3:
            brushRussian.draw(0,0);
            break;
            
        case 4:
            brushFrench.draw(0,0);
            break;
            
        case 5:
            brushHindi.draw(0,0);
            break;
            
        case 6:
            brushItalian.draw(0,0);
            break;
        
        case 7:
            brushKorean.draw(0,0);
            break;
            
        case 8:
            brushArabic.draw(0,0);
            break;
            
        case 9:
            brushHebrew.draw(0,0);
            break;
            
        case 10:
            brushGreek.draw(0,0);
            break;
            
        case 11:
            brushGerman.draw(0,0);
            break;
            
        case 12:
            brushJapanese.draw(0,0);
            break;
            
        case 13:
            brushPortuguese.draw(0,0);
            break;
            
        case 14:
            brushPersian.draw(0,0);
            break;
            
        case 15:
            brushVietnamese.draw(0,0);
            break;
            
        case 16:
            brushThai.draw(0,0);
            break;
            
        default:
            break;
    }
}


