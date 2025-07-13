#pragma once
#include<iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;
class clsUtility
{
public:
	static void Srand()
	{
		srand((unsigned)time(NULL));
}
	static int ReturnNumberInReverse(int Number)
    {
        int  Remainder = 0, sum = 0, coutner = 0;
        int ReversedNumber = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            ReversedNumber = ReversedNumber * 10 + Remainder;

        }
        return ReversedNumber;

    }
    static int DigitFreqancy(int Digit, int Number)
    {
        int  Remainder = 0, Frequancy = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (Remainder == Digit)
                Frequancy++;


        }
        return Frequancy;

    }
    static void PrintAllDigitFreqancyes(int number)
    {
        int frequancy = 0;
        for (int i = 0; i < 10; i++)
        {
            frequancy = DigitFreqancy(i, number);
            if (frequancy != 0) {
                cout << "the frequancy for the number " << i << " is : " << frequancy << endl;
            }
        }
    }
};

