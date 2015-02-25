//
//  Punk.cpp
//  02_hw_C_PunkGaussianPopulation
//
//  Created by Umi Syam on 2/16/15.
//
//

#include "Punk.h"

Punk::Punk() {
//constructor
}

//--------------------------------------------------------------
void Punk::setup(){
//    pos = _pos;
//    size = _size;
    
    r = ofRandom(1,255);
    g = ofRandom(1,255);
    b = ofRandom(1,255);
    
}

//--------------------------------------------------------------
void Punk::update(){

}

//--------------------------------------------------------------
void Punk::draw(float _x, float _y, float _size){
    pos.x = _x;
    pos.y = _y;
    size = _size;
    
    //face
    ofSetColor(r,g,b);
    ofCircle(pos.x, pos.y, size);
    
    //eyes
    ofSetColor(255);
    ofCircle(pos.x +15, pos.y -5, size/3);
    ofCircle(pos.x -15, pos.y -5, size/3);
    
    ofSetColor(0);
    ofCircle(pos.x +17, pos.y -2, size/6);
    ofCircle(pos.x -13, pos.y -2, size/6);
    
    //nose
    ofSetColor(r,g,b);
    ofTriangle(pos.x, pos.y, pos.x + 15, pos.y, pos.x - 25, pos.y - 60);
    
    //mouth
    ofSetColor(255);
    ofCircle(pos.x, pos.y+15, size/6);
}


