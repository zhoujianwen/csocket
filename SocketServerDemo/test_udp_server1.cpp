/*
 * test_udp_server1.cpp
 *
 *  Created on: 2017年3月8日
 *      Author: Administrator
 */

#include "test_udp_server1.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MYPORT 4950
#define MAXBUFLEN 100



void test_udp_server1(void)
{
	const char * TAG = "FUNC test_udp_server1()";
	cout<<TAG<<",RUN..."<<endl;

	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int addr_len, numbytes;
	char buf[MAXBUFLEN];
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero),sizeof(my_addr.sin_zero));

	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))==-1) {
		perror("bind");
		exit(1);
	}
	addr_len = sizeof(struct sockaddr);
	if ((numbytes=recvfrom(sockfd, buf, MAXBUFLEN, 0,
			(struct sockaddr *)&their_addr, &addr_len)) == -1)
	{
		perror("recvfrom");
		exit(1);
	}
	printf("got packet from %s/n",inet_ntoa(their_addr.sin_addr));
	printf("packet is %d bytes long/n",numbytes);
	buf[numbytes] = '/0';
	printf("packet contains \"%s\"/n",buf);
	close(sockfd);
}
