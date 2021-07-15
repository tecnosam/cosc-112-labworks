#include <iostream>

#define N_GOODS 3

using namespace std;

void displayGoods( string *goods, float *prices );

int main() {
    // database
    string goods[N_GOODS] = {"Shoes", "slippers", "SchoolBag"};
    float prices[N_GOODS] = { 1000, 2000, 3000 };
    

    char face, id_card;

    cout<<"Do you have a face mask: (y/n) ";
    cin>>face;

    cout<<"Do you have your id card: (y/n) ";
    cin>>id_card;

    if ( face == 'y' && id_card == 'y' ) {
        int n, good;
        float total;
        // 
        do {
            cout<<"How many products are you buying: ";
            cin>>n;
            if ( n < 1 ) {
                cout<<"You must buy at least one product"<<endl;
            }
        } while( n < 1 );

        int cart[n];
        for (int i = 0; i < n; i++) {

            do {
                displayGoods( goods, prices );
                cout<<"Pick a number from 1-3 for product "<<i+1<<": ";
                cin>>good;
            } while ( good > 3 || good <= 0 );

            cart[i] = good-1;

        }
        system( "clear" );

        cout<<"\t\tBU MALL RECEIPT"<<endl;
        // print out the products
        for  ( int i = 0; i < n; i++ ) {

            cout<<"\t"<<i+1<<") "<<goods[ cart[i] ]<<"\t";
            cout<<prices[ cart[i] ]<<endl;
            total += prices[ cart[i] ];

        }
        cout<<"\t() Total\t"<<total<<endl;

    } else {
        // they cant enter the mall
        cout<<"ID card and/or facemask is required to enter the mall :-("<<endl;
    }

    return 0;

}

void displayGoods( string * goods, float * prices ) {
    for (int i = 0; i < N_GOODS; i++) {
        cout<<i+1<<" "<<*(goods + i)<<" - "<<prices[ i ]<<endl;
    }
    cout<<endl;

    return;
}