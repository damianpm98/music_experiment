#ifndef MAIN_CPP
#define MAIN_CPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Metronome.hpp>
#include <Musician.hpp>

int main() {
    printMessage("Hello, Music Experiment!");
    Musician myMusician("John", "Mayer", 212121);

#ifdef VERBOSE
    myMusician.addInstrumentSkill("Guitar", 9);
    myMusician.addInstrumentSkill("Bass", 7);
    myMusician.checkInstrumentalSkills();

    myMusician.addGuitar(Guitar("Yamaha", "P-45", "Alice", 123456, 12));
    myMusician.addBass(Bass("Fender", "Jazz Bass", "Bob", 654321, 4));
    myMusician.checkInstruments();
#endif // VERBOSE

    // Add song test
    std::map<std::string, std::map<int, std::map<float, float>>> guitarSong = {
        {"Stairway to heaven",
         {{1, {{120.0f, 2.5f}, {130.0f, 3.0f}, {100.0f, 3.0f}, {90.0f, 3.0f}}},
          {2,
           {{110.0f, 2.0f}, {140.0f, 4.0f}, {120.0f, 3.0f}, {70.0f, 3.0f}}}}}};

    try {
        myMusician.addSong("Guitar", guitarSong);
    } catch (const char *msg) {
        std::cout << "Error adding song: " << msg << std::endl;
    } catch (...) {
        std::cout << "An unexpected error occurred while adding the song."
                  << std::endl;
    }

    try {
        myMusician.addSong("Piano", guitarSong);
    } catch (std::string msg) {
        std::cout << "Error adding song: " << msg << std::endl;
    } catch (...) {
        std::cout << "An unexpected error occurred while adding the song."
                  << std::endl;
    }

// Metronome test
#ifdef METRONOME_TEST
    Metronome myMetronome(120);
    myMetronome.start();

    sleepForMilliseconds(2000);
    myMetronome.pause();

    sleepForMilliseconds(3000);
    myMetronome.resume();

    while (!myMetronome.isSongFinished()) {
        sleepForMilliseconds(1000);
    }
#endif // METRONOME_TEST

    return 0;
}

#endif // !MAIN_CPP
