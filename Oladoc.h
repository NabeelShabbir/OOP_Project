#ifndef OLADOC_H // circular dependency of libraries is avoided
#define OLADOC_H

#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

class Oladoc
{
private:
	User* U[3];
public:
	Oladoc();

	void StartUp();
};

#endif