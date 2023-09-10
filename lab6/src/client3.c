#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
//#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
  int sockfd;
  int len;
  struct sockaddr_in adress;
  int result;
  char ch='A';
  char str[]="stroka";
  // создаем сокет клиент
  sockfd= socket(AF_INET,SOCK_STREAM,0);
  // настраиваем структуру 
  adress.sin_family=AF_INET;
  adress.sin_addr.s_addr=inet_addr("127.0.0.1");
  adress.sin_port=htons(9734);
  len=sizeof(adress);
  
  result=connect(sockfd, (struct sockaddr *) &adress,len  );
  if (!result)
  {
    write(sockfd,str,strlen(str));
    printf("%c\n",ch);
    read(sockfd,&ch,1);
    printf("%c\n",ch);
    close(sockfd);
  }
  else 
  {
    printf("Error connect with server\n");
  }
  
  
  return 0;
}