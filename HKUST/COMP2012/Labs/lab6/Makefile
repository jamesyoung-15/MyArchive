# use CPPFLAGS to set proper configurations in different platforms
CPPFLAGS = -std=c++11
SRCS = test1.cpp test2.cpp CipherUtility.cpp VigenereCipher.cpp
OBJS = CipherUtility.o VigenereCipher.o
DEPS = $(SRCS:.cpp=.d)

all: lab6_test1.exe lab6_test2.exe

lab6_test%.exe: $(OBJS) test%.o
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d
# (Windows) del *.o *.exe *.d
# (Linux or MacOS) rm -f *.o *.exe *.d