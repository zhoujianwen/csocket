/*
 * test_socket_host.cpp
 *
 *  Created on: 2017Äê3ÔÂ8ÈÕ
 *      Author: Administrator
 */

#include "test_socket_host.h"
#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>


void test_socket_host(void)
{
	const char * tag = "FUNC test_socket_host()";
	cout<<tag<<",RUN..."<<endl;
	struct hostent * pHost;
	const char * HOST = "www.baidu.com";
	if((pHost = gethostbyname(HOST)) == NULL)
	{
		 herror("gethostbyname");
		 return;
	}
	cout<<"Host name :"<<pHost->h_name<<endl;
	cout<<"IP Address : "<<inet_ntoa(*((struct in_addr *)pHost->h_addr))<<endl;
}
