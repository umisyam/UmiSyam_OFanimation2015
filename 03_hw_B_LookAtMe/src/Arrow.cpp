//
//  Arrow.cpp
//  03_hw_B_LookAtMe
//
//  Created by Umi Syam on 2/24/15.
//
//

#include "Arrow.h"

void Arrow::setup(float _x, float _y, int _i, ofColor _color) {
//    pos.set(_x, _y);
    set(_x, _y);
    size.set(30, 30);
    color = _color;
}

void Arrow::update(ofVec2f _newPos) {
//    ofVec2f newPos;
//    newPos.set(_x, _y);
//
    newPos = _newPos;
    pos = pos * 0.93 + newPos * 0.07;
//    pos = pos * 0.95 + _newPos * 0.05;
    
    ofVec2f diff; //the distance difference between the mouse and the arrow
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x); //atan2 gives the angle of this vector
    rot = ofRadToDeg(rot);
    
}

void Arrow::draw() {
    
    float x1 = 0;
    float y1 = -10;
    float x2 = 0;
    float y2 = 10;
    float x3 = 30;
    float y3 = 0;
    
    ofTranslate(pos);
    ofRotate(rot);
    ofSetColor(color);
    ofTriangle(x1, y1, x2, y2, x3, y3);
}