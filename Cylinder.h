#pragma once
#include "Menu.h"

class Cylinder : public Shape{

public:
	Cylinder(Point* center, GLUquadricObj* q,GLuint text) :Shape(center, q, text){
		
	}
	void Draw(){
		//glLoadIdentity();
		gluQuadricTexture(quadratic, GL_TRUE);
		//glBindTexture(GL_TEXTURE_2D, texture);
		glTranslated(x, y, z); // Move Right 1.5 Units And Into The
		glRotated(-80.0, 1.0, 0.0, 0.0);
		gluCylinder(quadratic, 1.0f, 1.0f, 2.0f, 50, 20);
		glRotated(80.0, 1.0, 0.0, 0.0);
		glTranslated(-x, -y, -z);
		gluQuadricTexture(quadratic, GL_FALSE);
	}
};