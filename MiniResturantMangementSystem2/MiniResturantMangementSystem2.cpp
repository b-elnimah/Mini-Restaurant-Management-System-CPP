#include <iostream>
#include<string>
#include<fstream>
using namespace std;
char getchoice();
void showMenu();
int dataCount = 0;
string FileName = "food.txt";
void displayItems(int[], string[], double[], string[]);
void readData(int[], string[], double[], string[]);



int main()
{
	const int SIZE = 100;
	int id[SIZE];
	string foodName[SIZE];
	double price[SIZE];
	string Ing[SIZE]; // Ing for Ingredients.
	char choice;
	readData(id, foodName, price, Ing);
	do
	{
		showMenu();
		choice = getchoice();
		if (choice != 'f' && choice != 'F')
		{
			switch (choice)
			{
			case 'a':
			case 'A':
				break;
			case 'b':
			case 'B':
				break;
			case'c':
			case'C':
				break;
			case 'd':
			case'D':  displayItems(id, foodName, price, Ing);
				break;
			case'e':
			case'E':
				break;
			case'f':
			case'F':
				break;
			default: cout << "Wrong choice! please try another choice\n";//invalid input
			}
		}
	} while (choice != 'f' && choice != 'F');
	system("pause");
	return 0;
}
void readData(int id[], string foodName[], double price[], string Ing[])
{
	ifstream inFile;
	inFile.open(FileName);
	if (inFile)
	{
		while (!inFile.eof()) {

			inFile >> id[dataCount];
			getline(inFile, foodName[dataCount]);
			inFile >> price[dataCount];
			getline(inFile, Ing[dataCount]);
			dataCount++;
		}

		inFile.close();
		cout << "Data read from file successfuly\n";
	}
	else
		cout << "Error opening the file..\n";
}

void showMenu()
{
	cout << "In this system you can do any of the following tasks\n";
	cout << "a. Add a food item to the list\n";
	cout << "b. Edit food item's to the list\n";
	cout << "c. Delete the food item's record\n";
	cout << "d. Display the list of all food items\n";
	cout << "e. Prepare invoice\n";
	cout << "f. Exit\n";
	cout << "To do any of the previous functions, please enter its letter: \n";
}
char getchoice()
{
	char choice;
	cout << "Enter your choice : \n";
	cin >> choice;
	return choice;
}


void displayItems(int id[], string foodName[], double price[], string Ing[])
{
	cout << "The food selected are: " << endl;
	cout << "----------------------------------------\n";
	cout << "Item-ID\tName\t\tPrice\t\tIngredients\n";
	cout << "--------------------------------------------\n";
	for (int i = 0; i < dataCount; i++)
		cout << id[i] << "\t" << foodName[i] << " \t" << price[i] << "\t" << Ing[i] << endl;

}



