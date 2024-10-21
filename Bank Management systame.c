#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store account information
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Array to store multiple accounts
Account accounts[MAX];
int accountCount = 0;

// Function prototypes
void createAccount();
void viewAccount();
void deposit();
void withdraw();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n----- Bank Management System -----\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    getchar(); // to consume the leftover newline character
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0'; // remove newline character
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

// Function to view account details
void viewAccount() {
    int accountNumber, found = 0;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to deposit money into an account
void deposit() {
    int accountNumber, found = 0;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully!\n");
            printf("New Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to withdraw money from an account
void withdraw() {
    int accountNumber, found = 0;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance < amount) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully!\n");
                printf("New Balance: %.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}
