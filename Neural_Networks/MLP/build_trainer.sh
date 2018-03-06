g++ parser.cpp -c -Wall -Werror -ggdb -std=c++11
g++ trainer.cpp parser.o -o trainer -Wall -Werror -ggdb -std=c++11
