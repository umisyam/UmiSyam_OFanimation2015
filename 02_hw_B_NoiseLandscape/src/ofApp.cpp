#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    yOffset = 10000.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //ofGetElapsedTimef gets the current time since we run the program
    float noiseX = ofNoise(ofGetElapsedTimef());
    float noiseY = ofNoise(ofGetElapsedTimef() + yOffset);
    
    pos.x = ofMap(noiseX, 0,1,0,ofGetWidth());
    pos.y = ofMap(noiseY, 0,1,0,ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(pos, 20);
    
    //you're on your way to win the Oscar!! yay perlin noise
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
