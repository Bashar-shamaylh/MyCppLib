#pragma once
#include<iostream>
#include "clsDate.h"
#include "clsString.h"
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;
class clsUtility
{
public:
    enum enSymbol { Small_letter = 1, Capital_letter = 2, Special_Character = 3, Digit = 4 };
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
    static string EncryptText(string text, int key)
    {
        string EncryptedText = "";
        int AsciValue;
        char c = 'c';
        for (int i = 0; i < text.length(); i++)
        {
            c = text[i];
            AsciValue = c;
            AsciValue += key;
            EncryptedText += char(AsciValue);
        }


        return EncryptedText;
    }
    static string DecryptText(string EncryptedText, int key)
    {
        string text = "";
        int AsciValue = 0;
        char c = 'c';
        for (int i = 0; i < EncryptedText.length(); i++)
        {
            EncryptedText[i] = char((int)EncryptedText[i] + key);
        }


        return EncryptedText;
    }
    static int RandomNumber(int from, int to)
    {
        int randNumber = rand() % (to - from + 1) + from;
        return randNumber;
    }
    static string RandomSymbol(enSymbol SymbolType)
    {
        string random;
        if (SymbolType == enSymbol::Small_letter)
            random = char(RandomNumber(97, 122));
        else if (SymbolType == enSymbol::Capital_letter)
            random = char(RandomNumber(65, 90));
        else if (SymbolType == enSymbol::Special_Character)
            random = char(RandomNumber(33, 47));
        else if (SymbolType == enSymbol::Digit)
            random = char(RandomNumber(48, 57));
        return random;
    }
    static string GenrateWord(enSymbol wordtype, int wordlength)
    {
        string word;
        for (int i = 0; i < wordlength; i++)
            word = word + RandomSymbol(wordtype);
        return word;
    }
    static  string GenrateKey()
    {
        string key = GenrateWord(Capital_letter, 4) + '-';
        key = key + GenrateWord(Capital_letter, 4) + '-';
        key = key + GenrateWord(Capital_letter, 4) + '-';
        key = key + GenrateWord(Capital_letter, 4);
        return key;

    }
    static void GenrateKeys(int number_of_keys)
    {
        for (int i = 0; i < number_of_keys; i++)
            cout << "key [" << i << "] :"
            << GenrateKey() << endl;
    }
    static void FillArrayRandomly(int arr[], int numberOfItems)
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            arr[i] = RandomNumber(0, 100);
        }
    }
    static int FindMax(int arr[], int length)
    {
        int max = 0;
        for (int i = 0; i < length; i++)
        {
            if (max < arr[i])
                max = arr[i];
        }
        return max;

    }
    static int FindMin(int arr[], int length)
    {
        int min = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (min > arr[i])
                min = arr[i];
        }
        return min;

    }
    static int ArraySummation(int arr[], int length)
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
    static float ArrayItemsAverage(int arr[], int length)
    {
        return (float)ArraySummation(arr, length) / length;
    }
    static void FillArrayWithNumbers(int arr[], int length)
    {
        for (int i = 0; i < length; i++)
            arr[i] = i + 1;
    }
    static void ShuffleArrayContent(int arr[], int length)
    {
        for (int i = 0; i < length; i++)
        {
            int randomInceces = RandomNumber(0, length - 1);
            int temp = arr[i];
            arr[i] = arr[randomInceces];
            arr[randomInceces] = temp;
        }
    }
    static void FillArrayWithKeys(string arr[], int length)
    {
        for (int i = 0; i < length; i++)
            arr[i] = GenrateKey();
    }
    static short FindArryElemantPostion(int array[], int length, int number)
    {
        for (int i = 0; i < length; i++)
            if (array[i] == number)
                return i;
        return -1;
    }
    static bool NumberInArray(int array[], int length, int number)
    {
        if (FindArryElemantPostion(array, length, number) == -1)
            return 0;
        return 1;
    }
    static int InputUserNumberInArray(int array[])
    {
        int counter = 0, number;
        bool wantToAddNumber = 1;
        while (wantToAddNumber)
        {
            cout << "do you want to add a number to the array?[0]:No,[1]:Yes" << endl;
            cin >> wantToAddNumber;
            if (wantToAddNumber)
                cin >> number;
            else
                break;
            array[counter] = number;
            counter++;
        }
        return counter;
    }
    static bool IsPalindromeArray(int array[], int length)
    {
        for (int i = 0; i < round(length / 2); i++)
            if (array[i] != array[length - i - 1])
                return 0;
        return 1;
    }
    static int OddNumbersCount(int array[], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
            if (array[i] % 2 != 0)
                counter++;
        return counter;
    }
    static int EvenNumbersCount(int array[], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
            if (array[i] % 2 == 0)
                counter++;
        return counter;
    }
    static int PostiveNumberCount(int array[], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (array[i] > 0)
                counter++;

        }
        return counter;
    }
    static int NegativeNumberCount(int array[], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (array[i] < 0)
                counter++;

        }
        return counter;
    }
    static int Myabs(int number)
    {
        if (number < 0)
            return number * -1;
        return number;
    }
    static void PrintSpaces(short NumberOfSpaces)
    {
        for (short i = 0; i < NumberOfSpaces; i++)
            cout << " ";
    }
    static void PrintTaps(short NumberOfTaps)
    {
        for (short i = 0; i < NumberOfTaps; i++)
        {
            cout << "\t";
        }
    }
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }
    static void SetScreen()
    {
        
        system("cls");
    }
    static void ReadInput(string message="")
    {
        cout << message;
        char c;
        cin >> c;
    }

    static string CurrentTime()
    {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);

        ostringstream oss;
        oss << setfill('0') << setw(2) << ltm.tm_hour << ":"
            << setfill('0') << setw(2) << ltm.tm_min << ":"
            << setfill('0') << setw(2) << ltm.tm_sec;

        return oss.str();
    }
};

