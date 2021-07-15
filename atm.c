
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


Account acc;
// DECLARING FUNCTIONS
void deposit_fund(  );
void withdraw_fund(  );

void displayMenu();

int main() {
    int option;

    acc.acc_num = 1234567890;
    acc.name = "Mosh Hamedani";
    acc.pin = 1000;
    acc.bal = 0.0;

    do {
        displayMenu();
        printf("Input an option from 1- 3: ");
        scanf( "%d", &option );

        switch ( option ) {
            case 1:
                deposit_fund();
                break;
            case 2:
                printf( "Your account balance is #%0.2f\n", acc.bal );
                break;
            case 3:
                withdraw_fund();
                break;
            case 4:
                printf("Bye Bye\n");
                break;
        }
    } while ( option != 4 );

    return 0;
}

void displayMenu() {
    printf("PICK AN OPTION\n");
    printf("1) DEPOSIT FUND\n");
    printf("2) CHECK BALANCE\n");
    printf("3) WITHDRAW FUND\n");
    printf("4) QUIT\n");

}

void deposit_fund() {
    float amnt;
    printf("How much would you like to deposit? ");
    scanf( "%f", &amnt );

    acc.bal += amnt;
}

void withdraw_fund() {
    float amnt;
    printf("How much would you like to withdraw? ");
    scanf( "%f", &amnt );

    acc.bal -= amnt;
}
