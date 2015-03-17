//
//  Particle.cpp
//  w06_midterm
//
//  Created by Umi Syam on 3/15/15.
//
//

#include "Particle.h"

Particle::Particle() {
    //by default the particle is dead
    isAlive = false;
}

void Particle::setup(ofVec2f _emitter, float _emitterRad, float _emitterVel, float _lifeTime) {
    
    //always starts from the center; the added random value makes it more 'funky'
    pos.set(_emitter + randomizeParticle(_emitterRad));
    vel = randomizeParticle(_emitterVel);
    time = 0;
    lifeTime = _lifeTime;
    isAlive = true;
    color.setHsb(ofRandom(0,255), 255, 255);
}

void Particle::resetForce() {
    acc *= 0;
}

ofVec2f Particle::randomizeParticle(float _nParticle) {
    ofVec2f particle;
    float n = ofRandom(0, _nParticle);
    float angle = ofRandom(0, TWO_PI);
    particle.x = cos(angle) * n;
    particle.y = sin(angle) * n;
    
    return particle;
}

void Particle::update(float dt, float _rotateAngle, float _emitterRad, float _force, float _spinning, float _damping) {
    
    if (isAlive) {
        
        //pass value from "Rotate Angle" slider
        vel.rotate(dt * _rotateAngle);
        
        //compute & normalize to make movement smoother
        //pass value from "Force", "Spinning", "Damping" sliders in the GUI
        ofVec2f diff = pos - ofGetWindowSize()/2;
        if (ofInRange(diff.length(), 0, _emitterRad)) {
            diff.normalize();
            acc += diff * _force;
            acc.x += -diff.y * _spinning;
            acc.y += diff.x * _spinning;
        }
        
        vel += acc * dt;
        vel *= (1 - _damping);
        
        pos += vel * dt;
        time += dt;
        
        //draw the tail
        tail.push_back(pos);
        if(tail.size() > 100){
            tail.erase(tail.begin());
        }
        
        //stop the particle from updating
        if (time >= lifeTime) {
            isAlive = false;
        }
    }
}

void Particle::draw(bool _drawTail) {
    if (isAlive) {
        float colorMap = ofMap( time, 0, lifeTime, 0, 255 );
//        try these:
//        color.setBrightness(hue);
//        color.setHue( hue );
        color.setSaturation(colorMap);
        ofSetColor( color );
        
        float size = ofMap(fabs(time - lifeTime/2), 0, lifeTime/2, 5, 1 );
        
        ofNoFill();
        ofSetColor(color);
        ofSetLineWidth(size);
        
        //passing the bool value from the GUI Toggle Button's state
        if (_drawTail) {
            ofBeginShape();
            for(ofPoint firetail : tail){
                ofVertex(firetail);
            }
            ofEndShape(false);
        }
        
        //finally draw the particle
        ofCircle(pos, size);
    }
    
    
}