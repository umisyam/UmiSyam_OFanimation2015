#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::salmon);
//    ofSetBackgroundAuto(false);
//    myArrow.setup();
    ofSetVerticalSync(true);
    for(int i = 0; i < NUMARROW; i++){
        ofVec2f initPos;
        //        initPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        initPos.set(ofGetWidth()/2, ofGetHeight()/2);
        ofColor color;
        color.setHsb(200 + (float)i/NUMARROW * 50, 255, 255);
        myArrow[i].setup(initPos.x, initPos.y, i, color);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
//    myArrow.update(ofGetMouseX(), ofGetMouseY());
    ofVec2f mouse;
    mouse.set(mouseX, mouseY);
    
    for(int i = 0; i < NUMARROW; i++){
        if(i > 0){
            myArrow[i].update(myArrow[i-1]);
        }else{
            myArrow[i].update(mouse);
        }
    }
    //    atan is short for arc tangent
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
