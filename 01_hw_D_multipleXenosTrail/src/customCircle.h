//
//  customCircle.h
//  01_hw_D_multipleXenosTrail
//
//  Created by Umi Syam on 2/10/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    void setup(ofVec2f _pos, int _i, ofColor _color);
    void update(int _mouseX, int _mouseY);
    void draw();
    
private:
    ofVec2f pos, dir, finalPos;
    float speed;
    ofColor color;
};