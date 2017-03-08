CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS = TestMain.o	\
		socket_addr_demo.o	\
		test_socket.o	\
		test_socket_bind.o \
		test_socket_connect.o	\
		test_socket_accept.o	\
		test_socket_host.o	\
		test_socket_select.o

LIBS =

TARGET =	SocketDemo1.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
