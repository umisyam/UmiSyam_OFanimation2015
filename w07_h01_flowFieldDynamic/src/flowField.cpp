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


void flowField::draw(ofVideoGrabber &vid) {

    for (int y = 0; y < height; y+=resolution) {
        for (int x = 0; x < width; x+=resolution) {
            int i = (y * width + x) * 3;
            
            //get pixels from vidgrabber
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+2];
            int b = vid.getPixels()[i+4];
            
            float brightness = (r+g+b) / 255.0 / 2;
            ofSetColor(ofColor::fromHsb(brightness * 255,255,255));
            
            //sine and cosine of the video's brightness
            float cosB = cos(brightness*TWO_PI);
            float sinB = sin(brightness*TWO_PI);
            
            //draw rotated line based on brightness
            ofLine(x-5*cosB, y-5*sinB, x+5*cosB, y+5*sinB);
            ofCircle(x*sinB, y*cosB, 2);
            

        }
    }
}