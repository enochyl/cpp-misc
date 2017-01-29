// polymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class Polygon {

protected:
	double width, height;
public:
	~Polygon() {
		cout << "rekt" << endl;
	}
	void set_values(int a, int b) {
		width = a; height = b;
	}
	virtual double area() { return 0; };
};

class Rectangle : public Polygon {
public:
	~Rectangle() {
		cout << "rekt" << endl;
	}
	double area() {
		return width*height;
	}
};

class Triangle : public Polygon {
public:
	double area() {
		return 0.5*width*height;
	}
};

int main()
{
	Rectangle rect;
	Triangle trgl;

	Polygon *poly1 = &rect;
	Polygon *poly2 = &trgl;

	poly1->set_values(3, 5); // The original (mother) class has the function set_values
	poly2->set_values(3, 5); // This can be circumvented with the use of virtual functions
							 // which says that the functon will be defined in subsequent 
							 // derived classes.

	cout << rect.area() << endl;
	cout << trgl.area() << endl;

	cout << poly1->area() << endl; // Use of virtual function.
	cout << poly2->area() << endl;

    return 0;
}

