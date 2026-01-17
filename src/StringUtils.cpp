#include "StringUtils.h"
#include <cctype>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    std::string temp = str;
    size_t s = start;
    size_t e = end;
    if(!temp.empty()){
        if(s < 0){
            s = 0;
        } else if(s >= temp.length()){
            s = temp.length();
        }
        if(e < 0){
            e = 0;
        } else if(e >= temp.length()){
            e = temp.length();
        }
    }
    return temp.substr(s, e-s);
}

std::string Capitalize(const std::string &str) noexcept{
    // Replace code here
    std::string Temp = str;
    if(!Temp.empty()){
        Temp[0] = toupper(Temp[0]);
        for(size_t i = 1; i < Temp.length(); i++){
            Temp[i] = tolower(Temp[i]);
        }
    }
    return Temp;
}

std::string Upper(const std::string &str) noexcept{
    std::string Temp = str;
    if(!Temp.empty()){
        for(size_t i = 0; i < Temp.length(); i++){
            Temp[i] = toupper(Temp[i]);
        }
    }
    return Temp;
}

std::string Lower(const std::string &str) noexcept{
    std::string Temp = str;
    if(!Temp.empty()){
        for(size_t i = 0; i < Temp.length(); i++){
            Temp[i] = tolower(Temp[i]);
        }
    }
    return Temp;
}

std::string LStrip(const std::string &str) noexcept{
    std::string Temp = str;
    size_t i = 0;
    size_t len = Temp.length();
    while((i < len) && isspace(Temp[i])){
        i++;
    }

    return Temp.substr(i);
}

std::string RStrip(const std::string &str) noexcept{
    std::string temp = str;
    if(!temp.empty()){
        size_t i = temp.length() - 1;
        while(isspace(temp[i])){
            if(!i){
                return "";
            }
            i--;
        }
        return temp.substr(0,i+1);
    }
    return "";
}

std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string temp = str;
    std::string initial;
    size_t len = temp.length();
    std::string filling;
    if(fill == '\0'){
        filling = ' ';
    }else{
        filling = fill;
    }
    if(len >= width){
        return temp;
    }
    size_t remaining = width - len;
    size_t left = remaining / 2;
    size_t right = remaining - left;
    for(size_t i = 0; i < left; i++){
        initial += filling;
    }
    initial += temp;
    for(size_t i = 0; i < right; i++){
        initial += filling;
    }
    return initial;  
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    std::string temp = str;
    std::string initial;
    size_t len = temp.length();
    if(width < len){
        return temp;
    }
    size_t remaining = width - len;
    std::string filling;
    if(fill == '\0'){
        filling = ' ';
    }else{
        filling = fill;
    }
    initial += temp;
    for(size_t i = 0; i < remaining; i++){
        initial += filling;
    }
    return initial;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    std::string temp = str;
    std::string initial;
    size_t len = temp.length();
    if(width < len){
        return temp;
    }
    size_t remaining = width - len;
    std::string filling;
    if(fill == '\0'){
        filling = ' ';
    }else{
        filling = fill;
    }
    for(size_t i = 0; i < remaining; i++){
        initial += filling;
    }
    initial += temp;
    return initial;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};