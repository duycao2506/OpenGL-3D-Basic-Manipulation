/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW3 - Transformation using matrix
*/

#include <iostream>
#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "Display.h"
//#include "Matrix.h"

int main(int argc, char** argv)
{
	/*Matrix myMatrix(1, 3, 2, 4, 2, 1);
	Matrix a = myMatrix;
	a.Invert();
	a.printMatrix();

	vector<Point> arr;
	arr.push_back(Point(2, 3, 4));
	arr.push_back(Point(2, 3, 9));
	arr.push_back(Point(2, 3, 5));

	a.TransformPoints(arr);
	cout << arr.at(1).get(2) << endl;
	*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(he, wd);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display); //(13)
	glutMouseFunc(MouseAction);
	glutReshapeFunc(reshape); //(14)
	glutKeyboardFunc(keyboard);//(15)
	glutSpecialFunc(arrow);
	//glutTimerFunc(25, update, 0);
	quadratic = gluNewQuadric();

	MAIN_MENU = Menu(menus, quadratic);
	/* define the viewing transformation */
	for (int i = 0; i < NUM_TEXTURES; i++){
		texture[i] = 5; //LoadTexture(texNames[i]);
		if (texture[i] == 0) return 0;
	}
	MAIN_MENU.SetTextureList(texture, NUM_TEXTURES);
	
	MAIN_MENU.h = he;
	MAIN_MENU.w = wd;
	glutMainLoop();
}

