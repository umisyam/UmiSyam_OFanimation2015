//
//  customCircle.cpp
//  01_hw_D_multipleXenosTrail
//
//  Created by Umi Syam on 2/10/15.
//
//

#include "customCircle.h"


void customCircle::setup(ofVec2f _pos, int _i, ofColor _color){
    pos = _pos;
    speed = 0.1 + 0.05 * _i;
    color = _color;
}

void customCircle::update(int _mouseX, int _mouseY){
    finalPos.set(_mouseX, _mouseY);
    dir = finalPos - pos;
    pos += dir * speed;
    //    pos =  pos*0.95 + finalPos*0.05;
}

void customCircle::draw() {
    ofSetColor(color);
    ofCircle(pos, 20);
}
