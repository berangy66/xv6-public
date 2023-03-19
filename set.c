#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
   if(argc != 3) // check if the number of arguments is 3
   {
      printf(2, "Usage: set pid priority\n");
      exit();
   }
   
    int priority = atoi(argv[2]); // convert the string to int
    if(priority < 0 || priority > 8) // check if the pid and priority are positive
    {
        printf(2, "$ priority 0 <= priority <= 8, No negative numbers\n");
    }

   set(atoi(argv[1]), atoi(argv[2])); // set the priority of the process with pid = argv1 to argv2 and using atoi to convert the string to int
    exit();
}