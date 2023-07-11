#include <iostream>
#include <fstream>
#include "string"
using namespace std;

class Donor
{
protected:
	string name;
	string bloodGroup;
	char sex;
	unsigned long cellNo;
	string city;
	string country;
public:
	Donor()
	{

	}
	void login(int& present);
	void show(int& present);
	void update(Donor donor[], int& present);
	string show_DBloodGroup();
	string show_DCity();
};

void Donor::login(int& present) 
{
	{
		cout << present + 1 << " --- Please Enter Name : ";
		cin.ignore();
		getline(cin, name);
		cout << endl;

	h:
		cout << present + 1 << " --- Please Enter SEX (m/f) : ";
		cin >> sex;
		if (sex != 'm' && sex != 'f' && sex != 'M' && sex != 'F')
		{
			cout << "Please Enter the Right One " << endl;
			goto h;
		}
		else
			cout << endl;

		cout << present + 1 << " --- Please Enter Blood Group (like AB+) : ";
		cin.ignore();
		getline(cin, bloodGroup);
		cout << endl;

		cout << present + 1 << " --- Please Enter Cell no : ";
		cin >> cellNo;
		cout << endl;

		cout << present + 1 << " --- Please Enter Residential City : ";
		cin.ignore();
		getline(cin, city);
		cout << endl;

		cout << present + 1 << " --- Please Enter Country : ";
		cin.ignore();
		getline(cin, country);

		cout << endl << endl;

		ofstream donor_data("donor_data.txt", ios::trunc);
		donor_data << name << ' ' << bloodGroup << ' ' << sex << ' ' << cellNo << ' ' << city << ' ' << country << endl;
		donor_data.close();

		present++;
		system("cls");
	}

}

void Donor::show(int& present) 
{

		for (int i = 0; i < present; ++i)
		{
			cout << " --- This Is Donor # " << present + 1 << " Name : " << name << endl;
			cout << " --- This Is Donor # " << present + 1 << " Blood Group : " << bloodGroup << endl;
			cout << " --- This Is Donor # " << present + 1 << " SEX : " << sex << endl;
			cout << " --- This Is Donor # " << present + 1 << " Cell No : " << cellNo << endl;
			cout << " --- This Is Donor # " << present + 1 << " City : " << city << endl;
			cout << " --- This Is Donor # " << present + 1 << " Country : " << country << endl << endl << endl;
		}
}

void Donor::update(Donor donor[],int& present)
{
	ifstream donor_data("donor_data.txt");
	donor_data >> name >> bloodGroup >> sex >> cellNo >> city >> country;
	donor_data.close();

	int z;
	cout << "Enter The Cell No OF Donor Who Want to UPDATE : ";
	cin >> z;
	cout << endl;

	for (int i = 0; i < present; i++)
	{
		if (z == donor[i].cellNo)
		{
			cout << "Please Enter The New Name : ";
			cin.ignore();
			getline(cin, donor[i].name);

			cout << "Please Enter The New blood Group : ";
			cin >> donor[i].bloodGroup;

		g:
			cout << "Please Enter The New sex : ";
			cin >> donor[i].sex;
			if (sex != 'm' && sex != 'f' && sex != 'M' && sex != 'F')
			{
				cout << "Please Enter the Right One " << endl;
				goto g;
			}

			else
				cout << endl;

			cout << "Please Enter The New Cell No : ";
			cin >> donor[i].cellNo;

			cout << "Please Enter The New City : ";
			cin.ignore();
			getline(cin, donor[i].city);

			cout << "Please Enter The New Country : ";
			cin.ignore();
			getline(cin, donor[i].country);

			cout << endl << endl;

			system("cls");
		}
		else
			cout << "Warning --> No Donor Exist On This Cell No " << endl;
		cout << "Please Re-Enter The Correct Cell No ";
	}
}

string Donor::show_DBloodGroup()
{
	return bloodGroup;
}
string Donor::show_DCity()
{
	return city;
}

class Admin :public Donor
{
private:
	string password;

public:
	Admin()
	{

	}
	void setData(string name)
	{
		this->name = name;
	}
	void setPassowrd(string password)
	{
		this->password = password;
	}

	void showName()
	{
		cout << "\nAdmin Name : " << name << endl << endl;
	}
	int pass()
	{
	back:
		string pass;
		cout << "Please Enter Your Password : ";
		cin >> pass;
		cout << endl;
		if (pass == "123")
		{
			return 1;
		}
		else {
			cout << "Please Re-enter Right Password " << endl;
			goto back;
		}
	}
	void update(Donor donor[], int& present)
	{
		donor->update(donor, present);
		system("cls");
	}
	void insert(Donor donor[], int& present)
	{
		donor->login(present);
		system("cls");
	}
	void display(Donor donor[], int& present)
	{
		donor->show(present);
	}
};

class Accepter :public Donor
{
public:
	Accepter()
	{

	}
	string show_BloodGroup()
	{
		return bloodGroup;
	}
	string show_ACity()
	{
		return city;
	}
	void login()
	{
		cout << "please enter your name : " << endl;
		cin.ignore();
		getline(cin, name);

		cout << "please enter your blood group : " << endl;
		cin.ignore();
		getline(cin, bloodGroup);

		cout << "please enter your city :" << endl;
		cin.ignore();
		getline(cin, city);

		cout << "Please enter your country :" << endl;
		cin.ignore();
		getline(cin, country);

		system("cls");
	}
	void show()
	{
		cout << "This is your name : " << name << endl;
		cout << "This is your blood group : " << bloodGroup << endl;
		cout << "This is your city : " << city << endl;
		cout << "This is your country : " << country << endl;
	}
	void search(Accepter accepter[], Donor donor[], int& present)
	{

		if (accepter->show_BloodGroup() == donor->show_DBloodGroup() && accepter->show_ACity() == donor->show_DCity())
		{
			donor->show(present);
		}
		else
			cout << "No Match Found!";
	}

};

int main()
{
	Admin admin;
	Donor donor[50];
	Accepter accepter[50];

	int present = 0;

	while (true)
	{
		int value;

		cout << "\n\n   ----------------------------------  \n\n" << endl;
		cout << "             --->If You Are Admin --- Press 1 : " << endl;
		cout << "             --->If You Are A Donor --- Press 2 : " << endl;
		cout << "             --->If You Are A Accepter --- Press 3 : " << endl << endl;
		cout << "             --->Choose An Option : ";
		cin >> value;

		switch (value)
		{
		case 1:
			admin.setData("HANZALA SALEEM");
			admin.showName();
			admin.setPassowrd("123");
			admin.pass();

			int b;
			cout << "    --->If You Want To Insert A Donor --- Press 1" << endl;
			cout << "    --->If You Want To Display Donor --- Press 2" << endl;
			cout << "    --->If You Want To Update A Donor --- Press 3" << endl;
			cout << "    --->Choose An Option : ";
			cin >> b;

			switch (b)
			{
				case 1:
					admin.insert(donor, present);
					continue;//break jumped to next switch but continue shift back to main menu
				case 2:
					admin.display(donor, present);
					continue;
				case 3:
					admin.update(donor, present);
					continue;
				default:
					cout << " Please Enter The Right Option " << endl;
			}
		case 2:
			int a;
			cout << "    --->If You Want To Log-in Yourself --- Press 1" << endl;
			cout << "    --->If You Want To Display Your Data --- Press 2" << endl;
			cout << "    --->If You Want To Update Yourself --- Press 3" << endl << endl;
			cout << "    --->Choose An Option : ";
			cin >> a;
			switch (a)
			{
				case 1:
					donor->login(present);
					continue;
				case 2:
					donor->show(present);
					continue;
				case 3:
					donor->update(donor, present);
					continue;

				default:
						cout << " Please Enter The Right Option " << endl;
			}
		case 3:
			int c;
			cout << "    --->If You Want To Log In Yourself As Accepter --- Press 1" << endl;
			cout << "    --->If You Want To Search A donor --- press 2" << endl << endl;
			cout << "    --->Choose An Option : ";
			cin >> c;
			switch (c)
			{
				case 1:
					accepter->login();
					continue;
				case 2:
					accepter->search(accepter, donor, present);
					continue;
				default:
					cout << " Please Enter The Right Option " << endl;
			}
		default:
			cout << "Please Enter Right Option" << endl;
		}
	}
	return 0;
}