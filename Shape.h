/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW3 - Transformation using matrix
*/
#pragma once
#include <vector>
#include "Point.h"

#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

using namespace std;

class Shape{
protected :
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	GLuint texture;
	GLUquadricObj* quadratic;
public:
	Shape(){

	}

	
	Shape(Point* center, GLUquadricObj * q,GLuint text){
		x = center->get(0);
		y = center->get(1);
		z = center->get(2);
		quadratic = q;
		texture = text;
	}
	virtual void Draw() {
		
	};

	void Up(double a){
		y += a;
	}

	void Down(double a){
		y -= a;
	}

	void Right(double a){
		x += a;
	}

	void Left(double a){
		x -= a;
	}
};
