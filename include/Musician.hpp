#ifndef MUSICIAN_HPP
#define MUSICIAN_HPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Human.hpp>
#include <Utils.hpp>
#include <list>
#include <map>
#include <string>

struct Song {
    std::string artist;
    std::string album;
    std::string title;
    int year;
    std::map<int, std::map<float, float>>
        musicSheet; // string -> (tempo -> duration)
};

class Musician : public Human {
  public:
    Musician(const char *name, const char *surname, int id)
        : Human(name, surname, id) {
        std::cout << "Musician " << _name << " " << _surname << " with ID "
                  << id << " created." << std::endl;
    }
    ~Musician() {}

    void addInstrumentSkill(std::string instrument, int skillLevel);
    void addGuitar(const Guitar &guitar);
    void addBass(const Bass &bass);
    void checkInstrumentalSkills() const;
    void checkInstruments() const;
    void addSong(std::string instrument, Song &song);
    void songsList() const;

  private:
    std::list<Guitar> _guitars;
    std::list<Bass> _basses;
    std::map<std::string, int> _instrumentSkill = {}; // skills -> skill level
    std::list<Song> _guitarSongs = {};
    std::list<Song> _bassSongs = {};
};

#endif // !MUSICIAN_HPP
