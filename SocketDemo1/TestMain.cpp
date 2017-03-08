/*
 * TestMain.cpp
 *
 *  Created on: 2017��3��7��
 *      Author: Administrator
 */


#include <stdio.h>
#include <stdlib.h>
#include "socket_addr_demo.h"
#include "test_socket.h"
#include "test_socket_bind.h"
#include "test_socket_connect.h"
#include "test_socket_accept.h"
#include "test_socket_host.h"
#include "test_socket_select.h"

int main(void) {
	puts("Hello World!!!");
//	test_socket_addr();
//	test_socket();
//	test_socket_bind();
//	test_socket_connect();
//	test_socket_accept();
//	test_socket_host();
	test_socket_select();
	return EXIT_SUCCESS;
}

