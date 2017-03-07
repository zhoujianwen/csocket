/*
 * test_socket_connect.cpp
 *
 *  Created on: 2017Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "test_socket_connect.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#define DEST_IP "132.241.5.10"
#define DEST_PORT 23

void test_socket_connect(void)
{
	char * func_tag = "FUNC test_socket_connect()";
	cout<<func_tag<<",RUN..."<<endl;
	int sockfd;
	struct sockaddr_in dest_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DEST_PORT);
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
	bzero(&(dest_addr.sin_zero),sizeof(dest_addr.sin_zero));
	int connect_res = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
	cout<<func_tag<<",connect_res:"<<connect_res<<endl;
}
