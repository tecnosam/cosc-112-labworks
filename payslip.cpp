#include <iostream>
#include <string>
#define TITHE(sal) (sal*0.1)
#define TAX(sal) (sal*0.25)
#define PAYE(sal) (sal*0.058)

using namespace std;

int main() {

    const int sal_map[7] = {500000, 350000, 200000, 150000, 50000, 10000, 5000};
    const string lev_map[7] = {"Professor", "senior Lecturer", "Lecturer", "Asst Lecturer", "Graduat Asst", "Lab tech", "NA"};
    // Prof, senior_lect, lect, Asst_lect, grad_asst, lab_tech, NON TEACHING

    string name, dept, etype;

    int type, staff_code, level;

    float gross_pay, sal, living_cost, enhance, net_pay;

    cout<<"Input your staff code: ";
    cin>>staff_code;

    cin.ignore();

    cout<<"Input your name: ";
    getline( cin, name );

    cout<<"\n (1) Teaching staff\n (2) Non-teaching staff\n Employee type: "; 
    cin>>type;
    etype = type == 1? "Teaching" : "Non teaching";

    if (type == 1){
        cin.ignore();

        cout<<"What department are you in: ";
        getline( cin, dept );

        cout<<"Input a number between 1-6"<<endl;
        cout<<"1) Proffessor"<<endl;
        cout<<"2) Senior Lecturer"<<endl;
        cout<<"3) Lecturer"<<endl;
        cout<<"4) Assistant lecturer"<<endl;
        cout<<"5) Graduate Assistant"<<endl;
        cout<<"6) Lab Tech"<<endl;
        cin>>level;
    
        sal = sal_map[ level - 1 ];

    } else {
        dept = "NA";
        level = 7;
        sal = sal_map[6];
    }


    cout<<"Input your monthly expenses (0 to skip): ";
    cin>>living_cost;

    cout<<"Input your enhancement benefits: ";
    cin>>enhance;

    gross_pay = sal + enhance;

    net_pay = gross_pay - ( TITHE(sal) + TAX(sal) + PAYE(sal) + living_cost );

    cout<<"\t\tBABCOCK UNIVERSITY SLIP\t\t"<<endl;
    cout<<endl<<"Staff code: "<<staff_code<<"\t\tstaff name: "<<name<<endl;
    cout<<"Dept: "<<dept<<"\t\tlevel: "<<lev_map[ level-1 ]<<"\nEmployee Type: "<<etype;
    cout<<"\n\n\n\nGrossPay: "<<gross_pay<<"\n\nEarning\tAmount\n"<<"Basic salary:\t"<<sal<<endl;
    cout<<"Tax:\t\t"<<TAX(sal)<<endl; 
    cout<<"Tithe:\t\t"<<TITHE(sal)<<endl;
    cout<<"PAYE:\t\t"<<PAYE(sal)<<endl;
    cout<<"Cost of living: "<<living_cost<<endl;
    cout<<"Enhance:\t\t"<<enhance<<endl;
    cout<<"\n\nNET PAY: "<<net_pay<<endl;

    return 0;
}