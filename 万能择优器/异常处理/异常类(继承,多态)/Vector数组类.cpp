#pragma once
#include "Vector������.h"

void �׳��쳣�ӿ�(int i) {
	if (i < 0) {
		throw errNegativeException(i);
	}
	else if (i == 0) {
		throw errZeroException(i);
	}
	else if (i > 1000) {
		throw errTooBigException(i);
	}
	else if (i < 10) {
		throw errTooSmallException(i);
	}
}

Vector::Vector(int V_size) {
	�׳��쳣�ӿ�(V_size);
	this->V_size = V_size;
	V_bese = new int[V_size];
}
Vector::Vector(const Vector& other) {
	if (V_bese != NULL)delete[] V_bese;
	if (other.V_bese == NULL) {
		V_bese = NULL;
		V_size = other.V_size;
	}
	else {
		V_size = other.V_size;
		V_bese = new int[V_size];
		for (int i = 0; i < V_size; i++) {
			V_bese[i] = other.V_bese[i];
		}
	}
}
Vector::~Vector() {
	if (V_bese != NULL)delete[] V_bese;
	V_bese = NULL;
	V_size = 0;
}
int Vector::getV_size()const{
	return V_size;
}
int& Vector::operator[](int i) {
	
	return V_bese[i];
}