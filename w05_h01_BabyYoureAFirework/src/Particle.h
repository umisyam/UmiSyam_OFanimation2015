//
//  Particle.h
//  w05_h01_BabyYoureAFirework
//
//  Created by Umi Syam on 3/10/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle(ofVec2f pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float lifespan;
    
    ofColor color;
    vector<ofVec2f> tail;
};