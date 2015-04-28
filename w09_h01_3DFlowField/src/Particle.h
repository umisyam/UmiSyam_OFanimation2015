//
//  Particle.h
//  19_particles
//
//  Created by Umi Syam on 3/3/15.
//  modified from w07_h02_flowFieldParticles
//

#pragma once
#include "ofMain.h"
#include "flowField.h"

class Particle {
public:
    void setup(flowField flowf);
    void resetForces();
    void applyForce(ofVec3f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    //using ofVec3f instead of ofVec2f because we're making 3D flowfield
    ofVec3f pos, vel, acc;
    float mass;
};