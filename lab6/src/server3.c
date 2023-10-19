#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
//#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define portn 9734

int main()
{
  
  char buf[100]; // Буфер для приема данных
  int lenbuf;
  int a, // Начало факториала
      b; // Конец факториала 
  long long f=1; // факториал числа
  int server_sockfd, // указатель на сокет сервера
      client_sockfd; // укзатель на сокет клиента
  int server_len, client_len;
  struct sockaddr_in server_adress, // объект сокет сервера 
                    client_adress; // объект сокет клиента
  // Создание Сокета для сервера
  server_sockfd=socket(AF_INET,SOCK_STREAM,0);
  // Заполняем структуры адреса
  server_adress.sin_family=AF_INET;
  server_adress.sin_addr.s_addr=inet_addr("127.0.0.1");
  server_adress.sin_port=htons(portn);
  server_len=sizeof(server_adress);
  // просл
  bind(server_sockfd,(struct sockaddr*)&server_adress,server_len );
  listen(server_sockfd,5);
  
  //strcpy(buf,"sfsefgesfsfsef");
  while (1)
  {
    printf("server waiting\n");
    memset(buf,'\0',sizeof(buf));
    client_len=sizeof(client_adress);
    client_sockfd=accept(server_sockfd, 
                  (struct sockaddr*)&server_adress,
                  &client_len);
    lenbuf=sizeof(buf) ;              
    lenbuf=read(client_sockfd,buf,sizeof(buf) );
    // расчет данных 
    sscanf(buf,"%d %d",&a,&b);
    f=1;
    for (int i = a; i <= b; i++)
    {
      f=f*i;
      /* code */
    }
    memset(buf,'\0',sizeof(buf));
    printf("%d %d result %llu\n",a,b,f);
    sprintf(buf,"%llu",f);
    write(client_sockfd,buf,strlen(buf));
    close(client_sockfd);
  }
  


  return 0;
}