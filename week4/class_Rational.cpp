#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (numerator > 0) {
            if (denominator < 0) {
                reverse_numbers(numerator, denominator);
            }
        }
        else if (numerator < 0) {
            if (denominator < 0){
                reverse_numbers(numerator, denominator);
            }
        }
        else {
            denominator = 1;
        }

        int nod;
        nod = NOD(numerator, denominator);

        num = numerator / nod;
        den = denominator / nod;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }

private:
    // Добавьте поля
    int num, den;

    void reverse_numbers(int& a, int& b) {
        a *= -1;
        b *= -1;
    }

    int NOD(int a, int b) {
        a = abs(a);
        b = abs(b);

        while (a > 0 && b > 0){
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }

        return a+b;
    }
};

bool operator== (const Rational& r1, const Rational& r2) {
    return r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator();
}

Rational operator+ (const Rational& r1, const Rational& r2) {
    int x = r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator();
    int y = r1.Denominator() * r2.Denominator();
    return Rational(x, y);
}

Rational operator- (const Rational& r1, const Rational& r2) {
    int x = r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator();
    int y = r1.Denominator() * r2.Denominator();
    return Rational(x, y);
}

Rational operator* (const Rational& r1, const Rational& r2) {
    int x = r1.Numerator() * r2.Numerator();
    int y = r1.Denominator() * r2.Denominator();
    return Rational(x, y);
}

Rational operator/ (const Rational& r1, const Rational& r2) {
    int x = r1.Numerator() * r2.Denominator();
    int y = r1.Denominator() * r2.Numerator();
    return Rational(x, y);
}

istream& operator>> (istream& stream, Rational& r) {
    int x, y;
    if (stream >> x && stream.ignore(2, '/') && stream >> y)
        r = {x, y};
    return stream;
}

ostream& operator<< (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator> (const Rational& r1, const Rational& r2) {
    double x = (double)r1.Numerator() / (double)r1.Denominator();
    double y = (double)r2.Numerator() / (double)r2.Denominator();
    return x > y;
}

bool operator< (const Rational& r1, const Rational& r2) {
    double x = (double)r1.Numerator() / (double)r1.Denominator();
    double y = (double)r2.Numerator() / (double)r2.Denominator();
    return x < y;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
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
