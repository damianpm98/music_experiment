#ifndef MAIN_CPP
#define MAIN_CPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Musician.hpp>

int main() {
    printMessage("Hello, Music Experiment!");
    Musician myMusician("John", "Mayer", 212121);
    myMusician.addInstrumentSkill("Guitar", 9);
    myMusician.addInstrumentSkill("Bass", 7);
    myMusician.checkInstrumentalSkills();
    myMusician.addGuitar(Guitar("Yamaha", "P-45", "Alice", 123456, 12));
    myMusician.addBass(Bass("Fender", "Jazz Bass", "Bob", 654321, 4));
    myMusician.checkInstruments();
    return 0;
}

#endif // !MAIN_CPP
