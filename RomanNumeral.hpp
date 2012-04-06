#ifndef ROMANNUMERAL_HPP
#define ROMANNUMERAL_HPP

#include<string>
#include<map>
#include<vector>
#include<list>
#include<iostream>

typedef std::map<char, int> char_int_map;

class RomanNumeral {
  public:
    RomanNumeral(const std::string&);
    RomanNumeral(const int&);
    inline int toInt() const {return decimal;}
    void print(std::ostream&) const;
    inline std::string toString() const {return roman;}
    RomanNumeral& operator+=(const RomanNumeral&);
    RomanNumeral operator+(const RomanNumeral&);
  private:
    int decimal;
    std::string roman;
    static char_int_map create_valuemap();
    static char_int_map Roman;
    static std::vector<char> create_ordered_roman_number_vector();
    static std::vector<char> RomanOrder;
    int convertRomanToInt(const std::string&);
    std::string convertIntToRoman(const int&);
    void updateRoman();

};

std::ostream& operator<<(std::ostream&, const RomanNumeral&);
std::string charListToString(const std::list<char> &);

#endif

