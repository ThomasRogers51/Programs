/*

Write a program that will compute the total sales tax on a $95 purchase. Assume the state sales tax is 4 percent and the county 
sales tax is 2 percent.

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double purchase = 95,
		   stateSalesTax = 4,
		   countySalesTax = 2;

	double totalSalesTax = (stateSalesTax + countySalesTax) / 100 * purchase;
	
	cout << "The purchase is $" << purchase << "." << endl;
	cout << "The state sales tax is " << stateSalesTax << "%." << endl;
	cout << "The county sales tax is " << countySalesTax << "%." << endl;
	cout << "The total sales tax is $" << setprecision(2) << fixed <<totalSalesTax << "." << endl;
}
