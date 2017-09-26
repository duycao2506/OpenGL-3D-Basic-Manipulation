
/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW3 - Transformation using matrix
*/

#pragma once


#include "Menu.h"
#include <iostream>
#include <stdlib.h>
#include <gl\GLAux.h>
#include <gl\glui.h>
/////////////////////////////
/////////////////////////////
#define NUM_TEXTURES 3
GLuint texture[NUM_TEXTURES];
char* texNames[NUM_TEXTURES] = { "text1.bmp","text2.bmp", "text3.bmp" };
GLuint i = 0;
//////////////////////////////
//////////////////////////////
//Display
int he = 1000;
int wd = 1000;
/////////////////////////////
/////////////////////////////
typedef struct{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}RGBColor;
//////////////////////////////
//////////////////////////////

RGBColor B_Color = { 108, 122, 137 };
RGBColor Background = { 236, 236, 236 };

/////////////////////////////////


void MouseAction(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		MAIN_MENU.OnClickListenner(x, y);
		glutPostRedisplay();
	}

}



GLuint LoadTexture(const char * imagepath)
{

	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	FILE * file = fopen(imagepath, "rb");
	if (!file){ printf("Image could not be opened\n"); return 0; }
	if (fread(header, 1, 54, file) != 54){ // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}
	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way	
	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);
	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return textureID;
}


void init(){
	
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading (7)
	glClearColor(Background.r / 255.0, Background.g / 255.0, Background.b / 255.0, 0.5f); // Black Background (8)
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv( GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT1);
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ClearScreen And Depth Buffer
	glColor4d(55 / 255.0, 12 / 255.0, 211/ 255.0,0.7);
	//MAIN_MENU.Draw();
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	
	glPushMatrix();
	glLoadIdentity();
	//gluQuadricOrientation(quadratic, GLU_OUTSIDE);
	gluQuadricDrawStyle(quadratic, GL_FILL);
	gluQuadricNormals(quadratic,GLU_SMOOTH);
	
	
	MAIN_MENU.Draw();
	
	
	//glTranslatef(0.2f, 0.5f, -7.0f);
	
	
	glPopMatrix();
	
	glutSwapBuffers();//(11)
}



void keyboard(unsigned char key, int x, int y){
	MAIN_MENU.OnKeyListenner(key, x, y);
}


void arrow(int key, int x, int y)
{
	MAIN_MENU.OnSpecialKeyListenner(key, x, y);
}



void reshape(GLsizei w, GLsizei h) {  // GLsizei for non-negative integer
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutMouseFunc(MouseAction);
	glutReshapeFunc(reshape); //(14)
	glutKeyboardFunc(keyboard);//(15)
	glutSpecialFunc(arrow);
}


