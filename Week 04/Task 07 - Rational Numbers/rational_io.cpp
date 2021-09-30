#include <iostream>
#include <sstream>
#include <numeric>
#include <string>

using namespace std;
class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {

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
    return Rational(res_num, res_den);
}

bool IsDigit(string str) {
    if (str.size() == 0) {
        return 0;
    }

    for (const char& ch : str) {
        if (!isdigit(ch)) {
            return 0;
        }
    }

    return 1;
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }
    return is;
}

/*
istream& operator >> (istream& stream, Rational& r) {
    if (stream.rdbuf()->in_avail() == 0) {
        stream.setstate(ios_base::failbit);
        return stream;
    }
    char sign;
    int numerator{ NULL }, denumerator{ NULL };
    stream >> numerator;
    stream >> sign;
    stream >> denumerator;
    if ((numerator != NULL) && (denumerator != NULL) && (sign == '/')) {
        r = { numerator, denumerator };
    }

    return stream;
}*/

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

int main() {

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("15/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(15, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }
    
    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }
    
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }
    
    {
        istringstream input1("1*2"), input2("1 /"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}