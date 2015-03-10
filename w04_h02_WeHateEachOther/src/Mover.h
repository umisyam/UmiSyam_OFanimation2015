//
//  Mover.h
//  w04_h02_WeHateEachOther
//
//  Created by Umi Syam on 3/8/15.
//
//


#pragma once
#include "ofMain.h"

class Mover {
public:
    void setup(float x, float y);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
    ofImage bee;
};