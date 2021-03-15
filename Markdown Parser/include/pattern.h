//
// Created by magicgh on 6/20/2020.
//

#pragma once

#include <iostream>
#include <functional>
#include <cstring>
#include <sstream>
#include <regex>


namespace pattern {

    enum Token{
        err=-1, nul=0, p=1, href=2, ul=3, ol=4, li=5, em=6, strong=7, hr=8, br=9, img=10, quote=11, del=12, h1=13, h2=14, h3=15, h4=16, h5=17, h6=18, code=19, code_block=20
    };

    struct ReplaceResult{
        const std::string str;
        const Token type;
        ReplaceResult(const std::string str, const Token type):str(str), type(type){};
    };

    struct RegexPair {
        std::regex reg;
        std::function<ReplaceResult(std::string &)> func;
    };


    ReplaceResult replace_header(std::string &line, std::regex &reg);

    ReplaceResult replace_bold(std::string &line, std::regex &reg);

    ReplaceResult replace_italic(std::string &line, std::regex &reg);

    ReplaceResult replace_del(std::string &line, std::regex &reg);

    ReplaceResult replace_br(std::string &line, std::regex &reg);

    ReplaceResult replace_link(std::string &line, std::regex &reg);

    ReplaceResult replace_img(std::string &line, std::regex &reg);

    ReplaceResult replace_hr(std::string &line, std::regex &reg);

    ReplaceResult replace_code(std::string &line, std::regex &reg);

    ReplaceResult replace_quote(std::string &line, std::regex &reg);

    ReplaceResult replace_ul(std::string &line, std::regex &reg);

    ReplaceResult replace_ol(std::string &line, std::regex &reg);

    ReplaceResult replace_code_block(std::string &line, std::regex &reg);


    class Pattern {
    private:
        std::regex header_pattern = std::regex( R"((#{1,6})\s+(.+))");
        std::regex bold_pattern = std::regex(R"((\*\*)(.*)\1)");
        std::regex italic_pattern = std::regex(R"((\*)(.*)\1)");
        std::regex del_pattern = std::regex(R"((~~)(.*)\1)");
        std::regex br_pattern = std::regex(R"((.*)(\s{2,})$)");
        std::regex link_pattern = std::regex(R"(\[([^\[]+)\]\(([^\)]+)\))");
        std::regex img_pattern = std::regex(R"(!\[(.+)\]\(([^\)]+)\))");
        std::regex hr_pattern = std::regex(R"(^-{3,}|\*{3,}$)");
        std::regex code_pattern = std::regex(R"(`{1,2}(.*?)`{1,2})");
        std::regex code_block_pattern = std::regex(R"(^```$)");
        std::regex quote_pattern = std::regex(R"(^((&gt;|&amp;gt;)+)(.*))");
        std::regex ul_pattern = std::regex(R"(^([\s]*)[-\*\+] +(.*))");
        std::regex ol_pattern = std::regex(R"(^([\s]*)[0-9]+\.(.*))");

    public:
        std::vector<RegexPair> block_rules, line_rules;
        Pattern();

    };

}
