#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100
#define MAX_BOOKINGS 100

typedef struct flight
{
    int fid;
    char fname[50];
    char source[50];
    char destination[50];
    float price;
    int seats;
} flight;

typedef struct passenger
{
    int pid;
    char pname[50];
    char passport[20];
    char phone[15];
} passenger;

typedef struct booking
{
    int bid;
    int fid;
    int pid;
    int seatsBooked;
    float totalCost;
} booking;

void addFlight(flight f[MAX_FLIGHTS], int flightCount);
void updateFlight(flight f[MAX_FLIGHTS], int flightCount);
int deleteFlight(flight f[MAX_FLIGHTS], int flightCount);
void displayFlights(flight f[MAX_FLIGHTS], int flightCount);

void addPassenger(passenger p[MAX_PASSENGERS], int passengerCount);
void updatePassenger(passenger p[MAX_PASSENGERS], int passengerCount);
int deletePassenger(passenger p[MAX_PASSENGERS], int passengerCount);
void displayPassengers(passenger p[MAX_PASSENGERS], int passengerCount);

int bookFlight(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount);
void updateBooking(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount);
int cancelBooking(booking b[MAX_BOOKINGS], int bookingCount);
void displayBookings(booking b[MAX_BOOKINGS], int bookingCount);

void search(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount);

void searchFlightById(flight f[MAX_FLIGHTS], int flightCount);
void searchPassengerById(passenger p[MAX_PASSENGERS], int passengerCount);
void searchBookingById(booking b[MAX_BOOKINGS], int bookingCount);

void displayFlightReport(flight f[MAX_FLIGHTS], int flightCount);
void displayPassengerReport(passenger p[MAX_PASSENGERS], int passengerCount);
void displayBookingReport(booking b[MAX_BOOKINGS], int bookingCount);

int main()
{
    flight f[MAX_FLIGHTS];
    passenger p[MAX_PASSENGERS];
    booking b[MAX_BOOKINGS];

    int flightCount = 0;
    int passengerCount = 0;
    int bookingCount = 0;

    int choice, choice1, choice2, choice3, choice4, w, x, y;

    FILE *fflight1;
    fflight1 = fopen("flight.txt", "r");

    fscanf(fflight1, "%d\n", &flightCount);

    for (int i = 0; i < flightCount; i++)
    {
        fscanf(fflight1, "%d;%50[^;];%50[^;];%50[^;];%f;%d\n", &f[i].fid, f[i].fname, f[i].source, f[i].destination, &f[i].price, &f[i].seats);
    }

    fclose(fflight1);

    FILE *fpassenger1;
    fpassenger1 = fopen("passenger.txt", "r");

    fscanf(fpassenger1, "%d\n", &passengerCount);

    for (int i = 0; i < passengerCount; i++)
    {
        fscanf(fpassenger1, "%d;%50[^;];%20[^;];%15[^\n]\n", &p[i].pid, p[i].pname, p[i].passport, p[i].phone);
    }

    fclose(fpassenger1);

    FILE *fbooking1;
    fbooking1 = fopen("booking.txt", "r");

    fscanf(fbooking1, "%d\n", &bookingCount);

    for (int i = 0; i < bookingCount; i++)
    {
        fscanf(fbooking1, "%d;%d;%d;%d;%f\n", &b[i].bid, &b[i].fid, &b[i].pid, &b[i].seatsBooked, &b[i].totalCost);
    }

    fclose(fbooking1);

    printf("***********Flight Management System***********\n\n");

    do
    {
        printf("\n********MAIN MENU********\n\n");
        printf("1. MANAGE FLIGHTS\n");
        printf("2. MANAGE PASSENGERS\n");
        printf("3. MANAGE BOOKINGS\n");
        printf("4. SEARCH\n");
        printf("5. REPORT\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\n******MANAGE FLIGHTS******\n\n");
                printf("1. ADD FLIGHT\n");
                printf("2. UPDATE FLIGHT\n");
                printf("3. DISPLAY FLIGHTS\n");
                printf("4. DELETE FLIGHT\n");
                printf("0. EXIT\n");

                scanf("%d", &choice1);

                switch (choice1)
                {
                case 1:
                    addFlight(f, flightCount);
                    flightCount++;
                    break;
                case 2:
                    updateFlight(f, flightCount);
                    break;
                case 3:
                    displayFlights(f, flightCount);
                    break;
                case 4:
                    w = deleteFlight(f, flightCount);
                    if (w == 1)
                    {
                        flightCount--;
                    }
                    else
                    {
                        printf("Flight not found!!!\n");
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }

                FILE *fflight;
                fflight = fopen("flight.txt", "w");

                fprintf(fflight, "%d\n", flightCount);

                for (int i = 0; i < flightCount; i++)
                {
                    fprintf(fflight, "%d;%s;%s;%s;%f;%d\n", f[i].fid, f[i].fname, f[i].source, f[i].destination, f[i].price, f[i].seats);
                }

                fclose(fflight);

            } while (choice1 != 0);
            break;

        case 2:
            do
            {
                printf("\n******MANAGE PASSENGERS******\n\n");
                printf("1. ADD PASSENGER\n");
                printf("2. UPDATE PASSENGER\n");
                printf("3. DISPLAY PASSENGERS\n");
                printf("4. DELETE PASSENGER\n");
                printf("0. EXIT\n");

                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                    addPassenger(p, passengerCount);
                    passengerCount++;
                    break;
                case 2:
                    updatePassenger(p, passengerCount);
                    break;
                case 3:
                    displayPassengers(p, passengerCount);
                    break;
                case 4:
                    x = deletePassenger(p, passengerCount);
                    if (x == 1)
                    {
                        passengerCount--;
                    }
                    else
                    {
                        printf("Passenger not found!!!\n");
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }

                FILE *fpassenger;
                fpassenger = fopen("passenger.txt", "w");

                fprintf(fpassenger, "%d\n", passengerCount);

                for (int i = 0; i < passengerCount; i++)
                {
                    fprintf(fpassenger, "%d;%s;%s;%s\n", p[i].pid, p[i].pname, p[i].passport, p[i].phone);
                }

                fclose(fpassenger);

            } while (choice2 != 0);
            break;

        case 3:
            do
            {
                printf("\n********MANAGE BOOKINGS********\n");
                printf("1. BOOK FLIGHT\n");
                printf("2. UPDATE BOOKING\n");
                printf("3. CANCEL BOOKING\n");
                printf("4. DISPLAY BOOKINGS\n");
                printf("0. EXIT\n");

                scanf("%d", &choice3);

                switch (choice3)
                {
                case 1:
                    y = bookFlight(f, p, b, flightCount, passengerCount, &bookingCount);
                    if (y == 1)
                    {
                        bookingCount++;
                    }
                    break;
                case 2:
                    updateBooking(f, p, b, flightCount, passengerCount, bookingCount);
                    break;
                case 3:
                    y = cancelBooking(b, &bookingCount);
                    if (y == 1)
                    {
                        bookingCount--;
                    }
                    else
                    {
                        printf("Booking not found!!!\n");
                    }
                    break;
                case 4:
                    displayBookings(b, bookingCount);
                    break;
                case 0:
                    break;
                }

                FILE *fbooking;
                fbooking = fopen("booking.txt", "w");

                fprintf(fbooking, "%d\n", bookingCount);

                for (int i = 0; i < bookingCount; i++)
                {
                    fprintf(fbooking, "%d;%d;%d;%d;%f\n", b[i].bid, b[i].fid, b[i].pid, b[i].seatsBooked, b[i].totalCost);
                }

                fclose(fbooking);

            } while (choice3 != 0);
            break;

        case 4:
            search(f, p, b, flightCount, passengerCount, bookingCount);
            break;

        case 5:
            do
            {
                printf("\n*REPORT*\n\n");
                printf("1. FLIGHT REPORT\n");
                printf("2. PASSENGER REPORT\n");
                printf("3. BOOKING REPORT\n");
                printf("0. EXIT\n");

                scanf("%d", &choice4);

                switch (choice4)
                {
                case 1:
                    displayFlightReport(f, flightCount);
                    break;
                case 2:
                    displayPassengerReport(p, passengerCount);
                    break;
                case 3:
                    displayBookingReport(b,bookingCount);
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid input!!!\n");
                    break;
                }
            } while (choice4 != 0);
            break;

        case 0:
            printf("Exiting program .......\n");
            break;

        default:
            printf("Invalid input. Please try again!!!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

void addFlight(flight f[MAX_FLIGHTS], int flightCount)
{
    printf("\nEnter Flight ID: ");
    scanf("%d", &f[flightCount].fid);

    printf("Enter Flight Name: ");
    scanf(" %[^\n]s", f[flightCount].fname);

    printf("Enter Source: ");
    scanf(" %[^\n]s", f[flightCount].source);

    printf("Enter Destination: ");
    scanf(" %[^\n]s", f[flightCount].destination);

    printf("Enter Price: ");
    scanf("%f", &f[flightCount].price);

    printf("Enter Number of Seats: ");
    scanf("%d", &f[flightCount].seats);

    printf("Flight added successfully!!\n");
   
}

void updateFlight(flight f[MAX_FLIGHTS], int flightCount)
{
    int id;
    printf("\nEnter Flight ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < flightCount; i++)
    {
        if (f[i].fid == id)
        {
            printf("Enter new Flight Name: ");
            scanf(" %[^\n]s", f[i].fname);

            printf("Enter new Source: ");
            scanf(" %[^\n]s", f[i].source);

            printf("Enter new Destination: ");
            scanf(" %[^\n]s", f[i].destination);

            printf("Enter new Price: ");
            scanf("%f", &f[i].price);

            printf("Enter new Number of Seats: ");
            scanf("%d", &f[i].seats);

            printf("Flight updated successfully!!!\n");
            return;
        }
    }
    printf("Flight ID not found!!!\n");
}

int deleteFlight(flight f[MAX_FLIGHTS], int flightCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the flight you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < flightCount; i++)
    {
        if (f[i].fid == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    for (int j = found; j < flightCount - 1; j++)
    {
        f[j] = f[j + 1];
    }
    printf("Flight deleted successfully!!!\n");
    return 1;
}

void displayFlights(flight f[MAX_FLIGHTS], int flightCount)
{
    for (int i = 0; i < flightCount; i++)
    {
        printf("\nFlight %d: \n", i + 1);
        printf("ID: %d, Name: %s, Source: %s, Destination: %s, Price: %.2f, Seats: %d\n",
               f[i].fid, f[i].fname, f[i].source, f[i].destination, f[i].price, f[i].seats);
    }
    if (flightCount == 0)
    {
        printf("No flight available!!!\n");
    }
}

void addPassenger(passenger p[MAX_PASSENGERS], int passengerCount)
{
    printf("\nEnter Passenger ID: ");
    scanf("%d", &p[passengerCount].pid);

    printf("Enter Passenger Name: ");
    scanf(" %[^\n]s", p[passengerCount].pname);

    printf("Enter Passport Number: ");
    scanf(" %[^\n]s", p[passengerCount].passport);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]s", p[passengerCount].phone);

    printf("Passenger added successfully!!\n");

}

void updatePassenger(passenger p[MAX_PASSENGERS], int passengerCount)
{
    int id;
    printf("\nEnter Passenger ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < passengerCount; i++)
    {
        if (p[i].pid == id)
        {
            printf("Enter new Passenger Name: ");
            scanf(" %[^\n]s", p[i].pname);

            printf("Enter new Passport Number: ");
            scanf(" %[^\n]s", p[i].passport);

            printf("Enter new Phone Number: ");
            scanf(" %[^\n]s", p[i].phone);

            printf("Passenger updated successfully!!!\n");
            return;
        }
    }
    printf("Passenger ID not found!!!\n");
}

int deletePassenger(passenger p[MAX_PASSENGERS], int passengerCount)
{
    int id, found = -1;
    printf("\nEnter the ID number of the passenger you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < passengerCount; i++)
    {
        if (p[i].pid == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    for (int j = found; j < passengerCount - 1; j++)
    {
        p[j] = p[j + 1];
    }
    printf("Passenger deleted successfully!!!\n");
    return 1;
}

void displayPassengers(passenger p[MAX_PASSENGERS], int passengerCount)
{
    for (int i = 0; i < passengerCount; i++)
    {
        printf("\nPassenger %d: \n", i + 1);
        printf("ID: %d, Name: %s, Passport: %s, Phone: %s\n",
               p[i].pid, p[i].pname, p[i].passport, p[i].phone);
    }
    if (passengerCount == 0)
    {
        printf("No passenger available!!!\n");
    }
}

int bookFlight(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount)
{
    int fid, pid, seats;
    printf("\nEnter Flight ID to book: ");
    scanf("%d", &fid);

    int flightIndex = -1;
    for (int i = 0; i < flightCount; i++)
    {
        if (f[i].fid == fid)
        {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1)
    {
        printf("Flight ID not found!!!\n");
        return 0;
    }

    printf("Enter Passenger ID: ");
    scanf("%d", &pid);

    int passengerIndex = -1;
    for (int i = 0; i < passengerCount; i++)
    {
        if (p[i].pid == pid)
        {
            passengerIndex = i;
            break;
        }
    }

    if (passengerIndex == -1)
    {
        printf("Passenger ID not found!!!\n");
        return 0;
    }

    printf("Enter number of seats to book: ");
    scanf("%d", &seats);

    if (seats > f[flightIndex].seats)
    {
        printf("Not enough seats available!!!\n");
        return 0;
    }

    b[bookingCount].bid = bookingCount + 1;
    b[bookingCount].fid = fid;
    b[bookingCount].pid = pid;
    b[bookingCount].seatsBooked = seats;
    b[bookingCount].totalCost = f[flightIndex].price * seats;

    f[flightIndex].seats -= seats;

    FILE *fflight;
    fflight = fopen("flight.txt", "w");

    fprintf(fflight, "%d\n", flightCount);

    for (int i = 0; i < flightCount; i++)
    {
        fprintf(fflight, "%d;%s;%s;%s;%f;%d\n", f[i].fid, f[i].fname, f[i].source, f[i].destination, f[i].price, f[i].seats);
    }

    fclose(fflight);

    printf("Flight booked successfully!!!\n");
    return 1;
}

void updateBooking(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount)
{
    int bid, seats;
    printf("\nEnter Booking ID to update: ");
    scanf("%d", &bid);

    int bookingIndex = -1;
    for (int i = 0; i < bookingCount; i++)
    {
        if (b[i].bid == bid)
        {
            bookingIndex = i;
            break;
        }
    }

    if (bookingIndex == -1)
    {
        printf("Booking ID not found!!!\n");
        return;
    }

    int flightIndex = -1;
    for (int i = 0; i < flightCount; i++)
    {
        if (f[i].fid == b[bookingIndex].fid)
        {
            flightIndex = i;
            break;
        }
    }

    printf("Enter new number of seats to book: ");
    scanf("%d", &seats);

    if (seats > f[flightIndex].seats + b[bookingIndex].seatsBooked)
    {
        printf("Not enough seats available!!!\n");
        return;
    }

    f[flightIndex].seats += b[bookingIndex].seatsBooked;
    f[flightIndex].seats -= seats;

    b[bookingIndex].seatsBooked = seats;
    b[bookingIndex].totalCost = f[flightIndex].price * seats;

    FILE *fflight;
    fflight = fopen("flight.txt", "w");

    fprintf(fflight, "%d\n", flightCount);

    for (int i = 0; i < flightCount; i++)
    {
        fprintf(fflight, "%d;%s;%s;%s;%f;%d\n", f[i].fid, f[i].fname, f[i].source, f[i].destination, f[i].price, f[i].seats);
    }

    fclose(fflight);

    printf("Booking updated successfully!!!\n");
}

int cancelBooking(booking b[MAX_BOOKINGS], int bookingCount)
{
    int bid, found = -1;
    printf("\nEnter the ID number of the booking you want to cancel: ");
    scanf("%d", &bid);

    for (int i = 0; i < bookingCount; i++)
    {
        if (b[i].bid == bid)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    for (int j = found; j < bookingCount - 1; j++)
    {
        b[j] = b[j + 1];
    }
    printf("Booking cancelled successfully!!!\n");
    return 1;
}

void displayBookings(booking b[MAX_BOOKINGS], int bookingCount)
{
    for (int i = 0; i < bookingCount; i++)
    {
        printf("\nBooking %d: \n", i + 1);
        printf("ID: %d, Flight ID: %d, Passenger ID: %d, Seats Booked: %d, Total Cost: %.2f\n",
               b[i].bid, b[i].fid, b[i].pid, b[i].seatsBooked, b[i].totalCost);
    }
    if (bookingCount == 0)
    {
        printf("No booking available!!!\n");
    }
}

void search(flight f[MAX_FLIGHTS], passenger p[MAX_PASSENGERS], booking b[MAX_BOOKINGS], int flightCount, int passengerCount, int bookingCount)
{

    int choice;

    do
    {
        printf("\nSEARCH\n\n");
        printf("1. SEARCH FLIGHT BY ID\n");
        printf("2. SEARCH PASSENGER BY ID\n");
        printf("3. SEARCH BOOKING BY ID\n");
        printf("4. EXIT\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            searchFlightById(f, flightCount);
            break;
        case 2:
            searchPassengerById(p, passengerCount);
            break;
        case 3:
            searchBookingById(b, bookingCount);
            break;
        case 4:
            break;
        default:
            printf("enter valid input!!!\n");
        }
    } while (choice != 4);
}

void searchFlightById(flight f[MAX_FLIGHTS], int flightCount)
{
    int id;
    printf("Enter Flight ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < flightCount; i++)
    {
        if (f[i].fid == id)
        {
            found = 1;
            printf("\nFlight found:\n");
            printf("ID: %d, Name: %s, Source: %s, Destination: %s, Price: %.2f, Seats: %d\n",
                   f[i].fid, f[i].fname, f[i].source, f[i].destination, f[i].price, f[i].seats);
            break;
        }
    }

    if (!found)
    {
        printf("Flight ID not found!!!\n");
    }
}

void searchPassengerById(passenger p[MAX_PASSENGERS], int passengerCount)
{
    int id;
    printf("Enter Passenger ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < passengerCount; i++)
    {
        if (p[i].pid == id)
        {
            found = 1;
            printf("\nPassenger found:\n");
            printf("ID: %d, Name: %s, Passport: %s, Phone: %s\n",
                   p[i].pid, p[i].pname, p[i].passport, p[i].phone);
            break;
        }
    }

    if (!found)
    {
        printf("Passenger ID not found!!!\n");
    }
}

void searchBookingById(booking b[MAX_BOOKINGS], int bookingCount)
{
    int id;
    printf("Enter Booking ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < bookingCount; i++)
    {
        if (b[i].bid == id)
        {
            found = 1;
            printf("\nBooking found:\n");
            printf("ID: %d, Flight ID: %d, Passenger ID: %d, Seats Booked: %d, Total Cost: %.2f\n",
                   b[i].bid, b[i].fid, b[i].pid, b[i].seatsBooked, b[i].totalCost);
            break;
        }
    }

    if (!found)
    {
        printf("Booking ID not found!!!\n");
    }
}

void displayFlightReport(flight f[MAX_FLIGHTS], int flightCount)
{
    if (flightCount == 0)
    {
        printf("\nNo flights available!!!\n");
        return;
    }

    int totalSeats = 0;
    float totalPrice = 0;
    float mostCostlyPrice = f[0].price;
    float leastCostlyPrice = f[0].price;
    int mostCostlyIndex = 0;
    int leastCostlyIndex = 0;

    printf("\n****** FLIGHT REPORT ******\n");

    for (int i = 0; i < flightCount; i++)
    {
        printf("\nFlight ID: %d\n", f[i].fid);
        printf("Flight Name: %s\n", f[i].fname);
        printf("Source: %s\n", f[i].source);
        printf("Destination: %s\n", f[i].destination);
        printf("Price: %.2f\n", f[i].price);
        printf("Seats Available: %d\n", f[i].seats);
        printf("-------------------------------\n");

        totalSeats += f[i].seats;
        totalPrice += f[i].price;

        if (f[i].price > mostCostlyPrice)
        {
            mostCostlyPrice = f[i].price;
            mostCostlyIndex = i;
        }

        if (f[i].price < leastCostlyPrice)
        {
            leastCostlyPrice = f[i].price;
            leastCostlyIndex = i;
        }
    }

    float averagePrice = totalPrice / flightCount;

    printf("\n****** SUMMARY ******\n");
    printf("Total Number of Flights: %d\n", flightCount);
    printf("Total Number of Available Seats: %d\n", totalSeats);
    printf("Average Price of Flights: %.2f\n", averagePrice);
    printf("-------------------------------\n");

    printf("\n****** MOST COSTLY FLIGHT ******\n");
    printf("Flight ID: %d\n", f[mostCostlyIndex].fid);
    printf("Flight Name: %s\n", f[mostCostlyIndex].fname);
    printf("Source: %s\n", f[mostCostlyIndex].source);
    printf("Destination: %s\n", f[mostCostlyIndex].destination);
    printf("Price: %.2f\n", f[mostCostlyIndex].price);
    printf("Seats Available: %d\n", f[mostCostlyIndex].seats);
    printf("-------------------------------\n");

    printf("\n****** LEAST COSTLY FLIGHT ******\n");
    printf("Flight ID: %d\n", f[leastCostlyIndex].fid);
    printf("Flight Name: %s\n", f[leastCostlyIndex].fname);
    printf("Source: %s\n", f[leastCostlyIndex].source);
    printf("Destination: %s\n", f[leastCostlyIndex].destination);
    printf("Price: %.2f\n", f[leastCostlyIndex].price);
    printf("Seats Available: %d\n", f[leastCostlyIndex].seats);
    printf("-------------------------------\n");
}

void displayPassengerReport(passenger p[MAX_PASSENGERS], int passengerCount) {
    printf("\n************PASSENGER REPORT************\n\n");
    printf("-------------------------------------------------\n");
    printf("| %-5s | %-20s | %-12s | %-15s |\n", "ID", "Name", "Passport", "Phone");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < passengerCount; ++i) {
        printf("| %-5d | %-20s | %-12s | %-15s |\n", p[i].pid, p[i].pname, p[i].passport, p[i].phone);
    }
    printf("-------------------------------------------------\n");
}

void displayBookingReport(booking b[MAX_BOOKINGS], int bookingCount)
{
    float totalRevenue = 0.0;
    int maxBookings = 0;
    int maxPassengerID = -1;

    printf("\n*********** BOOKING REPORT ***********\n\n");

    if (bookingCount > 0) {
        // Calculate total revenue and find passenger with most bookings
        for (int i = 0; i < bookingCount; i++)
        {

            printf("Booking ID: %d\n", b[i].bid);
            printf("Flight ID: %d\n", b[i].fid);
            printf("Passenger ID: %d\n", b[i].pid);
            printf("Seats Booked: %d\n", b[i].seatsBooked);
            printf("Total Cost: %.2f\n", b[i].totalCost);

            printf("--------------------\n");

            totalRevenue += b[i].totalCost;

            // Count bookings for each passenger
            int currentPassengerID = b[i].pid;
            int bookingsForPassenger = 1; // Start with current booking

            for (int j = i + 1; j < bookingCount; j++)
            {
                if (b[j].pid == currentPassengerID)
                    bookingsForPassenger++;
            }

            // Update max bookings and corresponding passenger ID
            if (bookingsForPassenger > maxBookings)
            {
                maxBookings = bookingsForPassenger;
                maxPassengerID = currentPassengerID;
            }
        }

        // Display passenger with most bookings and total revenue
        printf("Passenger ID with most bookings: %d\n", maxPassengerID);
        printf("Total Revenue Generated from Bookings: %.2f\n", totalRevenue);
    } else {
        printf("No bookings found.\n");
    }
}
