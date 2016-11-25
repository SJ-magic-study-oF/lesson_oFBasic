#include "ofApp.h"

vector<ofPoint> vertices;
vector<ofColor> colors;
int nTri;		//The number of triangles
int nVert;		//The number of the vertices equals nTri * 3

//--------------------------------------------------------------
void ofApp::setup() {
	nTri = 1500;			//The number of the triangles
	nVert= nTri * 3;		//The number of the vertices

	float Rad = 250;	//The sphere's radius
	float rad = 25;		//Maximal triangle's “radius”

	vertices.resize( nVert );
	for (int i=0; i<nTri; i++) {
		ofPoint center( ofRandom( -1, 1 ), ofRandom( -1, 1 ), ofRandom( -1, 1 ) );
		center.normalize();
		center *= Rad;

		for (int j=0; j<3; j++) {
			vertices[ i*3 + j ] = center + ofPoint( ofRandom( -rad, rad ), ofRandom( -rad, rad ), ofRandom( -rad, rad ) );
		}
	}

	colors.resize( nTri );
	for (int i=0; i<nTri; i++) {
		colors[i] = ofColor( ofRandom( 0, 255 ), 0, 0 );
	}

	shader.load( "shaderVert.c", "shaderFrag.c" );
}

//--------------------------------------------------------------
float time0 = 0;
float phase = 0;
float distortAmount = 0;

void ofApp::update(){
  float time = ofGetElapsedTimef();
  float dt = ofClamp( time - time0, 0, 0.1 );
  time0 = time;

  float speed = ofMap( mouseY, 0, ofGetHeight(), 0, 5 );
  phase += speed * dt;
  distortAmount = ofMap( mouseX, 0, ofGetWidth(), 0, 1.0 );
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();

	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

	ofPushMatrix();

	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

	float time = ofGetElapsedTimef();
	float angle = time * 10;		//Compute angle. We rotate at speed 10 degrees per second
	ofRotate( angle, 0, 1, 0 );

	shader.begin();		
	shader.setUniform1f( "phase", phase );
	shader.setUniform1f( "distortAmount", distortAmount );

	for (int i=0; i<nTri; i++) {
		ofSetColor( colors[i] );	//Set color
		ofTriangle( vertices[ i*3 ], vertices[ i*3 + 1 ], vertices[ i*3 + 2 ] ); //Draw triangle
	}

	shader.end();	//Disable the shader

	ofPopMatrix();	//Restore the coordinate system
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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