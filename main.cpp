#include <iostream>

#include "json.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 4096
using namespace std;

int main()
{

    Json::Value root;
    Json::FastWriter fast_writer;
    root["REGION_ID"]="600901";

     root["REGION_ID5"]="700901";
      root["REGION_ID8"]="6009055";
       root["REGION_ID10"]="6009";



    string A=//"{ 123456 }";
        root.toStyledString().c_str();

    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[4096];
    char buff2[4096];
    int n;

    //?«Ø¤@?TCPªºsocket
    if( (listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        printf(" create socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

    //¥ý§â¦a§}²MªÅ¡A??¥ô·NIP
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);


    //¦a§}?©w¨ìlistenfd
    if ( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    {
        printf(" bind socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

    //?§vlistenfd
    if( listen(listenfd,10) == -1)
    {
        printf(" listen socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

    printf("====waiting for client's request=======\n");
    //accept ©Mrecv,ª`·N±µ¦¬¦r²Å¦ê²K¥[?§ô²Å'\0'
    while(1)
    {

        if( (connfd = accept(listenfd, (struct sockaddr *)NULL, NULL))  == -1)
        {
            printf(" accpt socket error: %s (errno :%d)\n",strerror(errno),errno);
            return 0;
        }
        n = recv(connfd,buff,MAXLINE,0);
        buff[n] = '\0';
        printf("recv msg from client:%s\n",buff);

        if ( send(connfd,A.c_str(),A.size(),0) <0)
        {
            printf("send msg error: %s(errno :%d)\n",strerror(errno),errno);
            return 0;
        }
printf("size=%d\n",A.size());

        printf("%s",A.c_str());
        close(connfd);
    }
    close(listenfd);


    cout << fast_writer.write(root)<< endl;
    return 0;
}
