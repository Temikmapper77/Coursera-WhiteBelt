#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;
class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {

        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }

        if (denominator < 0) {
            if (numerator < 0) {
                numerator = abs(numerator);
                denominator = abs(denominator);
            }
            else {
                numerator = -(abs(numerator));
                denominator = abs(denominator);
            }
        }

        int gcd = std::gcd(numerator, denominator);

        num = numerator / gcd;
        den = denominator / gcd;

        if (numerator == 0) denominator = 1;
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

Rational operator* (Rational lhs, Rational rhs) {
    int res_num = lhs.Numerator() * rhs.Numerator();
    int res_den = lhs.Denominator() * rhs.Denominator();
    return Rational(res_num, res_den);
}

Rational operator/ (Rational lhs, Rational rhs) {
    int res_num = lhs.Numerator() * rhs.Denominator();
    int res_den = lhs.Denominator() * rhs.Numerator();

    if (res_den == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(res_num, res_den);
}

ostream& operator<< (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& rational) {

    if (!stream) {
        return stream;
    }

    char ch;
    int numerator, denominator;
    stream >> numerator >> ch >> denominator;
    if (ch == '/') {
        rational = { numerator, denominator };
    }
    return stream;
    }

bool operator< (Rational lhs, Rational rhs) {
    double weight_lhs{ double(lhs.Numerator()) / double(lhs.Denominator()) };
    double weight_rhs{ double(rhs.Numerator()) / double(rhs.Denominator()) };
    return (weight_lhs < weight_rhs);
}
int main() {

    istringstream s1;
    char operation{'0'};
    Rational r1, r2;
    try {
        cin >> r1 >> operation >> r2;
    }
    catch(invalid_argument& in_arg) {
        cout << in_arg.what();
        return 0;
    }
    try {
        if (operation == '+') {
            cout << r1 + r2;
        }
        else if (operation == '-'){
            cout << r1 - r2;
        }
        else if (operation == '*') {
            cout << r1 * r2;
        }
        else if (operation == '/') {
            try {
                cout << r1 / r2;
            }
            catch (domain_error& err) {
                cout << err.what();
                return 0;
            }
        }
        else {
            throw invalid_argument("Invalid argument");
            return 0;
        }
    } 
    catch (invalid_argument& in_arg) {
        cout << in_arg.what();
    }
    
    return 0;
}