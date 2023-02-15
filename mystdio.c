#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mystdio.h"


FILE stdin0 = {.fd = 0, .mode = 0, .buffer_current_positon = 0};
FILE *mystdin = &stdin0;
FILE stdout1 = {.fd = 1, .mode = 0, .buffer_current_positon = 0};
FILE *mystdout = &stdout1;
FILE stderr2 = {.fd = 2, .mode = 0, .buffer_current_positon = 0};
FILE *mystderr = &stderr2;

// mode 'r' to read & mode 'w' to write
FILE *myfopen(const char *path, char mode)
{
  int fd1;
  FILE *fp = (FILE *)malloc(sizeof(FILE));
  int m;
  if (mode == 'r')
  {
    m = O_RDONLY;
  }
  else if (mode == 'w')
  {
    m = O_WRONLY | O_CREATE;
  }
  else
  {
    printf(2, "You have entered invalid mode\n");
    exit();
  }
  fd1 = open(path, m);
  if (fd1 < 0)
  {
    printf(2, "could not open a file to Read or Write!\n");
    exit();
  }

  fp->fd = fd1;
  fp->mode = m;
  fp->buffer_current_positon = 0;
  //memset(fp->mybuffer, 0, BUFF_SIZE); // set buffer to 0

  return fp;

} // END FUNCTION *myfopen

/******** fluhes buffer  **********/
void myclose(FILE *fp)
{
  close(fp->fd);
  exit();

} // END FUNCTION myclose

void myfflush(FILE* fp)
{
  // flush the buffer
}

/****** it's fully buffered and handles %d, %x, %p and %s **********/
/****** it works with file pointers instead of file descriptor *********/
/****** uses constant BUFF_SIZE *************/
void myfprintf1(FILE *fp, const char *s, ...)
{

  int nbytesRD = 0;
  int nbytesWR = 0;
  int fd = fp->fd;

  printf(1, "i am in myfprintf block %d\n", fd);
  strcpy(fp->mybuffer, s);
  while ((nbytesRD = read(fd, fp->mybuffer, sizeof(BUFF_SIZE))) > 0)
  {

    nbytesWR = write(fd, fp->mybuffer, BUFF_SIZE);
  }

  fp->buffer_current_positon = nbytesWR;
  // fp->mybuffer[nbytesWR];
  // close(fp->fd);
  exit();

} // END FUNCTION myfprintf

static void
myputc(FILE *fp, char c)
{
  write(fp->fd, &c, 1);
}

static void
myfprintint(FILE *fp, int xx, int base, int sgn)
{
  static char digits[] = "0123456789ABCDEF";
  char buf[16];
  int i, neg;
  uint x;

  neg = 0;
  if (sgn && xx < 0)
  {
    neg = 1;
    x = -xx;
  }
  else
  {
    x = xx;
  }

  i = 0;
  do
  {
    buf[i++] = digits[x % base];
  } while ((x /= base) != 0);
  if (neg)
    buf[i++] = '-';

  while (--i >= 0)
    myputc(fp, buf[i]);
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void myfprintf(FILE *fp, const char *fmt, ...)
{
  char *s;
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint *)(void *)&fmt + 1;
  for (i = 0; fmt[i]; i++)
  {
    c = fmt[i] & 0xff;
    if (state == 0)
    {
      if (c == '%')
      {
        state = '%';
      }
      else
      {
        myputc(fp, c);
      }
    }
    else if (state == '%')
    {
      if (c == 'd')
      {
        myfprintint(fp, *ap, 10, 1);
        ap++;
      }
      else if (c == 'x' || c == 'p')
      {
        myfprintint(fp, *ap, 16, 0);
        ap++;
      }
      else if (c == 's')
      {
        s = (char *)*ap;
        ap++;
        if (s == 0)
          s = "(null)";
        while (*s != 0)
        {
          myputc(fp, *s);
          s++;
        }
      }
      else if (c == 'c')
      {
        myputc(fp, *ap);
        ap++;
      }
      else if (c == '%')
      {
        myputc(fp, c);
      }
      else
      {
        // Unknown % sequence.  Print it to draw attention.
        myputc(fp, '%');
        myputc(fp, c);
      }
      state = 0;
    }
  }
}
