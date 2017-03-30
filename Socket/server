#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <iostream>
using namespace std;
void main()
{
	int recv;
	WSADATA wsadata;
	int newsock;
	
	SOCKET socketfd;
	int len=sizeof(SOCKADDR_IN);
	SOCKADDR_IN server_addr;         //服务器所在的地址（端口号，IP，协议）
	SOCKADDR_IN client_addr;         //客户端所在的地址
	WSAStartup(MAKEWORD(2,2),&wsadata);

	socketfd=socket(AF_INET,SOCK_STREAM,0);   //创建服务器端用于监听的socket

	//为SOCKADDR_IN一系列参数赋值
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(5150);
	server_addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");

	//socket和服务器端地址绑定
	bind(socketfd,(SOCKADDR*)&server_addr,sizeof(server_addr));
	cout<<"bind success!"<<endl;

	//监听客户端的请求连接
	listen(socketfd,5);

	//创建新的socket用于处理等待队列中的客户端连接请求
	newsock=accept(socketfd,(SOCKADDR*)&client_addr,&len);
	cout<<"accept success!"<<endl;
	while(1)
	{
		char buf[20];
		recv=recvfrom(newsock,buf,20,0,(SOCKADDR*)&client_addr,&len);
		cout<<"recv success!"<<endl;
		printf("%s\n",buf);
	}
	closesocket(newsock);
  closesocket(socketfd);
	WSACleanup();

}
