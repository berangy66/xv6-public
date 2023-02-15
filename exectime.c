#include "types.h"
#include "user.h"


int main(int argc, char **argv)
{
    if(argc < 2)//USER ARGV CAN NOT BE  < 2 
    {
        printf(1,"Usage: exectime command argument-list\n");
        exit();
    }
   
    int UptimeValue = uptime(); //START UPTIME
    printf(1,"Uptime : %d\n", UptimeValue); //PRRINT OUT START UPTIME 

    int forkpid = fork(); //FORK A CHILD 
    if(forkpid == -1) //COULDNT FORK -1
    {
        printf(1,"Could not fork!!\n"); 
        exit(); 
    }
    else if(forkpid > 0) //PARENT 
    {
        wait(); 
    }
    else if(forkpid == 0) //CHILD FORK
    {
       int execValue = exec(argv[1], argv+1); //EXEC ARGVS
       if(execValue < 0) // COULD NOT EXEC, RETUENED -1 
       {
        printf(1,"Exec function Error!!\n");
        exit(); 
       }
    }
    
    UptimeValue = uptime(); //FINISH UPTIME 
    printf(1,"Uptime : %d\n", UptimeValue);//PRINTOUT FINISHED UPTIME
    exit();
}