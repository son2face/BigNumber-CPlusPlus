#include "BigNumber.h"
#include <stdio.h>
#include <winsock2.h>
using namespace std;
typedef struct DSLienket {
     char *ht;
     struct DSLienket *next;

} SinhVien;
SinhVien *pdau, *pcuoi;
int main()
{
    SinhVien *pnew;
    pdau = pcuoi = NULL;
    char *x = new char;
    FILE *Database = fopen("Database.txt","wb");
    BigNumber a("0");
    BigNumber b("9");
    BigNumber y("100");
    BigNumber k("10");
    for (BigNumber i("1"); i <= y;  i++)
    {
        a= a+i*b;
        b= b*k;
    }
    cout << a;
    return 0;
}
//9999999999999999999999999999999999999999999999999999999999999999999999999999999800000000000000000000000000000000000000000000000000000000000000000000000000000001
//10000000000000000000000000000000000000000000000000000000000000000000000000000009800000000000000000000000000000000000000000000000000000000000000000000000000000001
