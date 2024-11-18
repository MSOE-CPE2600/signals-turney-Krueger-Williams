/**
 * File: send_signal.c
 * Modified by: Mac Williams
 * 
 * Brief summary of program: sends a SIGUSR1 with a random int
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    // Store PID
    char pid[7];

    printf("Please enter a PID: ");

    // Get PID from user
    fgets(pid, sizeof(pid), stdin);

    // Seed random number generator
    srand(time(NULL));

    // Random number
    int random_number = rand();

    // Union for storing signal data
    union sigval sig_data;

    // Set random number
    sig_data.sival_int = random_number;

    // Generate signal with data
    sigqueue(atoi(pid), SIGUSR1, sig_data);

    printf("Sending randon number: %d\n", random_number);
}
