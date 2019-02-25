g++ -c unit.cpp -ggdb -std=c++11
g++ -c unit.o network.cpp -ggdb -std=c++11
g++ network.o main.cpp -o main -ggdb -std=c++11
rm *.o
