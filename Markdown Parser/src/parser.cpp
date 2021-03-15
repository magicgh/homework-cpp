//
// Created by magicgh on 6/20/2020.
//

#include "parser.h"

std::string l_tag[] = {
        "<blockquote>",
        "<ul>",
        "<ol>",
        "<pre><code><code><div>"
};

std::string r_tag[] = {
        "</blockquote>",
        "</ul>",
        "</ol>",
        "</div></code></code></pre>"
};


void Parser::parse(std::vector<std::string>&lines) {

    for(int i=0; i<ptn.block_rules.size()-1;i++){
        auto reg_pair = ptn.block_rules[i];
        bool in_block = 0; int now_level = 0, last_level = 0, cnt=0;
        for(auto &line:lines){
            bool in_while = 0;
            std::smatch m;
            while(std::regex_search(line, m, reg_pair.reg)){

                line = reg_pair.func(line).str;
                now_level = m[1].length();
                if(in_block){
                    if (now_level > last_level)
                        line = l_tag[i] + line, cnt++;
                    else if(now_level < last_level)
                        line = r_tag[i] + line, cnt--;
                }
                else line = l_tag[i] + line, cnt++;
                in_while = 1, in_block = 1, last_level = now_level;
            }
            if(!in_while&&in_block) {
                while(cnt--) line = r_tag[i] + "\n" +line;
                in_block = now_level = last_level = cnt = 0;
            }
        }
    }

    auto code_block_pair = ptn.block_rules[3];
    bool status = 0;
    for(auto &line:lines) {
        while (std::regex_search(line, code_block_pair.reg)) {
            line = (!status)?l_tag[3]:r_tag[3];
            status ^=1;
        }
    }


    for(auto &line:lines) {
        for(auto reg_pair: ptn.line_rules){
            while(std::regex_search(line, reg_pair.reg)){
                auto result = reg_pair.func(line);
                line = result.str;
            }
        }
        parsed_context << line <<std::endl;
    }

}