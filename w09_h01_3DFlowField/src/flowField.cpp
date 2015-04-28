//
//  flowField.cpp
//  23_flowField
//
//  Created by Umi Syam on 3/31/15.
//  modified from w07_h02_flowFieldParticles
//

#include "flowField.h"

flowField::flowField() {
    
}

void flowField::setup(int w, int h, int dep, int res) {
    width = w;
    height = h;
    depth = dep;
    resolution = res;
    
    fieldX = ceil (width/resolution);
    fieldY = ceil (height/resolution);
    fieldZ = ceil (depth/resolution);
    
    for (int z = 0; z < fieldZ; z++) {
        vector<vector<ofVec3f> > planeZ;
        field.push_back ( planeZ );
        
        for (int y = 0; y < fieldY; y++) {
            vector<ofVec3f> planeY;
            field[z].push_back ( planeY );
            
            for (int x = 0; x < fieldX; x++) {
                ofVec3f planeX( 10, 10, 10 );
                field[z][y].push_back ( planeX );
                
            }
        }
    }
    
    fieldSize = fieldX * fieldY * fieldZ;

//    testing
    cout << "Size of vector field = " << fieldSize << " points." << endl;
}

void flowField::setRandom(float scale) {
    for (int z = 0; z<fieldZ; z++) {
        for (int y = 0; y<fieldY; y++) {
            for (int x = 0; x < fieldX; x++) {
                float a = ofRandom(-1,1) * scale;
                float b = ofRandom(-1,1) * scale;
                float c = ofRandom(-1,1) * scale;
                field[z][y][x].set(ofVec3f(a,b,c));
            }
        }
    }
}

void flowField::setNoise() {
    
    for (int z = 0; z<fieldZ; z++) {
        for (int y = 0; y<fieldY; y++) {
            for (int x = 0; x < fieldX; x++) {
                float noise = ofNoise(x * 0.05, y * 0.05, z * 0.05);
                noise = ofMap(noise, 0, 1, 0, TWO_PI);
                
                field[z][y][x].set(ofVec3f(cos(noise) * 20.0, sin(noise) * 20.0, sin(noise) * 20.0));
            }
        }
    }
    
}

ofVec3f flowField::getForceAt(float x, float y, float z) {
    
    
    float xPct = x/width;
    float yPct = y/height;
    float zPct = z/depth;
    
    fieldX = (width/resolution);
    fieldY = (height/resolution);
    fieldZ = (depth/resolution);
    
//    if (xPct < 0 || xPct > 1 || yPct < 0 || yPct > 1) {
//        return frc;
//    }
    
    int xValue = ofClamp( xPct * fieldX, 0, fieldX-1 );
    int yValue = ofClamp( yPct * fieldY, 0, fieldY-1 );
    int zValue = ofClamp( zPct * fieldZ, 0, fieldZ-1 );
    
    ofVec3f frc;
    frc.set( field[zValue][yValue][xValue] );
    
    return frc;
    
}

void flowField::draw() {
    ofSetColor(200);
    
    for (int z = 0; z<fieldZ; z++) {
        for (int y = 0; y<fieldY; y++) {
            for (int x = 0; x < fieldX; x++) {
//    for( int z = 0; z < field.size(); z++){
//        for( int y=0; y<field[z].size(); y++){
//            for( int x=0; x<field[z][y].size(); x++){
                ofVec3f temp = ofVec3f( x*resolution, y*resolution, z*resolution );
                ofLine ( temp, temp+field[z][y][x] );
            }
        }
    }
}