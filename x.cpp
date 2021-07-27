#include<iostream>
#define sal 300000
#define enh 400000
#define houseallowance 150000
#define enh 400000
#define tax sal * 0.5/100
#define tithe enh * 0.1
#define paye tax + tax + tax
#define grosspay 850000
#define netpay 750000
using namespace std;
int main()
{
    cout <<  " Access Bank plc" << endl;
    cout << "Staff Name: Akande Oyebola\t\t\tStaff ID: 12789 "<<endl;
    cout << "Rank: Senior Staff"<<endl;
    cout << "Addition\t|\tDeduction"<<endl;
    cout << sal<<"\t|\t"<<tithe<<endl;
    cout << enh<<"\t|\t"<<tax<<endl;
    cout <<houseallowance<<"\t|\t"<<paye<<endl;
    cout <<"__________________________"<<endl;
    cout <<grosspay<<"\t|\t"<<netpay<<endl;
    cout <<"__________________________"<<endl;
}