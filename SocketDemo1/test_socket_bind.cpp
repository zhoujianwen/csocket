/*
 * test_socket_bind.cpp
 *
 *  Created on: 2017Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "test_socket_bind.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#define MY_PORT 9999

void test_socket_bind(void)
{
	cout<<"FUNC test_socket_bind(),RUN..."<<endl;
	int sockfd;
	struct sockaddr_in my_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MY_PORT);
	my_addr.sin_addr.s_addr = inet_addr("132.241.5.10");
	bzero(&my_addr.sin_zero,sizeof(my_addr.sin_zero));
	bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
}
