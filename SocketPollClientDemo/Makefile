CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		SocketPollClientDemo.o

LIBS =

TARGET =	SocketPollClientDemo.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
