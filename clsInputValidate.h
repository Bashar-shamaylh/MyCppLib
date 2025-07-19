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
	static bool IsNumberBetween(double number, double upperBound, double lowerBound)
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
	static int ReadIntNumber(string message="")
	{
		string text;
		char c;
		cout << message;
		while (true)
		{
			cin >> text;
			for (short i = 0; i < text.length(); i++)
			{
				c = text.at(i);
				if ((i == 0 && int(c) == 45))
				{
					continue;
				}
				if (int(c) > 57 || int(c) < 48)
				{	
						break;
				}
				if (i == text.length() - 1)
					return stoi(text);
			}
			cout << message;

		}
	}
	static double ReadDblNumber(string message="")
	{
		string text;
		char c;
		cout << message;
		short commaCounter = 0;
		while (true)
		{
			cin >> text;
			for (short i = 0; i < text.length(); i++)
			{
				c = text.at(i);
				if (int(c) == 46)
					commaCounter++;
				if ((i == 0 && int(c) == 45))
				{
					continue;
				}
				if (int(c) > 57 || (int(c) < 48 && int(c)!=46))
				{
					break;
				}
				if (commaCounter > 1)
					break;
				if (i == text.length() - 1&&commaCounter!=0)
					return stod(text);

			}
			cout << message;
		}
	}
	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}
	static int ReadIntNumberBetween(int upperBound, int lowerBound)
	{
		int number = ReadIntNumber();
		while (!IsNumberBetween(number, upperBound, lowerBound))
		{
			cout << "The number isn't between " << lowerBound << " and " << upperBound << " plese enter another number : ";
			number = ReadIntNumber();
		}
		return number;
	}
	static double ReadDblNumberBetween(double upperBound, double lowerBound)
	{
		double number = ReadDblNumber();
		while (!IsNumberBetween(number, upperBound, lowerBound))
		{
			cout << "The number isn't between " << lowerBound << " and " << upperBound << " plese enter another number : ";
			number = ReadDblNumber();
		}
		return number;
	}

};

