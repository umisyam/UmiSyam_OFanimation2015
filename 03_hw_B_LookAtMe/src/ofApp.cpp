#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    ofSetBackgroundAuto(false);
//    myArrow.setup();

    ofSetVerticalSync(true);
    for(int i = 0; i < NUMARROW; i++){
        ofVec2f initPos;
//        initPos.set(ofGetWidth()/4, ofGetHeight()/4);
        initPos.set(10,10);
        ofColor color;
        color.setHsb(70 + (float)i/NUMARROW * 100, 255, 255);
        myArrow[i].setup(initPos.x, initPos.y, i, color);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
//    myArrow.update(ofGetMouseX(), ofGetMouseY());
    ofVec2f mouse;
    mouse.set(ofGetMouseX(), ofGetMouseY());
    
    for(int i = 0; i < NUMARROW; i++){
        if(i > 0){
            myArrow[i].update(myArrow[i-1]);
        }else{
            myArrow[i].update(mouse);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    myArrow.draw();
    for(int i = 0; i < NUMARROW; i++){
        myArrow[i].draw();
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
