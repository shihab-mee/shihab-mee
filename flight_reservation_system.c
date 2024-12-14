#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESERVATIONS 100
#define NAME_LENGTH 50
#define FLIGHT_NUMBER_LENGTH 10
#define DATE_LENGTH 11
#define DESTINATION_LENGTH 50
#define SEAT_NUMBER_LENGTH 5
#define CONTACT_LENGTH 15
#define EMAIL_LENGTH 50
#define REQUEST_LENGTH 100

typedef struct {
    char passengerName[NAME_LENGTH];
    char flightNumber[FLIGHT_NUMBER_LENGTH];
    char departureDate[DATE_LENGTH];
    char destination[DESTINATION_LENGTH];
    char seatNumber[SEAT_NUMBER_LENGTH];
    char contactNumber[CONTACT_LENGTH];
    char email[EMAIL_LENGTH];
    char specialRequests[REQUEST_LENGTH];
} Reservation;

Reservation reservations[MAX_RESERVATIONS];
int reservationCount = 0;

void addReservation();
void displayReservations();
void searchReservation();
void updateReservation();
void deleteReservation();
void saveToFile();
void loadFromFile();
void sortReservations();
void filterReservations();
void displayStatistics();
void showMenu();

int main() {
    loadFromFile();
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addReservation(); break;
            case 2: displayReservations(); break;
            case 3: searchReservation(); break;
            case 4: updateReservation(); break;
            case 5: deleteReservation(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 8: sortReservations(); break;
            case 9: filterReservations(); break;
            case 10: displayStatistics(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}

void showMenu() {
    printf("\nFlight Reservation System Menu:\n");
    printf("1. Add Reservation\n");
    printf("2. Display Reservations\n");
    printf("3. Search Reservation\n");
    printf("4. Update Reservation\n");
    printf("5. Delete Reservation\n");
    printf("6. Save Reservations to File\n");
    printf("7. Load Reservations from File\n");
    printf("8. Sort Reservations\n");
    printf("9. Filter Reservations\n");
    printf("10. Display Statistics\n");
    printf("0. Exit\n");
}

void inputReservationDetails(Reservation *reservation) {
    printf("Enter passenger name: ");
    scanf(" %[^\n]", reservation->passengerName);
    printf("Enter flight number: ");
    scanf(" %[^\n]", reservation->flightNumber);
    printf("Enter departure date (YYYY-MM-DD): ");
    scanf(" %[^\n]", reservation->departureDate);
    printf("Enter destination: ");
    scanf(" %[^\n]", reservation->destination);
    printf("Enter seat number: ");
    scanf(" %[^\n]", reservation->seatNumber);
    printf("Enter contact number: ");
    scanf(" %[^\n]", reservation->contactNumber);
    printf("Enter email address: ");
    scanf(" %[^\n]", reservation->email);
    printf("Enter special requests: ");
    scanf(" %[^\n]", reservation->specialRequests);
}

void addReservation() {
    if (reservationCount >= MAX_RESERVATIONS) {
        printf("Reservation limit reached.\n");
        return;
    }
    Reservation newReservation;
    inputReservationDetails(&newReservation);
    
    reservations[reservationCount++] = newReservation;
    printf("Reservation added successfully.\n");
}

void displayReservations() {
    if (reservationCount == 0) {
        printf("No reservations found.\n");
        return;
    }
    printf("\nReservations:\n");
    for (int i = 0; i < reservationCount; i++) {
        printf("Reservation %d:\n", i + 1);
        printf("Passenger Name: %s\n", reservations[i].passengerName);
        printf("Flight Number: %s\n", reservations[i].flightNumber);
        printf("Departure Date: %s\n", reservations[i].departureDate);
        printf("Destination: %s\n", reservations[i].destination);
        printf("Seat Number: %s\n", reservations[i].seatNumber);
        printf("Contact Number: %s\n", reservations[i].contactNumber);
        printf("Email: %s\n", reservations[i].email);
        printf("Special Requests: %s\n", reservations[i].specialRequests);
        printf("-------------------------\n");
    }
}

void searchReservation() {
    char searchTerm[NAME_LENGTH];
    printf("Enter passenger name or flight number to search: ");
    scanf(" %[^\n]", searchTerm);
    
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].passengerName, searchTerm) == 0 || 
            strcmp(reservations[i].flightNumber, searchTerm) == 0) {
            printf("Reservation found:\n");
            printf("Passenger Name: %s\n", reservations[i].passengerName);
            printf("Flight Number: %s\n", reservations[i].flightNumber);
            printf("Departure Date: %s\n", reservations[i].departureDate);
            printf("Destination: %s\n", reservations[i].destination);
            printf("Seat Number: %s\n", reservations[i].seatNumber);
            printf("Contact Number: %s\n", reservations[i].contactNumber);
            printf("Email: %s\n", reservations[i].email);
            printf("Special Requests: %s\n", reservations[i].specialRequests);
            return;
        }
    }
    printf("No reservation found for the given name or flight number.\n");
}

void updateReservation() {
    char searchTerm[NAME_LENGTH];
    printf("Enter passenger name or flight number to update: ");
    scanf(" %[^\n]", searchTerm);
    
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].passengerName, searchTerm) == 0 || 
            strcmp(reservations[i].flightNumber, searchTerm) == 0) {
            printf("Updating reservation for %s:\n", reservations[i].passengerName);
            printf("Enter new passenger name: ");
            scanf(" %[^\n]", reservations[i].passengerName);
            printf("Enter new flight number: ");
            scanf(" %[^\n]", reservations[i].flightNumber);
            printf("Enter new departure date (YYYY-MM-DD): ");
            scanf(" %[^\n]", reservations[i].departureDate);
            printf("Enter new destination: ");
            scanf(" %[^\n]", reservations[i].destination);
            printf("Enter new seat number: ");
            scanf(" %[^\n]", reservations[i].seatNumber);
            printf("Enter new contact number: ");
            scanf(" %[^\n]", reservations[i].contactNumber);
            printf("Enter new email address: ");
            scanf(" %[^\n]", reservations[i].email);
            printf("Enter new special requests: ");
            scanf(" %[^\n]", reservations[i].specialRequests);
            printf("Reservation updated successfully.\n");
            return;
        }
    }
    printf("No reservation found for the given name or flight number.\n");
}

void deleteReservation() {
    char searchTerm[NAME_LENGTH];
    printf("Enter passenger name or flight number to delete: ");
    scanf(" %[^\n]", searchTerm);
    
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].passengerName, searchTerm) == 0 || 
            strcmp(reservations[i].flightNumber, searchTerm) == 0) {
            for (int j = i; j < reservationCount - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            reservationCount--;
            printf("Reservation deleted successfully.\n");
            return;
        }
    }
    printf("No reservation found for the given name or flight number.\n");
}

void saveToFile() {
    FILE *file = fopen("reservations.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < reservationCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
                reservations[i].passengerName, 
                reservations[i].flightNumber, 
                reservations[i].departureDate, 
                reservations[i].destination, 
                reservations[i].seatNumber,
                reservations[i].contactNumber,
                reservations[i].email,
                reservations[i].specialRequests);
    }
    fclose(file);
    printf("Reservations saved to file successfully.\n");
}

void loadFromFile() {
    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    while (1) {
        Reservation tempReservation;
        if (fscanf(file, " %49[^,],%9[^,],%10[^,],%49[^,],%4[^,],%14[^,],%49[^,],%99[^,\n]\n", 
                   tempReservation.passengerName, 
                   tempReservation.flightNumber, 
                   tempReservation.departureDate, 
                   tempReservation.destination, 
                   tempReservation.seatNumber,
                   tempReservation.contactNumber,
                   tempReservation.email,
                   tempReservation.specialRequests) != 8) {
            break; // Exit loop if not all fields are read
        }
        reservations[reservationCount++] = tempReservation; // Add to reservations
    }
    fclose(file);
    printf("Reservations loaded from file successfully.\n");
}

void sortReservations() {
    // Implement sorting logic here (e.g., by passenger name or date)
    printf("Sorting reservations...\n");
    // Example sorting by passenger name
    for (int i = 0; i < reservationCount - 1; i++) {
        for (int j = i + 1; j < reservationCount; j++) {
            if (strcmp(reservations[i].passengerName, reservations[j].passengerName) > 0) {
                Reservation temp = reservations[i];
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
    printf("Reservations sorted successfully.\n");
}

void filterReservations() {
    char destination[DESTINATION_LENGTH];
    printf("Enter destination to filter: ");
    scanf(" %[^\n]", destination);
    
    printf("\nFiltered Reservations:\n");
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].destination, destination) == 0) {
            printf("Passenger Name: %s\n", reservations[i].passengerName);
            printf("Flight Number: %s\n", reservations[i].flightNumber);
            printf("Departure Date: %s\n", reservations[i].departureDate);
            printf("Seat Number: %s\n", reservations[i].seatNumber);
            printf("Contact Number: %s\n", reservations[i].contactNumber);
            printf("Email: %s\n", reservations[i].email);
            printf("Special Requests: %s\n", reservations[i].specialRequests);
            printf("-------------------------\n");
        }
    }
}

void displayStatistics() {
    printf("Total Reservations: %d\n", reservationCount);
    // Additional statistics can be added here
}