// Todd Oakes submission for the Programming Fundamentals II: Programming Portion.
// Completed 12/12/2016
//  author: Todd Oakes
//
#pragma once
#include "CustomerData.h"
//contains a CustomerData and a purchasesAmount and a discountLevel.
class PreferredCustomer :
	public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;

	//if Purchase $2000, 10% discount
	//            $1500, 7% discount
	//            $1000, 6% discount
	//            $ 500, 5% discount
	//          < $ 500 = no discount.
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

	//unused
	void addPurchaseAmount(double amount)
	{
		purchasesAmount += amount;
	}

	//unused
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
		setDiscountLevel(); //re-calculates discount level based on current putchases.
		return discountLevel; // and returns the re-calculated level.
	}

};

