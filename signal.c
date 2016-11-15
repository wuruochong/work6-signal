#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    umask(0000);
    int f = open("sigmsg.txt", O_CREAT|O_RDWR|O_APPEND, 0644);
    char msg[] = "main.c exited due to SIGINT signal\n";
    write(f,msg,sizeof(msg));
    close(f);
    printf("\nProgram exiting due to SIGINT signal\n");
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("PID of parent process: %d\n", getppid());
  }
}

int main(){
  while (1){
    printf("Process ID: %d\n", getpid());
    sleep(1);
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
  }
}
