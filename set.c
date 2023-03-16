
#include "types.h"
#include "user.h"




int main(int argc, char *argv[])
{
   
   set(atoi(argv[1]), atoi(argv[2])); // set the priority of the process with pid = argv1 to argv2 and using atoi to convert the string to int
    exit();
}