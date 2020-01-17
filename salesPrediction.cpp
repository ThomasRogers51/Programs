/*

The East Coast sales division of a company generates 58 percent of total sales. Based on that percentage, write a program that will 
predict how much the East Coast Division will generate if the company has $8.6 million in sales this year. Display the result on the
screen.

*/
#include <iostream>

using namespace std;

int main()
{
	double sales = 8.6,
		percentOfTotalSales = 58,
		eastCoastSales = sales * percentOfTotalSales / 100;

	cout << "Total company sales is $" << sales << " million." << endl;
	cout << "The percentage of sales from the east coast division is " << percentOfTotalSales << " %." << endl;
	cout << "The East Coast division will generate $" << eastCoastSales << " million in sales this year." << endl;
	return 0;
}
