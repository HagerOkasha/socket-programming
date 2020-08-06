#include <stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

//...............................client to connect with remote server........................................

int main(int argc, char *argv[])
{
   WSADATA wsa;
   SOCKET sockid;
   struct sockaddr_in serverinfo;
   serverinfo.sin_addr.s_addr=inet_addr("216.58.205.196");
   serverinfo.sin_family=AF_INET;
   serverinfo.sin_port=htons(80);

 //windows socket  initialization ..........................................................................


    if((WSAStartup(MAKEWORD(2,2),&wsa))!=0)
    {
        printf("initializing failed %d",WSAGetLastError());

    }


    while(1)
    {

  //create socket............................................................................................


        if((sockid=socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET)
        {
            printf("creation failed %d\n",WSAGetLastError());
        }

 //connect with remote server(google).......................................................................

    int status =connect(sockid,(struct sockaddr*)&serverinfo,sizeof(serverinfo));
     if(status<0)
     {
         printf("connection failed");
     }

  //send a request for google and google reply with the  page content..........................................
     char massage[100]="GET \HTTP/1.1\r\n\r\n";

     send(sockid,massage,sizeof(massage),0);

     char buff[2000];
     recv(sockid,buff,2000,0);

     printf("%s\n",buff);
     //or..... puts(buff);

     printf("finished\n");

     Sleep(20000);
 }
     closesocket(sockid);


     return 0;


}




