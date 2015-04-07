//
//  Particle.cpp
//  19_particles
//
//  Created by Umi Syam on 3/3/15.
//
//

#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
//    vel.set(0.0, 0.0);
    acc.set(0.0, 0.0);
    
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-1,-5);
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}
void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    

    // check edges
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

void Particle::draw() {
    float alpha = ofMap(vel.length(), 0, 5, 100, 255);
    ofColor color;
    color.setHsb(ofRandom(30,70), 255, 255, alpha);
    
    float radius = ofMap(vel.length(), 0, 5, 2, 5);
    
    ofSetColor(color);
    ofCircle(pos, radius);
}