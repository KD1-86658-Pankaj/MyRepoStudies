#include <stdio.h>

// Define the structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Function to initialize the date
void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}


void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}


void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}


int main() {
    struct Date myDate;
    int choice;

    initDate(&myDate);

    do {
        printf("\nMenu:\n");
        printf("1. Accept Date from Console\n");
        printf("2. Print Date on Console\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptDateFromConsole(&myDate);
                break;
            case 2:
                printDateOnConsole(&myDate);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}