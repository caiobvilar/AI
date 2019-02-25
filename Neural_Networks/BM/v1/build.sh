g++ -c base.cpp -ggdb -std=c++11
echo -e base built [OK]
g++ base.o main.cpp -o main -ggdb -std=c++11
echo -e main built [OK]
rm *.o
echo -e object files cleaned [OK]
