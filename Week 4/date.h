//
// Created by magicgh on 3/21/20.
//

#ifndef DATE_IMPLEMENT_DATE_H
#define DATE_IMPLEMENT_DATE_H

#endif //DATE_IMPLEMENT_DATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <regex>

using namespace std;

class Date {
    private:
        int y, m, d;
        const int days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        inline const int getDays() {
            if (m != 2)return days[m];
            else return (((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0) ? 29 : 28;
        }

        inline const void updateDate() {
            d -= getDays();
            if (++m > 12) m -= 12, y++;
        }

        inline bool isValid() {
            if (m < 1 || m > 12)return 0;
            int scope = getDays();
            return d < 1 || d > getDays() ? 0 : 1;
        }

        void str2Date(string &s) {
            regex p("^(\\d+)[\\s\\.\\-/]+(\\d{1,2})[\\s\\.\\-/]+(\\d{1,2})$");
            smatch r;
            try {
                if (regex_search(s, r, p)) {
                    Date t(stoi(r.str(1)), stoi(r.str(2)), stoi(r.str(3)));
                    if (t.isValid()) *this = t;
                    else throw "Invalid Date";
                } else throw "Invalid Date";
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

    public:
        Date() {
            time_t t = time(0);
            tm *now = localtime(&t);
            this->y = now->tm_year + 1900;
            this->m = now->tm_mon + 1;
            this->d = now->tm_mday;
        }

        Date(int y, int m, int d, bool c=0) : y(y), m(m), d(d) {
            try {
                if(!isValid()&&!c)throw "Invalid Date";
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        };

        Date(const Date &a) : y(a.y), m(a.m), d(a.d) {};

        Date(string &s) {
            str2Date(s);
        }

        Date(const char *ch) {
            string s(ch);
            str2Date(s);
        }

        friend Date operator+(const Date &a, const int &b) {
            Date c(a.y, a.m, a.d + b,1);
            while (c.d > c.getDays())c.updateDate();
            return c;
        }

        Date &operator=(const Date &a) {
            this->y = a.y, this->m = a.m, this->d = a.d;
            return *this;
        }

        Date operator+=(const int &t) {
            *this = *this + t;
            return *this;
        }

        Date &operator++() {
            *this += 1;
            return *this;
        }

        Date operator++(int) {
            Date t(*this);
            *this += 1;
            return t;
        }

        friend istream &operator>>(istream &in, Date &a) {
            in >> a.y >> a.m >> a.d;
            return in;
        }

        friend ostream &operator<<(ostream &out, const Date &a) {
            out << a.y << '.' << a.m << '.' << a.d;
            return out;
        }
};
