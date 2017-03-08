//============================================================================
// Name        : SocketSelectDemo.cpp
// Author      : pix
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "test_select_server1.h"
#include "test_select_clinet1.h"

int main(void) {
//	test_select_server1();
	test_select_clinet1();
	puts("Hello World!!!");
	return EXIT_SUCCESS;
}
