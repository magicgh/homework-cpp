//
// Created by magicgh on 6/20/2020.
//

#include "file.h"

auto formalize = [](std::string &str){

    std::regex reg_list[] = {
            std::regex(R"(</ul>\n<ul>)"),
            std::regex(R"(</ol>\n<ol>)"),
            std::regex(R"(</p>\s*<p>)")
    };

    for(int i=0; i<3; i++){
        std::regex reg = reg_list[i];

        while(std::regex_search(str, reg))
            str = std::regex_replace(str, reg, "\n");
    }

};

auto normalize_line= [](std::string &str){

    std::unordered_map<std::string,std::string>replacements;

    replacements.emplace("<","&lt;");
    replacements.emplace(">","&gt;");
    replacements.emplace("\"","&quot;");
    replacements.emplace("&","&amp;");

    for(auto &it:replacements){
        int pos = str.find(it.first);
        while(pos != std::string::npos){
            str.replace(pos, 1, it.second);
            pos = str.find(it.first ,pos+1);
        }
    }
};

std::string header = R"(<!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title></title>
        <style>
</style>

        <link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/Microsoft/vscode/extensions/markdown-language-features/media/markdown.css">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/Microsoft/vscode/extensions/markdown-language-features/media/highlight.css">

        <style>
.task-list-item { list-style-type: none; } .task-list-item-checkbox { margin-left: -20px; vertical-align: middle; }
</style>
        <style>
            body {
                font-family: -apple-system, BlinkMacSystemFont, 'Segoe WPC', 'Segoe UI', system-ui, 'Ubuntu', 'Droid Sans', sans-serif;
                font-size: 14px;
                line-height: 1.6;
            }
        </style>
    </head>
    <body class="vscode-light">

)";

std:: string tail = R"(</body>
</html>)";

MDFile::MDFile(const std::string input_path, const std::string output_path): input_path(input_path),output_path(output_path) {

    if(input_path.substr(input_path.length()-3)!=".md")
        throw std::runtime_error("Not supported file type");
    input.open(input_path, std::ios::in);
    if(!input.is_open())
        throw std::runtime_error(std::strerror(errno));

    while(!input.eof()){
        lines.push_back("");
        getline(input, lines.back());
        normalize_line(lines.back());
    }
    input.close();

}

void MDFile::write() {
    //formalize(html_context);
    output.open(output_path, std::ios::out);
    if(!output.is_open())
        throw std::runtime_error("Unable to open HTML file");
    else output << header << html_context << tail;
    output.close();
}

void MDFile::convert() {
    parser.parse(lines);
    this->html_context = parser.output();
}
