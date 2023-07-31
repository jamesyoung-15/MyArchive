CPPFLAGS = -std=c++11 -static-libgcc -static-libstdc++ -static
SRCS = main.cpp course.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: lab5.exe

lab5.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	rm *.exe *.o *.d