#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;     //it can be named in any way, GLSL just links it

uniform sampler2DRect texture1;		//second image
uniform sampler2DRect texture2;		//spectrum

#define N (256)
uniform float specArray[N];


void main(){
    vec2 pos = gl_TexCoord[0].st;     
	
	
    vec4 color0 = texture2DRect(texture0, pos);
	vec4 color1 =  texture2DRect(texture1, pos);	//colors converted to 0..1


	vec2 center = vec2(1024.0, 768.0) / 2.0;
	float dist = distance( center, pos );	//built-in function for distance 

	//Antialiasing
	vec2 spectrumPos = vec2( dist / 7.0, 0.5 );
	vec4 color2 =  texture2DRect(texture2, spectrumPos);	//spectrum values
	float spectrValue = color2.r;		//get spectrum value, normally in [0..1] 


	vec2 delta = pos - center;
	delta *= 1-2*spectrValue;
	// delta *= 1-spectrValue;
	
	vec2 posS = center + delta;

	//Audio responsible
	color0 = texture2DRect(texture0, posS);
	color1 = texture2DRect(texture1, posS);


	vec4 color;

	color = min( color0, color1 );	
	// color = color0;

	gl_FragColor = color;
}
