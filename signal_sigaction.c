/**
 * File: signal_sigaction.c
 * Modified by: Mac Williams
 * 
 * Brief summary of program: registers a handler for sigusr1 and
 * prints the PID of the sender on 
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
    sa.sa_handler = handle_sigusr1;

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

// Send sigusr1 using kill -SIGUSR1 <pid>
void handle_sigusr1(int sig, siginfo_t *siginfo, void *context) {
    printf("SIGUSR1 Sent From PID: %d\n", siginfo->si_pid);
    return;
}
