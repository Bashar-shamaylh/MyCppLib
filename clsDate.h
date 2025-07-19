#pragma once
#include<iostream>
#include<ctime>
#include <vector>
#include<string>
using namespace std;
class clsDate
{
	int _day;
	int _month;
	int _year;
	string _FullDate;
public:
	clsDate()
	{
		time_t now = time(0);
		tm localTime;

		// Use localtime_s (safe version)
		localtime_s(&localTime, &now);

		_year = 1900 + localTime.tm_year;
		_month = 1 + localTime.tm_mon;
		_day = localTime.tm_mday;

	}
	clsDate(string date)
	{
		clsDate Date = FromStringToDate(date);
		_day = Date.day;
		_month = Date.month;
		_year = Date.year;
	}
	clsDate(int day, int month, int year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	clsDate(int dayNumber, int year)
	{
		clsDate Date = FromStringToDate(DateFromNumberOfDays(dayNumber, year));
		_day = Date.day;
		_month = Date.month;
		_year = Date.year;

	}
	void SetDay(int day)
	{
		_day = day;
	}
	void SetMonth(int month)
	{
		_month = month;
	}
	void SetYear(int year)
	{
		_year = year;
	}
	int GetDay()
	{
		return _day;
	}
	int GetMonth()
	{
		return _month;
	}
	int GetYear()
	{
		return _year;
	}
	_declspec(property(get = GetDay, put = SetDay)) int day;
	_declspec(property(get = GetMonth, put = SetMonth)) int month;
	_declspec(property(get = GetYear, put = SetYear)) int year;
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
	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31
		};
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			NumberOfDays[Month - 1];
	}
	static bool IsValidYear(short year)
	{
		return year > 0 ? true : false;
	}
	static bool IsValidMonth(short month)
	{
		return month > 0 && month < 13 ? true : false;
	}
	static bool IsValidDay(clsDate date)
	{
		return date.day <= NumberOfDaysInAMonth(date.month, date.year) && date.day >= 1 ? true : false;
	}
	static bool IsValidDate(clsDate date)
	{
		return IsValidDay(date) && IsValidMonth(date.month) && IsValidYear(date.year);
	}
	static string DateFromNumberOfDays(short numberOfDays, short year)
	{
		short monthDays = 0;
		short currentMonth = 0;
		for (short month = 1; month <= 12; month++)
		{
			monthDays = NumberOfDaysInAMonth(month, year);
			if (numberOfDays > monthDays)
			{
				numberOfDays -= monthDays;
			}
			else
			{
				currentMonth = month;
				break;
			}
		}
		
		return to_string(numberOfDays) + "/" + to_string(currentMonth) + "/" + to_string(year);
	
	}
	clsDate FromStringToDate(string date)
	{
		vector <string> tokens = split(date, "/");
		clsDate Date;
		Date.day = stoi(tokens.at(0));////////// need to updateeeeee
		Date.month = stoi(tokens.at(1));
		Date.year = stoi(tokens.at(2));
		return Date;
	}
	void Print()
	{
		cout << _day << "/" << _month << "/" << _year << endl;
	}
	static int FindDayOrder(int year, int month, int day = 1)
	{
		int a, m, y;

		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	int FindDayOrder() { return FindDayOrder(_day, _month, _year); }
	static string DayName(int day)
	{
		string arr[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[day];
	}
	string DayName() { return DayName(_day); }
	static string MonthName(short month)
	{
		string arr[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arr[month - 1];
	}
	string MonthName() { return MonthName(_month); }
	static void MonthCalender(short year, short month)
	{
		short numOfDays = NumberOfDaysInAMonth(month, year); // 28 or 29 for month 2 and 30 or 31 for the rest of the months
		short current = FindDayOrder(year, month, 1);  //what is the first day in the month 0,1,2,3,4,5,6     //Sun,Mon.....
		cout << "  _______________" << MonthName(month) << "_______________" << endl;
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
		short i;
		for (i = 0; i < current; i++)
			cout << "     ";
		for (short j = 1; j <= numOfDays; j++)
		{
			printf("%3d", j);
			if (++i == 7)
			{
				cout << endl << "  ";
				i = 0;
			}
			else
				cout << "  ";

		}
		cout << endl;
		cout << "   ------------------------------" << endl;
	}
	void MonthCalender() { return MonthCalender(_year, _month); }
	static void YearCalender(short year)
	{
		cout << "   ------------------------------" << endl;
		cout << "            Calender for " << year << " year" << endl;
		cout << "   ------------------------------" << endl;
		for (int i = 1; i <= 12; i++)
			MonthCalender(year, i);
	}
	void YearCalender()
	{
		return YearCalender(_year);
	}
	static short NumberOfDaysFromTheBegingOfTheYear(short day, short month, short year)
	{
		short numberOfDays = 0;
		for (short i = 1; i < month; i++)
		{
			numberOfDays += NumberOfDaysInAMonth(i, year);
		}
		numberOfDays += day;
		return numberOfDays;
	}
	short NumberOfDaysFromTheBegingOfTheYear() { return NumberOfDaysFromTheBegingOfTheYear(_day, _month, _year); }
	static string DateAfterAddingNumberOfDaysToTheStartOfTheYear(short numberOfDays, short year)
	{
		short monthDays = 0;
		short currentMonth = 0;
		for (short month = 1; month <= 12; month++)
		{
			monthDays = NumberOfDaysInAMonth(month, year);
			if (numberOfDays > monthDays)
			{
				numberOfDays -= monthDays;
			}
			else
			{
				currentMonth = month;
				break;
			}
		}
		return to_string(numberOfDays) + "/" + to_string(currentMonth) + "/" + to_string(year);

	}
	string DateAfterAddingNumberOfDaysToTheStartOfTheYear(int numberOfDays) { return DateAfterAddingNumberOfDaysToTheStartOfTheYear(numberOfDays, _year); }
	static clsDate DateAfterAddingNumberOfDaysToTheCurrentDate(short numberOfDaysToAdd, clsDate date)
	{
		numberOfDaysToAdd = numberOfDaysToAdd + NumberOfDaysFromTheBegingOfTheYear(date._day, date._month, date._year);
		date._month = 1;
		date._day = 1;
		while (true)
		{
			short monthdays = NumberOfDaysInAMonth(date._month, date._year);
			if (numberOfDaysToAdd > monthdays)
			{
				if (date._month == 12)
				{
					numberOfDaysToAdd -= monthdays;
					date._month = 1;
					date._year++;
				}
				else
				{
					date._month++;
					numberOfDaysToAdd -= monthdays;
				}

			}
			else
			{
				date._day = numberOfDaysToAdd;
				return date;
			}
			
		}
	}
	clsDate DateAfterAddingNumberOfDaysToTheCurrentDate(short numberOfDaysToAdd)
	{
		return DateAfterAddingNumberOfDaysToTheCurrentDate(numberOfDaysToAdd, *this);
	}
	static bool DateIsLessThanDate2(clsDate date1, clsDate date2)
	{

		return((date1._year < date2._year) ? true :
			(date1._year == date2._year) ? (date1._month < date2._month) ? true :
			(date1._month == date2._month) ? (date1._day < date2._day) ? true :
			false : false : false);
	}
	bool DateIsLessThanDate2(clsDate date2) { return DateIsLessThanDate2(*this, date2); }
	static bool DateIsEqualDate2(clsDate date1, clsDate date2)
	{

		return(date1._year == date2._year && date1._month == date2._month && date1._day == date2._day) ? true : false;
	}
	bool DateIsEqualDate2(clsDate date2)
	{
		return DateIsEqualDate2(*this, date2);
	}
	static bool IsLastDayInTheMonth(clsDate date)
	{
		return NumberOfDaysInAMonth(date._month, date._year) == date.day;
	}
	bool IsLastDayInTheMonth()
	{
		return IsLastDayInTheMonth(*this);
	}
	static bool IsLastMonthInTheYear(clsDate date)
	{
		return date._month == 12;
	}
	bool IsLastMonthInTheYear()
	{
		return IsLastMonthInTheYear(*this);
	}
	static void increaseDateByOneDay(clsDate& date)
	{
		if (IsLastDayInTheMonth(date))
		{
			date._day = 1;
			if (IsLastMonthInTheYear(date))
			{
				date._month = 1;
				date._year++;
			}
			else
				date._month++;
		}
		else
			date._day++;
		
	}
	void increaseDateByOneDay() { increaseDateByOneDay(*this); }
	static void SwapTwoDates(clsDate& date1, clsDate& date2)
	{
		clsDate temp;
		temp._day = date1._day;
		temp._month = date1._month;
		temp._year = date1._year;

		date1._day = date2._day;
		date1._month = date2._month;
		date1._year = date2._year;

		date2._day = temp._day;
		date2._month = temp._month;
		date2._year = temp._year;

	}
	static short DiffranceInDaysBetweenTwoDates(clsDate date1, clsDate date2, bool EncludeTheLastDay = false)
	{
		short diffranceInDays = 0;
		short SwapFlag = 1;
		if (!DateIsLessThanDate2(date1, date2))
		{
			SwapTwoDates(date1, date2);
			SwapFlag = -1;
		}
		while (!DateIsEqualDate2(date1, date2))
		{
			diffranceInDays++;
			increaseDateByOneDay(date1);
		}
		return EncludeTheLastDay ? ++diffranceInDays * SwapFlag : diffranceInDays * SwapFlag;
	}
	short DiffranceInDaysBetweenTwoDates(clsDate date2, bool EncludeTheLastDay = false) {
		return DiffranceInDaysBetweenTwoDates
		(*this, date2, EncludeTheLastDay);
	}
	static string fromDateToString(clsDate date)
	{
		return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}
	void fromDateToString()
	{
		_FullDate = fromDateToString(*this);
	}
	static clsDate IncreaseDateByXDays(clsDate date, short numberOfDaysToAdd)
	{
		for (short i = 0; i < numberOfDaysToAdd; i++)
			increaseDateByOneDay(date);
		return date;
	}
	void IncreaseDateByXDays(short numberOfDaysToAdd)
	{
		 *this=IncreaseDateByXDays(*this, numberOfDaysToAdd);
	}
	static clsDate IncreaseDateByOneWeek(clsDate date)
	{
		date = IncreaseDateByXDays(date, 7);
		return date;
	}
	void IncreaseDateByOneWeek()
	{
		*this= IncreaseDateByOneWeek(*this);
	}
	static clsDate IncreaseDateByXWeeks(clsDate date, short NumberOfWeeks)
	{
		for (short i = 0; i < NumberOfWeeks; i++)
			date = IncreaseDateByOneWeek(date);
		return date;
	}
	void IncreaseDateByXWeeks(short NumberOfWeeks)
	{
		*this = IncreaseDateByXWeeks(*this, NumberOfWeeks);
	}
	static clsDate IncreaseDateByOneMonth(clsDate date)
	{
		if (date._year == 12)
		{
			date._month = 1;
			date._year++;
		}
		else
			date._month++;
		short maxDays = NumberOfDaysInAMonth(date._month, date._year);
		if (date._day > maxDays)
			date._day = maxDays;
		return date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}
	static clsDate IncreaseDateByXMonths(clsDate date, short NumberOfMonthsToAdd)
	{
		for (short i = 0; i < NumberOfMonthsToAdd; i++)
			date = IncreaseDateByOneMonth(date);
		return date;
	}
	void IncreaseDateByXMonths(short NumberOfMonths)
	{
		*this= IncreaseDateByXMonths(*this, NumberOfMonths);
	}
	static clsDate IncreaseDateByOneYear(clsDate date)
	{
		date._year++;
		short maxDays = NumberOfDaysInAMonth(date._month, date._year);
		if (date._day > maxDays)
			date._day = maxDays;
		return date;
	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}
	static clsDate IncreaseDateByXYears(clsDate date, short NumberOfYearsToAdd)
	{
		for (int i = 0; i < NumberOfYearsToAdd; i++)
			date = IncreaseDateByOneYear(date);
		return date;
	}
	void IncreaseDateByXYears(short NumberOfYears)
	{
		*this = IncreaseDateByXYears(*this, NumberOfYears);
	}
	static clsDate IncreaseDateByOneDecade(clsDate date)
	{
		date = IncreaseDateByXYears(date, 10);
		return date;
	}
	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}
	static clsDate IncreaseDateByXDecades(clsDate date, short NumberOfDecadesToAdd)
	{
		for (int i = 0; i < NumberOfDecadesToAdd; i++)
			date = IncreaseDateByOneDecade(date);
		return date;
	}
	void IncreaseDateByXDecades(short NumberOfDecades)
	{
		*this = IncreaseDateByXDecades(*this, NumberOfDecades);
	}

	static clsDate IncreaseDateByXDecadesFaster(clsDate date, short NumberOfDecadesToAdd)
	{
		NumberOfDecadesToAdd = NumberOfDecadesToAdd * 10;
		date._year += NumberOfDecadesToAdd;
		short maxDays = NumberOfDaysInAMonth(date._month, date._year);
		if (date._day > maxDays)
			date._day = maxDays;
		return date;
	}
	void IncreaseDateByXDecadesFaster(short NumberOfDecades)
	{
		*this = IncreaseDateByXDecadesFaster(*this, NumberOfDecades);
	}
	static clsDate IncreaseDateByOneCentary(clsDate date)
	{
		date = IncreaseDateByXDecadesFaster(date, 10);
		return date;
	}
	void IncreaseDateByOneCentary()
	{
		*this = IncreaseDateByOneCentary(*this);
	}
	static clsDate IncreaseDateByMillennium(clsDate date)
	{
		date = IncreaseDateByXDecadesFaster(date, 100);
		return date;
	}
	void IncreaseDateByMillennium()
	{
		*this = IncreaseDateByMillennium(*this);
	}
	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!DateIsLessThanDate2(date1, date2) && !DateIsEqualDate2(date1, date2));
	}
	bool isDate1AfterDate2(clsDate date2)
	{
		return isDate1AfterDate2(*this, date2);
	}
	static bool isEndOfWeek(clsDate date)
	{
		return (FindDayOrder(date._year, date._month, date._day) == 6);
	}
	static bool isWeekend(clsDate date)
	{
		return (FindDayOrder(date._year, date._month, date._day) == 5 || FindDayOrder(date._year, date._month, date._day) == 6);
	}
	static bool isBussnissDay(clsDate date)
	{
		return !isWeekend(date);
	}
	static short untilEndOfTheWeek(clsDate date)
	{
		return 6 - FindDayOrder(date._year, date._month, date._day);
	}
	static short untillEndOfTheMonth(clsDate date)
	{
		return NumberOfDaysInAMonth(date.month, date.year) - date.day;
	}
	static short untillEndOfTheYear(clsDate date)
	{
		short numberOfDaysInTheYear = isLeapYear(date._year) ? 366 : 365;
		short NumberOfDaysfromBegingOfTheYear = NumberOfDaysFromTheBegingOfTheYear(date._day, date._month, date._year);
		return numberOfDaysInTheYear - NumberOfDaysfromBegingOfTheYear;
	}
	static short ActualVacationDays(clsDate date1, clsDate date2)
	{
		short diffranceInDays = 0;
		short dayOrder;
		while (!DateIsEqualDate2(date1, date2))
		{

			if (isBussnissDay(date1))
			{
				diffranceInDays++;
			}

			increaseDateByOneDay(date1);
		}
		return diffranceInDays;
	}
	short ActualVacationDays(clsDate date2)
	{
		return ActualVacationDays(*this, date2);
	}
	static clsDate CalculateReturnDateAfterVacation(clsDate VacationStartDate, short VacationDays)
	{
		short diffranceInDays = 0;
		short dayOrder;
		while (VacationDays != 0)
		{

			if (isWeekend(VacationStartDate))
			{
				 increaseDateByOneDay(VacationStartDate);
			}
			else
			{
				increaseDateByOneDay(VacationStartDate);
				VacationDays--;
			}


		}
		return VacationStartDate;
	}

};

