//
//  customCircle.cpp
//  01_hw_C_multipleXenos
//
//  Created by Umi Syam on 2/6/15.
//
//

#include "customCircle.h"


void customCircle::setup(ofVec2f _pos, int _i, ofColor _color){
    pos = _pos;
    speed = 0.1 + 0.05 * _i;
    color = _color;
}

void customCircle::update(int _mouseX, int _mouseY){
    ofVec2f _finalPos;
    _finalPos.set(_mouseX, _mouseY);
    dir = _finalPos - pos;
    //    dir.normalize();
    //    pos += dir * 4;
    pos += dir * speed;
//    pos =  pos*0.95 + _finalPos*0.05;
}

void customCircle::draw() {
    ofSetColor(color);
    ofCircle(pos, 20);
}
