#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;
class clsInputValidate
{
public :
	static bool IsNumberBetween(int number, int From, int To)
	{
		return (number>=From && number<=To) ? true : false;
	}
	static bool IsNumberBetween(double number, double From, double To)
	{
		return (number>=From && number<=To) ? true : false;
	}
	static bool IsDateBetween(clsDate date, clsDate From, clsDate To)
	{
		if (!clsDate::DateIsLessThanDate2(From, To))
		{
			clsDate::SwapTwoDates(From, To);
			
		}
		return date.DateIsLessThanDate2(To) && date.isDate1AfterDate2(From) ? true : false;
	}
	static int ReadIntNumber(string message="")
	{	// this is the first soluation to the problem:
		/*string text;
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
			cout << message;*/ 
		//this is the doctor solution:
		int Number;
		while(!(cin>>Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> ::max(),'\n'));
			cout << message;
		}
		return Number;
	}
	static double ReadDblNumber(string message="")
	{
		/*string text;
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
			cout << message;*/
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> ::max(), '\n'));
			cout << message;
		}
		return Number;
		
	}
	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}
	static int ReadIntNumberBetween(int From, int To)
	{
		int number = ReadIntNumber();
		while (!IsNumberBetween(number, From, To))
		{
			cout << "The number isn't between " << From << " and " << To << " plese enter another number : ";
			number = ReadIntNumber();
		}
		return number;
	}
	static double ReadDblNumberBetween(double From, double To)
	{
		double number = ReadDblNumber();
		while (!IsNumberBetween(number, From, To))
		{
			cout << "The number isn't between " << From << " and " << To << " plese enter another number : ";
			number = ReadDblNumber();
		}
		return number;
	}

};

