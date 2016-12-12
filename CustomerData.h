#pragma once
#include "PersonData.h"
class CustomerData :
	public PersonData
{
private:
	int customerNumber;
	bool mailingList;
public:

	CustomerData()
	{
		PersonData();
		customerNumber = getID();
		mailingList = true;
	}

	//mutator methods

	
	void setCustomerNumber(int num)
	{
		customerNumber = num;
	}
	void setMailingList(bool mail)
	{
		mailingList = mail;
	}

	//accessor methods

	//malleable ID, auto-assiged or can be set by person.
	int getCustomerNumber()
	{
		return customerNumber;
	}
	bool getMailingList()
	{
		return mailingList;
	}
};

