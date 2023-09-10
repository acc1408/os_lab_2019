#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
//#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int server_sockfd, // указатель на сокет сервера
      client_sockfd; // укзатель на сокет клиента
  int server_len, client_len;
  struct sockaddr_in server_adress, // объект сокет сервера 
                    client_adress; // объект сокет клиента
  // Создание Сокета для сервера
  server_sockfd=socket(AF_INET,SOCK_STREAM,0);

  server_adress.sin_family=AF_INET;
  server_adress.sin_addr.s_addr=inet_addr("127.0.0.1");
  server_adress.sin_port=htons(9734);
  server_len=sizeof(server_adress);
  
  bind(server_sockfd,(struct sockaddr*)&server_adress,server_len );
  listen(server_sockfd,5);
  int k=0;
  char ch;
  char buf[100];
  int lenbuf;
  while (1)
  {
    printf("server waiting\n");
    client_len=sizeof(client_adress);
    client_sockfd=accept(server_sockfd, 
                  (struct sockaddr*)&server_adress,
                  &client_len);
    lenbuf=sizeof(buf) ;              
    lenbuf=read(client_sockfd,buf,sizeof(buf) );
    k++;
    if (k>50)
      k=1;
    ch+=k;
    sleep(3);
    write(client_sockfd,&ch,1);
    close(client_sockfd);
  }
  


  return 0;
}