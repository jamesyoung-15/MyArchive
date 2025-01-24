CPPFLAGS = -std=c++11 
# -fsanitize=address -g

all: lab4.exe

lab4.exe: Employee.o Full_time.o Contract.o main.cpp
	g++ -o $@ $(CPPFLAGS) Employee.o Full_time.o Contract.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe