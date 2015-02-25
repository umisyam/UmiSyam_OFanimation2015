#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(12);
    
//    myPunk.setup();
    for (int i=0; i < NUMPUNK ; i++) {
        punks[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float num = ofxGaussian();
    float sd = 120;
    float mean = ofGetWidth() / 2;
    x = (sd * num) + mean;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    myPunk.draw(x, ofGetHeight()/2, 30);
    for (int i=0; i < NUMPUNK ; i++) {
        punks[i].draw(x,ofRandom(250, 500), 30);
    }
}

//code for ofxGaussian taken from: https://github.com/andyr0id/ofxGaussian

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofApp::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
