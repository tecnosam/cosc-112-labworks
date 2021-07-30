#include <iostream>

using namespace std;

int main() {
    int loop, n = 6;

    cout<<"Which of the patterns do you want. 1,2,3 or 4: ";
    cin>>loop;


    switch (loop) {

        case 1:
            for ( int i = n; i > 0; i-- ) {
                for ( int j = i; j > 0; j-- ) {
                    cout<<"*";
                }
                cout<<endl;
            }
            break;
        
        case 2:
            for ( int i = 1; i <= n; i++ ) {
                if ( i == n ) {
                    for ( int j = 0; j < n; j++ ) {
                        cout<<"*";
                    }
                    cout<<endl;
                } else {
                    cout<<"*\n";
                }
            }
            break;

        case 3:
            for ( int i = 0; i < n; i++ ) {
                cout<<"*\n";
            }
            break;

        case 4:
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j <= i; j++ ) {
                    cout<<"*";
                }
                cout<<endl;
            }
            break;
    }

    return 0;
}