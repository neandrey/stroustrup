#файл для сборки проекта 1_triangle
CXX = g++
CXXFLAG = -q `fltk-config --ldflags --use-images`
CLEAN = rm -f
PROGRAM_NAME = main.out
######################################################
objects = main.o Simple_window.o Graph.o GUI.o Window.o Arc.o
main = main.cpp
arc = Arc.cpp
path = ../../GUI
simple_window 	= $(path)/Simple_window.cpp  
graph 			= $(path)/Graph.cpp 
gui 			= $(path)/GUI.cpp 
window			= $(path)/Window.cpp 

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(objects) 
	$(CXX) $(CXXFLAG) $(objects) -o $(PROGRAM_NAME) 

Arc.o: $(arc)
	$(CXX) -c $(arc)

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