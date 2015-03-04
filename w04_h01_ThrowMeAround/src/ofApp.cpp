#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::tomato);
//    mover.setup(ofGetMouseX(),ofGetMouseY(), 2.0);
//    vthrow.set(ofGetWindowSize()/2);
    gravity.set(0, 0.5);
    isThrow = 0;
    wind.set(0.1, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<moverList.size(); i++) {
        moverList[i].resetForces();
        moverList[i].applyForce(gravity + vthrow);
        moverList[i].update();
    }
    while (moverList.size() > 30) {
        moverList.erase(moverList.begin());
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(ofColor::yellow, 150);
    for (int i=0; i<moverList.size(); i++) {
        moverList[i].draw();
//        ofLine(moverList[i].pos, vthrow);
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
    for (int i=0; i<NUM; i++) {
        Mover mover;
        mover.setup(x,y, ofRandom(1,5));
        moverList.push_back(mover);
    }
//    vthrow.x = ofGetPreviousMouseX() - ofGetMouseX();
//    vthrow.y = ofGetPreviousMouseY() - ofGetMouseY();
    vthrow.set(ofGetPreviousMouseX() - x, ofGetPreviousMouseY() - y);
    
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
