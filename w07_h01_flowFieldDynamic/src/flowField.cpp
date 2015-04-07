//
//  flowField.cpp
//  23_flowField
//
//  Created by Umi Syam on 3/31/15.
//
//

#include "flowField.h"

flowField::flowField() {
    
}

void flowField::setup(float w, float h, float res) {
    width = w;
    height = h;
    resolution = res;
    
    internalWidth = ceil (width/resolution);
    internalHeight = ceil (height/resolution);
    
    fieldSize = internalWidth * internalHeight;
    
    for (int i = 0; i < fieldSize; i++) {
        ofVec2f flow;
        flow.set(0.0, 0.0);
        field.push_back(flow);
    }
}

void flowField::setRandom(float scale) {
    for (int i = 0; i<fieldSize; i++) {
        float x = ofRandom(-1,1) * scale;
        float y = ofRandom(-1,1) * scale;
        field[i].set(x,y);
    }
}

void flowField::setNoise() {
    for (int y = 0; y<internalHeight; y++) {
        for (int x = 0; x < internalWidth; x++) {
            int index = (y * internalWidth) + x;
            float noise = ofNoise(x * 0.05, y * 0.05);
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            field[index].set(ofVec2f(cos(noise), sin(noise) * 2.0));
        }
    }
}

ofVec2f flowField::getForceAt(float x, float y) {
    ofVec2f frc;
    frc.set(0,0);
    
    float xPct = x/width;
    float yPct = y/height;
    
    if (xPct < 0 || xPct > 1 || yPct < 0 || yPct > 1) {
        return frc;
    }
    
    int internalPosX = xPct * internalWidth;
    int internalPosY = yPct * internalHeight;
    
    int pos = internalPosY * internalWidth + internalPosX;
    
    frc.set(field[pos].x * 0.01, field[pos].y * 0.01);
    
    return frc;
    
}


void flowField::draw() {
    ofSetColor(255,0,0);
    for (int y = 0; y < internalHeight; y++) {
        for (int x = 0; x < internalWidth; x++) {
            int index = (y * internalWidth) + x;
            
            float px = x * resolution;
            float py = y * resolution;

            float px2 = px + field[index].x * 5;
            float py2 = py + field[index].y * 5;
            
            ofLine (px, py, px2, py2);
            ofCircle(px, py, 1);
        }
    }
}