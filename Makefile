all: main.cpp
	clang++ -F /Library/Frameworks -framework sfml-system -framework sfml-window -framework sfml-graphics -framework SFML -framework sfml-audio main.cpp

