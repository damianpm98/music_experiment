#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <iostream>

class Instrument {
  public:
    virtual void playSound(int note) = 0; // Pure virtual function
    virtual ~Instrument() {}

    void displayInfo() const {
        std::cout << "Instrument Info:" << std::endl;
        std::cout << "Brand: " << _brandName << std::endl;
        std::cout << "Model: " << _modelName << std::endl;
        std::cout << "Owner: " << _ownerName << std::endl;
        std::cout << "Serial Number: " << _serialNumber << std::endl;
    }

  protected:
    std::string _brandName;
    std::string _modelName;
    std::string _ownerName;
    int _serialNumber;
};

#endif // !INSTRUMENT_HPP
