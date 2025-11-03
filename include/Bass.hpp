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

  private:
    int _numberOfStrings;
};

#endif // !BASS_HPP
