# Stefan Popov Oct 5 2016 - MATH3316 Project2
# compiler & flags
CXX = g++
CXXFLAGS = -O -std=c++11
#CXXFLAGS = -O0 -g -std=c++11

# makefile targets
all : vandermonde.exe test_newton.exe kepler.exe

vandermonde.exe : vandermonde.cpp vandermonde.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test_newton.exe : test_newton.cpp matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

kepler.exe : kepler.cpp matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

vandermonde.o : matrix.cpp vandermonde.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test_newton.o : matrix.cpp test_newton.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

kepler.o : matrix.cpp kepler.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	\rm -f *.o *.out a_data *.txt

realclean : clean
	\rm -f *.exe *~
