//
//  Punk.h
//  02_hw_C_PunkGaussianPopulation
//
//  Created by Umi Syam on 2/16/15.
//
//

#pragma once
#include "ofMain.h"

class Punk {
public:
    Punk();
    
    void setup();
    void update();
    void draw(float _x, float _y, float _size);
    
    ofPoint pos;
    
    int r, g, b;
    float size;
    
};