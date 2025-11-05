#ifndef METRONOME_CPP
#define METRONOME_CPP

#include <Metronome.hpp>
#include <cmath>

void Metronome::start() {
    std::cout << "Metronome started at " << _bpm << " BPM." << std::endl;
    _beats = 0;

    // TODO: this bool has to be used to sync the song with ALL THE INSTRUMENTS
    // TODO: needs upgrade and has to be done by a Coordinator class
    _playingSong = true;

    // Start ticking in a separate thread
    std::thread tickThread(&Metronome::ticking, this);
    tickThread.detach();
}

void Metronome::ticking() {
    int pulses = 1;

    // TODO: this time has to be used to sync the song with ALL THE INSTRUMENTS
    // TODO: needs upgrade and has to be done by a Coordinator class
    _timePointStart = timeNow();

    bool continueSong = _playingSong;

    while (!_songFinished) {
        // If the song is being played, wait for the next pulse time
        _metronomeMutex.lock();
        continueSong = _playingSong;
        _metronomeMutex.unlock();

        if (continueSong) {
            sleepForMilliseconds(static_cast<int>(
                round(_pulseTime))); // TODO: upgrade needed for precision
            tick(pulses);
            if (_beats >= 8) { // Stop after 8 beats for demonstration
                std::cout << "DEMO: Metronome stopped after 8 beats."
                          << std::endl;
                _playingSong = false;
                _songFinished = true;
                break;
            }
        } else // If not playing, just wait until we are told to play
        {
            std::cout << "Metronome is paused. Waiting to start..."
                      << std::endl;
            // TODO: needs upgrade and has to be done by a Coordinator class
            sleepForMilliseconds(1000);
        }
    }
}

void Metronome::tick(int &pulses) {
    if (pulses < PULSES_PER_BEAT) {
        pulses++;
        std::cout << "Tick" << std::endl;
    } else {
        pulses = 1;
        _beats++;
        std::cout << "Tick and Beat" << std::endl;
    }
}

void Metronome::pause() {
    _metronomeMutex.lock();
    _playingSong = false;
    _metronomeMutex.unlock();
    std::cout << "Metronome paused." << std::endl;
}

void Metronome::resume() {
    _metronomeMutex.lock();
    _playingSong = true;
    _metronomeMutex.unlock();
    std::cout << "Metronome activated again." << std::endl;
}

void Metronome::stop() {
    _metronomeMutex.lock();
    _playingSong = false;
    _songFinished = true;
    _metronomeMutex.unlock();
    std::cout << "Metronome stopped. Song stopped" << std::endl;
}

#endif // !METRONOME_CPP
