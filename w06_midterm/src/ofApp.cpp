//
//  Creative Coding - Animation by Code
//  w06_midterm
//
//  Created by Umi Syam on 3/15/15.
//  Addons: ofxUI, ofxXmlSettings
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowShape(1440, 900);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    ofSetFullscreen(true);
    
    backgroundColor = ofColor(0,55,110);
//    backgroundColor = ofColor(0,0,0);
    fileIndex = 0;
    
    /*------------------VARIABLE SETUP--------------------------*/
    emitter = ofVec2f(ofGetWindowSize()/2);
    emitterRad = 50;
    emitterVel = 50;
    lifeTime = 2.0;
    rotateAngle = 30;
    force = 1000;
    spinning = 1000;
    damping = 0.15;
    
    drawTail = false;
    isResetPos = false;
    drawPadding = false;
    
    initTime = ofGetElapsedTimef();
    
    /*-----------------GUI Setup here----------------------------*/
    gui = new ofxUISuperCanvas("FUNKY PARTICLE");
    
    gui->addTextArea("TEXT AREA", "f: Toggle Fullscreen", OFX_UI_FONT_SMALL);
    gui->addTextArea("TEXT AREA", "g: Hide/show the GUI panel.", OFX_UI_FONT_SMALL);
    gui->addTextArea("TEXT AREA", "1-9: Load Preset", OFX_UI_FONT_SMALL);
    gui->addTextArea("TEXT AREA", "s: Save Preset", OFX_UI_FONT_SMALL);
    gui->addTextArea("TEXT AREA", "<space>: Take Screenshot", OFX_UI_FONT_SMALL);
    
    gui->addSpacer();
    gui->addLabel("BACKGROUND", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addSlider("R", 0, 255, backgroundColor.r);
    gui->addSlider("G", 0, 255, backgroundColor.g);
    gui->addSlider("B", 0, 255, backgroundColor.b);
    gui->addSpacer();
    
    gui->addLabel("PARTICLE CONTROL", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addLabelToggle("DRAW TAIL", drawTail);
    gui->addSpacer();
    gui->addSlider("Emitter Radius", 0, 500, &emitterRad);
    gui->addSlider("Emitter Velocity", 0, 1000, &emitterVel);
    gui->addSlider("LifeTime", 0, 5, &lifeTime);
    gui->addSlider("Rotate Angle", -2000, 2000, &rotateAngle);
    gui->addSlider("Force", -2000, 2000, &force);
    gui->addSlider("Spinning", -2000, 2000, &spinning);
    gui->addSlider("Damping", 0, 1, &damping);
    gui->addSpacer();
    
    gui->addLabel("MOVE IT!", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->add2DPad("POSITION", ofVec2f(0, ofGetWidth()), ofVec2f(0, ofGetHeight()), emitter);
    gui->addSpacer();
    gui->addLabelButton("RESET POSITION", false);
    gui->addSpacer();
    
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Add the particles to the vector storage
    for (int i=0; i<NUM; i++) {
        Particle p;
        p.setup(emitter, emitterRad, emitterVel, lifeTime);
        particle.push_back( p );
    }
    
    //Check if there are inactive/dead particles
    int i=0;
    while (i < particle.size()) {
        if ( !particle[i].isAlive ) {
            particle.erase( particle.begin() + i );
        } else {
            i++;
        }
    }
    
    //Find out the delta
    float currentTime = ofGetElapsedTimef();
    float dt = ofClamp( currentTime - initTime, 0, 0.1 );
    initTime = currentTime;
    
    //Update the particles
    for (int i=0; i<particle.size(); i++) {
        particle[i].resetForce();
        particle[i].update(dt, rotateAngle, emitterRad, force, spinning, damping);
    }
    
    //If the "RESET POSITION" button is clicked, return to the center
    if (isResetPos) {
        emitter.set(ofGetWindowSize()/2);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(backgroundColor);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    for (int i=0; i<particle.size(); i++) {
        particle[i].draw(drawTail);
    }
    
}

//----------------------------------Modified from ofxUI Examples
void ofApp::guiEvent(ofxUIEventArgs &e)
{
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    if(name == "R")
    {
        ofxUISlider *rslider = (ofxUISlider *) e.widget;
        backgroundColor.r = rslider->getScaledValue();
    }
    else if(name == "G")
    {
        ofxUISlider *rslider = (ofxUISlider *) e.widget;
        backgroundColor.g = rslider->getScaledValue();
    }
    else if(name == "B")
    {
        ofxUISlider *rslider = (ofxUISlider *) e.widget;
        backgroundColor.b = rslider->getScaledValue();
    }
    else if(name == "POSITION")
    {
        ofxUI2DPad *pad = (ofxUI2DPad *) e.widget;
        emitter.x = pad->getPercentValue().x*ofGetWidth();
        emitter.y = pad->getPercentValue().y*ofGetHeight();
    }    
    else if(name == "DRAW TAIL")
    {
        ofxUILabelToggle *toggle = (ofxUILabelToggle *) e.widget; 
        drawTail = toggle->getValue();
    }
    else if(name == "RESET POSITION")
    {
        ofxUILabelButton *button = (ofxUILabelButton *) e.widget;
        isResetPos = button->getValue();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'g':
            gui->toggleVisible();
            break;
        
        case 'p':
            drawPadding = !drawPadding;
            gui->setDrawWidgetPadding(drawPadding);
//            gui->setDrawPadding(drawPadding);
//            gui->setDrawWidgetPaddingOutline(drawPadding);
            break;
        
        case '0':
            gui->loadSettings("particle-preset0.xml");
            break;
            
        case '1':
            gui->loadSettings("particle-preset1.xml");
            break;
        
        case '2':
            gui->loadSettings("particle-preset2.xml");
            break;
        
        case '3':
            gui->loadSettings("particle-preset3.xml");
            break;
        
        case '4':
            gui->loadSettings("particle-preset4.xml");
            break;
        
        case '5':
            gui->loadSettings("particle-preset5.xml");
            break;
        
        case '6':
            gui->loadSettings("particle-preset6.xml");
            break;
            
        case '7':
            gui->loadSettings("particle-preset7.xml");
            break;
            
        case '8':
            gui->loadSettings("particle-preset8.xml");
            break;
            
        case '9':
            gui->loadSettings("particle-preset9.xml");
            break;
            
        case 's':
        {
            //save to file - if you press 's' a couple of times it will increment the fileIndex resulting in multiple files
            string xmlFile = "particle-preset" + ofToString(fileIndex) + ".xml";
            gui->saveSettings(xmlFile);
            fileIndex++;
            break;
        }
        case ' ':
        {
            ofImage screenshot;
            screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            //rename it according to the current timestamp
            string filename = "scrshot-" + ofGetTimestampString() + ".png";
            screenshot.saveImage(filename);
            break;
        }

        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
