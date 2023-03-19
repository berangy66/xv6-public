#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//=======================================================
// ps system call added
//=======================================================
int 
sys_ps(void)
{
  ps();
  return 0;
}
//=======================================================


//=======================================================
// set system call added
//=======================================================
int
sys_set(void)
{
  int pid; 
  int priority; 
  if((argint(0, &pid) < 0) || (argint(1, &priority) < 0)) // if the pid or priority is not an integer return -1
  {
    return -1;
    exit(); // exit the process
  }
  // if(priority < 0 || priority > 8) // if the priority is not between 0 and 100 return -1
  // {
  //   return -1;
  //   exit(); // exit the process
    
  // }
  return set(pid, priority); // set the priority of the process with pid = pid to priority

}
//=======================================================
 
