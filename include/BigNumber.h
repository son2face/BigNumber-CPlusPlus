
#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include <vector>
#include <string.h>
#define lap(i,n) for(int i = 0; i < n; i++)
#include <ostream>
#include <iostream>
using namespace std;
class BigNumber
{
    public:
        friend class caculator;
        BigNumber();
        BigNumber(string value);
        BigNumber(const BigNumber&n1);
        unsigned int length()const;
        string toString() const;
        char* toArray() const;
        friend ostream& operator<<(ostream& out, const BigNumber& number);
        friend istream& operator>>(istream& in, BigNumber& number);
        friend const BigNumber operator+(const BigNumber& n1,const BigNumber& n2);
        friend const BigNumber operator-(const BigNumber& n1,const BigNumber& n2);
        friend const BigNumber operator*(const BigNumber& n1,const BigNumber& n2);
        friend const BigNumber operator/(const BigNumber& n1,const BigNumber& n2);
        friend const BigNumber operator%(const BigNumber& n1,const BigNumber& n2);
        friend bool operator>(const BigNumber& n1,const BigNumber& n2);
        friend bool operator<(const BigNumber& n1,const BigNumber& n2);
        friend bool operator>=(const BigNumber& n1,const BigNumber& n2);
        friend bool operator<=(const BigNumber& n1,const BigNumber& n2);
        friend bool operator==(const BigNumber& n1,const BigNumber& n2);
        friend const BigNumber operator++(BigNumber& n1);
        friend const BigNumber operator++(BigNumber& n1,int );
        friend const BigNumber operator--(BigNumber& n1);
        friend const BigNumber operator--(BigNumber& n1,int );
        friend void _in(BigNumber x){ for(int i=0; i<x.digitpairs.size(); i++) cout << x.digitpairs[i] << " ";}
        BigNumber& operator=(const BigNumber& n1);
        int _sign(int a) { sign = a;}
        unsigned char& operator[](unsigned int i);
        virtual ~BigNumber();
    protected:
    private:
        vector<unsigned char> digitpairs;
        int sign;
};

#endif // BIGNUMBER_H
