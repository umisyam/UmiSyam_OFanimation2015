//
//  Particle.cpp
//  w05_h01_BabyYoureAFirework
//
//  Created by Umi Syam on 3/10/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos) {
    pos.set(_pos);
    vel.x = ofRandom(ofRandom(-12,-7),ofRandom(7,12));
    vel.y = ofRandom(-10,3);
    lifespan = 255.0;
    color.setHsb(ofRandom(10, 40), 255, 255);
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    color.a = lifespan;
    if (lifespan > 0) lifespan -= 5.0;
    
    tail.push_back(pos);
    if(tail.size() > 20){
        tail.erase(tail.begin());
    }
}

void Particle::draw() {
    ofNoFill();
    ofSetColor(color);
    ofSetLineWidth(15);
    ofBeginShape();
    for(ofPoint firetail : tail){
        ofVertex(firetail);
    }
    ofEndShape(false);
    
    ofFill();
    ofSetColor(color);
    ofCircle(pos, 8);
}

