//
//  customCircle.h
//  01_hw_B_interpolationProperties
//
//  Created by Umi Syam on 2/6/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup();
    void update(float _pct, float _circleSize);
    void draw();
    
    void setPointA (float _x, float _y);
    void setPointB (float _x, float _y);
    
    
private:
    ofVec2f pointA, pointB, currentPos;
    float pct;
    float circleSize;
};