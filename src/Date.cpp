#include <iostream>
#include <bits/stdc++.h>
#define lap(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long LL;
#include "Date.h"
void Date::inputData(){
 cout << "Nhap ngay: ";
 cin >> day;
 cout << "Nhap thang: ";
 cin >> month;
 cout << "Nhap nam: ";
 cin >> year;
 cin.ignore();// loai bo dau ENTER trong istream
}
// in dang dd/mm/yyyy
void Date::printShortForm(){
 cout << (day < 10 ? "0" : "") << day << "/"
 << (month < 10 ? "0" : "") << month << "/"
 << year;
}
// in xau tieng Anh day du
void Date::printLongForm(){
 cout << MONTHS[month - 1] << " " << day << ", " << year;
}
