#include <iostream>

using namespace std;

int main() {
    int ticket, face_m, entrance, medical, veg;

    cout<<"NOTE: Input any number for yes and 0 for no"<<endl;

    cout<<"Do you have meal ticket: ";
    cin>>ticket;

    cout<<"Do you have face mask? ";
    cin>>face_m;

    if ( ticket && face_m ){

        cout<<"Are you at the entrance? ";
        cin>>entrance;

        if (entrance) {
            cout<<"Are you a vegetarian? ";
            cin>>veg;

            cout<<"Are you a medical student? ";
            cin>>medical;

            system("clear"); // use cls if running on windows 

            cout<<"\t\tBU CAFE\n";
            cout<<"\tStudent type: ";

            if (medical) {

                cout<<"Medical"<<endl;
                cout<<"meal: "<<"Fried rice";

                if (veg) {
                    cout<<" and boiled egg"<<endl;
                } else {
                    cout<<" and Goat meat"<<endl;
                }

            } else {

                cout<<"Non-medical"<<endl;
                cout<<"\tmeal: "<<"Jollof rice";

                if (veg) {
                    cout<<" and Tofu"<<endl;
                } else {
                    cout<<" and Beef"<<endl;
                }

            }


        } else {
            cout<<"You have to be at the entrance to get some food: "<<endl;
        }
    
    } else {
        cout<<"You need your facemask and meal ticket to proceed to the entrance :( "<<endl;
    }

    return 0;
}