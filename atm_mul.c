
/* ATM THAT ALLOWS ITS USERS TO
    1) DEPOSIT FUNDS
    2) CHECK BALANCE
    3) wITHDRAW FUNDS
*/
#include <stdio.h>

typedef struct Account {
    int acc_num;
    char *name;
    int pin;
    float bal;
} Account;


Account acc[ 100 ];
// DECLARING FUNCTIONS
void deposit_fund( int cur );
void withdraw_fund( int cur );

void displayMenu();

int login(); // returns index of logged in user

int main() {

    int option;
    
    int cur = login(); // index of the current user

    if (cur == -1) {
        printf("Your login details are not correct!\n")
        return 1;
    }

    do {
        displayMenu();
        printf("Input an option from 1- 3: ");
        scanf( "%d", &option );

        switch ( option ) {
            case 1:
                deposit_fund( cur );
                break;
            case 2:
                printf( "Your account balance is #%0.2f\n", acc[cur].bal );
                break;
            case 3:
                withdraw_fund( cur );
                break;
            case 4:
                printf("Bye Bye\n");
                break;
        }
    } while ( option != 4 );

    return 0;
}
// kolawaleteke96@gmail.com
// check out hackerrank.com to practice C
// check out codingame.com to practice C
// check out leetcode and codewars to practice C
int login() {
    int acc_num, pin;

    printf("Account number: ");
    scanf( "%d", &acc_num );

    printf( "Pin: " );
    scanf( "%d", &pin );

    // linear search
    for ( int i = 0; i < 100; i++ ) {

        if (arr[ i ].acc_num == acc_num) {
            if ( arr[ i ].pin == pin ) {
                printf("WELCOME %s \n", acc[i].name);
                return i;
            }
        }

    }

    return -1;

}

void displayMenu() {
    printf("PICK AN OPTION\n");
    printf("1) DEPOSIT FUND\n");
    printf("2) CHECK BALANCE\n");
    printf("3) WITHDRAW FUND\n");
    printf("4) QUIT\n");

}

void deposit_fund( int cur ) {
    float amnt;
    printf("How much would you like to deposit? ");
    scanf( "%f", &amnt );

    acc[cur].bal += amnt;
}

void withdraw_fund(int cur) {
    float amnt;
    printf("How much would you like to withdraw? ");
    scanf( "%f", &amnt );

    acc[cur].bal -= amnt;
}
