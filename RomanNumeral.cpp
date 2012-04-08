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

vector<char> RomanNumeral::create_ordered_roman_number_vector() {
  vector<char> v;
  v.push_back('M');
  v.push_back('D');
  v.push_back('C');
  v.push_back('L');
  v.push_back('X');
  v.push_back('V');
  v.push_back('I');
  return v;
}

char_int_map RomanNumeral::Roman = RomanNumeral::create_valuemap();
vector<char> RomanNumeral::RomanOrder = RomanNumeral::create_ordered_roman_number_vector();

RomanNumeral::RomanNumeral(const string& input) :
  roman(input) {
    decimal = convertRomanToInt(input);
  }

RomanNumeral::RomanNumeral(const int& input) :
  roman(convertIntToRoman(input)),
  decimal(input) {
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
  int integer = value;
  list<char> result;
  for(int i = 0; i < RomanOrder.size(); ++i) {
      int mod = integer / Roman[RomanOrder[i]];
      if(mod == 4) { // the magic number
        int prev = 1;
        while ( *(result.rbegin())  == RomanOrder[i - prev] &&
            result.size() > 1) {
          result.pop_back();
          prev++;
        }
        result.push_back(RomanOrder[i]);
        result.push_back(RomanOrder[i-prev]);
      } else {
        for (int j = 0; j < mod; ++j) {
          result.push_back(RomanOrder[i]);
        }
      }
      integer %= Roman[RomanOrder[i]];
    }
  return charListToString(result);
}

string charListToString(const list<char> & charlist) {
  string result = "";
  result.reserve(charlist.size());
  for (list<char>::const_iterator i = charlist.begin(); i != charlist.end(); ++i) {
    result += *i;
  }
  return result;
}

void RomanNumeral::print(ostream &o) const {
  o << roman;
}

RomanNumeral& RomanNumeral::operator+=(const RomanNumeral& rhs) {
  decimal += rhs.decimal;
  updateRoman();
  return *this;
}
RomanNumeral RomanNumeral::operator+(const RomanNumeral& rhs) const{
  return RomanNumeral(*this) += rhs;
}

std::ostream& operator<<(std::ostream& o, const RomanNumeral& rn) {
  rn.print(o);
  return o;
}

