/************************************************************
URL
	http://www.slideshare.net/tado/media-art-ii-2013
************************************************************/


/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"


/************************************************************
************************************************************/

class ofApp : public ofBaseApp{
	private:
		enum{
			WIDTH	= 640,
			HEIGHT	= 480,
			NUM_PARTICLES	= WIDTH * HEIGHT,
		};
		
		ofEasyCam cam;
		ofLight light;
		
		ofVbo Vbo;
		ofVec3f Verts[NUM_PARTICLES];
		ofFloatColor Color[NUM_PARTICLES];
		
		ofVideoGrabber video;
		
		
		void clear_VboSetting_gl();
		
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
