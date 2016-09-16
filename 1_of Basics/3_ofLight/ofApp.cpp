#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	ofEnableSmoothing();
	
	light.enable();
	light.setSpotlight();
	light.setPosition(-500, 500, 1000);
	
	light.setAmbientColor(ofFloatColor(1.0, 0, 0, 1.0));	// 環境反射光
	light.setDiffuseColor(ofFloatColor(0, 1.0, 0));			// 拡散反射光
	light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));	// 鏡面反射光
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	
	/*
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	*/
	
	ofSetColor(255);
	
	box.set(200); // size
	box.setResolution(60);
	box.setPosition(-150, 0, 0);
	// box.drawWireframe();
	box.draw();
	
	// sphere.set(100, 16); // r, Resolution
	sphere.set(100, 600); // r, Resolution
	sphere.setPosition(150, 0, 0);
	// sphere.drawWireframe();
	sphere.draw();
	
	// ofPopMatrix();
	
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
