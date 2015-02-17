#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(50);
    ofSetVerticalSync(true);
    
    num = 0;
    
    gui.setup();
    gui.add(filled.setup("Fill Shape", true));
    gui.add(reset.setup("Reset Canvas"));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawBitmapString("Press spacebar to randomize shape", 10, 90);
    
    if(filled){
        ofFill();
    }else{
        ofNoFill();
    }
    
    if (reset) {
        //what is the code to empty canvas?

    }
    
    gui.draw();
    ofSetBackgroundAuto(false);
    switch (num) {
        case 0:
            ofSetColor(ofColor::red);
            ofCircle(mouseX, mouseY, 20);
            break;
        case 1:
            ofSetColor(ofColor::green);
            ofRect(mouseX, mouseY, 10, 10);
            break;
        case 2:
            ofSetColor(ofColor::blue);
            ofTriangle(mouseX, mouseY, mouseX+30, mouseY, mouseX+15, mouseY-30);
            break;
        case 3:
            ofSetColor(ofColor::yellow);
            ofSetCircleResolution(5);
            ofCircle(mouseX, mouseY, 15);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        num = ofRandom(4);
    }
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
