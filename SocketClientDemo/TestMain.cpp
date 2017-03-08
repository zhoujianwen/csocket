//============================================================================
// Name        : SocketClientDemo.cpp
// Author      : pix
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "test_tcp_client1.h"
#include "test_udp_client1.h"

int main(void) {
	puts("Hello World!!!");
	test_tcp_client1();
//	test_udp_client1();
	return EXIT_SUCCESS;
}
