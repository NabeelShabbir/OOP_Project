#include "Doctor.h"

void Doctor::Register()
{
	system("CLS");
	do
	{
		cout << "Enter Your CNIC(1111122222223): ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(CNIC, TempStr.c_str());
		if (CNIC_verification(CNIC) == false)
		{
			cout << "Invalid CNIC or This CNIC is already registered" << endl;
		}

	} while (CNIC_verification(CNIC) == false);

	do
	{
		cout << "Enter Your Name: ";
		string TempStr;
		getline(cin, TempStr);
		strcpy_s(Name, TempStr.c_str());

		if (Name_verification(Name) == false)
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
		if (E_Mail_verification(E_Mail) == false)
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
		if (UserName_verification(E_Mail) == false)
		{
			cout << "Invalid UserName or it is already in use" << endl;
		}

	} while (UserName_verification(E_Mail) == false);

	do
	{
		cout << "Enter Your Password(Password must be 8 characters long and the use of a minimum of one special character, uppercase, lowercase, and the numeric digit): ";

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

	cout << "How many years of experience do you have?" << endl;
	cout << "Enter experience in years: ";
	cin >> Years_Of_Experience;

	cout << "What Hospital/Clinic Do you work at?" << endl;
	cout << "Enter name of the Hospital/Clinic: ";
	cin.ignore(1);
	string TempStr;
	getline(cin, TempStr);
	strcpy_s(HospitalOrClinic_Name, TempStr.c_str());

	cout << "What Location Do you work at?" << endl;
	cout << "Enter name of the Location: ";
	TempStr;
	getline(cin, TempStr);
	strcpy_s(Location, TempStr.c_str());

	cout << "What do you specialise in?\n1. Gynecology\n2. Dermatology\n3. Oncology\n4. Orthopedics\nEnter corresponding number: " << endl;
	do
	{
		cin >> Speciality;
	} while (!(Speciality >= 1 && Speciality <= 4));

	write_Doctor(*this);
}

string Doctor::Login()
{
	bool flag = false;
	char ch = 0;
	string temp1;
	Doctor obj;

	system("CLS");

	do
	{
		cout << "Enter your Username: ";
		getline(cin, temp1);

		ifstream fin("Doctor.dat", ios::binary);
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

void Doctor::Menu(char* cnic)
{
	int Day;
	int Time;
	char ch = 0;

	do
	{
		system("CLS");
		cout << "Do you want to:\n1. Update Availibility\n2. Update Password\n" << endl;
		cin >> ch;
		cin.ignore(1);
		if (ch == '1')
		{
			do
			{
				system("CLS");
				cout << "At what days are you available: " << endl;
				cout << "1. Monday\n2. Tuesday\n3. Wednesday\n 4. Thursday\n5. Friday\n6. Saturday\n 7. Sunday" << endl;
				cout << "Enter corresponding number: ";
				cin >> Day;

				cout << "At what time of that day are you availaible: " << endl;
				cout << "0. 00:00 - 01:00 \n1. 01:00 - 02:00 \n 3. 03:00 - 04:00 \n.\n.\n.\n23. 23:00 - 00:00" << endl;
				cout << "Enter corresponding number: ";
				cin >> Time;

				Availibility[Day - 1][Time] = true; // Availibility is stored in int which tells us at what day of what time will the doctor be available

				update_Availibility(cnic, Availibility);

				cout << "Do you want to edit more availibility? (y/n)";
				cin >> ch;
				cin.ignore(1);
			} while (ch != 'N' && ch != 'n');
		}
		else if (ch == '2')
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

bool Doctor::CNIC_verification(char* C)
{
	if (strlen(C) < 13 || strlen(C) > 13)
	{
		return false;
	}

	for (int i = 0; i < 13; i++)
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
			string temp2 = obj.getCNIC();
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
			string temp1 = CNIC;
			string temp2 = obj.CNIC;
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	return true;
}

bool Doctor::Name_verification(char* N)
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

bool Doctor::E_Mail_verification(char* E)
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
			string temp2 = obj.getE_Mail();
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
			string temp2 = obj.E_Mail;
			if (temp1 == temp2)
			{
				return false;
			}
		}
		fin.close();
	}

	return true;
}

bool Doctor::UserName_verification(char* U)
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

bool Doctor::Password_verification(char* P)
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

void Doctor::write_Doctor(Doctor obj)
{
	ofstream fout("Doctor.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Doctor::update_Availibility(char* cnic, bool arr[7][24])
{
	fstream f("Doctor.dat", ios::in | ios::out | ios::binary);
	
	Doctor obj;

	while (f.read((char*)&obj, sizeof(obj)))
	{
		string temp1 = obj.CNIC;
		string temp2 = cnic;
		if (temp1 == temp2)
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 24; j++)
				{
					obj.Availibility[i][j] = arr[i][j];
				}
			}
			int a = f.tellg();
			int size = sizeof(obj);
			f.seekp(a - size);
			f.write((char*)&obj, size);
			break;
		}
	}
	f.close();
}

void Doctor::update_Password(char* cnic, string Password)
{
	fstream f("Doctor.dat", ios::in | ios::out | ios::binary);

	Doctor obj;

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

void Doctor::update_Password(string UN, string Password)
{
	fstream f("Doctor.dat", ios::in | ios::out | ios::binary);

	Doctor obj;

	while (f.read((char*)&obj, sizeof(obj)))
	{
		string temp1 = obj.CNIC;
		string temp2 = UN;
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

void Doctor::read()
{
	Doctor obj;
	ifstream fin("Doctor.dat", ios::binary);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
			obj.Display();
	}
	fin.close();
}

void Doctor::read(char C)
{
	Doctor obj;
	ifstream fin("Doctor.dat", ios::binary);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (C == obj.Speciality)
		{
			obj.Display();
		}
	}
	fin.close();
}

void Doctor::read(string S)
{
	Doctor obj;
	ifstream fin("Doctor.dat", ios::binary);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		string temp = obj.Location;
		if (S == temp)
		{
			obj.Display();
		}

		temp = obj.HospitalOrClinic_Name;
		if (S == temp)
		{
			obj.Display();
		}

	}
	fin.close();
}

void Doctor::Display()
{
	cout << endl;
	cout << "Name: " << endl;
	cout << Name << endl << endl;
	cout << "email: " << endl;
	cout << E_Mail << endl << endl;
	cout << "Speciality:" << endl;
	cout << Speciality << endl << endl;
	cout << "Years Of Experience:" << endl;
	cout << Years_Of_Experience << endl << endl;
	cout << "Location:" << endl;
	cout << Location << endl << endl;
	cout << "Hospital/Clinic:" << endl;
	cout << HospitalOrClinic_Name << endl << endl;


	cout << endl << endl << endl;
}


