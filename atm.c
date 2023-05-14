#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void withdraw();
void deposit();
void checkBalance();
void changePin();

// Global variables
int balance = 10000;
int pin = 1234;

int main() {
    int choice;

    printf("*** Welcome to the ATM machine ***\n");
    printf("Please enter your 4-digit PIN: ");
    scanf("%d", &pin);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                withdraw();
                break;
            case 2:
                deposit();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                changePin();
                break;
            case 5:
                printf("Thank you for using the ATM machine. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Withdraw money\n");
    printf("2. Deposit money\n");
    printf("3. Check balance\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
}

// Function to withdraw money
void withdraw() {
    int amount;

    printf("Enter the amount to withdraw: ");
    scanf("%d", &amount);

    if (amount > balance) {
        printf("Insufficient balance. Please try again.\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful. Your new balance is %d.\n", balance);
    }
}

// Function to deposit money
void deposit() {
    int amount;

    printf("Enter the amount to deposit: ");
    scanf("%d", &amount);

    balance += amount;
    printf("Deposit successful. Your new balance is %d.\n", balance);
}

// Function to check balance
void checkBalance() {
    printf("Your balance is %d.\n", balance);
}

// Function to change PIN
void changePin() {
    int newPin, confirmPin;

    printf("Enter your new 4-digit PIN: ");
    scanf("%d", &newPin);

    printf("Confirm your new 4-digit PIN: ");
    scanf("%d", &confirmPin);

    if (newPin == confirmPin) {
        pin = newPin;
        printf("PIN changed successfully.\n");
    } else {
        printf("PINs do not match. Please try again.\n");
    }
}
