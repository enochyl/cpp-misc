// pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void passByValue(int x);
void passByReference(int* x);

int main()
{
	int betty = 30;
	int sandy = 52;

	passByValue(betty);
	passByReference(&sandy);

	cout << betty << endl;
	cout << sandy << endl;

	//int array[100000];
	//cout << sizeof(array) / sizeof(array[0]) << endl;
	
	return 0;
}

void passByValue(int x) {
	x = 99;
}

void passByReference(int *x) {
	*x = 99;
}