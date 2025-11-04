#ifndef MUSICIAN_CPP
#define MUSICIAN_CPP

#include <Musician.hpp>

void Musician::addInstrumentSkill(std::string instrument, int skillLevel) {
    _instrumentSkill[instrument] = skillLevel;
    std::cout << "Added skill level " << skillLevel << " for instrument "
              << instrument << " to musician " << _name << " " << _surname
              << "." << std::endl;
}

void Musician::checkInstrumentalSkills() const {
    std::cout << "Instrumental skills for musician " << _name << " " << _surname
              << ":" << std::endl;
    for (const auto &skill : _instrumentSkill) {
        std::cout << "Instrument: " << skill.first
                  << ", Skill Level: " << skill.second << std::endl;
    }
}

void Musician::addGuitar(const Guitar &guitar) {
    if (!checkIfExistsInList(_guitars, guitar)) {
        _guitars.push_back(guitar);
        std::cout << guitar << " added to musician " << _name << " " << _surname
                  << "." << std::endl;
    } else {
        std::cout << guitar << " already exists for musician " << _name << " "
                  << _surname << "." << std::endl;
    }
}

void Musician::addBass(const Bass &bass) {
    if (!checkIfExistsInList(_basses, bass)) {
        _basses.push_back(bass);
        std::cout << bass << " added to musician " << _name << " " << _surname
                  << "." << std::endl;
    } else {
        std::cout << bass << " already exists for musician " << _name << " "
                  << _surname << "." << std::endl;
    }
}

void Musician::checkInstruments() const {
    std::cout << "Instruments owned by musician " << _name << " " << _surname
              << ":" << std::endl;

    for (const auto &guitar : _guitars) {
        guitar.displayInfo();
    }

    for (const auto &bass : _basses) {
        bass.displayInfo();
    }
}

#endif // !MUSICIAN_CPP
