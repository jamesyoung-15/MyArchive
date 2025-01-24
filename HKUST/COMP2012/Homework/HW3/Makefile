
CPPFLAGS = -std=c++11 -fsanitize=address
SRCS = main.cpp board.cpp boardtree.cpp hashtable.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: pa3.exe

pa3.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f *.o pa3.exe *.d

.PRECIOUS: $(OBJS)