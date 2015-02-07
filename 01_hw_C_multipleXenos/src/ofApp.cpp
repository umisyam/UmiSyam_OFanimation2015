#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    for (int i=0; i<NUMCIRCLE; i++) {
        xenos.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
        color.setHsb(ofRandom(100,255), 255, 255);
        crcle[i].setup(xenos, i, color);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<NUMCIRCLE; i++) {
        crcle[i].update(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<NUMCIRCLE; i++) {
        crcle[i].draw();
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
