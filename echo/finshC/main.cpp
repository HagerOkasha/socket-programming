#include <stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

 // .................................client for echo..................

int main(int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET sockid;
    int status;
    struct sockaddr_in forginserver;

    forginserver.sin_addr.s_addr =inet_addr("192.168.1.100");
    forginserver.sin_family= AF_INET;
    forginserver.sin_port=htons(10);



    // windows socket initialization............................................................................

    printf("initializing win sock..\n");
   if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
   {
       printf("failed %d \n",WSAGetLastError());

   }



   //create socket...........................................................

 while(1)
 {
   if((sockid= socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET)
   {
        printf("creation failed %d \n",WSAGetLastError());
   }

   //connect with server.......................................................




   printf("Connect here \t");
   int status = connect(sockid,(struct sockaddr *)&forginserver,sizeof(forginserver));
   if( status <0 )
   {
       printf("Failed \t ");
   }
  // if((status = connect(sockid,(struct sockaddr*)&forginserver,sizeof(forginserver))) <0)
  // {
   //  printf("connection failed\n");
   //}

   //send massage to server.......................................................

   char massage[20]="hager okasha";
   //int size = strlen(massage);
   printf("sending\n");
   send(sockid,massage,strlen(massage),0);
   Sleep(1000);

}
  closesocket(sockid);
  return(0);
}
