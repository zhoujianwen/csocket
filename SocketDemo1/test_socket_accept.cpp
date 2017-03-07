/*
 * test_socket_accept.cpp
 *
 *  Created on: 2017Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "test_socket_accept.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#define MYPORT 3490
#define BACKLOG 10

void test_socket_accept()
{
	const char * const func_tag = "FUNC test_socket_accept()";
	cout<<func_tag<<",RUN..."<<endl;

	int sockfd, new_fd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int sin_size;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero),sizeof(my_addr.sin_zero));

	bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
	listen(sockfd, BACKLOG);
	sin_size = sizeof(struct sockaddr_in);
	new_fd = accept(sockfd,(struct sockaddr *)&their_addr,&sin_size);
}
