#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    w = ofGetWidth();
    h = ofGetHeight();
    res = 10;
    vid.initGrabber(w,h,true);
    
    flowField.setup(w, h, res);
    flowField.setNoise();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    vid.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    flowField.draw();
    
    for (int y=0; y<h; y+=res) {
        for (int x=0; x<w; x+=res) {
            
            //get pixel color from video
            int i = (w*y+x)*3;
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+2];
            int b = vid.getPixels()[i+4];
            
            float brightness = (r+g+b) / 255.0 / 2;
            ofSetColor(ofColor::fromHsb(brightness * 255,255,255));
            
            //sine and cosine of brightness
            float cosB = cos(brightness*TWO_PI);
            float sinB = sin(brightness*TWO_PI);
            
            //draw rotated line based on brightness
            ofLine(x-5*cosB, y-5*sinB, x+5*cosB, y+5*sinB);
            ofCircle(x*sinB, y*cosB, 2);
            
        }
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
