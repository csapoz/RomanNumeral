#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "RomanNumeral.hpp"

using namespace std;

TEST_CASE("One digit numerals",
    "I equals 1, V equals 5, X equals 10") {
  RomanNumeral I("I");
  REQUIRE(I.toInt() == 1);

  RomanNumeral V("V");
  REQUIRE(V.toInt() == 5);

  RomanNumeral X("X");
  REQUIRE(X.toInt() == 10);
}

TEST_CASE("Multi char roman digits",
    "Like II is 2 or VI is 6") {

  RomanNumeral II("II");
  REQUIRE(II.toInt() == 2);
  RomanNumeral VI("VI");
  REQUIRE(VI.toInt() == 6);
  RomanNumeral XI("XI");
  REQUIRE(XI.toInt() == 11);
}

TEST_CASE("When smaller values precede larger values, the smaller values are subtracted from the larger ones",
    "like IV is 4") {
  RomanNumeral IV("IV");
  REQUIRE(IV.toInt() == 4);
}

TEST_CASE("General cases", "Examples from wikipedia") {

  RomanNumeral MCMXLIV("MCMXLIV");
  REQUIRE(MCMXLIV.toInt() == 1944);

  RomanNumeral MCMLIV("MCMLIV");
  REQUIRE(MCMLIV.toInt() == 1954);

  RomanNumeral MDCCCCX("MDCCCCX");
  REQUIRE(MDCCCCX.toInt() == 1910);

  RomanNumeral MCMXC("MCMXC");
  REQUIRE(MCMXC.toInt() == 1990);

  RomanNumeral MDCCCCLXXXXVIIII("MDCCCCLXXXXVIIII");
  REQUIRE(MDCCCCLXXXXVIIII.toInt() == 1999);
  RomanNumeral MCMXCIX("MCMXCIX");
  REQUIRE(MCMXCIX.toInt() == 1999);
  RomanNumeral MIM("MIM");
  REQUIRE(MIM.toInt() == 1999);
}

TEST_CASE("Ostream",
    "cout << RomanNumeral --> should write like XII") {
  RomanNumeral XII("XII");
  ostringstream expected, result;
  result << XII;
  expected << "XII";
  REQUIRE(result.str() == expected.str());
}

TEST_CASE("Constructor for int",
    "like RomanNumeral(5) prints V or RomanNumeral(14) == XIV") {
  RomanNumeral V(5);
  RomanNumeral IV(4);
  ostringstream expected, result;
  result << V << " " << IV;
  expected << "V" << " " << "IV";
  REQUIRE(result.str() == expected.str());

  ostringstream expected_what, result_what;
  RomanNumeral r1900(1900);
  REQUIRE(r1900.toString() ==  "MCM");
  RomanNumeral r1910(1910);
  REQUIRE(r1910.toString() ==  "MCMX");
  RomanNumeral r1999(1999);
  REQUIRE(r1999.toString() ==  "MCMXCIX");
  RomanNumeral r14(14);
  REQUIRE(r14.toString() ==  "XIV");
  RomanNumeral r19(19);
  REQUIRE(r19.toString() ==  "XIX");
  
}

TEST_CASE("Operator+: Add two RomanNumber",
    "X + I = XI") {
  RomanNumeral mI("I");
  mI += mI;
  REQUIRE( mI.toInt() == 2); 

  RomanNumeral I("I");
  RomanNumeral X("X");

  REQUIRE( RomanNumeral(X + I).toString() == "XI");
  REQUIRE( RomanNumeral(X + I).toInt() == 11);
}
