CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: test-rot13cipher test-caesar

ROT13_OBJECTS = test-rot13cipher.o rot13cipher.o ioutils.o
test-rot13cipher: $(ROT13_OBJECTS)
	$(CXX) -o $@ $(ROT13_OBJECTS)

CAESAR_OBJECTS = test-caesar.o caesar.o ioutils.o
test-caesar: $(CAESAR_OBJECTS)
	$(CXX) -o $@ $(CAESAR_OBJECTS)
	
DATE_OBJECTS = test-date.o datecipher.o ioutils.o
test-date: $(DATE_OBJECTS)
	$(CXX) -o $@ $(DATE_OBJECTS)

# Remove all objects and test- programs (TODO: add your own executables)
clean: 
	$(RM) *.o test-rot13cipher test-caesar test-date
