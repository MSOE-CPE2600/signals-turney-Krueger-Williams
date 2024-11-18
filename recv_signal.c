/**
 * File: recv_signal.c
 * Modified by: Mac Williams
 * 
 * Brief summary of program: receives a SIGUSR1 and prints a sent number
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigusr1(int sig, siginfo_t *siginfo, void *context);

int main() {
    // Sigaction structure
    struct sigaction sa;

    // Set function to handle sigusr1
    sa.sa_sigaction = handle_sigusr1;

    // Tell sigaction to use sigaction
    sa.sa_flags = SA_SIGINFO;

    // Check for error setting handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        printf("Error setting handler\n");
        exit(1);
    }

    // Wait infinitely
    while (1) {
        sleep(1);
    }
    
}

void handle_sigusr1(int sig, siginfo_t *siginfo, void *context) {
    printf("SIGUSR1 Integer: %d\n", siginfo->si_value.sival_int);
    return;
}
