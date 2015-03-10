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
    color.setHsb(ofRandom(0, 255), 255, 255);
    
    angle = ofRandom(30);
    spaceship.loadImage("shuttle.png");
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::update() {
    angle += 0.0005;
    vel += acc;
    pos += vel;
    
    resetForces();

    
    sinOfTime = sin(sin(sin (angle) * sin(angle * 20) * sin(angle / 20)));
//    float y = ofMap(sinOfTime,-1,1,0,pos.y + ofRandom(ofGetHeight()));
    float y = ofMap(sinOfTime,-1,1,0, ofGetHeight());
    float x = pos.x + angle * sin(TWO_PI * ofGetFrameNum()/30);
    
    pos.x = x;
    pos.y = y;
    
    color.a = lifespan;
    if (lifespan > 0) lifespan -= 5.0;
    
    tail.push_back(pos);
    if(tail.size() > 50){
        tail.erase(tail.begin());
    }
}

void Particle::draw() {
    ofNoFill();
    ofSetColor(color);
    ofSetLineWidth(20);
    ofBeginShape();
    for(ofPoint firetail : tail){
        ofVertex(firetail);
    }
    ofEndShape(false);
    
    spaceship.draw(pos.x-26, pos.y-57);
    
//    ofFill();
//    ofSetColor(color);
//    ofCircle(pos, 8);
}

