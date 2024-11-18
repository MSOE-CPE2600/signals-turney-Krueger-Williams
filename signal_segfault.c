/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Mac Williams
 * 
 * Brief summary of modifications: Added a seg fault handler that causes
 * the program to infinitely loop with the seg fault.
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigsegv();

int main (int argc, char* argv[]) {

    // Register signal handler
    signal(SIGSEGV,handle_sigsegv);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}


// Handles a segmentation violation
void handle_sigsegv() {
    printf("Seg fault occurred\n");
    return;
}