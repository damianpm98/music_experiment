#ifndef GUITAR_HPP
#define GUITAR_HPP
#include <Instrument.hpp>

class Guitar : public Instrument {
  public:
    Guitar(const std::string &brandName, const std::string &modelName,
           const std::string &ownerName, int serialNumber, int numberOfStrings)
        : _numberOfStrings(numberOfStrings) {
        _brandName = brandName;
        _modelName = modelName;
        _ownerName = ownerName;
        _serialNumber = serialNumber;
        std::cout << "Guitar constructor for " << _brandName << " / "
                  << _modelName << " / " << std::to_string(_serialNumber)
                  << " of " << _ownerName << " called" << std::endl;
    }

    ~Guitar() override {
        std::cout << "Guitar destructor for " << _brandName << " / "
                  << _modelName << " / " << std::to_string(_serialNumber)
                  << " of " << _ownerName << " called" << std::endl;
    }

    void playSound(int note) override {
        std::cout << "Guitar playing note " << std::to_string(note)
                  << std::endl;
    }

  private:
    int _numberOfStrings;
};

#endif // !GUITAR_HPP
