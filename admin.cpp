// admin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//it21155352 kamesh
#include <iostream>
#include<cstring>
#define size 2
using namespace std;

class supportservice
{

private:
	char SuportID[20];
	char SuportType[20];
public:
	void setDetails(const char Sid[], const char sType[])
	{
		strcpy_s(SuportID, Sid);
		strcpy_s(SuportType, sType);
	}
	void Display()
	{
		cout << "Support service ID  :" << SuportID << endl;
		cout << "Support service  type :" << SuportType << endl;

	}
	void displayeedback();
	void DispalyInvoise();
};

class report {

private:
	char ReportID[15];
	char ReportTitale[20];
	char Reportdata[100];

public:
	void setDetails(const char id[], const char titale[])
	{
		strcpy_s(ReportID, id);
		strcpy_s(ReportTitale, titale);
	}
	void setdata(const char data[])
	{
		strcpy_s(Reportdata, data);
	}

	void displayDitalse()
	{
		cout << "ID : " << ReportID << endl;
		cout << "------" << ReportTitale << "----------" << endl << endl;
		cout << Reportdata << endl;

	}
};

class admin {

private:
	char AdminId[20];
	char AdminName[20];
	supportservice *Sservice;//aggrigation
	report *rep[size];//uni association

public:

	admin()
	{
		strcpy_s(AdminId, "");
		strcpy_s(AdminName, "");
	}
	admin(const char ID[], const char name[], supportservice *ss1)
	{
		strcpy_s(AdminId, ID);
		strcpy_s(AdminName, name);
		Sservice = ss1;
	}

	void report(report *r1, report *r2)
	{
		rep[1] = r1;
		rep[2] = r2;
	}

	void UpdateReport()
	{

	}
	void dispaly()
	{
		cout << " Admin ID : " << AdminId << endl;
		cout << " Adimn name : " << AdminName << endl;

		Sservice->Display();
	}
	void Displayreport()
	{

		rep[1]->displayDitalse();
		rep[2]->displayDitalse();
	}
};
int main()
{
	supportservice *service1;
	admin *ad;
	report *re1, *re2;

	service1->setDetails("SA1253", "complen");

	ad = new admin("fg123", "Sunile", service1);

	ad->Displayreport();

	re1->setDetails("h475", "active customer");

	//delete ad;


	return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
