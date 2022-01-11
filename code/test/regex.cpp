#include <regex>
#include <iostream>
#include <string>

int main()
{
    std::regex r("(^j|^h).*\\.(?:mm|dat)$");

    std::vector<std::string> file_names = {"jelloworld.dat", "helloworld.mm"};

    std::regex re("^h.*");

    for(auto file_name : file_names)
    {
        std::cout << file_name << " " <<std::boolalpha << std::regex_match(file_name,r) << "\n";
        std::cout << file_name << " " <<std::boolalpha << std::regex_match(file_name,re) << "\n";
    } 


}