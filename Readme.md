# Nepali Date Convertor

There is no any formula for date conversion from BS to AD or viceversa as BS calender donot have any set number of days in month. This Program calculates days elapsed from a reference date (eg.in BS) and then add up calculated day elapsed to another refrence date (eg. in AD). The calculation is possible with array of days in month in bs calendar. The limit can be increased by adding more data. This program can convert for:
- AD: 1944-2034
- BS: 2000-2090


### _Usage_
- Add dateconv.c to directory
-  #include 'dateconv.c'
### _Functions_
```sh
Bs2Ad(char date_in_bs[]): convert Bs date to Ad date
Ad2Bs(char date_in_ad[]): convert Ad date to Bs date
Function return type: Date
dateformat:YYYY-MM-DD
```
### Data Type Date


```sh
Date.year-Year (int)
Date.month- Month (int)
Date.day - Day (int)
Date.Month - MonthName(char[])
Date.Day - WeekdayName (char[])
Date.error - Error (char[])
```