/*

Write a program that computes the tax and tip on a restaurant bill for a patron with a $88.67 meal charge. The tax should be 6.75
percent of the meal cost. The tip should be 20 percent of the total after adding the tax. Display the meal cost, tax amount, tip
amount, and total bill on the screen.

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double bill = 88.67,
			tax = 6.75,
			tip = 20;

	double taxAmount = (tax / 100) * bill;
	
	double tipAmount = (tip / 100) * bill;
	
	double totalBill = bill + taxAmount + tipAmount;

	cout << "The meal cost is $" << bill << "." << endl;
	cout << "The tax amount is $" << setprecision(2) << fixed << taxAmount << "." << endl;
	cout << "The tip amount is $" << setprecision(2) << fixed << tipAmount << "." << endl;
	cout << "The total bill is $" << setprecision(2) << fixed << totalBill << "." << endl;
	return 0;
}
