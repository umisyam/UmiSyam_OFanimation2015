#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    ofBackground(0);
    
    gravity.set(0.0, 0.4);
    //    for (int i=0; i<10; i++) {
    //        Particle particle(ofGetWindowSize()/2);
    //        particleList.push_back(particle);
    //    }
    
    //Create the stars in the black sky
    for (int i=0; i<400; i++) {
        star.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        ofSetColor(255, ofRandom(100,255));
        stars.push_back(star);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].applyForce(gravity);
        particleList[i].update();
    }
    
    while (particleList.size() > 20) {
        particleList.erase(particleList.begin());
    }
    
    //create new particles
    if(ofGetFrameNum() % 3 == 0){
        ofVec2f pos;
        pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        Particle myParticle(pos);
        particleList.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("SPACE TRAFFIC! overcrowded spaceships", 20, 20);
    //draw stars
    for (int i=0; i<stars.size(); i++) {
        ofSetColor(255, ofRandom(20,200));
        ofCircle(stars[i].x, stars[i].y, 0.5);
    }
    
    //draw spaceships
    for (int i=0; i<particleList.size(); i++) {
        particleList[i].draw();
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
