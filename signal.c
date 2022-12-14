/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int alarmTrigger = 0;

void handler(int signum)
{ //signal handler
  alarmTrigger = 1;
  printf("Hello World!\n");
}

int main(int argc, char * argv[])
{
  while(1){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(3); //Schedule a SIGALRM for 1 second
    while(alarmTrigger == 0){
      ;
    }
    printf("Turing was right!\n");
    alarmTrigger = 0;

  }
} 