#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	
	ofSetWindowShape(WIDTH, HEIGHT);
	
	/********************
	********************/
	ParticleSet.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	ParticleSet.update(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	ParticleSet.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ParticleSet.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ParticleSet.set_attractive(true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ParticleSet.set_attractive(false);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
