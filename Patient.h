#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include "Doctor.h"
using namespace std;


class Patient: public User
{
protected:
	double Balance = 3500; // preset balance of 3500
public:
	void Register();

	string Login();

	void Menu(char* cnic);

	bool CNIC_verification(char* C);

	bool Name_verification(char* N);

	bool E_Mail_verification(char* E);

	bool UserName_verification(char* U);

	bool Password_verification(char* P);

	void write_Patient(Patient obj);

	void update_Password(char* cnic, string Password);

	void read();

	void Display();
};

#endif 
