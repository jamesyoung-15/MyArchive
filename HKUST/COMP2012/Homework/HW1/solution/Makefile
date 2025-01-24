CPPFLAGS = -std=c++11 # -static-libgcc -static-libstdc++
CPPFLAGS_leak = -std=c++11 -fsanitize=address

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak

SOURCES = main_test.cpp player.cpp match.cpp swiss.cpp
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))
OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(SOURCES:.cpp=.o))

all: create_directory pa1.exe pa1_leak.exe

create_directory:
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_leak)

pa1.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

pa1_leak.exe: $(OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -c $< -o $@

clean:
	rm  -rf  $(OBJ_DIR) $(OBJ_DIR_leak) *.exe
