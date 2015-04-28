//
//  Particle.cpp
//  19_particles
//
//  Created by Umi Syam on 3/3/15.
//  modified from w07_h02_flowFieldParticles
//

#include "Particle.h"

void Particle::setup(flowField flowf) {
    pos.x = ofRandom(flowf.width);
    pos.y = ofRandom(flowf.height);
    pos.z = ofRandom(flowf.depth);
    
//    vel.set(0.0, 0.0, 0.0);
    acc.set(0.0, 0.0, 0.0);
    
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-1,-5);
    vel.z = ofRandom(-3,3);
    
    mass = 1.5;
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec3f force) {
    acc += (force / mass);
}
void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    vel *= 0.97;
    resetForces();

    // check edges of the flowfield
    if (pos.x > ofGetWidth()) pos.x = 0;
    if (pos.y > ofGetHeight()) pos.y = 0;
    if (pos.z > 500) pos.z = 0;
    
    if (pos.x < 0) pos.x = ofGetWidth();
    if (pos.y < 0) pos.y = ofGetHeight();
    if (pos.z < 0) pos.z = 500;
}

void Particle::draw() {
    float alpha = ofMap(vel.length(), 0, 5, 30, 100);
    ofColor color;
    color.setHsb(255,255,ofRandom(0,30), alpha);
    
    float radius = ofMap(vel.length(), 0, 5, 1, 4);
    
    ofSetColor(color);
    ofSetLineWidth(1.f);
    ofNoFill();
    ofCircle(pos, radius);
}

