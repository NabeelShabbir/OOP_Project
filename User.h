#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Doctor;
class Patient;

class User
{
protected:
	char CNIC[50]; // char used instead of string because chars will take defined space so file handling will not generate error
	char Name[50];
	char UserName[50];
	char Password[50];
	char E_Mail[50];
public:
	virtual void Register() {} // void functions for polymorphism as these are being used in both Doctor and Patient
	virtual string Login() { return ""; }
	virtual void Menu(char* cnic) {}
	virtual void read() {}
	char* getCNIC() { return CNIC; }
	char* getE_Mail() { return E_Mail; }
	char* getUserName() { return UserName; }
};


#endif 
