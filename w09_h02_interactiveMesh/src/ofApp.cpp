#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetSmoothLighting(true);
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    counter = 0.1;
    image.loadImage("heart.jpg");
    width = 50;
    height = 50;
    res = 10;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float tempNoise = ofNoise(counter*y*0.02, counter*x*0.02);
            ofVec3f tempVec = ofVec3f (y*5, x*5, tempNoise*100);
            mesh.addVertex(ofPoint(y*res, x*res, tempNoise*100));
            mesh.addColor(1.0);
            myPoints.push_back(tempVec);
        }
    }
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mesh.addTexCoord(ofVec2f(x, height-y) * res);
        }
    }
    
    for (int y = 0; y<height-1; y++){
        for (int x=0; x<width-1; x++){
            mesh.addIndex(x+y*width);				// 0
            mesh.addIndex((x+1)+y*width);			// 1
            mesh.addIndex(x+(y+1)*width);			// 10
            
            mesh.addIndex((x+1)+y*width);			// 1
            mesh.addIndex((x+1)+(y+1)*width);		// 11
            mesh.addIndex(x+(y+1)*width);			// 10
        }
    }
    
    light.setPointLight();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float tempNoise = ofNoise((y*0.2) + counter, (x*0.2));
            ofVec3f tempVec = ofVec3f (y*res, x*res, tempNoise*100);
            mesh.setVertex((y*height) + x, tempVec);
        }
    }
    
    ofPushMatrix();
    
    glEnable(GL_DEPTH_TEST);
    ofEnableLighting();
    light.enable();
    
    cam.begin();
    ofTranslate(-250, -250);
    
    image.bind();
    mesh.draw();
//    mesh.drawWireframe();
    image.unbind();
    
    cam.end();
    
    ofDisableLighting();
    glDisable(GL_DEPTH_TEST);
    
    
    
    ofPopMatrix();
    
    counter += 0.01;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofTranslate(-250, -250);
    light.setPosition(x, y, 100);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
