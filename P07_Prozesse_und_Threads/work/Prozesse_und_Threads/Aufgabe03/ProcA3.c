//***************************************************************************
// File:             ProcA4.c
// Original Author:  M. Thaler (Modul BSY)
//***************************************************************************

//***************************************************************************
// system includes
//***************************************************************************

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

//***************************************************************************
// Function: main(), parameter: none
//***************************************************************************

int main(void) {
    fork();
    fork();
    fork();
    fork();
    printf("PID: %d\t PPID: %d\n", getpid(), getppid());
    sleep(10);  // keep processes in system to display their "stammbaum"
    exit(0);
}

//***************************************************************************
