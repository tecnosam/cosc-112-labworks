#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef struct MenuItem{
    char option;
    string title;
    string category;
} MenuItem;

class Product {
    public:
        Product() {}
        Product( string n, float p, string cat ) {
            name = n;
            price = p;
            category = cat;
        }
        string name;
        float price;
        string category;
};

vector<Product> products;
vector<MenuItem> menu;

void displayMenu( );
int listProducts( char option );
void displayReceipt( vector<Product*> cart );
void loadData( string pfn, string mfn );


int main() {
    char face_m, id_card;

    cout<<"Are you wearing a facemask? (y/n): ";
    cin>>face_m;

    cout<<"Are you wearing your ID card? (y/n): ";
    cin>>id_card;

    if ( face_m == 'y' && id_card == 'y' ) {
        char option;
        vector<Product*> cart;

        loadData( "data.txt", "menu.txt" );
        system("clear");


        do {
            displayMenu();

            cout<<"Where would you like to go: ";
            cin>>option;
            system("clear");

            option = toupper( option );
            int n_products = listProducts( option );
            if (n_products) {
                for ( ; ; ) {
                    int item_i; // item user is about to purchase
                    cout<<"Input number behind product: ";
                    cin>>item_i;
                    if (item_i == 0) {
                        system("clear");
                        break;
                    }
                    cart.push_back( &(products[ item_i - 1 ]) );
                    cout<<"Product "<< products[ item_i -1].name <<" added to cart successfully :->"<<endl<<endl;
                }
            } else {
                switch ( option ) {
                    case 'V':
                        // view receipt
                        displayReceipt( cart );
                        break;
                    case 'Q':
                        // Q to exit and print out receipt
                        break;
                    default:
                        cout<<"Could not find section in our store: Please try something else";
                        cout<<endl;
                }
            }
        } while ( option != 'Q' );
    }else {
        cout<<"You need a face mask and an ID card to enter :-("<<endl;
    }

    return 0;
}

void loadData( string pfn, string mfn ) {

    string line;

    ifstream pfile( pfn ), mfile( mfn );

    // load products
    if ( pfile.is_open() ) {

        string name, category;
        float price;

        while ( getline( pfile, line ) ) {

            if ( line == "----" ) {

                getline( pfile, name );
                getline( pfile, category );
                pfile >> price;
                products.push_back( Product( name, price, category ) );

                // cout<<name<<" "<<price<<" "<<category<<endl;

            }
        }

        pfile.close();

    }

    // load menu
    if ( mfile.is_open() ) {
        MenuItem m; // option title
        while ( getline( mfile, line ) ) {
            if ( line == "----" ) {
                getline( mfile, m.title );
                getline( mfile, m.category );
                mfile>>m.option;
                menu.push_back( m );
            }
        }
        mfile.close();
    }

    return;

}

int listProducts( char option ) {
    cout<<endl;

    MenuItem *m = NULL;

    for ( int i = 0; i < menu.size(); i++ ) {

        if ( menu[i].option == option ) {
            m = new MenuItem;
            if (m == NULL) {
                cerr<<"You've run out of computer memory :-("<<endl;
                cerr<<"Bros, shey na 12kb ram you dey use ni?"<<endl;
                return 0;
            }
            m->category = menu[i].category;
            m->title = menu[i].title;
            m->option = menu[i].option;
            break;
        }

    }

    if (m == NULL) {
        cout<<"This section is not in BU mall"<<endl<<endl;
        return 0;
    }
    int n = 0;
    cout<<"\t\t"<<m->title<<" AT BU MALL"<<endl;
    for ( int i = 0; i < products.size(); i++ ) {
        if ( products[i].category == m->category ) {
            cout<<"\t"<<i+1<<") "<<products[i].name<<"\t$";
            cout<<products[i].price<<endl;
            n++;
        }
    }
    if (n){

        cout<<"\t0) Back to main menu\t$0"<<endl;
    }
    cout<<endl;
    return n;

}

void displayMenu() {

    cout<<"\t\tBU SHOPPING MALL"<<endl<<endl;

    for ( int i = 0; i < menu.size(); i++ ) {
        cout<<"\tPress "<<menu[i].option<<" to visit "<<menu[i].title<<endl;
    }

    cout<<endl;
}


void displayReceipt( vector<Product*> cart ) {
    if (!(cart.size())) {
        return;
    }
    int n_products = 0;
    float bill = 0;
    for (int j = 0; j < cart.size(); j++) {
        n_products++;
        bill += cart[j]->price;
        cout<<"\t$"<<cart[j]->price<<"\t\t"<<cart[j]->name<<endl;
    }

    cout<<"\t$"<<bill<<"\t\tTotal("<<n_products<<")"<<endl;

    cout<<endl;
}