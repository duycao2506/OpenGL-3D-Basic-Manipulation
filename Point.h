/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW3 - Transformation using matrix
*/
#pragma once
using namespace std;

class Point{
private :
	float coordinates[4];
public:
	Point(){
		for (int x = 0; x < 3; x++){
			coordinates[x] = 0;
		}
		coordinates[3] = 1;
	}
	Point(float x1, float y1, float z1){
		coordinates[0] = x1;
		coordinates[1] = y1;
		coordinates[2] = z1;
		coordinates[3] = 1;
	}

	void set(Point p2){
		coordinates[0] = p2.get(0);
		coordinates[1] = p2.get(1);
		coordinates[2] = p2.get(2);
		coordinates[3] = 1;
	}


	float get(int ind){
		return coordinates[ind];
	}

	void set(float x, float y, float z){
		coordinates[0] = x;
		coordinates[1] = y;
		coordinates[2] = z;
		coordinates[3] = 1;
	}
	
	// Assume that this point is according to O
	

	
};