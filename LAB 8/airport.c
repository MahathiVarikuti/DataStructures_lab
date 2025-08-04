#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int landingQueue[MAX_QUEUE_SIZE];
    int takeoffQueue[MAX_QUEUE_SIZE];
    int landingFront, landingRear, landingCount;
    int takeoffFront, takeoffRear, takeoffCount;
    int totalLanded, totalTookOff, totalRefused;
    int landingWaitTime, takeoffWaitTime, idleTime;
} Airport;

void initAirport(Airport *airport) {
    airport->landingFront = airport->landingRear = -1;
    airport->takeoffFront = airport->takeoffRear = -1;
    airport->landingCount = airport->takeoffCount = 0;
    airport->totalLanded = airport->totalTookOff = airport->totalRefused = 0;
    airport->landingWaitTime = airport->takeoffWaitTime = airport->idleTime = 0;
}

int isFull(int count) {
    return count == MAX_QUEUE_SIZE;
}

int isEmpty(int count) {
    return count == 0;
}

void addLanding(Airport *airport, int planeID) {
    if (isFull(airport->landingCount)) {
        airport->totalRefused++;
        printf("Landing queue full. Plane %d refused.\n", planeID);
        return;
    }
    if (airport->landingFront == -1) {
        airport->landingFront = airport->landingRear = 0;
    } else {
        airport->landingRear = (airport->landingRear + 1) % MAX_QUEUE_SIZE;
    }
    airport->landingQueue[airport->landingRear] = planeID;
    airport->landingCount++;
}

void addTakeoff(Airport *airport, int planeID) {
    if (isFull(airport->takeoffCount)) {
        airport->totalRefused++;
        printf("Takeoff queue full. Plane %d refused.\n", planeID);
        return;
    }
    if (airport->takeoffFront == -1) {
        airport->takeoffFront = airport->takeoffRear = 0;
    } else {
        airport->takeoffRear = (airport->takeoffRear + 1) % MAX_QUEUE_SIZE;
    }
    airport->takeoffQueue[airport->takeoffRear] = planeID;
    airport->takeoffCount++;
}

void processLanding(Airport *airport) {
    if (isEmpty(airport->landingCount)) {
        printf("No planes waiting to land.\n");
        return;
    }
    int planeID = airport->landingQueue[airport->landingFront];
    airport->landingFront = (airport->landingFront + 1) % MAX_QUEUE_SIZE;
    airport->landingCount--;
    airport->totalLanded++;
    printf("Plane %d landed.\n", planeID);
}

void processTakeoff(Airport *airport) {
    if (isEmpty(airport->takeoffCount)) {
        printf("No planes waiting to take off.\n");
        return;
    }
    int planeID = airport->takeoffQueue[airport->takeoffFront];
    airport->takeoffFront = (airport->takeoffFront + 1) % MAX_QUEUE_SIZE;
    airport->takeoffCount--;
    airport->totalTookOff++;
    printf("Plane %d took off.\n", planeID);
}

void simulateAirport(Airport *airport, int simulationTime) {
    srand(time(0));
    for (int time = 0; time < simulationTime; time++) {
        printf("Time unit: %d\n", time);
        int action = rand() % 3;
        if (action == 0) {
            int planeID = rand() % 1000;
            addLanding(airport, planeID);
            printf("Plane %d added to landing queue.\n", planeID);
        } else if (action == 1) {
            int planeID = rand() % 1000;
            addTakeoff(airport, planeID);
            printf("Plane %d added to takeoff queue.\n", planeID);
        } else {
            if (!isEmpty(airport->landingCount)) {
                processLanding(airport);
            } else if (!isEmpty(airport->takeoffCount)) {
                processTakeoff(airport);
            } else {
                airport->idleTime++;
                printf("Runway idle.\n");
            }
        }
    }
}

void printStatistics(Airport *airport) {
    printf("\nSimulation Statistics:\n");
    printf("Total planes processed: %d\n", airport->totalLanded + airport->totalTookOff);
    printf("Total planes landed: %d\n", airport->totalLanded);
    printf("Total planes took off: %d\n", airport->totalTookOff);
    printf("Total planes refused: %d\n", airport->totalRefused);
    printf("Average landing wait time: %.2f\n", (float)airport->landingWaitTime / airport->totalLanded);
    printf("Average takeoff wait time: %.2f\n", (float)airport->takeoffWaitTime / airport->totalTookOff);
    printf("Average runway idle time: %.2f\n", (float)airport->idleTime);
}

int main() {
    Airport airport;
    initAirport(&airport);

    int simulationTime;
    printf("Enter simulation time: ");
    scanf("%d", &simulationTime);

    simulateAirport(&airport, simulationTime);
    printStatistics(&airport);

    return 0;
}
