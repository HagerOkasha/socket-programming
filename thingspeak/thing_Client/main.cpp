#include <stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws_32.lib")
//................................client send data to thingspeak.........................................
int main(int argc, char *argv[])
{
 WSADATA wsa;
 SOCKET sockid;
 struct sockaddr_in thinginfo;
 thinginfo.sin_addr.s_addr =inet_addr("52.203.112.237");
 thinginfo.sin_family=AF_INET;
 thinginfo.sin_port=htons(80);

 // windows socket initialization............................................................................


 if((WSAStartup(MAKEWORD(2,2),&wsa))!=0)
 {
     printf("initialization failed %d\n",GetLastError());
 }

while(1)
{
//create socket.......................................................................................
    if((sockid =socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET)
    {
        printf("creation failed %d\n",GetLastError());
    }
    printf("socket create\n");

//connect.............................................................................................

    int status =connect(sockid,(struct sockaddr*)&thinginfo,sizeof(thinginfo));
    if(status <0)
    {
        printf("connection failed\n");
    }
    printf("connected\n");

//send data...............................................................................................

    char massage[200]="GET https://api.thingspeak.com/update?api_key=UEX250B95EY2J6TG&field1=14&field2=14 HTTP/1.1\r\n\r\n";

    send(sockid,massage,sizeof(massage),0);
    printf("sending\n");


 Sleep(2000);
}
closesocket(sockid);
return 0;
}
