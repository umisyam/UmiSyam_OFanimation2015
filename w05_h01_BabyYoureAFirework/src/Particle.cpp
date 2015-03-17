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
    vel.x = ofRandom(ofRandom(-17,-10),ofRandom(10,17));
    vel.y = ofRandom(-15,0);
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
    if(tail.size() > 100){
        tail.erase(tail.begin());
    }
}

void Particle::draw() {
    ofNoFill();
    ofSetColor(color);
    ofSetLineWidth(15);
    
    ofBeginShape();
//    for (int x = 0; x<tail.size(); x++) {
//        for (int y=0; y<tail.size(); y++) {
//            ofVertex(x, y);
//        }
//    }
    for(ofPoint firetail : tail){
        ofVertex(firetail);
    }
    ofEndShape(false);
    
    ofFill();
    ofSetColor(color);
    ofCircle(pos, 8);
}

