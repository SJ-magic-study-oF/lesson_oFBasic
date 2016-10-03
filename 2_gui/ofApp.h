/************************************************************
************************************************************/


/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxGui.h"

/************************************************************
************************************************************/

class ofApp : public ofBaseApp{
	private:
		ofxPanel gui;
		ofxFloatSlider radius;
		ofxColorSlider color;
		ofxVec2Slider position;
		ofxVec3Slider vec3D;
		ofxButton button;
		ofxToggle toggle;
		ofxLabel label;
		
		ofxGuiGroup GuiGroup1;
		ofxFloatSlider G1_Slider1;
		ofxFloatSlider G1_Slider2;
		ofxFloatSlider G1_Slider3;
		
		bool b_disp;
		
		void testButton_released();
		
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
