#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
char buf[10000];
int port;
int countIP=1;
int countchar;
char *ip[500];

//char port[7];
int len;
int main()
{
  int file=open("./iplist.txt",O_RDONLY);
  countchar=read(file,buf,sizeof(buf));
  close(file);
  ip[0]=buf;
  for (int i = 1; i < countchar; i++)
  {
    if (buf[i]==':'||buf[i]=='\n')
    {
      ip[countIP]=&buf[i+1];
      countIP++;
      buf[i]='\0';
    }
  }

  if (countIP%2==1)
  {
    countIP--;
  } 

  
  
  return 0;
}