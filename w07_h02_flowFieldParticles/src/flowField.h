//
//  flowField.h
//  23_flowField
//
//  Created by Umi Syam on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class flowField {
public:
    flowField();
    
    void setup(float w, float h, float res);
    void update();
    void draw();
    
    void setRandom(float scale);
    void setNoise();
    ofVec2f getForceAt(float x, float y);
    void setDirection(ofVec2f dir);
    
    vector<ofVec2f> field;
    int width;
    int height;
    
    int internalWidth;
    int internalHeight;
    
    float resolution;
    int fieldSize;
};