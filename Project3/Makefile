###################################################################
#  Makefile for project 3
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  28 September 2015
# Edited by Stefan Popov on Oct 23 2016 for Project 3 in Math 3316
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# makefile targets
all : test_Lagrange.exe test_Lagrange2D.exe test_newton.exe Runge_Chebyshev.exe Runge_uniform.exe

test_Lagrange.exe : Lagrange.cpp test_Lagrange.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Lagrange2D.exe : test_Lagrange2D.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_newton.exe : test_newton.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Runge_uniform.exe : Runge_uniform.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Runge_Chebyshev.exe : Runge_Chebyshev.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
