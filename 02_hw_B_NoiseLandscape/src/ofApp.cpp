#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    w = 600;
    h = 600;
    img.allocate(w,h,OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int y = 0; y < w; y++) {
        for (int x = 0; x < h; x++) {
            
            float a = x * .009;
            float b = y * .008;
            float c = ofGetFrameNum() / 50.0;
            
            float noise = ofNoise(a,b,c) * 255;
            float color;
            
            if (noise > 200) {
                color = ofMap(noise, 200, 255, 0, 255);
            } else {
                color = ofMap(noise,0,200,100,255);
            }
            
            img.getPixels()[y * w + x] = color;
        }
    }
    
    img.reloadTexture();
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0);
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
