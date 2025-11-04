#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>

class Human {
  public:
    Human(const char *name, const char *surname, int id)
        : _name(name), _surname(surname), _id(id) {}
    ~Human() {}

  protected:
    const char *_name;
    const char *_surname;
    int _id;
};

#endif // !HUMAN_HPP
