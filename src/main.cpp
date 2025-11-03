#ifndef MAIN_CPP
#define MAIN_CPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Utils.hpp>

int main() {
    printMessage("Hello, Music Experiment!");
    Guitar myGuitar("Yamaha", "P-45", "Alice", 123456, 12);
    Bass myBass("Fender", "Jazz Bass", "Bob", 654321, 4);
    return 0;
}

#endif // !MAIN_CPP
