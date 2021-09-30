#include <iostream>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {

        gcd = std::gcd(numerator, denominator);

        (numerator * denominator > 0) ? positivity = 1 : positivity = 0;

        if (positivity) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        else {
            numerator = -(abs(numerator));
            denominator = abs(denominator);
        }

        if (gcd == 1) {
            num = numerator;
            den = denominator;
        }
        else {
            num = numerator / gcd;
            den = denominator / gcd;
        }


    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num;
    int den;
    int gcd;
    bool positivity;
};

bool operator== (Rational lhs, Rational rhs) {
    double weight_lhs{ double(lhs.Numerator()) / double(lhs.Denominator()) };
    double weight_rhs{ double(rhs.Numerator()) / double(rhs.Denominator()) };
    return weight_lhs == weight_rhs;
}

Rational operator+ (Rational lhs, Rational rhs) {
    int least_com_mult{ lcm(lhs.Denominator(), rhs.Denominator()) };

    int numerator_lhs{ lhs.Numerator() };
    int numerator_rhs{ rhs.Numerator() };

    if (lhs.Denominator() != least_com_mult) {
        numerator_lhs = least_com_mult / lhs.Denominator() * lhs.Numerator();
    }

    if (rhs.Denominator() != least_com_mult) {
        numerator_rhs = least_com_mult / rhs.Denominator() * rhs.Numerator();
    }
    
    int result_numerator = numerator_lhs + numerator_rhs;

    return Rational(result_numerator, least_com_mult);
}

Rational operator- (Rational lhs, Rational rhs) {
    int least_com_mult{ lcm(lhs.Denominator(), rhs.Denominator()) };

    int numerator_lhs{ lhs.Numerator() };
    int numerator_rhs{ rhs.Numerator() };

    if (lhs.Denominator() != least_com_mult) {
        numerator_lhs = least_com_mult / lhs.Denominator() * lhs.Numerator();
    }

    if (rhs.Denominator() != least_com_mult) {
        numerator_rhs = least_com_mult / rhs.Denominator() * rhs.Numerator();
    }

    int result_numerator = numerator_lhs - numerator_rhs;

    return Rational(result_numerator, least_com_mult);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }
    
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }
    
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    
    cout << "OK" << endl;
    return 0;
}