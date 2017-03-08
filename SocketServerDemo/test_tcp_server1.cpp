/*
 * test_tcp_server1.cpp
 *
 *  Created on: 2017��3��8��
 *      Author: pix
 */

#include "test_tcp_server1.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MYPORT 8787
#define BACKLOG 10

void test_tcp_server1(void)
{
	const char * TAG = "FUNC test_tcp_server1()";
	cout<<TAG<<",RUN..."<<endl;

	 //def param
	int server_sockfd,client_sockfd ;
	struct sockaddr_in server_addr,client_addr ;
	int addr_len ;
	//get server socket file description
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	//init server addr
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(MYPORT);
	server_addr.sin_addr.s_addr = INADDR_ANY ;
	bzero(&(server_addr.sin_zero),sizeof(server_addr.sin_zero));

	//bind
	int bind_res = bind(server_sockfd,(struct sockaddr *) &server_addr,sizeof(struct sockaddr));
	if(bind_res == -1)
	{
		cout<<TAG<<",bind() error,bind_res:"<<bind_res<<endl;
		perror("bind");
		return ;
	}
	cout<<"server bind success,port:"<<MYPORT<<endl;
	// listen
	int listen_res = listen(server_sockfd,BACKLOG);
	if(listen_res == -1)
	{
		cout<<TAG<<",listen() error,bind_res:"<<bind_res<<endl;
		perror("listen");
		return ;
	}
	cout<<"server listen success...\n"<<endl;
	addr_len = sizeof(struct sockaddr_in);
	//looper accept
	while(1) {
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr,&addr_len);
		if(client_sockfd == -1) {
			perror("accept");
			continue;
		}
		cout<<"accept client connect success IP:"<<inet_ntoa(client_addr.sin_addr)<<endl;
		if (!fork()) {
			if(send(client_sockfd,"Hello,i am server!\n\0",20,0)== -1) {
				perror("send");
			}
			cout<<"send msg success..\n"<<endl;
			close(client_sockfd);
			exit(0);
		}
	}
}
