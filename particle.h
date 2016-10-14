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
	各particle position(1つずつ)の管理.
	描画機能は保持しない.
	
unit	
	ms
	pixel

note
	forceは、重力中心からの距離のみで決定され、時間は無関係。
	forceがvelocityに、velocityがpositionに、それぞれ反映される時は、dtが必要になる。
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



