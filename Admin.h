#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

class Admin : public User
{
public:
	Admin();

	string Login();

	void Menu(char* UN);

	void write_Admin(Admin obj);
};













#endif
