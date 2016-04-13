CFLAGS = clang++ -std=c++14
LDLIBS = -lglfw3 -lGLEW -lGL -lGLU -pthread -lm -lX11 -lXcursor -lXxf86vm -lXrandr -lXinerama -lXi -lXmu -ldl

LIB_DIR = -L/usr/lib
INC_DIR = -I/usr/include


SOURCE = textEd.cpp
OBJECTS = ${SOURCE:%.cpp=%.o}
EXECUTABLE = textEd

all:  clean $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE):
	@$(CFLAGS) $(LDFLAGS) $(LIB_DIR) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.cpp
	@$(CFLAGS)  $(INC_DIR) -c $< -o $@


clean:
	@rm -rf $(EXECUTABLE) $(OBJECTS)
