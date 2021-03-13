#include<iostream>
using namespace std;
int main()
{
	const int size = 20;
	int iban[size] = { 0 }, pyear[size] = { 0 }, edi[size] = { 0 }, pri[size] = { 0 }, quan[size] = { 0 }, i = 0, opt = 0;
	char again = 'y' , rec='y' ;

	while (again == 'y' || again == 'Y')
	{
		cout << "\n 1. Add new books to the library and show records ";
		cout << "\n 2. Delete the record ";
		cout << "\n 3. Issue a book ";
		cout << "\n 4. Recievng a book back ";
		cout << "\n 5. Sorting of the book ";
		cout << "\n 6. If you only wants to see records press y ";
		cout << " \n\n Enter your option "; cin >> opt;


		if (opt == 1)
		{
			bool check = true;
			char morbooks = 'y';
			while (morbooks == 'y' || morbooks == 'Y')
			{
				cout << endl;

				cout << "\n Enter IBAN number "; cin >> iban[i];
				cout << "\n Enetr Publishing Year "; cin >> pyear[i];
				cout << "\n Enter Edition "; cin >> edi[i];
				cout << "\n Enter Price "; cin >> pri[i];
				cout << "\n Enter Quantity "; cin >> quan[i];

				for (int j = 0; j < i; j++)
				{
					if (iban[i] == iban[j] && i != 0)
					{
						check = false;
						break;
					}
					else
						check = true;
				}
				if (check == false)
					cout << "\n IBAN number of 2 books cannot be unique. Please netr unique IBAN number. ";
				else
					i++;

				cout << "\n Do you wanter to add more books ? Press 'y; else press 'n' "; cin >> morbooks;
			}
			cout << "\n\n The DATA you stored is following ";

		}

		if (opt==1 || opt==6)
		{
			for (int j = 0; j < i; j++)
			{
				cout << endl;
				cout << "\n IBAN " << iban[j];
				cout << "\n Publishing Year " << pyear[j];
				cout << "\n Edition " << edi[j];
				cout << "\n Price " << pri[j];
				cout << "\n Quantity " << quan[j];
			}
		}
	

		cout << endl;

		if (opt == 2)
		{
			char morbooks = 'y';
			while (morbooks == 'y' || morbooks == 'Y')
			{
				bool check = true , found=true;
				int del = 0, k = 0 , newiban=0;
				cout << " \n Please enetr the IBAN number of the book you want delete from the record "; cin >> del;

				for (int j = 0; j < i; j++)
				{
					if (del == iban[j])
					{
						check = true;
						break;
					}
					else
					{
						check = false;
						k++;
					}
				}

				if (check == true)
				{
					cout << "\n Please Enter new IBAN number "; cin >> newiban;
					for (int j = 0; j < i; j++)
					{
						if (newiban == iban[j] && j != k)
						{
							found = false;
							break;
						}
						else
							found = true;
					}

					if (found == true)
					{
						iban[k] = newiban;
						cout << "\n Enetr Publishing Year "; cin >> pyear[k];
						cout << "\n Enter Edition "; cin >> edi[k];
						cout << "\n Enter Price "; cin >> pri[k];
						cout << "\n Enter Quantity "; cin >> quan[k];
						cout << "\n\n  ** New record has been saved successfuly ** ";

						for (int j = 0; j < i; j++)
						{
							cout << endl;
							cout << "\n IBAN " << iban[j];
							cout << "\n Publishing Year " << pyear[j];
							cout << "\n Edition " << edi[j];
							cout << "\n Price " << pri[j];
							cout << "\n Quantity " << quan[j];
						}
					}
					else if (found == false)
						cout << "\n\n The new IBAN number you enterd is already in our records ";

					break;
				}
				else if (check==false)
					cout << "\n The IBAN you enterd is not found in our records ";

				cout << "\n\n If you want to delete more books press y else press n "; cin >> morbooks;
			}
		}

		if (opt == 3)
		{
			bool test = true;
			char issueagain = 'y', issue;
			int num = 0, k = 0, quantity = 0 , bleft=0;

			while (issueagain == 'y' || issueagain == 'Y')
			{
				bool test = true;
				char  issue;
				int num = 0, k = 0, quantity = 0;

				cout << "\n\n To whom do you want to issue the book? Oress s for students or pess t for teachers ";
				cin >> issue;

				if (issue == 's' || issue == 'S' || issue == 't' || issue == 'T')
				{
					cout << "\n Please enter the Iban number of the book you want issue "; cin >> num;

					for (int j = 0; j < i; j++)
					{
						if (num == iban[j])
						{
							test = true;
							break;
						}
						else
						{
							k++;
							test = false;
						}
					}
					if (test == true)
					{
						cout << "\n How much quantity you want to issue "; cin >> quantity;
						bleft = quan[k] - quantity;

						if (bleft >= 1)
						{
							quan[k] = bleft;
							cout << "\n The Book with IBAN number has been issued ";
							cout << " \n The Quantity left of the book of IBAN number " << num << " int the Library is " << quan[k];
							cout << "\n\n IBAN   PUBLISHING year   Edition   Price   Quantity left  ";
							cout << "\n\n " << iban[k] << "\t" << pyear[k] << " \t\t   " << edi[k] << " \t   " << pri[k] << " \t\t " << quan[k];
						}

						else if (bleft < 1)
							cout << "\n You cannot issue the book of this much quantity.\n As per rule library must have atleast 1 copy left of the desired book ";
					}

					else
						cout << "\n No Book with such IBAN number" << num << " exists in the reacords ";

				}
				else
					cout << "\n\n You can only issue the book to Students or Teachers not to any other ";

				cout << "\n If you want to issue The book press y otherwise press n "; cin >> issueagain;
			}
		}

		if (opt == 4)
		{
			char again = 'y';
			bool check = true;

			while (again == 'y' || again == 'Y')
			{
				int num = 0, k = 0, amount = 0;
				cout << "\n Enter Iban of the book you want to return "; cin >> num;

				for (int j = 0; j < i; j++)
				{
					if (num == iban[j])
					{
						check = true;
						break;
					}
					else
					{
						check = false;
						k++;
					}
				}

				if (check == true)
				{
					cout << "\n Enter the Quantity of the book you want to return "; cin >> amount;
					quan[k] += amount;
					cout << "\n ** The book has been recieved ** ";
					cout << "\n\n IBAN   PUBLISHING year   Edition   Price   Quantity ";
					cout << "\n\n " << iban[k] << "\t" << pyear[k] << " \t \t  " << edi[k] << " \t   " << pri[k] << " \t\t " << quan[k];
				}
				else
					cout << "\n No book wth such IBAN number exists in the records ";

				cout << "\n If you want to recieve back book press y else press n "; cin >> again;
			}
		}

		
		if (opt == 5)
		{   // sorting is based on the quantity left in the records of a particular IBAN number
			for (int k = 0; k < i; k++)
			{
				for (int j = k + 1; j < i; j++)
				{
					if (pri[i] < pri[j])
					{
						swap(pri[k], pri[j]);
						swap(iban[k], iban[j]);
						swap(pyear[k], pyear[j]);
						swap(edi[k], edi[j]);
						swap(quan[k], quan[j]);
					}

				}
			}

			for (int j = 0; j < i; j++)
			{
				cout << endl;
				cout << " \n  IBAN number " << iban[j];
				cout << "\n  Publishing Year " << pyear[j];
				cout << " \n  EDITION " << edi[j];
				cout << "\n  PRICE " << pri[j];
				cout << "\n  Quantity " << quan[j];
			}
		}
		cout << "\n\n\n If you wan to goto back to the option sthen press 'Y'. \n If you want to close the Program press 'n' "; cin >> again;
	}

	system("PAUSE");
	return 0;
}