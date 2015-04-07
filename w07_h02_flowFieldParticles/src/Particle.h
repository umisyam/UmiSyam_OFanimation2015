//
//  Particle.h
//  19_particles
//
//  Created by Umi Syam on 3/3/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    void setup();
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
};