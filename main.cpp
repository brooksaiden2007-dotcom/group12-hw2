#include <iostream>
#include <iomanip>
using namespace std;
//67
//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}
	if (argc < 4)
	{
		cout << "Not enough arguments. Must pass in three." << endl;
		return -1;
	}	

	int i = 1;
	double balance, yearlyinterest, monthpay;

	double arguments [3];

	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const invalid_argument&)
			{
				if(i==1)
					cout << "(Invalid loan amount): " << argv[i] << endl;
				else if (i==2)
					cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
				else
					cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;

				return -2;
			}
			i++;
		}
		
	}
	


	balance = arguments[0];
	yearlyinterest = arguments[1];
	monthpay = arguments[2];
	//iitalize variables
	int month = 0;
	double interest = 0;
	double totalinterest = 0;
	double payment = 0;
	double rate = yearlyinterest/12;
	double interestrate = rate/100;
	double principal = (monthpay - (balance * interestrate));


	if (balance < 0 )
	{
		cout << "(Invalid loan amount): " << balance << endl;
		return -3;
	}

	if (yearlyinterest < 0)
	{
		cout << "(Invalid interest rate): " << balance << " " << yearlyinterest << endl;
		return -3;
	}

	if (monthpay < 0)
	{
		cout << "(Invalid payment): " << balance << " " << yearlyinterest << " " << monthpay << endl;
		return -3;
	}

	if ((balance +  (balance * interestrate))>= balance - principal)
	{
		cout << "(Insufficient payment): " << balance << " " << yearlyinterest << " " << monthpay << endl;
		return -3;
	}
	
	//row lengths
	int col1 = 10;
	int col2 = 12;
	int col3 = 10;
	int col4 = 10;
	int col5 = 10;
	int col6 = 10;
	//total row length
	int len = 62;
	cout.setf(ios :: fixed);
	cout.setf(ios :: showpoint);
	cout.precision(2);

	//Formating columns
	cout << string(len, '*') << endl;

	cout << left << setw(22) << ' '
		 <<"Amortization Table" << endl;

	cout << string(len, '*') << endl;
	//Header
	cout << left 
		 << setw(col1) << "Month" 
		 << setw(col2) << "Balance" 
		 << setw(col3) << "Payment" 
		 << setw(col4) << "Rate" 
		 << setw(col5) << "Interest" 
		 << setw(col6) << "Principal" << endl;
	//First Row
	cout << left
		 << setw(col1) << month
		 << setw(col2) << balance 
		 << setw(col3) << "N/A" 
		 << setw(col4) << "N/A"  
		 << setw(col5) << "N/A"  
		 << setw(col6) << "N/A"  << endl;
		 month += 1;
	//the rest of the rows
	while (balance > 0)
	{

		interest = interestrate * balance;
		principal = monthpay - interest;
		
		if (balance >= principal)
		{
		balance = balance - principal;
		cout << left
		 << setw(col1) << month
		 << setw(col2) << balance 
		 << setw(col3) << monthpay 
		 << setw(col4) << rate 
		 << setw(col5) << interest 
		 << setw(col6) << principal  << endl;
		}
		//catch balance < principal
		else
		{
		principal = balance;
		payment = balance + interest;
		balance = 0;
		cout << left
		 << setw(col1) << month
		 << setw(col2) << balance 
		 << setw(col3) << payment
		 << setw(col4) << rate 
		 << setw(col5) << interest 
		 << setw(col6) << principal  << endl;
		}
		//count amount of months
		totalinterest += interest;
		if (balance != 0)
		{
		month += 1;
		}

	}

	cout << string(len, '*') << "\n\n";
	cout << "It takes " << month << " months to pay off the loan." << endl;
	cout << "Total interest paid is: $" << totalinterest << endl;
		 
	return 0;
}
