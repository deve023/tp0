CXX = g++
CXXFLAGS = -Wall -pedantic -g

all: tp0

Complejo.o: Complejo.cpp Complejo.h
	$(CXX) $(CXXFLAGS) -c Complejo.cpp

Pixel.o: Pixel.cpp Pixel.h Complejo.h
	$(CXX) $(CXXFLAGS) -c Pixel.cpp

Imagen.o: Imagen.cpp Imagen.h Pixel.h Complejo.h
	$(CXX) $(CXXFLAGS) -c Imagen.cpp

cmdline.o: cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cpp

main.o: main.cpp Imagen.h cmdline.h
	$(CXX) $(CXXFLAGS) -c main.cpp

tp0: main.o Pixel.o Imagen.o Complejo.o cmdline.o
	$(CXX) $(CXXFLAGS) $^ -o tp0

clean:
	rm *.o