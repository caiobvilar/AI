g++ parser.cpp -c -Wall -Werror -ggdb -std=c++11
echo -e PARSER BUILT [OK]
g++ trainer.cpp parser.o -o trainer -Wall -Werror -ggdb -std=c++11
echo -e TRAINER BUILT [OK]

