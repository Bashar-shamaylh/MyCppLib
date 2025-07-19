#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;
class clsInputValidate
{
public :
	static bool IsNumberBetween(int number, int upperBound, int lowerBound)
	{
		return (number<upperBound && number>lowerBound) ? true : false;
	}
	static bool IsDateBetween(clsDate date, clsDate upperDate, clsDate lowerDate)
	{
		if (clsDate::DateIsLessThanDate2(upperDate, lowerDate))
		{
			clsDate::SwapTwoDates(upperDate, lowerDate);
			
		}
		return date.DateIsLessThanDate2(upperDate) && date.isDate1AfterDate2(lowerDate) ? true : false;
	}
	static int ReadIntNumber(string message)
	{
		string text;
		char c;
		while (true)
		{
			cin >> text;
			for (short i = 0; i < text.length(); i++)
			{
				c = text.at(i);
				if (int(c) > 57 || int(c) < 48)
				{
					break;
				}
				if (i == text.length() - 1)
					return stoi(text);
			}
			cout << message << endl;

		}
	}
	static bool isValidDate(clsDate date)
	{
		cout << "later on" << endl;
	}
	static bool ReadDblNumber(string message)
	{

	}
};

