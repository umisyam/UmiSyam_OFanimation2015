#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
//    ofSetFullscreen(true);
    
    isDrawFF = true;
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 300, 30);
    flowField.setRandom(5.0);
    flowField.setNoise();
    
    particles.clear();
    
    for (int i = 0; i<50000; i++) {
        Particle p;
        p.setup(flowField);
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i<particles.size(); i++) {
        particles[i].resetForces();
        
        ofVec3f frc;
        frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z);
        particles[i].applyForce(frc * 0.008);
        particles[i].applyDampingForce(0.008);
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofColor color1, color2;
//    color1.set(10, 90, 70);
//    color2.set(50, 150, 90);
//    ofBackgroundGradient(color2, color1, OF_GRADIENT_LINEAR);
    
    ofSetColor(0);
    ofDrawBitmapString("Press <spacebar> to show/hide FlowField", ofGetWidth()-350,35);
    
    if (isDrawFF) {
        flowField.draw();
    }
    
    cam.begin();
    
    ofPushMatrix(); {
        ofTranslate(flowField.width/2*-1, flowField.height/2*-1, flowField.depth/2*-1);
        for (int i = 0; i<particles.size(); i++) {
            particles[i].draw();
        }
    } ofPopMatrix();
    
    cam.end();
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
