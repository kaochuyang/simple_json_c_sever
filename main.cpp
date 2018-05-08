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
#include <climits>
#define MAXLINE 4096
using namespace std;

int main()
{

    Json::Value root;
    Json::FastWriter fast_writer;
    root["REGION_ID"]="600901";

    root["REGION_ID5"]="901";
    root["REGION_ID6"]="5901";
    root["REGION_ID7"]="5501";

//string head="[";
//string tail="]";

//"["{   "REGION_ID" : "600901",   "REGION_ID10" : "6009",   "REGION_ID5" : "700901",   "REGION_ID8" : "6009055"}"]";
    string A="{\"Data\":{\"Name\":\"MichaelChan\",\"Email\":\"XXXX@XXX.com\",\"Phone\":[1234567,0911123456]}}";
        //="{[\"{ 123456 }"\";
       // root.toStyledString();
//

    cout<<"\""<<endl;
    cout<<"\\\""<<endl;

    cout<<A.find("\"")<<endl;


//
//    int count=0;
//
//    string str=A;
//    string match="\"";
//    string replacement="\\\"";
//    unsigned int max_replacements=UINT_MAX;
//    cout<<max_replacements<<endl;
//    size_t pos=0;
//    unsigned replacements=0;
//    while((pos=A.find(match,pos))!=string::npos
//            &&replacements<max_replacements)
//    {
//        count++;
//        A.replace(pos,match.length(),replacement);
//        pos+=replacement.length();
//        replacements++;
//    }
//
//    cout<<"count="<<count<<endl;
////A.replace(A.find("\""),size)
//    cout<<A.c_str()<<endl;
//    cout<<"hellp"<<endl;
////cout<<root["REGION_ID"].asString()<<endl;
//
//A="\""+A+"\"";
//


//root.as
//string B=root.getMemberNames();
//printf("%s\n",B.c_str());
//
//stirg s1=("123\"123");
//
//string s2="""";
//string s3="\"";
//
//
//
//printf("%s\n",s3.c_str());
//
//
//size_t found;
//string s3;
//s3=A.c_str();
//found=A.find(s2);
//s3.replace(found,");
//printf("%s\n",s3);



    printf("%s\n",A.c_str());

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

    //?§vlistenfdvu,6vu04
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
        printf("\n");


        printf("recv msg from client:%s\n",buff);
        printf("\n");
        if ( send(connfd,A.c_str(),A.size(),0) <0)
        {
            printf("send msg error: %s(errno :%d)\n",strerror(errno),errno);
            return 0;
        }
        printf("size=%d\n",A.size());

        printf("%s",A.c_str());

    }
    close(connfd);
    close(listenfd);


    cout << fast_writer.write(root)<< endl;
    return 0;
}
