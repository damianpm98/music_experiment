#ifndef METRONOME_HPP
#define METRONOME_HPP

#define MINUTE_IN_MILLISECONDS 60000.0
#define PULSES_PER_BEAT 32

#include <Utils.hpp>
#include <mutex>

class Metronome {
  public:
    Metronome(int bpm) {
        _bpm = bpm;
        _beats = 0;
        _intervalTime = MINUTE_IN_MILLISECONDS / _bpm;
        _pulseTime = _intervalTime / PULSES_PER_BEAT;

        std::cout << "Metronome class constructed. Ticking at " << _bpm
                  << " BPM with " << PULSES_PER_BEAT << " pulses per beat"
                  << std::endl;

        _playingSong = false;
        _songFinished = false;
    }

    ~Metronome() { std::cout << "Metronome class destructed." << std::endl; }

    int getBPM() const { return _bpm; }
    void setBPM(int bpm) { _bpm = bpm; }
    void tick(int &pulses);
    void start();
    void stop();
    void pause();
    void ticking();
    void resume();
    bool isSongFinished() const { return _songFinished; }

  private:
    int _bpm;            // beats per minute
    int _beats;          // beats going on the song
    float _intervalTime; // milliseconds per beat
    float _pulseTime;    // pulses per beat

    bool _songFinished;
    bool _playingSong;
    std::chrono::high_resolution_clock::time_point _timePointStart;

    std::mutex _metronomeMutex;
};

#endif // !METRONOME_HPP
