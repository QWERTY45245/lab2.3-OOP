#include <iostream>
#include <iomanip>
#include <string>

class Fraction {
private:
    long long wholePart;
    int fractionalPart;

public:
    Fraction();                            
    Fraction(long long whole, int fractional); 
    Fraction(const Fraction& other);       

    long long getWholePart() const;        
    void setWholePart(long long whole);    
    int getFractionalPart() const;         
    void setFractionalPart(int fractional);

    void Init();                           
    void Read();                           
    void Display() const;                  
    std::string toString() const;          
    Fraction add(const Fraction& other) const;   
    Fraction multiply(const Fraction& other) const;

    Fraction& operator=(const Fraction& other); 
    Fraction& operator++();                
    Fraction operator++(int);              
    Fraction& operator--();               
    Fraction operator--(int);          
};
