//
//  customCircle.cpp
//  01_hw_A_clickToChangeAB
//
//  Created by Umi Syam on 2/6/15.
//
//

#include "customCircle.h"


customCircle::customCircle() {
    // Constructor
}

void customCircle::setup() {
    setPointA(75, ofGetWindowHeight()/2);
    setPointB(ofGetWindowWidth()-75, ofGetWindowHeight()/2);
}

void customCircle::setPointA(float _x, float _y) {
    pointA.set(_x, _y);
}
void customCircle::setPointB(float _x, float _y) {
    pointB.set(_x, _y);
}
void customCircle::update(float _pct) {
    pct = _pct;
    currentPos = pointA * (1-pct) + pointB * pct;
}

void customCircle::draw() {
    ofSetColor(ofColor::white);
    ofCircle(pointA, 5);
    ofDrawBitmapString("A", pointA.x, pointA.y - 10);
    ofCircle(pointB, 5);
    ofDrawBitmapString("B", pointB.x, pointB.y - 10);
    ofDrawBitmapString("pct: " + ofToString(pct), currentPos.x - 35, currentPos.y - 35);
    
    ofLine(pointA, pointB);
    
    ofSetColor(ofColor::yellow);
    ofCircle(currentPos, 30);
    
}

