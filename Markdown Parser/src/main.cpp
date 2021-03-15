#include "file.h"

//#define TEST
#define RELEASE

int main(int argc, char **argv) {

#ifdef RELEASE
    if (argc < 2) {
        std::cout<< "usage: " << argv[0] << " input_file [output_file]" << std::endl;
        std::cout<< "\tinput_file: markdown filename to parse" << std::endl;
        std::cout<< "\toutput_file: optional output html filename" << std::endl;
        exit(1);
    }

    std::string input_path(argv[1]), output_path;

    if(argc == 2) output_path = input_path.substr(0,input_path.length()-2)+"html";
    else output_path = argv[2];

#endif

#ifdef TEST
    std::string input_path("test.md"), output_path("test.html");
#endif


    try {

        MDFile md_file(input_path, output_path);
        md_file.convert();
        md_file.write();
    }
    catch (std::runtime_error &e) {
        std::cout<<e.what();
    }

    return 0;
}