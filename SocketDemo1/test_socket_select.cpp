/*
 * test_socket_select.cpp
 *
 *  Created on: 2017年3月8日
 *      Author: Administrator
 */

#include "test_socket_select.h"
#include <iostream>
using namespace std;

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define STDIN 0

void test_socket_select(void)
{
	const char * TAG = "FUNC test_socket_select()";
	cout<<TAG<<",RUN..."<<endl;

	struct timeval tv;
	fd_set readfds;
	tv.tv_sec = 2;
	tv.tv_usec = 500000;
	FD_ZERO(&readfds);
	FD_SET(STDIN, &readfds);

	select(STDIN+1, &readfds, NULL, NULL, &tv);
	if(FD_ISSET(STDIN, &readfds))
	{
		cout<<"A key was pressed!\n";
	}
	else
	{
		cout<<"Timed out.\n";
	}
}
