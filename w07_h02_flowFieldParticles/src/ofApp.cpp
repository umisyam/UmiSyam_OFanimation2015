#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
//    ofSetBackgroundAuto(false);
//    ofSetFullscreen(true);
    
    isDrawFF = true;
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    flowField.setRandom(2.0);
    flowField.setNoise();
    
    for (int i = 0; i<1000; i++) {
        Particle p;
        p.setup();
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i<particles.size(); i++) {
        particles[i].resetForces();
        
        ofVec2f frc;
        frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.040);
        particles[i].update();
    }
    
    flowField.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(10, 90, 70);
    color2.set(50, 150, 90);
    ofBackgroundGradient(color2, color1, OF_GRADIENT_LINEAR);
    
    ofSetColor(255);
    ofDrawBitmapString("Press <spacebar> to show/hide FlowField", 30,35);
    
    if (isDrawFF) {
        flowField.draw();
    }
    
    for (int i = 0; i<particles.size(); i++) {
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        isDrawFF = !isDrawFF;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofVec2f dir = ofVec2f(x, y) - ofVec2f(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    flowField.setDirection(dir);
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
