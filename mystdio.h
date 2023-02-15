#define BUFF_SIZE 512
#define NULL (void *) 0;

typedef struct FILE // struct FILE HAS fd,
{
  int fd;
  int mode;
  char mybuffer[BUFF_SIZE];
  int buffer_current_positon;
  // char path;
  // char *str_holder;
  // char *fp;
} FILE;


extern FILE *mystdin;
 extern FILE *mystdout;
 extern FILE *mystderr;
 



// my function prototypes
FILE *myfopen(const char *path, char mode);   // opens a file path and assigns mode 'r' / 'w'
void myclose(FILE *fp);                       // flush buffer with myclose
void myfprintf(FILE *fp, const char *s, ...); // myfprintf will read/write into buffer
void myfflush(FILE* fp); //flushes the buffer when full
void myfprintf1(FILE *fp, const char *s, ...);//just test