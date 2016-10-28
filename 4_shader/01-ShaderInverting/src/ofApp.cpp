#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );

	fbo.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "sunflower.png" );	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	fbo.begin();

	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
	ofSetColor( 255, 255, 255 );
	image.draw( 351, 221 );

	fbo.end();

	/********************
	********************/
	shader.begin();

	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );

	shader.end();		//Disable the shader
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

