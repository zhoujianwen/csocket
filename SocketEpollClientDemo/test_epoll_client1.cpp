/*
 * test_epoll_client1.cpp
 *
 *  Created on: 2017年3月9日
 *      Author: pixboly
 */

#include "test_epoll_client1.h"
#include <iostream>
using namespace std;

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAXSIZE     1024
#define IPADDRESS   "127.0.0.1"
#define SERV_PORT   8787
#define FDSIZE        1024
#define EPOLLEVENTS 20

static void handle_connection(int sockfd);
static void
handle_events(int epollfd,struct epoll_event *events,int num,int sockfd,char *buf);
static void do_read(int epollfd,int fd,int sockfd,char *buf);
static void do_read(int epollfd,int fd,int sockfd,char *buf);
static void do_write(int epollfd,int fd,int sockfd,char *buf);
static void add_event(int epollfd,int fd,int state);
static void delete_event(int epollfd,int fd,int state);
static void modify_event(int epollfd,int fd,int state);


void test_epoll_client1(void)
{
	const char * TAG = "test_epoll_client1()";
	cout<<TAG<<",RUN..."<<endl;

	int sockfd;
	struct sockaddr_in  servaddr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,IPADDRESS,&servaddr.sin_addr);
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	//处理连接
	handle_connection(sockfd);
	close(sockfd);
}

static void handle_connection(int sockfd)
{
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    char buf[MAXSIZE];
    int ret;
    epollfd = epoll_create(FDSIZE);
    add_event(epollfd,STDIN_FILENO,EPOLLIN);
    for ( ; ; )
    {
        ret = epoll_wait(epollfd,events,EPOLLEVENTS,-1);
        handle_events(epollfd,events,ret,sockfd,buf);
    }
    close(epollfd);
}

static void
handle_events(int epollfd,struct epoll_event *events,int num,int sockfd,char *buf)
{
    int fd;
    int i;
    for (i = 0;i < num;i++)
    {
        fd = events[i].data.fd;
        if (events[i].events & EPOLLIN)				//可读
            do_read(epollfd,fd,sockfd,buf);
        else if (events[i].events & EPOLLOUT)		//可写
            do_write(epollfd,fd,sockfd,buf);
    }
}

static void do_read(int epollfd,int fd,int sockfd,char *buf)
{
	const char * TAG = "do_read()";
	cout<<TAG<<",RUN..."<<endl;
    int nread;
    nread = read(fd,buf,MAXSIZE);
    if (nread == -1)			//读数据失败
    {
        perror("read error:");
        close(fd);
    }
    else if (nread == 0)		//服务器关闭
    {
        fprintf(stderr,"server close.\n");
        close(fd);
    }
    else
    {
        if (fd == STDIN_FILENO) 			// 是标准输入,加入socket可发送
        {
        	cout<<TAG<<",(fd == STDIN_FILENO) "<<endl;
        	add_event(epollfd,sockfd,EPOLLOUT);
        }
        else								// 取消可读，变为标准输出，可输出
        {
        	cout<<TAG<<",(fd != STDIN_FILENO) "<<endl;
            delete_event(epollfd,sockfd,EPOLLIN);
            add_event(epollfd,STDOUT_FILENO,EPOLLOUT);
        }
    }
}

static void do_write(int epollfd,int fd,int sockfd,char *buf)
{
	const char * TAG = "do_write()";
	cout<<TAG<<",RUN..."<<endl;
    int nwrite;
    nwrite = write(fd,buf,strlen(buf));
    if (nwrite == -1) // 发送失败
    {
        perror("write error:");
        close(fd);
    }
    else			//发送成功
    {
        if (fd == STDOUT_FILENO)	// 标准输出fd，删除
        {
        	cout<<TAG<<",(fd == STDOUT_FILENO)"<<endl;
			delete_event(epollfd,fd,EPOLLOUT);
        }
        else						// 不是标准输出，就改为可读
        {
        	cout<<TAG<<",(fd != STDOUT_FILENO)"<<endl;
        	modify_event(epollfd,fd,EPOLLIN);
        }
    }
    memset(buf,0,MAXSIZE);
}

static void add_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);
}

static void delete_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);
}

static void modify_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);
}
