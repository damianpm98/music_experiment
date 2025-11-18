#ifndef MAIN_CPP
#define MAIN_CPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Metronome.hpp>
#include <Musician.hpp>

inline void includeSong(Musician &musician, std::string instrument, Song &song);

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
    std::map<int, std::map<float, float>> guitarSheet = {
        {{1, {{120.0f, 2.5f}, {130.0f, 3.0f}, {100.0f, 3.0f}, {90.0f, 3.0f}}},
         {2, {{110.0f, 2.0f}, {60.0f, 4.0f}, {80.0f, 3.0f}, {70.0f, 3.0f}}}}};

    Song guitarSong = {"Led Zeppelin", "Led Zeppelin IV", "Stairway to Heaven",
                       1971, guitarSheet};

    std::map<int, std::map<float, float>> bassSheet = {
        {{1, {{100.0f, 2.5f}, {130.0f, 3.0f}, {60.0f, 3.0f}, {90.0f, 3.0f}}},
         {2, {{85.0f, 2.0f}, {140.0f, 4.0f}, {55.0f, 3.0f}, {70.0f, 3.0f}}}}};

    Song bassSong = {"Pink Floyd", "The Dark Side of the Moon", "Money", 1973,
                     bassSheet};

    includeSong(myMusician, "Guitar", guitarSong);
    includeSong(myMusician, "Piano", guitarSong);
    includeSong(myMusician, "Bass", bassSong);

    myMusician.songsList();

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

inline void includeSong(Musician &musician, std::string instrument,
                        Song &song) {

    try {
        musician.addSong(instrument, song);
    } catch (const char *msg) {
        std::cout << "Error adding song: " << msg << std::endl;
    } catch (...) {
        std::cout << "An unexpected error occurred while adding the song."
                  << std::endl;
    }
}

#endif // !MAIN_CPP
