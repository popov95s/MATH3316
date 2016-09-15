# compiler & flags
CXX = g++
CXXFLAGS = -O -std=c++11
#CXXFLAGS = -O0 -g -std=c++11

# makefile targets
all : proj1_b.exe proj1_a.exe

proj1_a.exe : proj1_a.cpp proj1_a.o
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_b.exe : proj1_b.cpp matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_a.o : matrix.cpp proj1_a.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

proj1_b.o : matrix.cpp proj1_b.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	\rm -f *.o *.out a_data *.txt

realclean : clean
	\rm -f *.exe *~
