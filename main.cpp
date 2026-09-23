#include <iostream>
#include <iomanip>
using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];

	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const std::invalid_argument&)
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

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;
	//iitalize variables
	int month = 0;
	int balance = loan_amount;
	
	
	//row lengths
	int col1 = 10;
	int col2 = 12;
	int col3 = 10;
	int col4 = 10;
	int col5 = 10;
	int col6 = 10;
	//total row length
	int len = 62;


	//Formating columns
	cout << string(len, '*') << "\n";
	cout << "        Amortization Table"  << endl;
	cout << string(len, '*') << "\n";
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
	//the rest of the rows
	//while (Balance > 0;)

	cout << string(len, '*') << "\n";
	return 0;
}
