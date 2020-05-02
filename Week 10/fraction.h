//
// Created by magicgh on 4/30/2020.
//

#ifndef WEEK_10_FRACTION_H
#define WEEK_10_FRACTION_H

#endif //WEEK_10_FRACTION_H

#include <iostream>
#include <algorithm>
#include <regex>
#include <cmath>
#include <string>
#include <stdexcept>

namespace fraction {

    using namespace std;
    using ll = long long;
    using ld = long double;

    inline ll __lcm(const ll &a, const ll &b) { return a * b / __gcd(a, b); }

    class DivideByZeroException : public range_error {
    public:
        DivideByZeroException() : range_error("division by zero") {};
    };

    class InvalidFraction : public exception {
    private:
        const char *ptr;
    public:
        InvalidFraction(const char *ptr) {
            this->ptr = ptr;
        }

        const char *what() {
            return ptr;
        }
    };

    class CFraction {
    private:
        ll num, den;

    public:
        CFraction(ll a, ll b) {
            try {
                if (b == 0)throw DivideByZeroException();
            }
            catch (DivideByZeroException &e) {
                cout << "Exception occurred: " << e.what() << endl;
                exit(-1);
            }
            a = b / abs(b) * a, b = abs(b);
            ll gcd = __gcd(abs(a), abs(b));
            num = a / gcd, den = b / gcd;
        }

        CFraction(string &s) {
            regex p(R"(^(\-{0,1})(\d+)[/\\]{1,1}(\d+)$)");
            smatch r;
            try {
                if (regex_search(s, r, p)) {
                    *this = CFraction(stoll(r.str(2)) * (r.str(1) == "-" ? -1 : 1), stoll(r.str(3)));
                } else throw InvalidFraction("invalid fraction");
            }
            catch (InvalidFraction &e) {
                cout << "Exception occurred: " << e.what() << endl;
                exit(-1);
            }
        }

        CFraction(const CFraction &t) : num(t.num), den(t.den) {};

        CFraction(const char *ch) {
            string s(ch);
            *this = CFraction(s);
        }

        CFraction(ll t) {
            *this = CFraction(t, 1ll);
        }

        CFraction(int t) {
            *this = CFraction(static_cast<ll>(t), 1ll);
        }

        CFraction() {
            this->num = 0, this->den = 1;
        }

        CFraction &operator=(const CFraction &t) {
            this->num = t.num, this->den = t.den;
            return *this;
        }

        friend CFraction operator+(const CFraction &a, const CFraction &b) {
            ll lcm = __lcm(a.den, b.den);
            return CFraction(lcm / a.den * a.num + lcm / b.den * b.num, lcm);
        }

        friend CFraction operator+(const CFraction &a, const ll &b) {
            return a + CFraction(b);
        }

        friend CFraction operator+(const CFraction &a, const int &b) {
            return a + CFraction(b);
        }

        CFraction operator+=(const CFraction &t) {
            *this = *this + t;
            return *this;
        }

        CFraction operator+=(const ll &t) {
            *this = *this + t;
            return *this;
        }

        CFraction operator+=(const int &t) {
            *this = *this + t;
            return *this;
        }

        CFraction &operator++() {
            *this += 1;
            return *this;
        }

        CFraction operator++(int) {
            CFraction t(*this);
            *this += 1;
            return t;
        }

        friend CFraction operator-(const CFraction &a, const CFraction &b) {
            CFraction t(b.num * -1, b.den);
            return a + t;
        }

        friend CFraction operator-(const CFraction &a, const ll &b) {
            return a - CFraction(b);
        }

        friend CFraction operator-(const CFraction &a, const int &b) {
            return a - CFraction(b);
        }

        CFraction operator-=(const CFraction &t) {
            *this = *this - t;
            return *this;
        }

        CFraction operator-=(const ll &t) {
            *this = *this - t;
            return *this;
        }

        CFraction operator-=(const int &t) {
            *this = *this - t;
            return *this;
        }

        CFraction &operator--() {
            *this -= 1;
            return *this;
        }

        CFraction operator--(int) {
            CFraction t(*this);
            *this -= 1;
            return t;
        }

        friend CFraction operator*(const CFraction &a, const CFraction &b) {
            ll temp_num = a.num * b.num, temp_den = a.den * b.den;
            return CFraction(temp_num, temp_den);
        }

        friend CFraction operator*(const CFraction &a, const ll &b) {
            return a * CFraction(b);
        }

        friend CFraction operator*(const CFraction &a, const int &b) {
            return a * CFraction(b);
        }

        CFraction operator*=(const CFraction &t) {
            *this = *this * t;
            return *this;
        }

        CFraction operator*=(const ll &t) {
            *this = *this * t;
            return *this;
        }

        CFraction operator*=(const int &t) {
            *this = *this * t;
            return *this;
        }

        friend CFraction operator/(const CFraction &a, const CFraction &b) {
            CFraction t(b.den, b.num);
            return a * t;
        }

        friend CFraction operator/(const CFraction &a, const ll &b) {
            return a / CFraction(b);
        }

        friend CFraction operator/(const CFraction &a, const int &b) {
            return a / CFraction(b);
        }

        CFraction operator/=(const CFraction &t) {
            *this = *this / t;
            return *this;
        }

        CFraction operator/=(const ll &t) {
            *this = *this / t;
            return *this;
        }

        CFraction operator/=(const int &t) {
            *this = *this / t;
            return *this;
        }

        friend istream &operator>>(istream &in, CFraction &t) {
            string s;
            in >> s;
            t = CFraction(s);
            return in;
        }

        friend ostream &operator<<(ostream &out, const CFraction &t) {
            out << t.num << '/' << t.den;
            return out;
        }

        friend bool operator<(const CFraction &a, const CFraction &b) {
            return (a - b).num < 0;
        }

        friend bool operator>=(const CFraction &a, const CFraction &b) {
            return !(a < b);
        }

        friend bool operator>(const CFraction &a, const CFraction &b) {
            return (a - b).num > 0;
        }

        friend bool operator<=(const CFraction &a, const CFraction &b) {
            return !(a > b);
        }

        friend bool operator!=(const CFraction &a, const CFraction &b) {
            return (a - b).num != 0;
        }

        friend bool operator==(const CFraction &a, const CFraction &b) {
            return !(a != b);
        }

        inline CFraction inverse() const {
            return 1 / (*this);
        }

        inline ld decimal() const {
            return static_cast<ld>(this->num) / static_cast<ld>(this->den);
        }

        inline ll numerator() const {
            return this->num;
        }

        inline ll denominator() const {
            return this->den;
        }

    };
};