//In order to create a shell command pstate, we need to make a user program that makes a call to the pstate() system call
//Changing header files may also assist in implementing this
//Note that inside the kernel, cprintf() is what is used to print to the console. Once inside the kernel, various information pertaining to the process struct must be printed. 


#include "types.h"
#include "defs.h"

int main()
{
    pstate(); 
    exit(); 
}