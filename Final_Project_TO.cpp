// Final_Project_TO.cpp : Defines the entry point for the console application.
//

#include "PreferredCustomer.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//maximum number of customers the program can handle
const int MAX_CUSTOMERS = 50;
const int ID_NUMBER_WIDTH = 5; // "##.: ", max customer ID plus 3.
const int COLUMN_WIDTH = 14; //in characters

//displays x newlines
void clearScreen(int x)
{
	for (int y = 0; y < x; y++)
	{
		cout << endl;
	}
}

//displays a bunch of newlines
void clearScreen()
{
	clearScreen(3);
}



//uses console prompts to ask for information and returns a CustomerData.
CustomerData newCustomer()
{
	//must be static otherwise reference will be lost
	static CustomerData recruit = CustomerData();

	//variable for data entry (console input)
	string data;

	//prompts
	cout << "Please enter the following information to create a new customer:" << endl;

	cout << "First Name? ";
	getline(cin, data);
	recruit.setFirstName(data);

	cout << "Last name? ";
	getline(cin, data);
	recruit.setLastName(data);

	cout << "Address? ";
	getline(cin, data);
	recruit.setAddress(data);

	cout << "City? ";
	getline(cin, data);
	recruit.setCity(data);

	cout << "State? ";
	getline(cin, data);
	recruit.setState(data);

	cout << "Zip Code? ";
	getline(cin, data);
	recruit.setZip(data);

	cout << "Phone Number? ";
	getline(cin, data);
	recruit.setPhone(data);

	clearScreen();

	return recruit;
}

//uses console prompts to ask for information and returns a PreferredCustomer.
PreferredCustomer newPreferredCustomer()
{
	//must be static otherwise reference will be lost
	static PreferredCustomer recruit = PreferredCustomer();

	//data entry variable
	string data;

	//prompts
	cout << "Please enter the following information to create a new customer:" << endl;

	cout << "First Name? ";
	getline(cin, data);
	recruit.setFirstName(data);

	cout << "Last name? ";
	getline(cin, data);
	recruit.setLastName(data);

	cout << "Address? ";
	getline(cin, data);
	recruit.setAddress(data);

	cout << "City? ";
	getline(cin, data);
	recruit.setCity(data);

	cout << "State? ";
	getline(cin, data);
	recruit.setState(data);

	cout << "Zip Code? ";
	getline(cin, data);
	recruit.setZip(data);

	cout << "Phone Number? ";
	getline(cin, data);
	recruit.setPhone(data);

	clearScreen();

	return recruit;
}

//displays all the data we have on this customer in multiline format.
void displayFullCustomerData(CustomerData customer)
{
	//displays the information using get[varname]()
	cout << "1. First:   " << customer.getFirstName() << endl
		<< "2. Last     " << customer.getLastName() << endl
		<< "3. Address: " << customer.getAddress() << endl
		<< "4. City:    " << customer.getCity() << endl
		<< "5. State:   " << customer.getState() << endl
		<< "6. Zip:     " << customer.getZip() << endl
		<< "7. Phone:   " << customer.getPhone() << endl
		<< "8. Mail?:   " << customer.getMailingList() << endl
		<< "9. Customer#" << customer.getCustomerNumber() << endl;
}

//append to displayFullCustomerData(CustomerData customer)
//this method adds in the $ spent line and discount level
void displayFullCustomerData(PreferredCustomer customer)
{
		displayFullCustomerData(static_cast<CustomerData>(customer));
	cout<< "10. $ Spent: " << customer.getPurchasesAmount() << endl
		<< "Current Discount Level:  " << customer.getDiscountLevel()*100 <<"%" << endl;
}

//displays the "return to main menu" line, and gets user choice
int displayEditPrompt()
{
	cout << "0. Back to main menu" << endl;
	cout << "Select an option: ";
	string s = "";
	getline(cin, s);
	return stoi(s);
}

//if the input starts with "N" or "n", then no mail.  Otherwise, will be true.
bool getMailPref(string pref)
{
	//'N' or 'n' detected
	if (pref.at(0) == 'N' || pref.at(0) == 'n')
	{
		//take them off
		cout << "Mail will no longer be sent to this address." << endl;
		return false;
	}
	//only one other case exists
	//default is true (I'm greedy)
	// this might be illegal without letting the customer know about it
	// and offering the option to decline (it's in edit prompts)
	cout << "Mail will now be recieved by this address." << endl;
	return true;
}

//edits a single item of a CustomerData object
// choice defines which item, from 1-9 in the following order:
//  First, Last, Address, 
//  City, State, Zip, 
//  Phone, MailingList, CustomerNumber
CustomerData editCustomerData(CustomerData customer, int choice)
{
	//temperary variable
	string edit;

	//converts "choice" to a string variable of what we're going to edit
	// ex: 1 = "Please enter the new First Name :"
	switch (choice)
	{	
	case 1:
		edit = "First Name";
		break;
	case 2:
		edit = "Last Name";
		break;
	case 3:
		edit = "Address";
		break;
	case 4:
		edit = "City";
		break;
	case 5:
		edit = "State";
		break;
	case 6:
		edit = "Zip";
		break;
	case 7:
		edit = "Phone";
		break;
	case 8:
		edit = "Mailing List? [Y/N]";
		break;
	case 9:
		edit = "Customer number";
	}
	//neater console output of above switch
	cout << "Please enter the new " << edit << ": ";

	//reuse edit as the user's new entry
	getline(cin, edit);

	//set the apropriate variable from the list above.
	switch (choice)
	{
	case 1:
		customer.setFirstName(edit);
		break;
	case 2:
		customer.setLastName(edit);
		break;
	case 3:
		customer.setAddress(edit);
		break;
	case 4:
		customer.setCity(edit);
		break;
	case 5:
		customer.setState(edit);
		break;
	case 6:
		customer.setZip(edit);
		break;
	case 7:
		customer.setPhone(edit);
		break;
	case 8:
		customer.setMailingList(getMailPref(edit));
		break;
	case 9:
		customer.setCustomerNumber(stoi(edit));
	}

	//some space in the console
	clearScreen();

	//returns the customer
	return customer;
}

//checks if n is positive.
// if n is not positive, it will ask for new input until it is.
double validate(double n)
{
	//data entry variable
	string sn;

	//asks for user input until n is positive (or 0)
	while (n < 0)
	{
		cout << "Purchases cannot be negitive.  Please re-enter: $";
		getline(cin, sn);
		n = stod(sn);
	}

	//returns n (either new input or the parameter, whichever was positive)
	return n;
}

//copy of the above editCustomerData(CustomerData...
// adds a 10th line: Purchases Amount$
PreferredCustomer editCustomerData(PreferredCustomer customer, int choice)
{
	//temperary variable
	string edit;

	//converts "choice" to a string variable of what we're going to edit
	// ex: 1 = "Please enter the new First Name :"
	switch (choice)
	{
	case 1:
		edit = "First Name";
		break;
	case 2:
		edit = "Last Name";
		break;
	case 3:
		edit = "Address";
		break;
	case 4:
		edit = "City";
		break;
	case 5:
		edit = "State";
		break;
	case 6:
		edit = "Zip";
		break;
	case 7:
		edit = "Phone";
		break;
	case 8:
		edit = "Mailing List? [Y/N]";
		break;
	case 9:
		edit = "Customer number";
		break;
	case 10:
		edit = "Purchases Amount $";
	}
	//neat output prompt
	cout << "Please enter the new " << edit << ": ";

	//reuse edit as the user's new entry
	getline(cin, edit);

	//set the apropriate variable from the list above.
	switch (choice)
	{
	case 1:
		customer.setFirstName(edit);
		break;
	case 2:
		customer.setLastName(edit);
		break;
	case 3:
		customer.setAddress(edit);
		break;
	case 4:
		customer.setCity(edit);
		break;
	case 5:
		customer.setState(edit);
		break;
	case 6:
		customer.setZip(edit);
		break;
	case 7:
		customer.setPhone(edit);
		break;
	case 8:
		customer.setMailingList(getMailPref(edit));
		break;
	case 9:
		customer.setCustomerNumber(stoi(edit));
		break;
	case 10:
		customer.setPurchasesAmount(validate(stod(edit)));
	}

	//some space in the console
	clearScreen();

	//returns customer
	return customer;
}


//prints the table header
void displayCustomerChoice() // no data to display
{
	//column 1
	string c1 = "##.: ";
	//special resize for ID numbers (limited size)
	c1.resize(ID_NUMBER_WIDTH, ' ');

	//column 2
	string c2 = "First";
	//general column size with spaces added if needed
	c2.resize(COLUMN_WIDTH, ' ');

	//column 3
	string c3 = "Last";
	c3.resize(COLUMN_WIDTH, ' ');

	//column 4 should easily identify different people with similar names.
	//preferably nothing that's risky (do not use: SSN, Account Number, etc)
	string c4 = "Phone";
	c4.resize(COLUMN_WIDTH, ' ');

	//Outputs the 4 column headers
	//Starts the list with 0: new customer
	cout << c1<<c2<<c3<<c4 << endl
		 << " 0.: Create New Customer" << endl;

	//next method run should be a list of options (see main)
}

// sets the string's length to COLUMN_WIDTH
// because retyping .resize(COLUMN_WIDTH, ' '); is tiring.
string setwidth(string s)
{
	//1 line function to simplify coding
	s.resize(COLUMN_WIDTH, ' ');
	return s;
}


//display some data on the customer within one tabbed line
// used in a loop after displayCustomerChoice() to display all.
void displayCustomerChoice(CustomerData person)
{
	cout  << setw(2) << person.getID() << ".: " 
		<< setwidth(person.getFirstName()) 
		<< setwidth(person.getLastName()) 
		<< setwidth(person.getPhone()) << endl;
}

//displays all the customers on hand
int menu(CustomerData data[MAX_CUSTOMERS], int currentAmountOfCustomers)
{
	//print table header
	displayCustomerChoice();

	//print table content (remember 0 is "new customer")
	for (int x = 1; x <= currentAmountOfCustomers; x++)
	{
		displayCustomerChoice(data[x]);
	}

	//a dummy generated invalid choice presented to the user as an exit option
	cout << setw(2) << setfill(' ') << currentAmountOfCustomers + 1 << ".: Exit the program" << endl;
	// (any number other than 0 or a list item will result in an exit, this is just to make it easier to understand for the user)

	//return default invalid choice if input is invalid
	int choice = -1;

	//gets user input
	cout << "Please select an option: ";
	string s;
	getline(cin, s);

	//converts input to a int and returns it
	choice = stoi(s);
	clearScreen();
	return choice;
}

//displays all the customers on hand
int menu(PreferredCustomer data[MAX_CUSTOMERS], int currentAmountOfCustomers)
{
	//print table header
	displayCustomerChoice();

	//print table content (remember 0 is "new customer")
	for (int x = 1; x <= currentAmountOfCustomers; x++)
	{
		displayCustomerChoice(data[x]);
	}

	//a dummy generated invalid choice 
	cout << setw(2) << setfill(' ') << currentAmountOfCustomers + 1 << ".: Exit the program" << endl;

	//return default invalid choice if input is invalid
	int choice = -1;

	//gets user choice
	cout << "Please select an option: ";
	string s = "";
	getline(cin, s);

	//converts input to an int and returns it.
	choice = stoi(s);
	clearScreen();
	return choice;
}

//main program
int main()
{
	//Part 1
	// Demonstrate an object of the
	// CustomerData class in a simple program.

	//initize lists, MAX_CUSTOMERS is set at top of code.
	CustomerData customer[MAX_CUSTOMERS];
	PreferredCustomer pcustomer[MAX_CUSTOMERS];

	//inalize list
	int currentAmountOfCustomers = 0;

	//main program loop control
	bool exit = false;

	//it's actually two programs in one.
	// prompt user on which one to use
	cout << "Please enter 0 for CustomerData demonstration" << endl
		<< "Or enter     1 for PreferredCustomer demonstration" << endl
		<< "Choice: ";
	string s;
	getline(cin, s);
	clearScreen();

	//convert user input to menu item choice (an int)
	int demonstrationChoice = -1;
	demonstrationChoice = stoi(s);



	//main program loop for CustomerData demonstration
	while (!exit && (demonstrationChoice == 0))
	{

		//Select a menu option from availible customers and options
		int choice = menu(customer, currentAmountOfCustomers);

		//"new customer" option
		if (choice == 0)
		{
			//create next customer
			currentAmountOfCustomers++;

			//starts at customer[1]
			customer[currentAmountOfCustomers] = newCustomer();

			//sets internal ID
			customer[currentAmountOfCustomers].setID(currentAmountOfCustomers);
		}

		//selected a valid customer
		else if (choice <= currentAmountOfCustomers && choice > 0)
		{
			//display customer information
			displayFullCustomerData(customer[choice]);

			//ask if customer needs editing
			int fieldToEdit = displayEditPrompt();

			// 0 = no edit
			if (fieldToEdit > 0)
			{
				customer[choice] = editCustomerData(customer[choice], fieldToEdit);
			}

		}

		//did not select a valid option or intended to exit the program
		else { exit = true; }


	}


	//Part 2
	// Write appropriate member functions
	// for this class (PreferredCustomer) and demonstrate it in a simple program.

	//main program loop for PreferredCustomer demonstration
	while (!exit && (demonstrationChoice == 1))
	{
		//initialize variables including customer "database"
		int choice = menu(pcustomer, currentAmountOfCustomers);

		//"new customer" option
		if (choice == 0)
		{
			//create next customer
			currentAmountOfCustomers++;

			//starts at customer[1]
			pcustomer[currentAmountOfCustomers] = newPreferredCustomer();

			//sets internal ID
			pcustomer[currentAmountOfCustomers].setID(currentAmountOfCustomers);
		}

		//selected a valid customer
		else if (choice <= currentAmountOfCustomers && choice > 0)
		{
			//display customer information
			displayFullCustomerData(pcustomer[choice]);

			//ask if customer needs editing
			int fieldToEdit = displayEditPrompt();

			// 0 = no edit
			if (fieldToEdit > 0)
			{
				pcustomer[choice] = editCustomerData(pcustomer[choice], fieldToEdit);
			}

		}

		//did not select a valid option
		else { exit = true; }


	}

	//a goodbye message 
	cout << "Goodbye." << endl;

	//program exited intentionally.
	return 0;
}


