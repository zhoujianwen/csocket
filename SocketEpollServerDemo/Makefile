CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestMain.o	\
			test_epoll_server1.o

LIBS =

TARGET =	SocketEpollServerDemo.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
