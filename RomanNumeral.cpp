#include "RomanNumeral.hpp"

using namespace std;

char_int_map RomanNumeral::create_valuemap() {
      char_int_map m;
      m['I'] = 1;
      m['V'] = 5;
      m['X'] = 10;
      m['L'] = 50;
      m['C'] = 100;
      m['D'] = 500;
      m['M'] = 1000;
      return m;
}

char_int_map RomanNumeral::Roman = RomanNumeral::create_valuemap();

RomanNumeral::RomanNumeral(const string& input) :
  roman(input) {
  decimal = convertRomanToInt(input);
}

int RomanNumeral::convertRomanToInt(const string& input) {
  const int NEXT = 1;
  int intValue = 0;

  for (string::const_iterator letter = input.begin(); letter !=input.end(); ++letter) {
    int sign = 1;
    if((letter + NEXT) != input.end()) {
      if (Roman[*(letter + NEXT)] > Roman[*letter]) {
          sign = -1;
      }
    }
    intValue += sign * Roman[*letter];
  }
  return intValue;
}

void RomanNumeral::updateRoman() {
  roman = convertIntToRoman(decimal);
}

string RomanNumeral::convertIntToRoman(const int& value) {
  return "I";
}

void RomanNumeral::print(ostream &o) const {
  o << roman;
}

RomanNumeral& RomanNumeral::operator+=(const RomanNumeral& rhs) {
  decimal += rhs.decimal;
  updateRoman();
  return *this;
}

std::ostream& operator<<(std::ostream& o, const RomanNumeral& rn) {
  rn.print(o);
  return o;
}

