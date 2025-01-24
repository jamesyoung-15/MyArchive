CPPFLAGS = -std=c++11
CPPFLAGS_leak = -std=c++11 -fsanitize=address

OBJ_3_DIR = obj_3
OBJ_3_DIR_leak = obj_3_leak
OBJ_4_DIR = obj_4
OBJ_4_DIR_leak = obj_4_leak

SOURCES = main.cpp board.cpp boardtree.cpp hashtable.cpp
OBJECTS_3 = $(addprefix $(OBJ_3_DIR)/,$(SOURCES:.cpp=.o))
OBJECTS_3_leak = $(addprefix $(OBJ_3_DIR_leak)/,$(SOURCES:.cpp=.o))
OBJECTS_4 = $(addprefix $(OBJ_4_DIR)/,$(SOURCES:.cpp=.o))
OBJECTS_4_leak = $(addprefix $(OBJ_4_DIR_leak)/,$(SOURCES:.cpp=.o))

GPP = g++

all: create_directory change_const_3 pa3_3.exe pa3_3_leak.exe change_const_4 pa3_4.exe pa3_4_leak.exe

create_directory:
	mkdir -p $(OBJ_3_DIR) $(OBJ_3_DIR_leak) $(OBJ_4_DIR) $(OBJ_4_DIR_leak)

change_const_3:
	rm -f const.h
	cp const_3.h const.h

pa3_3.exe: $(OBJECTS_3)
	$(GPP) -o $@ $(CPPFLAGS) $^

pa3_3_leak.exe: $(OBJECTS_3_leak)
	$(GPP) -o $@ $(CPPFLAGS_leak) $^

change_const_4:
	rm -f const.h
	cp const_4.h const.h

pa3_4.exe: $(OBJECTS_4)
	$(GPP) -o $@ $(CPPFLAGS) $^

pa3_4_leak.exe: $(OBJECTS_4_leak)
	$(GPP) -o $@ $(CPPFLAGS_leak) $^

$(OBJ_3_DIR)/%.o: %.cpp
	$(GPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_3_DIR_leak)/%.o: %.cpp
	$(GPP) $(CPPFLAGS_leak) -c $< -o $@

$(OBJ_4_DIR)/%.o: %.cpp
	$(GPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_4_DIR_leak)/%.o: %.cpp
	$(GPP) $(CPPFLAGS_leak) -c $< -o $@

clean:
	rm  -rf  $(OBJ_3_DIR) $(OBJ_3_DIR_leak) $(OBJ_4_DIR) $(OBJ_4_DIR_leak) *.exe
