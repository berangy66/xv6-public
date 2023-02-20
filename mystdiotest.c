#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mystdio.h"

/* FUNCTION MAIN STARTS */
int main(int argc, char *argv[])
{

  FILE *fp;
  fp = myfopen("test.txt", 'w');

  myfprintf(mystdout, "my fp value is %d\n", fp);
  int starttime = 0;
  int endtime = 0;


  for (int i = 0; i < sizeof(fp->mybuffer); i++)
  {
   
   
      myfprintf(fp, "\n[%d] starttime: [%d] %s endtime[%d]", i, starttime = uptime(), "hello Xv6!..  ", endtime = uptime());
      myfprintf(mystdout,"%p Xv6\t",   fp->buffer_current_positon);
      myfflush(fp); // flush the buffer to write data to the file
  }

  close(fp->fd);
  exit();
} // END MAIN FUNCTION
