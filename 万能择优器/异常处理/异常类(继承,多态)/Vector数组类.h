#pragma once
#include "�쳣��.h"

class Vector {
public:
	Vector(int V_size = 0);
	Vector(const Vector& other);
	~Vector();
	int getV_size()const;
	int& operator[](int i);

private:
	int V_size = 0;
	int* V_bese = NULL;
};

