/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW3 - Transformation using matrix
*/
#pragma once

# define M_PI 3.14159265358979323846  /* pi */
#include "Shape.h"
#include <string>
#include <string.h>
#include <vector>
#include "Ring.h"
#include "Cone.h"
#include "Cylinder.h"

using namespace std;


bool light = false;

GLUquadricObj *quadratic = nullptr;

GLfloat LightAmbient[] = { 247 / 255.0f, 202 / 255.0f, 24 / 255.0f, 0.1f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

class Menu{
private:
	int menuhistory = 1;
	int currentShape = 0;
	int currentdrawshape = -1;
	vector<Shape*> shapes;
	double ANG_U = (1 / 180.0) * M_PI;
	GLUquadricObj* qu = nullptr;
	GLuint* textures;
public:
	
	double h = 0;
	double w = 0;
	Menu(){
	}

	~Menu(){
		for (unsigned int i = 0; i < shapes.size(); i++)
			delete shapes[i];
	}

	Menu(void menus(int), GLUquadricObj* qua){
		menuhistory = glutCreateMenu(menus);
		
		
		int menumain = glutCreateMenu(menus);
		glutAddMenuEntry("The Ring", -1);
		glutAddMenuEntry("The Cylinder", -3);
		glutAddMenuEntry("The Cone", -2);
		glutAddSubMenu("History", menuhistory);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		qu = qua;
		shapes = vector<Shape*>();
	}

	bool SetCurrentDrawingShape(int a)
	{
		if (a < 0){
			currentdrawshape = a;
			return true;
		}
		return false;
	}

	bool SetCurrentEditingShape(int a){
		if (a >= 1){
			currentShape = a-1;
			return true;
		}
		return false;
		
	}

	void OnClickListenner(int x, int y){
		string stri = "";
		Shape* a;
		int index = shapes.size() + 1;
		Point* p = new Point(((double)x) / w, ((double)y) / h, -7.0);
		switch (currentdrawshape){
			case -1 :
				a = new Ring(p,qu,textures[0]);
				shapes.push_back(a);
				stri = "Ring ";
				break;
			case -2:
				a = new Cone(p, qu, textures[1]);
				shapes.push_back(a);
				stri = "Cone ";
				break;
			case -3:
				a = new Cylinder(p, qu, textures[2]);
				shapes.push_back(a);
				stri = "Cylinder ";
				break;
			default:
				return;
		}
		delete p;
		glutSetMenu(menuhistory);
		
		stri = stri + to_string(index);
		glutAddMenuEntry(stri.c_str(), index);
		glutPostRedisplay();
	}

	void OnKeyListenner(unsigned char key, int x, int y){
		switch (key){
		case 'l':
			light = !light;
			if (!light)
				glDisable(GL_LIGHTING);
			else
				glEnable(GL_LIGHTING);
			break;
		case 'w':
			LightPosition[1] += 0.1f;
			break;
		case 'a':
			LightPosition[0] -= 0.1f;
			break;
		case 's':
			LightPosition[1] -= 0.1f;
			break;
		case 'd':
			LightPosition[0] += 0.1f;
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}

	void OnSpecialKeyListenner(unsigned char key, int x, int y){
		if (shapes.size() < 1) return;
		switch (key) {
		case  GLUT_KEY_LEFT: //LEFT
			shapes[currentShape]->Left(0.2);
			break;
		case GLUT_KEY_UP: //UP
			shapes[currentShape]->Up(0.2);
			break;
		case GLUT_KEY_RIGHT: //RIGHT
			shapes[currentShape]->Right(0.2);
			break;
		case GLUT_KEY_DOWN: //DOWN
			shapes[currentShape]->Down(0.2);
			break;
		default:
			break;
		}

		glutPostRedisplay();
	}


	void Draw(){
		for (unsigned int i = 0; i < shapes.size(); i++){
			shapes[i]->Draw();
		}
	}

	void SetTextureList(GLuint a[], int n){
		textures = new GLuint[n];
		for (int i = 0; i < n; i++)
			textures[i] = a[i];
	}

} MAIN_MENU;

void menus(int a){
	if(!MAIN_MENU.SetCurrentDrawingShape(a))
		MAIN_MENU.SetCurrentEditingShape(a);
}

