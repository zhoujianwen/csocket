CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestMain.o	\
			test_tcp_server1.o	\
			test_udp_server1.o

LIBS =

TARGET =	SocketServerDemo.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
