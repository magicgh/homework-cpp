//
// Created by magicgh on 6/20/2020.
//

#pragma once

#include <vector>
#include <fstream>
#include <map>
#include "pattern.h"

using namespace pattern;

class Parser{
private:
    Pattern ptn;
    std::stringstream parsed_context;
public:
    Parser() = default;
    ~Parser() = default;
    void parse(std::vector<std::string>&lines);
    inline std::string output(){
        return parsed_context.str();
    }
};
