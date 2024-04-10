#include "Fraction.h"
using namespace std;

Fraction::Fraction() : wholePart(0), fractionalPart(0) {}

Fraction::Fraction(long long whole, int fractional) : wholePart(whole), fractionalPart(fractional) {}

Fraction::Fraction(const Fraction& other) : wholePart(other.wholePart), fractionalPart(other.fractionalPart) {}

long long Fraction::getWholePart() const {
    return wholePart;
}

void Fraction::setWholePart(long long whole) {
    wholePart = whole;
}

int Fraction::getFractionalPart() const {
    return fractionalPart;
}

void Fraction::setFractionalPart(int fractional) {
    fractionalPart = fractional;
}

void Fraction::Read() {
    cout << "Enter the whole part: ";
    cin >> wholePart;
    cout << "Enter the fractional part: ";
    cin >> fractionalPart;
}

void Fraction::Display() const {
    cout << wholePart << "." << fractionalPart;
}

string Fraction::toString() const {
    return to_string(wholePart) + "." + to_string(fractionalPart);
}

Fraction Fraction::add(const Fraction& other) const {
    long long resultWhole = wholePart + other.wholePart;
    unsigned short int resultFractional;

    if (fractionalPart + other.fractionalPart >= 100 && fractionalPart < 100 && other.fractionalPart < 100) {
        resultWhole++;
        resultFractional = (fractionalPart + other.fractionalPart) - 100;
    }
    else {
        resultFractional = fractionalPart + other.fractionalPart;
    }

    return Fraction(resultWhole, resultFractional);
}

Fraction Fraction::multiply(const Fraction& other) const {
    long double result = (wholePart + (static_cast<long double>(fractionalPart) / 100)) *
        (other.wholePart + (static_cast<long double>(other.fractionalPart) / 100));

    long long intPart = static_cast<long long>(result);
    unsigned short int fracPart = static_cast<unsigned short int>((result - intPart) * 10000);

    return Fraction(intPart, fracPart);
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        wholePart = other.wholePart;
        fractionalPart = other.fractionalPart;
    }
    return *this;
}

Fraction& Fraction::operator++() {
    wholePart++;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    ++(*this); 
    return temp;
}

Fraction& Fraction::operator--() {
    wholePart--;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    --(*this); 
    return temp;
}
