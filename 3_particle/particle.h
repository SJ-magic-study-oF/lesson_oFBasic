/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxGui.h"


/************************************************************
class
************************************************************/

/**************************************************
description
	�eparticle position(1����)�̊Ǘ�.
	�`��@�\�͕ێ����Ȃ�.
	
unit	
	ms
	pixel

note
	force�́A�d�͒��S����̋����݂̂Ō��肳��A���Ԃ͖��֌W�B
	force��velocity�ɁAvelocity��position�ɁA���ꂼ�ꔽ�f����鎞�́Adt���K�v�ɂȂ�B
**************************************************/
class Particle {
private:
	/****************************************
	****************************************/
	/********************
	********************/
	ofVec2f position;
	ofVec2f velocity;
	
	/********************
	********************/
	float friction_DownPer_ms;
	ofVec2f force;
	
	
	/****************************************
	****************************************/
	void updateVel(float dt);
	void updatePos(float dt);
	void throughOfWalls();
	
public:
	/****************************************
	****************************************/
	Particle();

	void setup(ofVec2f position, ofVec2f velocity);
	void setup(float positionX, float positionY, float velocityX, float velocityY);

	void resetForce();

	void update(float dt);
	
	
	void addAttractionForce(float x, float y, float radius, float scale);
	
	float get_Speed()	{ return velocity.length(); }
	float get_pos_x()	{ return position.x; }
	float get_pos_y()	{ return position.y; }
	
	void set_friction(float val)	{ friction_DownPer_ms = val; }
};

/**************************************************
**************************************************/
class PARTICLE_SET {
private:
	/********************
	********************/
	enum{
		// NUM_PARTICLES = 100000,
		NUM_PARTICLES = 60000,
	};
	
	/********************
	********************/
	vector<Particle> particles;
	ofVbo Vbo;
	ofVec3f* Verts;
	ofFloatColor* Color;
	ofxFloatSlider PointSize;
	ofxFloatSlider friction_DownPer_sec;
	ofxFloatSlider forceScale;
	
	
	bool atraction;
	
	int mouseX;
	int mouseY;
	
	
	/********************
	********************/
	ofxPanel gui;
	ofxVec4Slider CommonColor;
	ofxFloatSlider SpeedThresh;
	
	bool b_DispGui;
	
	/********************
	********************/
	void Refresh_friction();
	void setup_gui();
	void clear_VboSetting_gl();
	void init_particleArray();
	void save_setting();
	

public:
	PARTICLE_SET();
	~PARTICLE_SET();
	
	void setup();
	void update(int _mouseX, int _mouseY);
	void draw();
	void keyPressed(int key);

	void set_attractive(bool b_val);
	void set_dispGui(bool val);
};



