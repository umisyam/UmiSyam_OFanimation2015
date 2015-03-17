//
//  Particle.h
//  w06_midterm
//
//  Created by Umi Syam on 3/15/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle();
    void setup(ofVec2f _emitter, float _emitterRad, float emitterVel, float _lifeTime);
    void update(float dt, float _rotateAngle, float _emitterRad, float _force, float _spinning, float _damping);
    void draw(bool _drawTail);
    
    void resetForce();
    ofVec2f randomizeParticle(float _nParticle);
    
    ofVec2f pos, vel, acc;
    float time;
    float lifeTime;
    bool isAlive;
    
    ofColor color;
    vector<ofVec2f> tail;
    
};