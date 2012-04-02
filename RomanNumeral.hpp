#ifndef ROMANNUMERAL_HPP
#define ROMANNUMERAL_HPP

#include<string>
#include<map>
#include<iostream>

typedef std::map<char, int> char_int_map;

class RomanNumeral {
  public:
    RomanNumeral(const std::string&);
    inline int toInt() const {return decimal;}
    void print(std::ostream&) const;
    RomanNumeral& operator+=(const RomanNumeral&);
  private:
    int decimal;
    std::string roman;
    static char_int_map create_valuemap();
    static char_int_map Roman;
    int convertRomanToInt(const std::string&);
    std::string convertIntToRoman(const int&);
    void updateRoman();

};

std::ostream& operator<<(std::ostream&, const RomanNumeral&);

#endif

