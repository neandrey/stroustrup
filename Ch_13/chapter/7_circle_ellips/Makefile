#файл для сборки проекта 1_triangle
CXX = g++
CXXFLAG = `fltk-config --ldflags --use-images`
CLEAN = rm -f
PROGRAM_NAME = main.out
######################################################
objects = main.o Simple_window.o Graph.o GUI.o Window.o
main = main.cpp
simple_window = ../GUI/Simple_window.cpp ../GUI/Simple_window.h 
graph = ../GUI/Graph.cpp ../GUI/Graph.h
gui = ../GUI/GUI.cpp ../GUI/GUI.h
window = ../GUI/Window.cpp ../GUI/Window.h

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(objects) 
	$(CXX) $(CXXFLAG) $(objects) -o $(PROGRAM_NAME) 

main.o: $(main) 
	$(CXX) -c $(main) 

Simple_window.o: $(simple_window) 
	$(CXX) -c $(simple_window) 

Graph.o: $(graph) 
	$(CXX) -c $(graph) 

GUI.o: $(gui) 
	$(CXX) -c $(gui) 

Window.o: $(window)
	$(CXX) -c $(window)


clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME) 