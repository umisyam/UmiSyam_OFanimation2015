#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(60);
//    ofSetBackgroundAuto(false);
    startAngle = 0;
    angleVelocity = 0.05;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    startAngle += .1f;
    angle = startAngle;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(0, 100, 200);
    color2.set(0, 20, 100);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
    //making the tornado
    for (int i = 1; i<150; i++) {
        
        float time = ofGetElapsedTimeMillis() * 0.0005;
        float sinOfTime = sin(sin(sin (time) * sin(time * i) * sin(time / i)));
        
        float y = i*5;
        float x = ofGetWidth()/2 + (sinOfTime * 500);
        
        ofSetColor(ofRandom(0,255),ofRandom(200,255),255,255);
        //        ofCircle(x, y, 3);
        //        ofRect(x, y, 7,7);
        ofTriangle(x,y-10, x+6,y, x-6, y);
    }
    
    
    float sinOfTime1 = sin(ofGetElapsedTimef() + 10);
    float radius = ofMap(sinOfTime1, -1, 1, 200, 230);
    
    //fish body
    ofSetColor(ofColor::blueViolet);
    ofEllipse(ofGetWidth()/2 + 120, ofGetHeight()-100, radius*2, radius);

    //fish tail
    ofBeginShape(); {
        ofVertex(900, 550);
        ofVertex(700, 670);
        ofVertex(900, 768);
    }ofEndShape(true);
    
    //fish eye
    ofSetColor(255);
    ofCircle(ofGetWidth()/2 +5, ofGetHeight()-150, radius/15);
    
    
    //draw the ocean wave
    for (int x = 0; x <= ofGetWidth(); x +=2) {
        float y = ofMap(sin(angle),-1,1,450,500);
        
        ofSetColor(0, ofRandom(100,255), 255, 100);
        ofCircle(x,y,15);
        angle += angleVelocity;
        
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
