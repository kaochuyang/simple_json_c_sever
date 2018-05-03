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





    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[4096];
    int n;

    //?«Ø¤@?TCPªºsocket
    if( (listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        printf(" create socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }


    //¥ý§â¦a§}²MªÅ¡A??¥ô·NIP
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);

    //¦a§}?©w¨ìlistenfd
    if ( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf(" bind socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

    //?§vlistenfd
    if( listen(listenfd,10) == -1) {
        printf(" listen socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

   while(1)
    {
    printf("====waiting for client's request=======\n");
    //accept ©Mrecv,ª`·N±µ¦¬¦r²Å¦ê²K¥[?§ô²Å'\0'

/////////////////////block 1
        if( (connfd = accept(listenfd, (struct sockaddr *)NULL, NULL))  == -1) {
            printf(" accpt socket error: %s (errno :%d)\n",strerror(errno),errno);
            return 0;
        }

        printf("hello\n");
        n = recv(connfd,buff,MAXLINE,0);
        buff[n] = '\0';
        printf("recv msg from client:%s\n",buff);
    }    close(connfd);

    close(listenfd);


    cout << fast_writer.write(root)<< endl;
    return 0;
}
