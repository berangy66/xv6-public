#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mystdio.h"

/* FUNCTION MAIN STARTS */
int main(int argc, char *argv[])
{
  // printf(1,"jamie said hello\n");
  FILE *fp;
  fp = myfopen("test.txt", 'w');
  myfprintf(mystdout, "my fp value is %d\n", fp);

  myfprintf(fp, "%s", "hello Behrang!");
  close(fp->fd);
  exit();
} // END MAIN FUNCTION
