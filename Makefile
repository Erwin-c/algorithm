CXXFLAGS = -std=c++2a -g -Wall

main : main.o ./out/sort/sort.o ./out/sort/helper.o
	$(CXX) $(CXXFLAGS) -o main ./out/main.o ./out/sort/sort.o ./out/sort/helper.o

main.o : main.cc
	$(CXX) -c $(CXXFLAGS) -o ./out/main.o main.cc

./out/sort/helper.o : ./sort/helper.cc
	$(CXX) -c $(CXXFLAGS) -o ./out/sort/helper.o ./sort/helper.cc

./out/sort/sort.o : ./sort/sort.cc
	$(CXX) -c $(CXXFLAGS) -o ./out/sort/sort.o ./sort/sort.cc

.PHONY : clean
clean:
	rm ./out/sort/*.o ./out/*.o main
