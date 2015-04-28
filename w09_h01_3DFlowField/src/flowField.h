//
//  flowField.h
//  23_flowField
//
//  Created by Umi Syam on 3/31/15.
//  modified from w07_h02_flowFieldParticles
//

#pragma once
#include "ofMain.h"

class flowField {
public:
    flowField();
    
    void setup(int w, int h, int dep, int res);
//    void update();
    void draw();
    
    void setRandom(float scale);
    void setNoise();
    ofVec3f getForceAt(float x, float y, float z);
    
//    vector<ofVec2f> field;
    vector<vector<vector<ofVec3f> > >  field;
    int width, height, depth;
    int resolution;
    
    int fieldX, fieldY, fieldZ;
    
    int fieldSize;
};