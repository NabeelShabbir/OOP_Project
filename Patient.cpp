#include "Patient.h"

void Patient::Register()
{
	system("CLS");// clear screen
	do
	{
		cout << "Enter Your CNIC(1111122222223): ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(CNIC, TempStr.c_str());
		if (CNIC_verification(CNIC) == false)// cnic validation function
		{
			cout << "Wrong digits CNIC entered or This CNIC is already registered" << endl;
		}

	} while (CNIC_verification(CNIC) == false);

	do
	{
		cout << "Enter Your Name: ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(Name, TempStr.c_str());

		if (Name_verification(Name) == false)// name validation
		{
			cout << "Too long of a Name or Name has no letters" << endl;
		}

	} while (Name_verification(Name) == false);

	do
	{
		cout << "Enter Your E_Mail: ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(E_Mail, TempStr.c_str());
		if (E_Mail_verification(E_Mail) == false)// email validation
		{
			cout << "Too long of an e-mail or it is already in use" << endl;
		}

	} while (E_Mail_verification(E_Mail) == false);

	do
	{
		cout << "Enter Your UserName: ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(UserName, TempStr.c_str());
		if (UserName_verification(E_Mail) == false)// email validation
		{
			cout << "Too long of an UserName or it is already in use" << endl;
		}

	} while (UserName_verification(E_Mail) == false);

	do
	{
		cout << "Enter Your Password\n(Password must be 8 characters long and the use of a minimum of one special character,\nuppercase, lowercase, and the numeric digit): ";

		string TempStr;
		getline(cin, TempStr);
		strcpy_s(Password, TempStr.c_str());
		if (Password_verification(Password) == false)
		{
			cout << "Invalid Password or it is already in use" << endl;
		}

	} while (Password_verification(Password) == false);

	bool F = false;
	bool F1 = true;

	do
	{
		if (F1 == false)
		{
			cout << "The password is not the same" << endl;
		}
		cout << "Enter your Password again to verify" << endl;
		string TempStr;
		getline(cin, TempStr);

		if (Password == TempStr)
		{
			F = true;
		}
		else
		{
			F1 = false;
		}

	} while (F == false);


	write_Patient(*this);
}

string Patient::Login() // differnet login for patient
{
	bool flag = false;
	char ch = 0;
	string temp1;
	Patient obj;

	system("CLS");

	do
	{
		cout << "Enter your Username: ";
		getline(cin, temp1);//cin 

		ifstream fin("Patient.dat", ios::binary);//binary file Patient.dat accessed
		while (fin.read((char*)&obj, sizeof(obj)))// new objects read from file
		{
			string temp2 = obj.getUserName();
			if (temp1 == temp2)
			{
				do {
					cout << "Enter Password: ";
					getline(cin, temp1);

					temp2 = obj.Password;

					if (temp1 == temp2) // password compared, if match then cnic returned
					{
						return obj.CNIC;
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

void Patient::Menu(char* cnic)// gets cnic as input from login
{
	char ch = 0;
	do
	{
		system("CLS");
		cout << "Do you want to:\n1. View Doctors\n2. Update Password\n" << endl;
		cin >> ch;
		cin.ignore(1);
		if (ch == '1')
		{
			do
			{
				system("CLS");
				cout << "Do you want to view Doctors by: \n1. Speciality \n2. Clinic/Hospital \n3. Location" << endl;
				cin >> ch;
				cin.ignore(1);

				if (ch == '1')
				{
					do
					{
						system("CLS");
						cout << "What Field Doctors do you want to view: " << endl;
						cout << "1. Gynecology\n2. Dermatology\n3. Oncology\n4. Orthopedics\nEnter corresponding number: ";
						cin >> ch;
						cin.ignore(1);

						Doctor D;
						D.read(ch - 48);// value entered -48 cause speciality is stored as integers

						cout << "Do you want to keep viewing by Speciality? (y/n)" << endl;
						cin >> ch;
						cin.ignore(1);

					} while (ch != 'N' && ch != 'n');
				}
				else if (ch == '2')
				{
					do
					{
						string temp;

						system("CLS");
						cout << "What Clinic/Hospital Doctors do you want to view: " << endl;
						cin >> temp;

						Doctor D;
						D.read(temp); // a read function which only reads Doctors which meet the parameter condition

						cout << "Do you want to keep viewing by Clinic/Hospital? (y/n)" << endl;
						cin >> ch;
						cin.ignore(1);

					} while (ch != 'N' && ch != 'n');
				}
				else if (ch == '3')
				{
					do
					{
						string temp;

						system("CLS");
						cout << "What Location Doctors do you want to view: " << endl;
						cin >> temp;

						Doctor D;
						D.read(temp);

						cout << "Do you want to keep viewing by Location? (y/n)" << endl;
						cin >> ch;
						cin.ignore(1);

					} while (ch != 'N' && ch != 'n');
				}

				cout << "Do you want to continue viewing Doctors? (y/n)" << endl;
				cin >> ch;
				cin.ignore(1);

			} while (ch != 'N' && ch != 'n');
		}
		else if (ch == '2') // Patient wants to update his/her password
		{
			do
			{
				cout << "Enter Your New Password\n(Password must be 8 characters long and the use of a minimum of one special character,\nuppercase, lowercase, and the numeric digit): ";

				string TempStr;
				getline(cin, TempStr);
				strcpy_s(Password, TempStr.c_str());
				if (Password_verification(Password) == false)
				{
					cout << "Invalid Password or it is already in use" << endl;
				}

			} while (Password_verification(Password) == false);

			update_Password(cnic, Password);
		}

		cout << "Do you want to Logout? (y/n)" << endl;
		cin >> ch;
		cin.ignore(1);

	} while (ch != 'Y' && ch != 'y');
}

bool Patient::CNIC_verification(char* C)
{
	if (strlen(C) < 13 || strlen(C) > 13) // size for cnic verification
	{
		return false;
	}

	for (int i = 0; i < 13; i++) // check if it is only integers
	{
		if (C[i] > '9' || C[i] < '0')
		{
			return false;
		}
	}

	{
		Patient obj;
		ifstream fin("Patient.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = CNIC;
			string temp2 = obj.CNIC;
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	{
		Doctor obj;
		ifstream fin("Doctor.dat", ios::binary); // check to see that cnic/username etc is not being reused from Doctor
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = CNIC;
			string temp2 = obj.getCNIC();
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	return true;
}

bool Patient::Name_verification(char* N)
{
	if (strlen(N) > 49)
	{
		return false;
	}

	for (int i = 0; i < strlen(N); i++)
	{
		if (!((N[i] >= 'A' && N[i] <= 'Z') || (N[i] >= 'a' && N[i] <= 'z') || N[i] == ' '))
		{
			return false;
		}
	}

	return true;
}

bool Patient::E_Mail_verification(char* E)
{
	if (strlen(E) > 49)
	{
		return false;
	}

	{
		Patient obj;
		ifstream fin("Patient.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = E_Mail;
			string temp2 = obj.E_Mail;
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	{
		Doctor obj;
		ifstream fin("Doctor.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = E_Mail;
			string temp2 = obj.getE_Mail();
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	return true;
}

bool Patient::UserName_verification(char* U)
{
	if (strlen(U) > 49)
	{
		return false;
	}

	{
		Patient obj;
		ifstream fin("Patient.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = UserName;
			string temp2 = obj.getUserName();
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	{
		Doctor obj;
		ifstream fin("Doctor.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			string temp1 = UserName;
			string temp2 = obj.getUserName();
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	return true;
}

bool Patient::Password_verification(char* P)
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;

	if (strlen(P) < 8 || strlen(P) > 49)
	{
		return false;
	}

	for (int i = 0; i < strlen(P); i++)
	{
		if (P[i] >= '0' && P[i] <= '9')
		{
			flag1 = true;
		}
		if (P[i] >= 'a' && P[i] <= 'z')
		{
			flag2 = true;
		}
		if (P[i] >= 'A' && P[i] <= 'Z')
		{
			flag3 = true;
		}
		if ((P[i] >= 33 && P[i] <= 47) || (P[i] >= 58 && P[i] <= 64) || (P[i] >= 91 && P[i] <= 96) || (P[i] >= 123 && P[i] <= 126))
		{
			flag4 = true;
		}
	}

	if (flag1 == false || flag2 == false || flag3 == false || flag4 == false)
	{
		return false;
	}

	return true;
}

void Patient::write_Patient(Patient obj) // file handling write function
{
	ofstream fout("Patient.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Patient::update_Password(char* cnic, string Password) // file handling update function
{
	fstream f("Patient.dat", ios::in | ios::out | ios::binary);

	Patient obj;

	while (f.read((char*)&obj, sizeof(obj)))
	{
		string temp1 = obj.CNIC;
		string temp2 = cnic;
		if (temp1 == temp2)
		{
			strcpy_s(obj.Password, Password.c_str());

			int a = f.tellg();
			int size = sizeof(obj);
			f.seekp(a - size);
			f.write((char*)&obj, size);
			break;
		}
	}
	f.close();
}

void Patient::read()
{
	Patient obj;
	ifstream fin("Patient.dat", ios::binary);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		obj.Display();
	}

	fin.close();
}

void Patient::Display() // display function which is called in read() function
{
	cout << endl;
	cout << "Username: " << endl;
	cout << UserName << endl << endl;
	cout << "Password: " << endl;
	cout << Password << endl << endl;
	cout << "CNIC: " << endl;
	cout << CNIC << endl << endl;
	cout << "email: " << endl;
	cout << E_Mail << endl << endl;
	cout << "Balance:" << endl;
	cout << Balance << " pkr" << endl << endl;
	cout << endl << endl;
}



