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
    try {
        if (_guitars.size() >= 10) {
            throw 101;
        }
        if (!checkIfExistsInList(_guitars, guitar)) {
            _guitars.push_back(guitar);
            std::cout << guitar << " added to musician " << _name << " "
                      << _surname << "." << std::endl;
        } else {
            std::cout << guitar << " already exists for musician " << _name
                      << " " << _surname << "." << std::endl;
            throw 201;
        }
    } catch (int error) {
        switch (error) {
        case 101:
            std::cout << "Error: Guitar list is full." << std::endl;
            break;

        case 201:
            std::cout << "Error: Duplicate guitar." << std::endl;
            break;

        default:
            std::cout << "Unknown error occurred." << std::endl;
            break;
        }
    } catch (...) {
        std::cout << "An unexpected error occurred while adding guitar."
                  << std::endl;
    }
}

void Musician::addBass(const Bass &bass) {
    try {
        if (_basses.size() >= 10) {
            throw 102;
        }
        if (!checkIfExistsInList(_basses, bass)) {
            _basses.push_back(bass);
            std::cout << bass << " added to musician " << _name << " "
                      << _surname << "." << std::endl;
        } else {
            std::cout << bass << " already exists for musician " << _name << " "
                      << _surname << "." << std::endl;
            throw 202;
        }
    } catch (int error) {
        switch (error) {
        case 102:
            std::cout << "Error: Bass list is full." << std::endl;
            break;

        case 202:
            std::cout << "Error: Duplicate bass." << std::endl;
            break;

        default:
            std::cout << "Unknown error occurred." << std::endl;
            break;
        }
    } catch (...) {
        std::cout << "An unexpected error occurred while adding bass."
                  << std::endl;
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
