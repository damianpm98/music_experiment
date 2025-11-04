#ifndef BASS_HPP
#define BASS_HPP
#include <Instrument.hpp>

class Bass : public Instrument {
  public:
    Bass(const std::string &brandName, const std::string &modelName,
         const std::string &ownerName, int serialNumber, int numberOfStrings)
        : _numberOfStrings(numberOfStrings) {
        _brandName = brandName;
        _modelName = modelName;
        _ownerName = ownerName;
        _serialNumber = serialNumber;
        std::cout << "Bass constructor for " << _brandName << " / "
                  << _modelName << " / " << std::to_string(_serialNumber)
                  << " of " << _ownerName << " called" << std::endl;
    }

    ~Bass() override {
        std::cout << "Bass destructor for " << _brandName << " / " << _modelName
                  << " / " << std::to_string(_serialNumber) << " of "
                  << _ownerName << " called" << std::endl;
    }

    void playSound(int note) override {
        std::cout << "Bass playing note " << std::to_string(note) << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Bass &bass) {
        os << "Bass Info:" << std::endl;
        os << "Brand: " << bass._brandName << std::endl;
        os << "Model: " << bass._modelName << std::endl;
        os << "Owner: " << bass._ownerName << std::endl;
        os << "Serial Number: " << bass._serialNumber << std::endl;
        return os;
    }

    friend bool operator==(const Bass &lhs, const Bass &rhs) {
        return (lhs._brandName == rhs._brandName &&
                lhs._modelName == rhs._modelName &&
                lhs._ownerName == rhs._ownerName &&
                lhs._serialNumber == rhs._serialNumber &&
                lhs._numberOfStrings == rhs._numberOfStrings);
    }

  private:
    int _numberOfStrings;
};

#endif // !BASS_HPP
