/*
 * test_udp_client1.cpp
 *
 *  Created on: 2017年3月8日
 *      Author: Administrator
 */

#include "test_udp_client1.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MYPORT 4950
#define IP "127.0.0.1"

void test_udp_client1(void)
{
	const char * TAG = "FUNC test_udp_client1()" ;
	cout<<TAG<<",RUN..."<<endl;

	int sockfd;
	struct sockaddr_in their_addr;
	int numbytes;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(MYPORT);
	their_addr.sin_addr.s_addr = inet_addr(IP);
	bzero(&(their_addr.sin_zero),sizeof(their_addr.sin_zero));
	char * msg = "i'm udp clinet.";
	numbytes = sendto(sockfd,msg,strlen(msg),0,(struct sockaddr *)(&(their_addr)),sizeof(struct sockaddr));
	if(numbytes == -1)
	{
		perror("sendto");
		exit(1);
	}
	printf("sent %d bytes to %s /n",numbytes,inet_ntoa(their_addr.sin_addr));
	close(sockfd);
}
