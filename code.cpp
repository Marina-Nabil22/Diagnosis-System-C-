#include<iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
using namespace std;
void return_to_docters_menu();
void menu_options_for_doctors();
void menu_options_for_patient();
void add_diseases();
void add_symbtome();
void El_patient();
void clear_diagnosis_history();
void diseases_decleration();
void number_of_patients();
void view_diagnosis_history();
void display_symptomps();
void display_diseasename();
void  display_patients_dignosed();
void choise();
void Login();
void Registration();
int x;
int main();
#define size 5
struct acc
{
	string username;
	string password;
};
struct patient
{
	acc acount;
	string account;
	int age;
	bool gender;

}Patient[10];
struct disease_history
{
	string disease_title;
	int ID;

} diseasehistory[5];

struct disease
{
	string title;
	int id;            //index of disease;
	string general_info;
	string symptome[size];
	int n_patient;    // fatma
	int count[100];
	int number_of_patiant = 0;
	string name_of_patient_digonsed[5];
	string name_of_patients[5];
	string history[20];
	int barcode;
} dis[5];

struct Doctor
{
	string fullname;
	acc acount;

}doctor[10];


void usernames_passwords()
{

	doctor[0].acount.username = "Marina";
	doctor[0].acount.password = "12345";
	doctor[1].acount.username = "Latifa";
	doctor[1].acount.password = "54321";
	doctor[2].acount.username = "Ayat";
	doctor[2].acount.password = "67890";

	Patient[0].acount.username = "AbdElrahman";
	Patient[0].acount.password = "1234";
	Patient[1].acount.username = "Fatma";
	Patient[1].acount.password = "55662";
	Patient[2].acount.username = "Lojain";
	Patient[2].acount.password = "99884";
}
void Registration()
{
	system("cls");
	usernames_passwords();
	bool flag = false;
	char rig;
	char get;
	cout << "\n\n\n\t\t*To rigester as a doctor enter ( D||d ) \ as a patient enter (	P||p ):* \n";
	cin >> rig;
	switch (rig)
	{
	case 'd':
	case 'D':

		cin.ignore();

		system("cls");
		cout << " Username : \n";
		for (int i = 0; i < 10; i++)
		{
			if (doctor[i].acount.username == "")
			{
				getline(cin, doctor[i].acount.username);
				flag = true;
				break;
			}
		}
		cout << " Password : \n";
		for (int i = 0; i < 10; i++)
		{
			if (doctor[i].acount.password == "")
			{
				getline(cin, doctor[i].acount.password);
				break;
			}
		}
		cout << "\t\t\tyour register is successful\n";
		break;

	case 'p':
	case 'P':
		cin.ignore();
		system("cls");
		cout << " Username : \n";
		for (int i = 0; i < 10; i++)
		{
			if (Patient[i].acount.username == "")
			{
				getline(cin, Patient[i].acount.username);
				flag = true;
				break;
			}
		}
		cout << " Password : \n";
		for (int i = 0; i < 10; i++)
		{
			if (Patient[i].acount.password == "")
			{
				getline(cin, Patient[i].acount.password);
				break;
			}
		}
		cout << "REGISTRETION IS SUCCESSFUL \n THANK YOU\n ";
	}
	cout << "If you want to login press (C|c)\n";
	cin >> get;
	switch (get)
	{
	case'c':
	case 'C':
		Login();
		break;

	default:
		break;

	}
}
void Login()
{

	usernames_passwords();
	bool success = false, success2 = false;
	int log = 0;
	string username, password;
	system("cls");
	cin.ignore();
	cout << "\t\tplease enter the username and password\n";

	cout << "\t UserName:        \n";

	getline(cin, username);

	cout << "\t PassWord:        \n";

	getline(cin, password);

	for (int j = 0; j < 10; j++)
	{
		if (username == doctor[j].acount.username && password == doctor[j].acount.password)
		{
			success = true;
			log = 1;
			break;
		}
	}
	for (int j = 0; j < 10; j++)
	{
		if (username == Patient[j].acount.username && password == Patient[j].acount.password)
		{
			success2 = true;
			log = 1;
			break;
		}
	}

	if (log == 0)
	{
		cout << "try again to enter right username and password \n\n";
		main();

	}
	if (success == true)
	{
		system("cls");
		menu_options_for_doctors();
	}
	if (success2 == true)
	{
		system("cls");
		El_patient();

		menu_options_for_patient();
	}


};

void El_patient()
{

	system("cls");
	const int a = 1;

	cout << " \t\t\t * Patient Entry * \t\t\t";
	for (int i = 0; i < a; i++)
	{
		cout << "\nName: " << endl;
		cin >> Patient[i].acount.username;
		cout << "\nAccount:";
		cin >> Patient[i].account;
		cout << "\nAge:";
		cin >> Patient[i].age;
		cout << "\nGender(f/m):";
		char gender;
		cin >> gender;
		if (gender == 'f' || gender == 'F')
		{
			cout << "female\n";
		}
		else if (gender == 'm' || gender == 'M')
		{
			cout << "male\n";
		}
		else
			cout << "Please enter correct character\n";

		
	}
}
void menu_options_for_patient()
{
	int c;
	cout << " \t\t\t\t\t WELCOME ,DEAR " << endl;
	cout << "\t\t\t\tTHIS MENUE SHOW ALL OPTIONS YOU CAN SELECT " << endl;
	cout << "\t\t\t\t***" << endl;
	cout << "\t\t\t\t\t MENU OF patients OPTIONS" << endl;
	cout << "\t\t\t\t***" << endl;
	cout << "\t\t\t PRESS| 1 | IF YOU WANT TO FIND OUT YOUR DISEASE BASED ON YOUR SYMPTOMES" << endl;
	cout << "\t\t\t PRESS |2|IF YOU WANT TO DISPLAY SYMPTOMES FOR A CERTAIN DISEASE " << endl;
	cout << "\t\t\t PRESS|3|IF YOU WANT TO SEE THE PATIENTS DIAGNOSED" << endl;
	cout << "\t\t\t PRESS|4|IF YOU WANT TO SEE NUMBER OF PAIENTS " << endl;
	cout << "\t\t\t press|5| IF YOU WANT TO SEE THE DIAGNOSIS HISTORY OF A DISEASE" << endl;
	cout << "\t\t\t press|6| IF YOU WANT TO CLEAR THE DIAGNOSIS HISTORY OF A DISEASE" << endl;
	cout << "\t\t\t Enter YOUR CHOICE PLEASE " << endl;
	cout << "\t\t\t *THE ID OF DISEASE FLU IS 0 *" << endl;
	cout << "\t\t\t *THE ID OF DISEASE HEPATITIS C IS 1 *" << endl;
	cout << "\t\t\t *THE ID OF DISEASE COVID_19 IS 2 *" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		display_diseasename();
		break;
	case 2:
		display_symptomps();
		break;
	case 3:
		display_patients_dignosed();
		break;
	case 4:
		number_of_patients();
		break;
	case 5:
		view_diagnosis_history();
		break;
	case 6:
		clear_diagnosis_history();
		break;
	default:
		cout << "ERROR" << endl;
	}
}

void diseases_decleration()
{
	dis[0].title = "flu";
	dis[1].title = "Hepatitis C";
	dis[2].title = "covid_19";


	dis[0].id = 0;
	dis[1].id = 1;
	dis[2].id = 2;

	dis[0].barcode = 000;
	dis[1].barcode = 111;
	dis[2].barcode = 222;

	dis[0].general_info = "Influenza (flu) is a contagious respiratory illness caused by influenza viruses that infect the nose, throat, and lungs. Some people,";
	dis[1].general_info = "Hepatitis C is a liver infection caused by the hepatitis C virus (HCV). Hepatitis C is spread through contact with blood from an infected person. ";
	dis[2].general_info = "Coronavirus disease 2019 (COVID-19) is a contagious disease caused by a virus, the severe acute respiratory syndrome coronavirus 2 (SARS-CoV-2). The first known case was identified in Wuhan, China, in December 2019.[7] The disease has since spread worldwide, leading to the ongoing COVID-19 pandemic.[8]";

	dis[0].symptome[0] = "fever* or feeling feverish/chills";
	dis[0].symptome[1] = "sore throat";
	dis[0].symptome[2] = "cough";                                   //flu
	dis[0].symptome[3] = "runny or stuffy nose";
	dis[0].name_of_patients[0] = "latifa";
	dis[0].name_of_patients[1] = "marina";
	dis[0].name_of_patients[2] = "logine";

	dis[1].symptome[1] = "blending .";
	dis[1].symptome[2] = "Yellow discoloration of the skin and eyes (jaundice).";  //Hepatitis C
	dis[1].symptome[3] = "Dark colored urine.";
	dis[1].name_of_patients[0] = "abdelrahman";
	dis[1].name_of_patients[1] = "ayat";
	dis[1].name_of_patients[2] = "fatma";

	dis[2].symptome[0] = "loss of smell and loss of taste";
	dis[2].symptome[1] = "headaches";                      //covid_19
	dis[2].symptome[2] = "shortness of breath";
	dis[2].symptome[3] = "runny nose";

	dis[2].name_of_patients[0] = "mabrook";
	dis[2].name_of_patients[1] = "habiba";
	dis[2].name_of_patients[2] = "mahmoud";


}
void display_diseasename()
{
	system("cls");
	string name;
	cin.ignore();
	bool cts = true, stop = true, search = true;
	int flag = 0, p[100];
	diseases_decleration();
	string symp_name[5];
	cout << "enter the symptomps you have\n";
	for (int a = 0; a < 5; a++)
	{
		getline(cin, symp_name[a]);
		if (symp_name[a] == "") { symp_name[a] = "jdgkakhfladksd"; }
	}
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (symp_name[z] == dis[j].symptome[i])
				{
					dis[j].count[j]++;
					p[j] = dis[j].count[j] * 20;

				}
			}
		}
	}
	for (int j = 0; j < 10; j++)
	{
		if (p[j] >= 60)
		{
			for (int z = j + 1; z < 10; z++)
			{
				if (p[z] >= 60)
				{
					cout << "you might have\t" << dis[j].title << "\tor\t" << dis[z].title << "\nyou should go to the doctor";
					stop = false;
					cts = false;
					flag = 1;

					break;
				}
			}
		}
	}

	while (stop)
	{
		for (int j = 0; j < 10; j++)
		{
			if (p[j] >= 60)
			{
				cout << "Enter diagnosis history\n";
				for (int i = 0; i < 20; i++)
				{
					getline(cin, dis[j].history[j]);
					break;
				}
				cout << "the disease you got is " << dis[j].title << endl;
				cts = false;
				flag = 1;
				stop = false;
				cout << "THE GENERAL INFO :" << dis[j].general_info << endl;
				dis[j].number_of_patiant++;
				cout << "ENTER YOUR NAME PLEASE" << endl;
				for (int i = 0; i < 5; i++)
				{
					if (dis[j].name_of_patients[i] == "")
					{
						getline(cin, name);
						dis[j].name_of_patients[i] = name;
						break;
					}
				}
			}
			stop = false;
		}
	}

	if (cts)
	{
		for (int j = 0; j < 10; j++)
		{
			if (p[j] > 0)
			{
				flag = 1;
				cout << "the symptomes you have inserted matches " << dis[j].title << "\t" << "with" << "\t" << p[j] << "%\n " << endl;

			}

		}

	}
	if (flag == 0) { cout << "there is no matched disease"; }
	menu_options_for_patient();
}

void display_symptomps()
{
	diseases_decleration();
	string dis_name;
	int x = 0;
	cout << "enter disease name\n";
	cin >> dis_name;
	for (int i = 0; i < 3; i++)
	{
		if (dis[i].title == dis_name)
		{
			x = 1;
			for (int j = 0; j < 5; j++)
			{
				cout << dis[i].symptome[j] << "\t";
			}
		}
	}
	if (x == 0) { cout << "there is no matched disease"; }
}
void view_diagnosis_history()
{
	cout << "the history is\n\t\t";
	for (int j = 0; j < 5; j++)
	{
		if (dis[j].history[j] != "")
		{
			cout << "the history of the disease  " << dis[j].title << "is" << endl;
			cout << dis[j].history[j] << endl;
		}
	}
	menu_options_for_patient();
}

void clear_diagnosis_history()
{
	diseases_decleration();
	int  ID, get = 0;
	char w;
	string histo;
	int count = 20;
	cout << "enter id of a disease you want to remove its history ";
	cin >> ID;
	cout << "enter the history of disease which want to remove";
	cin.ignore();
	getline(cin, histo);

	for (int i = 0; i < count; i++)
	{
		for (int position = i; position < count - 1; position++)
		{
			dis[ID].history[position] = dis[ID].history[position + 1];
		}
		get++;

		i--;

		count--;

	}
	if (get == 0)
		cout << "THIS HISTORY ISNOT FOUND" << endl;
	else
		cout << "THIS HHISTORY DELETED Successfully!" << endl;
	cout << endl;
	cout << "IF YOU WANT TO SEE THE HISTORY PRESS W " << endl;  //WANT
	cin >> w;
	cin.ignore();
	switch (w)
	{
	case 'w':
	case 'W':
		for (int j = 0; j < 20; j++)
		{
			cout << dis[j].history[j] << endl;
		}
		break;
	default:
		cout << " PLEASE ENTER CORRECT CHOICE" << endl;
	}
	menu_options_for_patient();
}
void display_patients_dignosed()
{
	diseases_decleration();
	int id;
	cout << " ENTER ID OF THE DISEASE YOU WANT TO SEE PATIENTS DIAGONESD BY THIS DISEASE  " << endl;
	cin >> id;
	for (int i = 0; i < 5; i++)
	{
		cout << dis[id].name_of_patients[i] << endl;
	}
	menu_options_for_patient();

}
void number_of_patients()
{
	int id;
	cout << "ENTER THE ID OF DISEASE YOU WANT  " << endl;
	cin >> id;
	cout << "THE NUMBER OF PATIENTS digonosed by THIS DISEASE ARE :" << dis[id].number_of_patiant << endl;
	menu_options_for_patient();
}
int barcode;
void add_diseases()
{

	int  id;
	cout << "ENTER THE ID OF THE DISEASE" << endl;
	cin >> id;
	if (id > 2)
	{
		dis[id].id = id;
		cout << "ENTER THE CODE OF THE DISEASE" << endl;
		cin >> barcode;
		dis[id].barcode = barcode;
		cin.ignore();
		cout << "\t\t Enter Title DISEASE\n ";
		getline(cin, dis[id].title);
		cout << "\t\t Enter General Info OF DISEASE  \n ";
		getline(cin, dis[id].general_info);
		cout << "\t\t Enter symptome of DISEASE  \n ";
		for (int j = 0; j < 4; j++)
		{
			getline(cin, dis[id].symptome[j]);
		}

		cout << "\t\t\t\tENTER NEXT DISEASE" << endl;
		system("cls");
		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t THANK YOU " << endl;
		cout << "THIS OPERATION COMPLETED SUCCESSFULLY" << endl;
		diseases_decleration();
		return_to_docters_menu();
	}
	else
		cout << "THIS DISEASE ALREADY EXIST" << endl;
}
void add_symbtome()
{

	diseases_decleration();
	int id;
	char c2;
	cout << "ENTER THE ID OF DESEASE " << endl;
	cin >> id;
	cout << "ENTER THE BARCODE" << endl;
	cin >> barcode;
	cin.ignore();
	if (dis[id].barcode == barcode)
	{
		cout << "ENTERE THE SYMPTOME YOU WANT TO ADD" << endl;
		getline(cin, dis[id].symptome[4]);
		cout << "THIS OPERATION COMPLETED SUCCESSFULLY" << endl;
		cout << "IF YOU WANT TO SEE THE SYMPTOMES PRESS Y" << endl;
		cin >> c2;
		if (c2 == 'y' || c2 == 'Y')
		{
			for (int i = 0; i < 5; i++)
			{
				cout << dis[id].symptome[i] << endl;
			}
		}
		else
			cout << "PLEASE ENTER CORRECT CHOICE " << endl;
	}
	else
		cout << "YOU CANT ADD SYMPTOME PLEASE ENTER CORRECT CODE" << endl;
	menu_options_for_doctors();
}
void return_to_docters_menu()
{
	char c3;
	cout << "ENTER Y IF YOU WANT TO RETURN TO MENUE" << endl;
	cin >> c3;
	switch (c3)
	{
	case 'y':
	case 'Y':
		menu_options_for_doctors();
		break;
	default:
		cout << "\t\t\t\tTHANK YOU" << endl;
		cout << "\t\t\t\tGOOD BYE" << endl;
	}
}

void remove_symptome()
{
	diseases_decleration();
	int id;
	int total = 5;
	int found = 0;
	char b;
	string symptome;
	cout << "PLEASE ENTER ID OF DISEASE" << endl;
	cin >> id;

	cout << "PLEASE ENTER code OF DISEASE" << endl;
	cin >> barcode;
	if (dis[id].barcode == barcode)
	{
		cout << "ENTER THE SYMPTOME YOU WANT TO REMOVE" << endl;

		cin.ignore();
		getline(cin, symptome);

		for (int j = 0; j < total; j++)                    //
		{
			if (dis[id].symptome[j] == symptome)          //
			{
				for (int s = j; s < (total - 1); s++)      // googleبتاعه function  في ال الي موجوده sهو ال j 
					dis[id].symptome[s] = dis[id].symptome[s + 1];

				found++;
				j--;
				total--;
			}

		}
		if (found == 0)
			cout << "THIS SYMPTOME DOSNOT EXIST !" << endl;
		else
			cout << "THIS SYMPTOME DELETED Successfully!" << endl;
		cout << endl;
		cout << "IF YOU WANT TO SEE SYMPTOME PRESS Y" << endl;
		cin >> b;
		cin.ignore();
		switch (b)
		{
		case 'y':
		case 'Y':
			for (int j = 0; j < 5; j++)
			{
				cout << dis[id].symptome[j] << endl;
			}
			break;
		default:
			cout << " PLEASE ENTER CORRECT CHOICE" << endl;
		}
	}
	else
		cout << "ENTER CORRECT CODE PLEASE" << endl;
	return_to_docters_menu();
}
void remove_disease()
{
	diseases_decleration();
	int id;
	int total = 5;
	int found = 0;
	cout << "ENTER THE ID OF DISEASE YOU WANT TO REMOVE" << endl;
	cin >> id;
	cout << "PLEASE ENTER code OF DISEASE" << endl;
	cin >> barcode;
	if (dis[id].barcode == barcode)
	{
		if (id > 0)
		{
			for (int i = 0; i < total; i++)
			{
				if (dis[i].id == id)
				{
					for (int j = i; j < (total - 1); j++)
					{
						dis[i].title = dis[i + 1].title;
						dis[i].id = dis[i + 1].id;
						dis[i].general_info = dis[i + 1].general_info;
						for (int j = 0; j < 5; j++)
						{
							dis[i].symptome[j] = dis[i + 1].symptome[j + 1];
						}
					}
					found++;
					i--;
					total--;
				}
			}
			if (found == 0)
				cout << "THIS DISEASE DOSNOT EXIST !" << endl;
			else
				cout << "THIS DISEASE DELETED Successfully!" << endl;
			cout << endl;
		}
	}
	else
		cout << "ENTER CORRECT CODE PLEASE" << endl;

	return_to_docters_menu();
}
void display_diseases()
{
	diseases_decleration();
	//int c3;
	for (int i = 0; i < 5; i++)
	{
		cout << " TITLE IS :";
		cout << dis[i].title << endl;
		cout << endl;
		cout << "ID OF THE THIS DISEASE :";
		cout << dis[i].id << endl;
		cout << endl;
		cout << "GENERAL ENFO OF THIS DISEASE:";
		cout << dis[i].general_info << endl;
		cout << endl;
		cout << " SOME SYMPTOMES OF THIS DISEASE :" << endl;
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << j + 1 << ":" << dis[i].symptome[j] << endl;
		}
		cout << "\t\t\t======================================================================" << endl << endl;
	}
	cout << endl;
	cout << "THIS OPERATION COMPLETED SUCCESSFULLY" << endl;

	return_to_docters_menu();
}

void menu_options_for_doctors()
{
	int c;
	cout << " \t\t\t\t\t WELCOME ,DEAR " << endl;
	cout << "\t\t\t\tTHIS MENUE SHOW ALL OPTIONS YOU CAN SELECT " << endl;
	cout << "\t\t\t\t***" << endl;
	cout << "\t\t\t\t\t MENU OF DOCTORS OPTIONS" << endl;
	cout << "\t\t\t\t***" << endl;
	cout << "\t\t\t PRESS| 7 |IF YOU WANT TO ADD DISEASEES" << endl;
	cout << "\t\t\t PRESS| 8 |IF YOU WANT REMOVE DISEASES" << endl;
	cout << "\t\t\t PRESS| 9 |IF YOU WANT ADD SYMPTOME TO ANY STORE DISEASE" << endl;
	cout << "\t\t\t PRESS| 10 |IF YOU WANT DISPLAY THE DISESSES" << endl;
	cout << "\t\t\t PRESS| 11|IF YOU WANT TO REMOVE SYMPTOME" << endl;
	cout << "\t\t\t PRESS| 12|IF YOU WANT TO SEE THE PATIENTS DIAGNOSED" << endl;

	cout << "\t\t\t Enter YOUR CHOICE PLEASE " << endl;
	cin >> c;
	switch (c)
	{
	case 7:
		add_diseases(); break;
	case 8:
		remove_disease();
		break;
	case 9:
		add_symbtome();
		break;
	case 10:
		display_diseases();
		break;
	case 11:
		remove_symptome();
		break;
	case 12:
		display_patients_dignosed();
		break;
	default:
		cout << "ERROR" << endl;
	}
}
void choise()
{
	cout << "\t\t\t=======================================================\n\n";
	cout << "\t\t\t                        Welcome                   \n\n";
	cout << "\t\t\t=======================================================\n\n";
	int x;
	cout << "\t        press 1 to Login.\n";
	cout << "\t        press 2 to Registr.\n";
	cin >> x;
	switch (x)
	{
	case 1:
		Login();
		break;
	case 2:
		Registration();

		break;
	default:
		break;
	}
}
int main()
{
	choise();
}
