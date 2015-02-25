#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::orangeRed);
    
    crcle.setup();
    pct = 0.0;
    mouseToggle = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    pct += 0.01;
    
    if (pct > 1) {
        pct = 0.0;
    }
    crcle.update(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
    crcle.draw();
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
    if(mouseToggle){
        crcle.setPointA(x, y);
        mouseToggle = 0;
    }else{
        crcle.setPointB(x, y);
        mouseToggle = 1;
    }
    
    pct = 0.0;
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
