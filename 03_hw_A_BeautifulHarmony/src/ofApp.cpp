#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    startAngle = 0;
//    angleVelocity = 0.15;
    angleVelocity = 0.6;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    startAngle += 0.005;
    angle = startAngle; 
    
    if (angle > 10) {
        startAngle = 0;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(100, 0, 255);
    color2.set(0, 0, 100);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
    ofSetColor(255);
    ofDrawBitmapString("Press spacebar for surprises!\nUmi Syam - Animation By Code HW Week 3", 20, 20);
    
    for (int x = 0; x < ofGetWidth(); x +=2) {
        //trying out from desmos graph calculator
        sinOfTime = sin(sin(sin (angle) * sin(angle * 20) * sin(angle / 20)));
        float y = ofMap(sinOfTime,-1,1,0,ofGetHeight());
        
        //make it rainbow color!
        ofColor rectColor;
        rectColor.setHsb(x*255/ofGetWidth(), y*255/ofGetHeight(), 255);
        ofSetColor(rectColor, 100);
        
//        ofSetColor(255, 255, 255, 100);
        ofCircle(x+10,y,10);
        angle -= angleVelocity;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        angleVelocity = ofRandom(0.14, 0.16);
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
