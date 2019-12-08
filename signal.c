/* hello_signal.c */
//#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

extern int totalAlarms;
void Alarm_incre();
void time_handler(int signum);

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was great!\n");
  Alarm_incre();
  alarm(1);
}


int totalAlarms = 0;
void Alarm_incre() {
    totalAlarms++;
}

void time_handler(int signum)
{ // sigint signal handler
    //signal(SIGALRM, handler);
    printf(" In seconds, program was executed for: %d\n", totalAlarms);
    exit(1);
    
}




int main(int argc, char * argv[])
{

  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, time_handler);
  //signal(SIGINT, time_handler);
  
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1);{
     pause();
  } //busy wait for signal to be delivered
 
  return 0; //never reached
}
