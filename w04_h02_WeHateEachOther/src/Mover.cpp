//
//  Mover.cpp
//  w04_h02_WeHateEachOther
//
//  Created by Umi Syam on 3/8/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y) {
    
    pos.set(x,y);
    bee.loadImage("bee.png");
}

void Mover::resetForces() {
    acc *= 0;
}

void Mover::applyForce(ofVec2f force) {
    acc += force;
}

void Mover::applyDampingForce(float damping) {
    ofVec2f dampingForce;
    dampingForce = vel.getNormalized() * damping * -1;
    
    acc += dampingForce;
    //takes vector which has magnitude & make the magnitude 1
}

void Mover::update() {
    vel += acc;
    pos += vel;
    
    //check the edges
    //    if (pos.x < 0) {
    //        pos.x = 0;
    //        vel.x *= -1;
    //    }
    //    if (pos.x > ofGetWidth()) {
    //        pos.x = ofGetWidth();
    //        vel.x *= -1;
    //    }
    //    if (pos.y < 0) {
    //        pos.y = 0;
    //        vel.y *= -1;
    //    }
    //    if (pos.y > ofGetHeight()) {
    //        pos.y = ofGetHeight();
    //        vel.y *= -1;
    //    }
}

void Mover::draw() {
    bee.draw(pos);
    
//    ofSetColor(0);
//    ofSetLineWidth(1);
//    
//    ofSetColor(ofColor::yellow);
//    ofCircle(pos.x, pos.y -11, 5);
//    
//    ofSetColor(ofColor::gold);
//    ofEllipse(pos, ofRandom(5,10), 20);
//    
////    ofTranslate(pos.x-1, pos.y-1);
//    ofEllipse(pos.x-3, pos.y-2, ofRandom(5,10), 15);
//    
//    ofSetColor(0);
//    ofRect(pos, 7, 5);
    
    
//    ofRect(pos, ofRandom(5,15), ofRandom(5,15));
}

