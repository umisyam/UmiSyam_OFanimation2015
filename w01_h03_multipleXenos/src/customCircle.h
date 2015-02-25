//
//  customCircle.h
//  01_hw_C_multipleXenos
//
//  Created by Umi Syam on 2/6/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    void setup(ofVec2f _pos, int _i, ofColor _color);
    void update(int _mouseX, int _mouseY);
    void draw();
    
    ofVec2f pos, dir, finalPos;
    float speed;
    ofColor color;
};