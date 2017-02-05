#include <iostream>
#include <bits/stdc++.h>
#define lap(i,n) for(int i = 0; i < n; i++)
#ifndef DATE_H
#define DATE_H
const string MONTHS[12] = {
 "January",
 "February",
 "March",
 "April",
 "May",
 "June",
 "July",
 "August",
 "September",
 "October",
 "November",
 "December"
};

class Date{
public:
 int getDay()const{return day;}
 int getMonth()const{return month;}
 int getYear()const{return year;}

 void inputData();// doc du lieu tu istream vao cac bien thanh vien
 void printShortForm();// in dang dd/mm/yyyy
 void printLongForm();// in xau tieng Anh day du
private:
 int day;
 int month;
 int year;
};

#endif // DATE_H
