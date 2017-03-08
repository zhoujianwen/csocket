CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestMain.o	\
			test_tcp_client1.o	\
			test_udp_client1.o

LIBS =

TARGET =	SocketClientDemo.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
