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

        SetNumbers(numerator, denominator);

    }

    void SetNumbers(int numerator, int denominator) {

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

ostream& operator<< (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& rational) {


    if (stream.rdbuf()->in_avail() != 0) {

    }
    else {
        stream.setstate(ios_base::failbit);
        return stream;
    }
    string numerator_str{};
    int numerator{ 0 };
    getline(stream, numerator_str, '/');
    if (IsDigit(numerator_str)) {
        numerator = atoi(numerator_str.c_str());
    }
    else {
        rational.SetNumbers(0, 1);
        return stream;
    }


    string denumerator_str{};
    int denumerator{ 0 };
    getline(stream, denumerator_str, ' ');
    if (IsDigit(denumerator_str)) {
        denumerator = atoi(denumerator_str.c_str());
    }
    else {
        rational.SetNumbers(0, 1);
        return stream;
    }


    rational.SetNumbers(numerator, denumerator);
    return stream;
}

bool operator< (Rational lhs, Rational rhs) {
    double weight_lhs{ double(lhs.Numerator()) / double(lhs.Denominator()) };
    double weight_rhs{ double(rhs.Numerator()) / double(rhs.Denominator()) };
    return (weight_lhs < weight_rhs);
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }
        
        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }
    
    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}