#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string email;
    string pwd;
    string name;
    int n_followers;

public:
// created a function get_name
    string get_name() {
        return name;
    }

            void set_name( string n ) {
        name = n;
    }

};

int main() {
    User jack;
    cout<<jack.get_name()<<endl;

    return 0;
}