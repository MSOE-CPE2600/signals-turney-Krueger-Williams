/**
 * File: signal_alarm.c
 * Modified by: Mac Williams
 * 11/17/2024
 * 
 * Brief summary of program: program to send an alarm and respond
 *  
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_alarm();

int main() {
    // Register Signal
    signal(SIGALRM, handle_alarm);

    // Trigger alarm
    alarm(5);

    printf("Alarm Scheduled\n");

    // Wait for alarm
    while (1) {
        sleep(1);
    }
        
    return 0;
}


// Exits program on alarm signal
void handle_alarm() {
    printf("We've got an alarm!\n");
    exit(0);
}