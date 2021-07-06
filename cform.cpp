#include <iostream>
#include <string>
using namespace std;


struct Course {
    string title;
    string code;
    int units;
    string lecturer;
};

int main() {
    int n; // number of courses
    cout<<"How many courses: ";
    cin>>n;

    // array of Courses of length n
    struct Course courses[ n ];

    for ( int i = 0; i < n; i++ ) {

        cin.ignore( 1, '\n' );
        cout<<"Input course title "<<i+1<<" ";
        getline( cin, courses[ i ].title );

        cout<<"Input course code "<<i+1<<" ";
        getline( cin, courses[i].code );

        cout<<"Input course units "<<i+1<<" ";
        cin>>courses[ i ].units;

        cin.ignore( 1, '\n' );
        cout<<"Input course lecturer "<<i+1<<" ";
        getline( cin, courses[ i ].lecturer );

    }
    cout<<"Course Title\tCourse code\tunits\tLecturer\n";

    for ( int i = 0; i < n; i++ ) {

        cout<<courses[i].title<<"\t"<<courses[i].code<<"\t"<<courses[i].units<<"\t";
        cout<<courses[i].lecturer<<"\n";
    }

    return 0;
}