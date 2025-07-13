#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
	string _value;
public:
	clsString()
	{
		_value = "";
	}
	clsString(string value)
	{
		_value = value;
	}
	void SetValue(string value)
	{
		_value = value;
	}
	string GetValue()
	{
		return _value;
	}
	_declspec(property(get = GetValue, put = SetValue)) string value;
	static string upperTheFirstLetterOfEachWord(string text)
	{
		short len = text.length();
		bool IsFirstNumber = true;
		for (short i = 0; i < len; ++i)
		{
			if (text[i] != ' ' && IsFirstNumber)
			{
				if(islower(text.at(i)))
					text.at(i) = toupper(text.at(i));

				   //the esiest way 
			}

			IsFirstNumber = (text[i] == ' ' ? true : false);
		}
		return text;
	}
	void upperTheFirstLetterOfEachWord()
	{
		_value= upperTheFirstLetterOfEachWord(_value);
	}
	static string lowerTheFirstLetterOfEachWord(string text)
	{
		short len = text.length();
		bool IsFirstNumber = true;
		for (short i = 0; i < len; ++i)
		{
			if (text[i] != ' ' && IsFirstNumber)
			{
				text.at(i) = tolower(text.at(i));   //the esiest way 
			}

			IsFirstNumber = (text[i] == ' ' ? true : false);
		}
		return text;
	}
	void lowerTheFirstLetterOfEachWord()
	{
		_value= lowerTheFirstLetterOfEachWord(_value);
	}
	static int CountCapitalLettersInString(string text)
	{
		short counter = 0;
		for (short i = 0; i < text.length(); i++)
			if (text[i] != ' ' && isupper(text[i]))
				counter++;
		return counter;
	}
	int CountCapitalLettersInString()
	{
		return CountCapitalLettersInString(_value);
	}
	static int CountLowerLettersInString(string text)
	{
		short counter = 0;
		for (short i = 0; i < text.length(); i++)
			if (text[i] != ' ' && islower(text[i]))
				counter++;
		return counter;
	}
	int CountLowerLettersInString()
	{
		return CountLowerLettersInString(_value);
	}
	static char convertLetterCase(char letter)
	{
		if (isupper(letter))
		{
			return tolower(letter);
		}
		else if (islower(letter))
			return toupper(letter);
		else
			return letter;
	}
	static string convertFullString(string text)
	{
		for (int i = 0; i < text.length(); i++)
			if (text[i] != ' ')
				text[i] = convertLetterCase(text[i]);
		return text;
	}
	void convertFullString()
	{
		_value= convertFullString(_value);
	}
	static short letterCounter(string text, char letter)
	{
		short counter = 0;
		for (int i = 0; i < text.length(); ++i)
		{
			if (tolower(letter) == tolower(text[i]) && text[i] != ' ')
				counter++;
		}
		return counter;
	}
	short letterCounter(char letter)
	{
		return letterCounter(_value, letter);
	}
	static bool  isVowel(char letter)
	{
		letter = tolower(letter);
		return (letter == 'a' || letter == 'o' || letter == 'e' || letter == 'i' || letter == 'u');
	}
	static short countVowels(string text)
	{
		short  counter = 0;
		for (int i = 0; i < text.length(); i++)
			if (isVowel(text[i]))
				counter++;
		return counter;
	}
	short countVowels()
	{
		return countVowels(_value);
	}
	static short countLetters(string text)
	{
		short counter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (isupper(text.at(i)) || islower(text.at(i)))
			{
				counter++;
			}
		}
		return counter;
	}
	short countLetters()
	{
		return countLetters(_value);
	}
	static short CountWordsInString(string text)
	{
		string delim = " ";
		short pos = 0;
		short counter = 0;
		while ((pos = text.find(delim)) != std::string::npos)
		{
			string sWord = text.substr(0, pos);
			if (sWord != "")
				counter++;
			text.erase(0, pos + delim.length());


		}
		if (text != "")
			counter++;
		return counter;

	}
	short CountWordsInString()
	{
		return CountWordsInString(_value);
	}
	short length()
	{
		return _value.length();
	}
	static string lowerAllString(string text)
	{
		for (int i = 0; i < text.length(); i++)
			if (text[i] != ' ')
				text[i] = tolower(text[i]);
		return text;
	}
	void lowerAllString()
	{
		_value= lowerAllString(_value);
	}
	static string upperAllString(string text)
	{
		for (int i = 0; i < text.length(); i++)
			if (text[i] != ' ')
				text[i] = toupper(text[i]);
		return text;
	}
	void upperAllString()
	{
		_value= upperAllString(_value);
	}
	static string join(string arr[100], int stlen, string del = " ")
	{
		string s;
		for (int i = 0; i < stlen; i++)
		{
			s += arr[i];
			s += del;
		}
		return s.substr(0, s.length() - del.length());
	}
	static string join(vector<string>& v, string del = " ")
	{
		string s;
		for (string item : v)
		{
			s += item;
			s += del;
		}
		return s.substr(0, s.length() - del.length());
	}
	static vector <string> split(string text, string delim)
	{
		vector<string> tokens;
		short pos = 0;
		string sWord;
		while (((pos = text.find(delim)) != std::string::npos))
		{
			sWord = text.substr(0, pos);
			if (sWord != "")
				tokens.push_back(sWord);
			text.erase(0, pos + delim.length());

		}
		if (sWord != "")
			tokens.push_back(text);
		return tokens;
	}
	vector <string> split(string delim=" ")
	{
		return split(_value,delim);
	}
	static string ReplaceAwordInString(string text, string oldWord, string newWord)
	{
		short tempIndex;
		while (text.find(oldWord) != std::string::npos)
		{
			tempIndex = text.find(oldWord);
			text = text.erase(tempIndex, oldWord.length());// insted of that you can use the prebuilt funcitno replace(pos,string.length(),string)
			text.insert(tempIndex, newWord);

		}
		return text;
	}
	void ReplaceAwordInString(string oldWord, string newWord)
	{
		_value= ReplaceAwordInString(_value, oldWord, newWord);
	}
	static string RemovePuncuations(string text)
	{
		string newstring = "";
		for (int i = 0; i < text.length(); i++)
		{
			if (ispunct(text[i]))
				continue;
			else
				newstring = newstring + text[i];

		}
		return newstring;
	}
	void RemovePuncuations()
	{
		_value =RemovePuncuations(_value);
	}
	static string rightTrim(string text)
	{
		string newstring;
		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] != ' ')
				return text.substr(0, i);

		}
		return " ";
	}
	static string leftTrim(string text)
	{
		string newstring;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
				return text.substr(i, text.length() - 1);

		}
		return " ";
	}
	void rightTrim()
	{
		_value= rightTrim(_value);
	}
	void leftTrim()
	{
		_value= leftTrim(_value);
	}
	static string Trim(string text)
	{
		return rightTrim(leftTrim(text));
	}
	void Trim()
	{
		_value= Trim(_value);
	}
	static string ReverseAString(string s)
	{
		vector <string> tokens = split(s, " ");
		vector<string> ReversedWords;
		for (int i = tokens.size() - 1; i > -1; i--)
		{
			ReversedWords.push_back( tokens.at(i));

		}
		return join(ReversedWords, " ");
	}
	string ReverseAString()
	{
		return ReverseAString(_value);
	}
};

