#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include "Patient.h"
using namespace std;


class Doctor : public User
{
protected:
	int Years_Of_Experience;
	char HospitalOrClinic_Name[50];
	char Location[50];
	int Speciality;
	bool Availibility[7][24] = {false};
public:

	void Register();

	string Login();

	void Menu(char* cnic);

	bool CNIC_verification(char* C);

	bool Name_verification(char* N);

	bool E_Mail_verification(char* E);

	bool UserName_verification(char* U);

	bool Password_verification(char* P);

	void write_Doctor(Doctor obj);

	void update_Availibility(char* cnic, bool arr[7][24]);

	void update_Password(char* cnic, string Password);

	void update_Password(string UN, string Password);

	void read();

	void read(char C);

	void read(string S);

	void Display();
};

#endif