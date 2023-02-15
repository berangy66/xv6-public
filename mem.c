#include "types.h"
#include "user.h"







int main(int argc, char *argv[]) {
    if (argc != 2) { 
	printf(1, "usage: mem <value>\n"); 
	exit(); 
    } 

    int *p; 
    p = malloc(sizeof(int));
   //assert(p != 0); // assert returns Error if there is not enough memory
   if(p == 0){
    printf(1,"Out of memeory!");
    exit(); 
   }
    printf(1, "(%d) addr pointed to by p: %p\n", (int) getpid(), p);
    *p = atoi(argv[1]); // assign value to addr stored in p
    while (1) {
	//Spin(1);
    sleep(100);
   
	*p = *p + 1; //we inc. the value in p variable 
	printf(1, "(%d) value of p: %d\n", getpid(), *p);
    }
    
}
// look at echo.c for examples 
//make clean 
//make to rebuild the makefile 
// to compile --> make qemu-nox