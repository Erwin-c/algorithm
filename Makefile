CXXFLAGS = -std=c++2a -g -Wall

main : main.o ./build/sort/sort.o ./build/sort/helper.o
	$(CXX) $(CXXFLAGS) -o main ./build/main.o ./build/sort/sort.o ./build/sort/helper.o

main.o : main.cc
	$(CXX) -c $(CXXFLAGS) -o ./build/main.o main.cc

sort.o : ./sort/sort.cc
	$(CXX) -c $(CXXFLAGS) -o ./build/sort/sort.o ./sort/sort.cc

helper.o : ./sort/helper.cc
	$(CXX) -c $(CXXFLAGS) -o ./build/sort/helper.o ./sort/helper.cc
