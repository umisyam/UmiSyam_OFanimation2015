//
//  Mover.cpp
//  w04_h01_ThrowMeAround
//
//  Created by Umi Syam on 3/2/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y, float _mass) {
    pos.set(x,y);
    mass = _mass;
}

void Mover::update() {
    vel += acc;
    pos += vel;
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Mover::resetForces() {
    acc *= 0;
}

void Mover::applyForce(ofVec2f force) {
    acc += force / mass;
}

void Mover::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
    //takes vector which has magnitude & make the magnitude 1
}

void Mover::draw() {
    
    ofCircle(pos, 10*mass);
}



