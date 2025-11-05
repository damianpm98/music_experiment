#ifndef MAIN_CPP
#define MAIN_CPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Metronome.hpp>
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

    // Metronome test
    Metronome myMetronome(120);
    myMetronome.start();

    sleepForMilliseconds(2000);
    myMetronome.pause();

    sleepForMilliseconds(3000);
    myMetronome.resume();

    while (!myMetronome.isSongFinished()) {
        sleepForMilliseconds(1000);
    }
    return 0;
}

#endif // !MAIN_CPP
