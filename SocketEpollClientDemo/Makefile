CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestMain.o	\
			test_epoll_client1.o

LIBS =

TARGET =	SocketEpollClientDemo.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
