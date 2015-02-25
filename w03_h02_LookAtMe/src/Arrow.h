//
//  Arrow.h
//  03_hw_B_LookAtMe
//
//  Created by Umi Syam on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class Arrow : public ofVec2f  {
public:
    void setup(float _x, float _y, int _i, ofColor _color);
//    void update(float _x, float _y);
    void update(ofVec2f _newPos);
    void draw();
    
    ofVec2f pos, newPos;
    float rot;
    ofVec2f size;
    ofColor color;
    
};