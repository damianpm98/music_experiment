#ifndef MUSICIAN_HPP
#define MUSICIAN_HPP

#include <Bass.hpp>
#include <Guitar.hpp>
#include <Human.hpp>
#include <Utils.hpp>
#include <list>
#include <map>

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
    void
    addSong(std::string instrument,
            std::map<std::string, std::map<int, std::map<float, float>>> &song);

  private:
    std::list<Guitar> _guitars;
    std::list<Bass> _basses;
    std::map<std::string, int> _instrumentSkill = {}; // skills -> skill level
    std::map<std::string, std::map<int, std::map<float, float>>> _guitarSongs =
        {}; // name of song -> string -> (tempo -> duration)
    std::map<std::string, std::map<int, std::map<float, float>>> _bassSongs =
        {}; // name of song -> string -> (tempo -> duration)
};

#endif // !MUSICIAN_HPP
