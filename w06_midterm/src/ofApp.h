#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"
#define NUM 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    //----GUI variables-------
    ofxUISuperCanvas *gui;
    float red, green, blue;
    void guiEvent(ofxUIEventArgs &e);
    ofColor backgroundColor;
    bool drawPadding;
    bool drawTail;
    bool isResetPos;
    
    
    //----Emitter & Particle
    vector<Particle> particle;
    ofVec2f emitter;
    float emitterRad;
    float emitterVel;
    float lifeTime;
    float rotateAngle;
    float force, spinning, damping;
    float initTime;

    int fileIndex;
};
