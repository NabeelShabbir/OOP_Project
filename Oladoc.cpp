#include "Oladoc.h"
#include "Admin.h"
#include "Patient.h"
#include "Doctor.h"


Oladoc::Oladoc()
{

}

void Oladoc::StartUp()
{
	Admin A;
	U[0] = new Patient(); // polymorphic creation of objects
	U[1] = new Doctor();

	char ch = 0;

	do
	{
		system("CLS");
		cout << "Do you want to: \n1. Login  \n2. Register" << endl;
		cin >> ch;
		cin.ignore(1);

		if (ch == '1')
		{
			do {
				system("CLS");
				cout << "Do you want to Login as a: \n1. Doctor\n2. Patient\n3. Admin" << endl;
				cin >> ch;
				cin.ignore(1);

				if (ch == '1')
				{
					string temp = U[1]->Login();
					if (temp != "")
					{
						U[1]->Menu(&temp[0]); // u1 is Doctors menu
					}
				}
				else if (ch == '2')
				{
					string temp = U[0]->Login();
					if (temp != "")
					{
						U[0]->Menu(&(temp[0])); // u0 is Patients menu
					}
				}
				else if (ch == '3')
				{
					A.Menu(&(A.Login()[0])); // Admins menu
				}

				cout << "Do you want to Login again: (y/n): ";
				cin >> ch;
				cin.ignore(1);

			} while (ch != 'n' && ch != 'N');
		}
		else if (ch == '2')
		{
			do {

				system("CLS"); // registration screen
				cout << "Do you want to register as a: \n1. Doctor\n2. Patient" << endl;
				cin >> ch;
				cin.ignore(1);

				if (ch == '1')
				{
					U[1]->Register();
				}
				else if (ch == '2')
				{
					U[0]->Register();
				}

				cout << "Do you want to Register More: (y/n): ";
				cin >> ch;
				cin.ignore(1);

			} while (ch != 'n' && ch != 'N');
		}

		ch = 'Y';
	} while (ch != 'n' && ch != 'N');

}
