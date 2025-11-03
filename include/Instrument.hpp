#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

class Instrument {
  public:
    virtual void playSound(int note) = 0; // Pure virtual function
    virtual ~Instrument() {}

  protected:
    std::string _brandName;
    std::string _modelName;
    std::string _ownerName;
    int _serialNumber;
};

#endif // !INSTRUMENT_HPP
