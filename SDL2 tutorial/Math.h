#pragma once
#include <iostream>
struct Vector2f
{
	//default
	Vector2f() :x(0.0f), y(0.0f){
	}
	Vector2f(float pX, float pY) :x(pX), y(pY) {
	}
	//print fps if needed
	void print() {
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;

};