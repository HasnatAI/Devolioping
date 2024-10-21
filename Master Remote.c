#include <stdio.h>
#include <stdlib.h>

// Structure for a TV
typedef struct {
    int isOn;
    int volume;
    int channel;
} TV;

// Structure for an AC
typedef struct {
    int isOn;
    int temperature;
    int mode; // 0 = Cool, 1 = Heat, 2 = Fan
} AC;

// Function prototypes
void controlTV(TV *tv);
void controlAC(AC *ac);
void displayMainMenu();
void displayTVMenu();
void displayACMenu();

// Main function
int main() {
    TV tv = {0, 10, 1}; // TV starts off, volume 10, channel 1
    AC ac = {0, 24, 0}; // AC starts off, temperature 24°C, mode Cool

    int choice;
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlTV(&tv);
                break;
            case 2:
                controlAC(&ac);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    printf("\n----- Remote Control -----\n");
    printf("1. Control TV\n");
    printf("2. Control AC\n");
    printf("3. Exit\n");
}

// Function to control the TV
void controlTV(TV *tv) {
    int choice;
    while (1) {
        displayTVMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Turn TV On/Off
                tv->isOn = !tv->isOn;
                printf("TV is now %s.\n", tv->isOn ? "ON" : "OFF");
                break;
            case 2: // Change channel
                if (tv->isOn) {
                    printf("Enter channel number: ");
                    scanf("%d", &tv->channel);
                    printf("Channel changed to %d.\n", tv->channel);
                } else {
                    printf("TV is OFF. Turn it ON first.\n");
                }
                break;
            case 3: // Adjust volume
                if (tv->isOn) {
                    printf("Enter volume level (0-100): ");
                    scanf("%d", &tv->volume);
                    if (tv->volume < 0) tv->volume = 0;
                    if (tv->volume > 100) tv->volume = 100;
                    printf("Volume set to %d.\n", tv->volume);
                } else {
                    printf("TV is OFF. Turn it ON first.\n");
                }
                break;
            case 4: // Back to main menu
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to display the TV control menu
void displayTVMenu() {
    printf("\n----- TV Control -----\n");
    printf("1. Turn TV On/Off\n");
    printf("2. Change Channel\n");
    printf("3. Adjust Volume\n");
    printf("4. Back to Main Menu\n");
}

// Function to control the AC
void controlAC(AC *ac) {
    int choice;
    while (1) {
        displayACMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Turn AC On/Off
                ac->isOn = !ac->isOn;
                printf("AC is now %s.\n", ac->isOn ? "ON" : "OFF");
                break;
            case 2: // Set temperature
                if (ac->isOn) {
                    printf("Enter temperature (16-30°C): ");
                    scanf("%d", &ac->temperature);
                    if (ac->temperature < 16) ac->temperature = 16;
                    if (ac->temperature > 30) ac->temperature = 30;
                    printf("Temperature set to %d°C.\n", ac->temperature);
                } else {
                    printf("AC is OFF. Turn it ON first.\n");
                }
                break;
            case 3: // Change mode
                if (ac->isOn) {
                    printf("Select mode (0 = Cool, 1 = Heat, 2 = Fan): ");
                    scanf("%d", &ac->mode);
                    if (ac->mode < 0 || ac->mode > 2) {
                        ac->mode = 0; // Default to Cool if invalid
                    }
                    printf("AC mode set to %s.\n", ac->mode == 0 ? "Cool" : ac->mode == 1 ? "Heat" : "Fan");
                } else {
                    printf("AC is OFF. Turn it ON first.\n");
                }
                break;
            case 4: // Back to main menu
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to display the AC control menu
void displayACMenu() {
    printf("\n----- AC Control -----\n");
    printf("1. Turn AC On/Off\n");
    printf("2. Set Temperature\n");
    printf("3. Change Mode\n");
    printf("4. Back to Main Menu\n");
}
