#pragma once
#include "Menu.h"

class Ring : public Shape{
public:
	Ring(Point* center, GLUquadricObj* q, GLuint text) :Shape(center, q, text){

	}

	void Draw(){

		//glBindTexture(GL_TEXTURE_2D, texture);

		glTranslated(x, y, z); // Move Right 1.5 Units And Into The
		
		glRotated(-80.0, 1.0, 0.0, 0.0);
			
		glutSolidTorus(0.5f, 2.0f, 100, 100);
		glRotated(80.0, 1.0, 0.0, 0.0);
		glTranslated(-x,-y, -z);
		
	}
};