
#pragma once


#ifndef AUTHSYS_H
#define AUTHSYS_H

#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>


using namespace std;

class AuthSys
{

    private:

	fstream F1;

	int i,f = 0;
	char user[25], pass1[10], pass2[10], email[50];
	char userlog[25], passlog[10];
	char emailver[20], newpass1[10], newpass2[10];
	 
	char a[100], key[12];
	size_t pos;
	string line;

	//Registered Password Verification

	void IDSetVerify()
	{
		if (strcmp(pass1, pass2) != 0)
		{
			cout << "\n\tError! Password Mismatch...";
			cout << "\n\tAccount Setup Failed. Please try Again!\n\n";
			IDSet();
		}

		else

		{
			cout << "\n\tAccount Setup Successful!\n\n";
		}
	}

	//Login Credentials Verification 

	void IDLogVerify()
	{
		char str[255];

		while (F1)
		{

			F1 >> str;  // delim defaults to '\n'
			while (F1)
			{
				for (i = 0; i <= str[i]; i++)
				{
					cout << str << endl;
						if (str == passlog)
						{
							f = 1;
								break;
						}
						else
						{
							f = 0;
								break;
						}
				}

			}

		}
	
	
	if (f == 1)
	{
		cout << "\n\n\tWelcome "<<user<<" !\n\n";
	}
	else if(f == 0)
	{
		cout << "\n\n\tIncorrect Password. \n\tTry Again...\n\n";
		IDLog();
	}

  }





    public:


	//Account Registration 

	void IDSet()
	{
		F1.open("AccData.txt", ios::out | ios::app);
		

		cout << "\n\n\t\t< ********** REGISTRATION ********** > ";

		cout << "\n\n\tEnter Username : ";
		cin >> user;

		F1 << user;

		cout << "\n\tEnter Email Address : ";
		cin >> email;

		F1 << " " << email;

		cout << "\n\tEnter Password : ";
		cin >> pass1;

		cout << "\n\tEnter Password Again : ";
		cin >> pass2;

		F1 << " " << pass1;

		IDSetVerify();

		F1.close();

	}


	//User Login 

	void IDLog()
	{
		F1.open("AccData.txt", ios::in);

		cout << "\n\n\t\t< ********** LOGIN ********** >\n";

		cout << "\n\tUsername : ";
		cin >> userlog;

		cout << "\n\tPassword : ";
		cin >> passlog;

		IDLogVerify();

		F1.close();

	}


	//Forgot Password 

	void IDRst()
	{
	L113: cout << "\n\t< ********** PASSWORD RESET ********** >";
		cout << "\n\n\tPlease enter you Email ID : ";
		cin >> emailver;

		if (strcmp(emailver, email) != 0)
		{
			cout << "\n\n\tEmail ID not found...\n\n";
			goto L113;
		}
		else
		{
		L124: cout << "\n\tUsername : " << user << endl;
			cout << "\n\tNew Password : ";
			cin >> newpass1;
			cout << "\n\tRe-Enter New Password : ";
			cin >> newpass2;

		}

		if (strcmp(newpass1, newpass2) != 0)
		{
			cout << "\n\n\tPasswords do not Match...\nPlease Re-Enter...";
			goto L124;
		}
		else
		{
			strcpy_s(pass1, newpass1);
			cout << "\n\n\tPassword Reset Successful!";
			cout << "\n\n\tUpdated Login Credentials ";
			cout << "\n\n\tUsername : " << user << "\n\tEmail : " << email << "\n\tPassword : " << pass1;
		}
	}


};

#endif /* AUTHSYS_H */





