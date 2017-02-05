#include "BigNumber.h"
unsigned char itoa(int _input) {return ('0'+_input);}
int atoi(unsigned char _input) {return (_input-'0');}

BigNumber::BigNumber()
{
    digitpairs.clear();
    sign = 1;
}

BigNumber::BigNumber(string value)
{
    sign = 1;
    int _count = value.length();
    int _end = 0;
    if (value[_end] == '-')
    {
        sign = 0;
        _end++;
    }
    while ((value[_end] == '0') && (_end <_count-1)) _end++;

   for (; _count>_end; _count--)
   {
       digitpairs.push_back(value[_count-1]);
   }
}

BigNumber::BigNumber(const BigNumber&n1)
{
    digitpairs.insert(digitpairs.begin(),n1.digitpairs.begin(),n1.digitpairs.end());
    sign = n1.sign;
}

BigNumber::~BigNumber()
{
}

unsigned int BigNumber::length()const
{
    return digitpairs.size();
}

string BigNumber::toString() const
{
    int i,j=0,n = length();
    char x[n+1];
    if(sign == 0) {
        x[0]='-';
        j++;
    }
    for(i = 0; digitpairs[n-i-1] == '0' && i<digitpairs.size()-1;i++);
    for(; i<n; i++){
        x[j]=digitpairs[n-i-1];
        j++;
    }
    x[j] = 0;
    return x;
}

istream& operator>>(istream& in, BigNumber& number)
{
    string temp;
    in >> temp;
    BigNumber temp1(temp);
    number = temp1;
   // for(int i=0;temp[i]!='/0';i++) digitpairs[i]=temp[i];
    return in;
}

ostream& operator<<(ostream& out, const BigNumber& number)
{
    out << number.toString();
    return out;
}

BigNumber& BigNumber::operator=(const BigNumber& n1)
{
    digitpairs=n1.digitpairs;
    sign = n1.sign;
}

const BigNumber operator+(const BigNumber& n1,const BigNumber& n2)
{
    int i,temp1,temp2,Minlength,Maxlength,Max_i,memory=0;
    BigNumber _result;
    if((n1.sign==0)&&(n2.sign==1)) { BigNumber n3(n1),n4(n2);n3._sign(1);_result = n4-n3;}
    else if ((n1.sign==1)&&(n2.sign==0)) { BigNumber n3(n1),n4(n2);n4._sign(1); _result = n3-n4;}
    else
    {
        if(n1.length()>n2.length())
        {
            Minlength = n2.length();
            Maxlength = n1.length();
            Max_i = 1;
        }
        else
        {
            Minlength = n1.length();
            Maxlength = n2.length();
            Max_i = 2;
        }
        for(i=0; i<Minlength; i++)
        {
            temp1 = atoi(n1.digitpairs[i]);
            temp2 = atoi(n2.digitpairs[i]);
            if(memory == 1){
                temp1++;
            }
            if(temp1+temp2>9){
                memory = 1;
                _result.digitpairs.push_back(itoa(temp1+temp2-10));
            }
            else {
                memory = 0;
                _result.digitpairs.push_back(itoa(temp1+temp2));
            }
        }
        if (Max_i == 1)
        {
            for(;i<Maxlength; i++)
            {
                temp1 = atoi(n1.digitpairs[i]);
                if(memory == 1){
                    temp1++;
                }
                if(temp1>9){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(0));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp1));
                }
            }
        }
        else
        {
            for(;i<Maxlength; i++)
            {
                temp2 = atoi(n2.digitpairs[i]);
                if(memory == 1){
                    temp2++;
                }
                if(temp2>9){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(0));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp2));
                }
            }
        }
        if(memory == 1){
            _result.digitpairs.push_back('1');
        }
        _result.sign = n1.sign;
    }
    return _result;
}

const BigNumber operator-(const BigNumber& n1,const BigNumber& n2)
{
    int i,temp1,temp2,Minlength,Maxlength,Max_i,memory=0;
    BigNumber _result;
    if (n2.sign == 0)
    {
        BigNumber n3(n1),n4(n2);
        n4._sign(1);
        _result = n3+n4;
    }
    else
    {
         if(n1>=n2)
        {
            Minlength = n2.length();
            Maxlength = n1.length();
            Max_i = 1;
        }
        else
        {
            Minlength = n1.length();
            Maxlength = n2.length();
            Max_i = 2;
        }
        if (Max_i == 1)
        {
            for(i=0; i<Minlength; i++)
            {
                temp1 = atoi(n1.digitpairs[i]);
                temp2 = atoi(n2.digitpairs[i]);
                if(memory == 1){
                    temp1--;
                }
                if(temp1-temp2<0){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(temp1-temp2+10));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp1-temp2));
                }
            }
            for(;i<Maxlength; i++)
            {
                temp1 = atoi(n1.digitpairs[i]);
                if(memory == 1){
                    temp1--;
                }
                if(temp1<0){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(9));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp1));
                }
            }
        }
        else
        {
            for(i=0; i<Minlength; i++)
            {
                temp2 = atoi(n1.digitpairs[i]);
                temp1 = atoi(n2.digitpairs[i]);
                if(memory == 1){
                    temp1--;
                }
                if(temp1-temp2<0){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(temp1-temp2+10));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp1-temp2));
                }
            }
            for(;i<Maxlength; i++)
            {
                temp2 = atoi(n2.digitpairs[i]);
                if(memory == 1){
                    temp2--;
                }
                if(temp2<0){
                    memory = 1;
                    _result.digitpairs.push_back(itoa(9));
                }
                else {
                    memory = 0;
                    _result.digitpairs.push_back(itoa(temp2));
                }
            }
            _result.sign=0;
        }
    }
    return _result;
}

bool operator>(const BigNumber& n1,const BigNumber& n2)
{
    string a,b;
    a = n1.toString();
    b = n2.toString();
    int temp1 = n1.length();
    int temp2 = n2.length();
    if(temp1>temp2)
    {
        return 1;
    }
    else if (temp1<temp2)
    {
        return 0;
    }
    else
    {
        for (int i=0;i<temp1; i++){
            if (a[i]<b[i]) return 0;
            else if (a[i]>b[i]) return 1;
        }
    }
    return 0;
}

bool operator<(const BigNumber& n1,const BigNumber& n2)
{
    return (n2>n1);
}

bool operator>=(const BigNumber& n1,const BigNumber& n2)
{
    return !(n2>n1);
}

bool operator<=(const BigNumber& n1,const BigNumber& n2)
{
    return !(n1>n2);
}

bool operator==(const BigNumber& n1,const BigNumber& n2)
{
    return (!(n1>n2) && !(n1<n2));
}

const BigNumber operator*(const BigNumber& n1,const BigNumber& n2)
{
    int temp1,memory=0;
    BigNumber _result("0");
    for(int i=0; i<n1.length(); i++)
    {
        BigNumber _temp;
        for(int j=0;j<i; j++) _temp.digitpairs.push_back('0');
        for(int j=0; j<n2.length(); j++)
        {
            temp1 = atoi(n1.digitpairs[i])*atoi(n2.digitpairs[j])+memory;
            memory = temp1/10;
            temp1 = temp1%10;
            _temp.digitpairs.push_back(itoa(temp1));
        }
        if(memory!=0) _temp.digitpairs.push_back(itoa(memory));
        memory = 0;
       // cout << _temp << " " << _result << endl;
        _result = _result + _temp;
    }
    if(n1.sign!=n2.sign) _result._sign(0);
    return _result;
}

const BigNumber operator/(const BigNumber& n,const BigNumber& n3)
{
     BigNumber n1(n),n2(n3);
    int length_a = n1.length();
    int length_b = n2.length();
    if (length_a < length_b) return (BigNumber)"0";
    int length_result = length_a - length_b + 1;
    char x[length_result+1];
    x[length_result] = 0;
    x[0] = '5';
    for (int i=1; i<length_result; i++) x[i] = '0';
    BigNumber result(x);
    if(n.sign!=n3.sign) result.sign = 0;
    //cout << n1 << " " << n2;
  //  cout <<length_result << " " << result << endl;
    for (int i=length_result-1;i>=0;i--)
    {
        int mid;
        int be = 0;
        int en = 9;
        //cout << result << endl;
        while (be<en)
        {
            if (be==(en-1))
            {
                result.digitpairs[i] = itoa(en);
                if (n1>=(result*n2));
                else result.digitpairs[i] = itoa(be);
                break;
            }
            else
            {
                mid = be+(en-be)/2;
                result.digitpairs[i] = itoa(mid);
                if ((result*n2)>=n1)
                {
                    en = mid;
                }
                else if (n1>(result*n2))
                {
                    be = mid;
                }
            }
        }
    }
    return result;
}

const BigNumber operator%(const BigNumber& n1,const BigNumber& n2)
{
    BigNumber result;
    result = n1-(n1/n2)*n2;
    result.sign = 1;
    return result;
}

const BigNumber operator++(BigNumber& n1)
{
    BigNumber x("1");
    n1=n1+x;
    return n1;
}

const BigNumber operator++(BigNumber& n1, int)
{
    BigNumber n2(n1),x("1");
    n1= n1+x;
    return n2;
}

const BigNumber operator--(BigNumber& n1)
{
    BigNumber x("1");
    n1 = n1-x;
    return n1;
}

const BigNumber operator--
(BigNumber& n1, int)
{
    BigNumber n2(n1),x("1");
    n1 = n1-x;
    return n2;
}

unsigned char& BigNumber::operator[](unsigned int i)
{
    return digitpairs[i];
}

char* BigNumber::toArray() const
{
    int i,j=0,n = length();
    char *x = new char[n+1];
    if(sign == 0) {
        x[0]='-';
        j++;
    }
    for(i = 0; digitpairs[n-i-1] == '0' && i<digitpairs.size()-1;i++);
    for(; i<n; i++){
        x[j]=digitpairs[n-i-1];
        j++;
    }
    x[j] = 0;
    return x;
}
