//
// Created by magicgh on 6/20/2020.
//

#pragma once

#include "parser.h"

class MDFile{
private:
    std::ifstream input;
    std::ofstream output;
    std::vector<std::string>lines;
    std::string html_context, input_path, output_path;
    Parser parser;
public:
    MDFile(const std::string input_path, const std::string output_path);

    void write();

    void convert();
};