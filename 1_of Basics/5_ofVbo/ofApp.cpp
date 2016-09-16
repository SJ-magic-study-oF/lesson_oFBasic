#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	ofSetVerticalSync();
		true
			60fps
			
		false
			trueの10倍くらい出る
	********************/
	ofSetVerticalSync(false);

	ofBackground(0);
	ofEnableDepthTest();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	cam.setDistance(100);
	
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			Verts[j * WIDTH + i].set(i - WIDTH/2, j - HEIGHT/2, 0);
			Color[j * WIDTH + i].set(0.5, 0.8, 1.0, 1.0);
		}
	}
	
	Vbo.setVertexData(Verts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	Vbo.setColorData(Color, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
	float time_f = ofGetElapsedTimef();
	
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			float x = 10 * sin(i * 0.1 + time_f);
			float y = 10 * sin(j * 0.15 + time_f);
			float z = x + y;
			
			Verts[j * WIDTH + i] = ofVec3f(i - WIDTH/2, j - HEIGHT/2 , z);
		}
	}
	
	Vbo.updateVertexData(Verts, NUM_PARTICLES);
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofSetHexColor(0xffffff);
	
	/********************
	********************/
	cam.begin();
	
	glPointSize(2.0);
	Vbo.draw(GL_POINTS, 0, NUM_PARTICLES);
	
	cam.end();
	
	/********************
	********************/
	// clear_VboSetting_gl();
	
	/********************
	********************/
	string info;
	info = "Vertex num = " + ofToString(WIDTH * HEIGHT, 0) + "\n";
	info += "FPS = " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(info, 30, 30);
}

/******************************
descrition
	ofVboで描画すると、openGlの設定が何らか変わるようだ。
	この結果、次に来る描画が所望の動作とならないケース多数。
		次のfunctionが描画されないなど
			ofDrawBitmapString()
			image.draw()
			
	この対応として、
		ofCircle(). ofRect().
	等を1発いれてやることで、OKとなった。
	おそらく、この関数内で、openGl設定が、また変わるのだろう。
		α = 0;
	にて描画する。
******************************/
void ofApp::clear_VboSetting_gl()
{
	ofSetColor(255, 255, 255, 0);
	ofCircle(0, 0, 1);
	
	ofSetColor(255, 255, 255, 255);
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
