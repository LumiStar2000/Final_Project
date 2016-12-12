#pragma once
#include "CustomerData.h"
class PreferredCustomer :
	public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;
	void setDiscountLevel()
	{
		if (purchasesAmount > 2000 )
		{
			discountLevel = 0.10; //10%
		}
		else if (purchasesAmount > 1500) //1500 < purchases < 2000
		{
			discountLevel = 0.07; //7%
		}
		else if (purchasesAmount > 1000) //1000 < purchases < 1500
		{
			discountLevel = 0.06; //6%
		}
		else if (purchasesAmount > 500)
		{
			discountLevel = 0.05; //5%
		}
		else
		{
			discountLevel = 0; //no discount, spend more.
		}
		
	}
public:

	PreferredCustomer()
	{
		purchasesAmount = 0;
		discountLevel = 0;
	}

	//mutator methods

	void setPurchasesAmount(double purchases)
	{
		purchasesAmount = purchases;
	}
	void addPurchaseAmount(double amount)
	{
		purchasesAmount += amount;
	}
	void addRefundAmount(double refund)
	{
		purchasesAmount -= refund;
	}
	
	//accessor methods

	double getPurchasesAmount()
	{
		return purchasesAmount;
	}
	double getDiscountLevel()
	{
		setDiscountLevel();
		return discountLevel;
	}

};

