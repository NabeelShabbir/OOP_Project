#include "Admin.h"
#include "Patient.h"
#include "Doctor.h"


Admin::Admin() // oladoc creates admin and predetermined username and password is given
{
	string temp = "Admin";
	string temp1 = "1Bih>2ib";

	strcpy_s(UserName, temp.c_str());
	strcpy_s(Password, temp1.c_str());

	write_Admin(*this);
}

string Admin::Login()
{
	bool flag = false;
	char ch = 0;
	string temp1;
	Admin obj;

	system("CLS");

	do
	{
		cout << "Enter your Username: "; // login verification
		getline(cin, temp1);

		ifstream fin("Admin.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp2 = obj.getUserName();
			if (temp1 == temp2)
			{
				do {
					cout << "Enter Password: ";
					getline(cin, temp1);

					temp2 = obj.Password;

					if (temp1 == temp2)
					{
						return obj.UserName;
					}
					else
					{
						cout << "Invald Password. Do you want to Exit (y/n): ";
						cin >> ch;
						cin.ignore(1);
						if (ch != 'N' && ch != 'n')
						{
							break;
						}
					}
				} while (1);

				flag = true;
			}
			else
			{
				break;
			}
		}
		fin.close();
		if (flag == false)
		{
			system("CLS");
			cout << "Invald Username. Do you want to Exit (y/n)" << endl;
			cin >> ch;
			cin.ignore(1);
			if (ch != 'N' && ch != 'n')
			{
				break;
			}
		}
	} while (flag == false);

	return "";
}

void Admin::Menu(char* UN) 
{
	char ch = 0;
	string temp = UN;
	
	if (temp == "Admin") // username must be equal for this to work
	{
		do
		{
			system("CLS");
			cout << "Do you want to: \n1. View Patient Data\n2. View Doctor\n3. Edit Doctor's Password\n";
			cin >> ch;
			cin.ignore(1);

			if (ch == '1')
			{
				Patient P;
				P.read(); // view patients data
			}
			else if (ch == '2')
			{
				Doctor D;
				D.read(); // doctors data
			}
			else if (ch == '3')
			{
				Doctor D;
				string temp;
				char cnic[14];
				cout << "Enter Doctors UserName that you want to change password of: "; // change doctors password with doctors username
				cin >> temp;

				do
				{
					cout << "Enter Doctors New Password\n(Password must be 8 characters long and the use of a minimum of one special character,\nuppercase, lowercase, and the numeric digit): ";

					string TempStr;
					getline(cin, TempStr);
					strcpy_s(Password, TempStr.c_str());
					if (D.Password_verification(Password) == false)
					{
						cout << "Invalid Password or it is already in use" << endl;
					}

				} while (D.Password_verification(Password) == false);


				D.update_Password(temp, Password);
			}

			cout << "Do you want to Logout? (y/n)" << endl;
			cin >> ch;
			cin.ignore(1);

		} while (ch != 'Y' && ch != 'y');
	}
	else 
	{
		cout << "Invalid Admin Username" << endl;
	}
}

void Admin::write_Admin(Admin obj) //file handling to write admin
{
	ofstream fout("Admin.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
