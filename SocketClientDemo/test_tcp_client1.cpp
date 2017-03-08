/*
 * test_tcp_client1.cpp
 *
 *  Created on: 2017年3月8日
 *      Author: Administrator
 */

#include "test_tcp_client1.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 8787
#define MAXDATASIZE 100
#define IP "127.0.0.1"

void test_tcp_client1(void)
{
	const char * TAG = "FUNC test_tcp_client1()";
	cout<<TAG<<",RUN..."<<endl;
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct sockaddr_in their_addr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr.s_addr = inet_addr(IP);
	bzero(&(their_addr.sin_zero),sizeof(their_addr.sin_zero));

	if (connect(sockfd, (struct sockaddr *)&their_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}

	char * msg = "hello server,i'm client55555";
	send(sockfd, msg, strlen(msg) +1,0);

	if ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
	{
		perror("recv");
		exit(1);
	}
	buf[numbytes] = '/0';
	cout<<TAG<<",Received:"<<buf<<endl;
	close(sockfd);
}
