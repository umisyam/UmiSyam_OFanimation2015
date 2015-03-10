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
}

void Mover::update() {
    vel += acc;
    pos += vel;
    
//    check the edges
//        if (pos.x < 0) {
//            pos.x = 0;
//            vel.x *= -1;
//        }
//        if (pos.x > ofGetWidth()) {
//            pos.x = ofGetWidth();
//            vel.x *= -1;
//        }
//        if (pos.y < 0) {
//            pos.y = 0;
//            vel.y *= -1;
//        }
//        if (pos.y > ofGetHeight()) {
//            pos.y = ofGetHeight();
//            vel.y *= -1;
//        }
}

void Mover::draw() {
    bee.draw(pos);
}

