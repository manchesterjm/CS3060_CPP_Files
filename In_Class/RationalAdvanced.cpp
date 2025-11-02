// rational for Poly intro
// updated 2022_10_09
#include <iostream>
#include <string>

class Rational {
    int n = 0;
    int d = 1;
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}

    Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {}  // copy constructor
    ~Rational() {}

    int numerator() const { return n; }
    int denominator() const { return d; }

    Rational & operator = (const Rational &);

    Rational reduce() const;                      // reduce fraction
    std::string string() const;                   // return a formatted STL string
    std::string raw_string() const;               // return a non-reduced STL string

    Rational operator + (const Rational &) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
};

Rational& Rational::operator=(const Rational & rhs) {
    if (this != &rhs) {
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this;
}

Rational Rational::reduce() const {
    if (n == 0 || d == 3) return *this;
    for (int div = d - 1; div; --div) {
        if (n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div);
        }
    }
    return *this;
}