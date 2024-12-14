#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESERVATIONS 100

typedef struct {
    char name[50];
    char flightNumber[10];
    char departureDate[15];
    char destination[50];
    int seatNumber;
} Reservation;

Reservation reservations[MAX_RESERVATIONS];
int reservationCount = 0;

void addReservation();
void displayReservations();
void searchReservation();
void updateReservation();
void saveToFile();
void loadFromFile();
void menu();

void addReservation() {
    if (reservationCount >= MAX_RESERVATIONS) {
        printf("\n[Error] Maximum reservations reached. Cannot add more.\n");
        return;
    }

    Reservation newReservation;
    printf("\nEnter passenger name: ");
    scanf(" %[^\n]s", newReservation.name);
    printf("Enter flight number: ");
    scanf(" %[^\n]s", newReservation.flightNumber);
    printf("Enter departure date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", newReservation.departureDate);
    printf("Enter destination: ");
    scanf(" %[^\n]s", newReservation.destination);
    printf("Enter seat number: ");
    scanf("%d", &newReservation.seatNumber);

    reservations[reservationCount++] = newReservation;
    printf("\n[Success] Reservation added successfully!\n");
}

void displayReservations() {
    if (reservationCount == 0) {
        printf("\n[Info] No reservations to display.\n");
        return;
    }

    printf("\n==============================\n");
    printf("       All Reservations       \n");
    printf("==============================\n");
    for (int i = 0; i < reservationCount; i++) {
        printf("\nReservation %d:\n", i + 1);
        printf("Name: %s\n", reservations[i].name);
        printf("Flight Number: %s\n", reservations[i].flightNumber);
        printf("Departure Date: %s\n", reservations[i].departureDate);
        printf("Destination: %s\n", reservations[i].destination);
        printf("Seat Number: %d\n", reservations[i].seatNumber);
    }
    printf("\n==============================\n");
}

void searchReservation() {
    char searchKey[50];
    printf("\nEnter passenger name or flight number to search: ");
    scanf(" %[^\n]s", searchKey);

    int found = 0;
    printf("\n==============================\n");
    printf("       Search Results         \n");
    printf("==============================\n");
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].name, searchKey) == 0 || strcmp(reservations[i].flightNumber, searchKey) == 0) {
            printf("\nReservation found:\n");
            printf("Name: %s\n", reservations[i].name);
            printf("Flight Number: %s\n", reservations[i].flightNumber);
            printf("Departure Date: %s\n", reservations[i].departureDate);
            printf("Destination: %s\n", reservations[i].destination);
            printf("Seat Number: %d\n", reservations[i].seatNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("\n[Info] No reservation found with the given details.\n");
    }
    printf("\n==============================\n");
}

void updateReservation() {
    char searchKey[50];
    printf("\nEnter passenger name or flight number to update: ");
    scanf(" %[^\n]s", searchKey);

    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].name, searchKey) == 0 || strcmp(reservations[i].flightNumber, searchKey) == 0) {
            printf("\nUpdating reservation:\n");
            printf("Enter new passenger name: ");
            scanf(" %[^\n]s", reservations[i].name);
            printf("Enter new flight number: ");
            scanf(" %[^\n]s", reservations[i].flightNumber);
            printf("Enter new departure date (YYYY-MM-DD): ");
            scanf(" %[^\n]s", reservations[i].departureDate);
            printf("Enter new destination: ");
            scanf(" %[^\n]s", reservations[i].destination);
            printf("Enter new seat number: ");
            scanf("%d", &reservations[i].seatNumber);

            printf("\n[Success] Reservation updated successfully!\n");
            return;
        }
    }

    printf("\n[Info] No reservation found with the given details.\n");
}

void saveToFile() {
    FILE *file = fopen("reservations.dat", "wb");
    if (!file) {
        printf("\n[Error] Unable to save reservations to file.\n");
        return;
    }

    fwrite(&reservationCount, sizeof(int), 1, file);
    fwrite(reservations, sizeof(Reservation), reservationCount, file);
    fclose(file);
    printf("\n[Success] Reservations saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("reservations.dat", "rb");
    if (!file) {
        printf("\n[Info] No saved reservations found.\n");
        return;
    }

    fread(&reservationCount, sizeof(int), 1, file);
    fread(reservations, sizeof(Reservation), reservationCount, file);
    fclose(file);
    printf("\n[Success] Reservations loaded from file successfully!\n");
}

void menu() {
    int choice;

    do {
        printf("\n=====================================");
        printf("\n       Flight Reservation System       ");
        printf("\n=====================================");
        printf("\n1. Add Reservation");
        printf("\n2. Display Reservations");
        printf("\n3. Search Reservation");
        printf("\n4. Update Reservation");
        printf("\n5. Save Reservations to File");
        printf("\n6. Load Reservations from File");
        printf("\n7. Exit");
        printf("\n=====================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n>> Adding a New Reservation <<\n");
                addReservation();
                break;
            case 2:
                printf("\n>> Displaying All Reservations <<\n");
                displayReservations();
                break;
            case 3:
                printf("\n>> Searching for a Reservation <<\n");
                searchReservation();
                break;
            case 4:
                printf("\n>> Updating an Existing Reservation <<\n");
                updateReservation();
                break;
            case 5:
                printf("\n>> Saving Reservations to File <<\n");
                saveToFile();
                break;
            case 6:
                printf("\n>> Loading Reservations from File <<\n");
                loadFromFile();
                break;
            case 7:
                printf("\nThank you for using the Flight Reservation System. Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid choice. Please try again.\n");
        }
        printf("\n=====================================");
    } while (choice != 7);
}

int main() {
    loadFromFile();
    menu();
    saveToFile();
    return 0;
}
