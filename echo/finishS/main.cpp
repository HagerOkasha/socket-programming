#include <stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")


 //.................................Server for echo............................................

int main(int argc, char *argv[])
{
  WSADATA wsa;
  SOCKET sockid;
  int status;
  int s;

  struct sockaddr_in myinfo;
  myinfo.sin_addr.s_addr = htonl(INADDR_ANY);   /*inet_addr("169.254.60.62");*/
  myinfo.sin_family = AF_INET;
  myinfo.sin_port= htons(10);
   struct sockaddr_in clintinfo;
   int size = sizeof(clintinfo);
   int st;



 // windows socket initialization ...............................................................


   if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
   {
       printf("initializing failed %d\n",WSAGetLastError());
   }




   //create socket................................................................................

      if((sockid =socket(PF_INET,SOCK_STREAM,0))==INVALID_SOCKET)
      {
           printf("Could not create socket %d \n",WSAGetLastError());
      }
       printf("Created\n");

   // Bind.........................................................................................

    if((status =bind(sockid,(struct sockaddr*)&myinfo,sizeof(myinfo)))<0)
      {
        printf("bind failed\n");
      }
    printf("bind\n");


  //listen..........................................................................................

     st =listen(sockid,1);

      printf("listen now\n");

  //accept..........................................................................................

while(1)
{

     s =accept(sockid,(struct sockaddr*)&clintinfo,&size);

     printf("accepted\n");


  // receive..........................................................................................





   char massage[20]="" ;

     recv(s,massage,sizeof(massage),0);
     printf("%s",massage);


   Sleep(1000);
   }
   closesocket(sockid);
   return 0;
}
