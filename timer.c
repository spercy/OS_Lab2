/* timer.c */
/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarmTrigger = 0;
int counter = 0;
time_t startTime, stopTime;

void handler(int signum)
{ //signal handler
  alarmTrigger = 1;
  counter++;
  printf("Hello World!\n");
  //exit(1); //exit after printing
}

void timerHandler(int signum)
{
  stopTime = time(NULL);

  printf("Number of alarms: %d\n",counter);
  printf("Number of seconds: %ld\n", (stopTime-startTime));
  exit(1);
}

int main(int argc, char * argv[])
{
  startTime = time(NULL);
  
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,timerHandler); //register handler to handle SIGALRM
  while(1){
    alarm(3); //Schedule a SIGALRM for 1 second
    while(alarmTrigger == 0){
      ;
    }
    printf("Turing was right!\n");
    alarmTrigger = 0;

  }
} 

//****

//COPY YOUR SIGNAL.C INTO THIS FILE

//UPDATE YOUR MAKEFILE


//*******/