//
// Created by magicgh on 6/21/2020.
//

#include "pattern.h"

namespace pattern{



    ReplaceResult replace_header(std::string &line, std::regex &reg) {
        std::smatch m;
        std::regex_match(line, m, reg);
        std::stringstream ret;
        std::string content = m[2].str();
        int h_level = static_cast<int>(m[1].length());
        ret << "<h" << h_level << ">" << content << "</h" << h_level << ">";
        return ReplaceResult(ret.str(), static_cast<Token>(12+h_level));
    }


    ReplaceResult replace_bold(std::string &line, std::regex &reg) {
        std::smatch m;
        std::regex_match(line, m, reg);
        return ReplaceResult(regex_replace(line, reg, "<strong>$2</strong>"),strong);
    }

    ReplaceResult replace_italic(std::string &line, std::regex &reg) {
        std::smatch m;
        std::regex_match(line, m, reg);
        return ReplaceResult(regex_replace(line, reg, "<em>$2</em>"),em);
    }

    ReplaceResult replace_del(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, "<del>$2</del>"),del);
    }

    ReplaceResult replace_br(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, "$1<br>"),br);
    }

    ReplaceResult replace_link(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, R"(<a href="$2">$1</a>)"),href);
    }

    ReplaceResult replace_img(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, R"(<img src="$2" alt="$1">)"),img);
    }

    ReplaceResult replace_hr(std::string &line, std::regex &reg) {
        return ReplaceResult("<hr>",hr);
    }

    ReplaceResult replace_code(std::string &line, std::regex &reg){
        return ReplaceResult(regex_replace(line, reg, "<code>$1</code>"),code);
    };

    ReplaceResult replace_code_block(std::string &line, std::regex &reg){
        return ReplaceResult("",code_block);
    };

    ReplaceResult replace_quote(std::string &line, std::regex &reg){
        return ReplaceResult(regex_replace(line, reg, "<p>$3</p>"),quote);
    }

    ReplaceResult replace_ul(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, "<li>$2</li>"),ul);
    }

    ReplaceResult replace_ol(std::string &line, std::regex &reg) {
        return ReplaceResult(regex_replace(line, reg, "<li>$2</li>"),ol);
    }




    Pattern::Pattern() {
        using namespace std::placeholders;
        line_rules.emplace_back((RegexPair) {img_pattern, std::bind(&replace_img, _1, ref(img_pattern))});
        line_rules.emplace_back((RegexPair) {link_pattern, std::bind(&replace_link, _1, ref(link_pattern))});
        line_rules.emplace_back((RegexPair) {header_pattern, std::bind(&replace_header, _1, ref(header_pattern))});
        line_rules.emplace_back((RegexPair) {hr_pattern, std::bind(&replace_hr, _1, ref(hr_pattern))});
        line_rules.emplace_back((RegexPair) {bold_pattern, std::bind(&replace_bold, _1, ref(bold_pattern))});
        line_rules.emplace_back((RegexPair) {italic_pattern, std::bind(&replace_italic, _1, ref(italic_pattern))});
        line_rules.emplace_back((RegexPair) {del_pattern, std::bind(&replace_del, _1, ref(del_pattern))});
        line_rules.emplace_back((RegexPair) {code_pattern, std::bind(&replace_code, _1, ref(code_pattern))});
        line_rules.emplace_back((RegexPair) {br_pattern, std::bind(&replace_br, _1, ref(br_pattern))});

        block_rules.emplace_back((RegexPair) {quote_pattern, std::bind(&replace_quote, _1, ref(quote_pattern))});
        block_rules.emplace_back((RegexPair) {ul_pattern, std::bind(&replace_ul, _1, ref(ul_pattern))});
        block_rules.emplace_back((RegexPair) {ol_pattern, std::bind(&replace_ol, _1, ref(ol_pattern))});
        block_rules.emplace_back((RegexPair) {code_block_pattern, std::bind(&replace_code_block, _1, ref(code_block_pattern))});

    }
}
