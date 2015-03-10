#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    //    mover.setup(50, 500);
    
    for (int i=0; i<NUM; i++) {
        Mover mover;
        float x = ofRandomWidth();
        float y= ofRandomHeight();
        mover.setup(x, y);
        moverList.push_back(mover);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i=0; i<moverList.size(); i++) {
        ofVec2f diff = mousePos - moverList[i].pos;
        //        attraction.set(diff * 0.01);
        
        attraction.set(diff.getNormalized() * 0.2);
        repulsion.set(attraction *-1);
        
        moverList[i].resetForces();
        
        if(diff.length() < 100) {
            moverList[i].applyForce(repulsion);
            
        } else if (diff.length() <250) {
            moverList[i].applyForce(attraction);
        }
        moverList[i].applyDampingForce(0.001);
        moverList[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<moverList.size(); i++) {

        //make it rainbow color!
//        ofColor moverColor;
//        moverColor.setHsb(i*255/ofGetWidth(), 255, 255);
//        ofSetColor(moverColor, 255);
        
        moverList[i].draw();
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
