

#ifndef UNTITLED_GOTOXY_H
#define UNTITLED_GOTOXY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Gotoxy{

public:

    // METODOS

    // CONSTRUCTOR
    Gotoxy(){}

    template <typename T>
    // PRE:
    // POST:
    inline std::string ToString(const T& t) {

        std::stringstream ss;
        ss << t;

        return ss.str();
    }

    // PRE:
    // POST:
    inline std::string pos(const int& y,const int& x) {

        return "\33[" + ToString(y) + ";" + ToString(x) + "H";
    }


};

#endif //UNTITLED_GOTOXY_H
