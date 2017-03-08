/*
 * test_select_clinet1.cpp
 *
 *  Created on: 2017年3月8日
 *      Author: Administrator
 */

#include "test_select_clinet1.h"
#include <iostream>
using namespace std;
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define IPADDRESS "127.0.0.1"
#define SERV_PORT 8787

#define max(a,b) (a > b) ? a : b


static void handle_connection(int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	int maxfdp, stdineof;
	fd_set readfds;
	int n;
	struct timeval tv;
	int retval = 0;

	while (1) {
		// 将服务器fd加入set
		FD_ZERO(&readfds);
		FD_SET(sockfd, &readfds);
		maxfdp = sockfd;
		// 5s超时
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		retval = select(maxfdp + 1, &readfds, NULL, NULL, &tv);
		// 错误，结束
		if (retval == -1) {
			return;
		}
		// 超时，继续
		if (retval == 0) {
			printf("client timeout.\n");
			continue;
		}
		// 检查是否有数据包
		if (FD_ISSET(sockfd, &readfds)) {
			n = read(sockfd, recvline, MAXLINE);
			// 服务器是否关闭
			if (n <= 0) {
				fprintf(stderr, "client: server is closed.\n");
				close(sockfd);
				FD_CLR(sockfd, &readfds);
				return;
			}
			printf("client recv msg is:%s\n", recvline);
			sleep(5);
			write(sockfd, recvline,n);
		}
	}
}

void test_select_clinet1(void) {
	const char * TAG = "FUNC test_select_clinet1()";
	cout << TAG << ",RUN..." << endl;
	// 创建socket
	int sockfd;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	// 设置地址
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,IPADDRESS,&servaddr.sin_addr);

	int retval = 0;
	// connect 服务器
	retval = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if (retval < 0) {
	fprintf(stderr, "connect fail,error:%s\n", strerror(errno));
	return ;
	}
	printf("client send to server .\n");
	write(sockfd, "hello server", 32);
	handle_connection(sockfd);

}
