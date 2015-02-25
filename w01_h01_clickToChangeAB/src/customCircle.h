//
//  customCircle.h
//  01_hw_A_clickToChangeAB
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
    void update(float _pct);
    void draw();
    
    void setPointA (float _x, float _y);
    void setPointB (float _x, float _y);
    
    
private:
    ofVec2f pointA, pointB, currentPos;
    float pct;
};