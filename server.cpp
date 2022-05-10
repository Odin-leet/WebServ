#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include "Request.hpp"
#include <sys/select.h>
#define PORT 8090
int main(){
      char buffer[1024] = { 0 };
      int activ;
      int clientsocket[30];
      int max_sd;
      int sd;
    char *hello =  "HTTP/1.1 200 OK\r\n"; //Connection: close\r\nDate: {}\r\nServer: Apache\r\nLast-Modified: Tue, 10 Nov 2020, 6:31:00 GMT\r\nContent-Length: 72 bytes\r\nContent-Type: text/html\r\n<html>\r\n<title>PAGE TITLE</title>\r\n<body>\rThis is the body\r\n</body></html>\r ";
    int opt = 1;

    for (int i = 0;i < 30; i++)
      clientsocket[i] = 0;
      int new_socket;
    fd_set readsfds;
    int valread = 0;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int sockfd = socket(PF_INET,SOCK_STREAM,0); 
    setsockopt(sockfd ,SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr*)&address, sizeof(address));
    listen(sockfd, 3);
    while (true)
    {
      FD_ZERO(&readsfds);
      FD_SET(sockfd, &readsfds);
      max_sd =  sockfd;
      for(int i = 0;i < 30;i++)
      {
        sd = clientsocket[i];
        if (sd > 0)
        FD_SET(sd, &readsfds);
        if (sd > max_sd )
          max_sd = sd;
      }
      int c = 0;
      int count = 0;
      activ = select(max_sd + 1, &readsfds, NULL, NULL, NULL);
      if (FD_ISSET(sockfd, &readsfds))
      {
         new_socket = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
             valread = read(new_socket, buffer, 1024);
             buffer[valread] = '\0';
             
             
           while (buffer[c] != '\0')
          {
            if (buffer[c] == '\n')
             count++;
             c++;
          }
             std::cout<<count<<"count";
          std::string tab[count + 1];

int j =0 ;
c = 0;
           while (buffer[c] != '\0')
           {
            // j = 0;
            if (buffer[c] == '\n')
            {
              j++;
              c++;
            }
            tab[j] += buffer[c];
            std::cout<<buffer[c]<<"char === "<<std::endl;
            c++;
           }
            for (int i = 0; i < count + 1; i++)
        std::cout<<"LINE = "<< i << " " <<tab[i]<<std::endl;



 //            if (valread > 0)
 //            {
 //            while (buffer[i] != '\0')
 //            {
 //              if (buffer[i] == '\n')
 //               count++;
 //               i++;
 //               std::cout<<count<<"count";
 //            }
 //            
 //            int j = 0, i = 0;
 //           
 //              while (buffer[i] != '\0')
 //              {
 //                j = 0;
 //               if (buffer[i] == '\n')
 //               {
 //                 j++;
 //                 i++;
 //               }
 //               tab[j] += buffer[i];
 //               i++;
 //              }
 //           
 //          //  Request re;
 //           std::cout<<"LINE = "<<std::endl;
 //          for (int i = 0; i < count + 1; i++)
 //           std::cout<<"LINE = "<< i << " " <<tab[i]<<std::endl;
 //            
   printf("%s\n", buffer);
 //            }
       send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
         for(int i = 0 ;i < 30;i++)
        {
          if (clientsocket[i] == 0)
          {
            clientsocket[i] = new_socket;
            break;
          }
        }
      }
    }
  
 
 
    return 0;
}