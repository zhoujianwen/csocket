/*
 * test_socket.cpp
 *
 *  Created on: 2017Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "test_socket.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
using namespace std;



void test_socket(void)
{
	cout<<"FUNC test_socket(),RUN..."<<endl;
	int fd = socket(AF_INET,SOCK_DGRAM,0);
	cout<<"FUNC test_socket(),"<<"fd:"<<fd<<endl;
}

