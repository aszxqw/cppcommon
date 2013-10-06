/************************************
 * file enc : ascii
 * author   : wuyanyi09@gmail.com
 ************************************/
#ifndef CPPCOMMON_STR_FUNCTS_H
#define CPPCOMMON_STR_FUNCTS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <memory.h>
#include "typedefs.h"
#include <functional> 
#include <locale>
namespace CPPCOMMON
{
    using namespace std;
    string string_format(const char*, ...) ;
    string joinStr(const vector<string>& source, const string& connector);
    vector<string> splitStr(const string& source, const string& pattern = " \t\n");
    bool splitStr(const string& source, vector<string>& res, const string& pattern = " \t\n");
    bool splitStrMultiPatterns(
                const string& strSrc, 
                vector<string>& outVec, 
                const vector<string>& patterns
                );
    string upperStr(const string& str);
    string lowerStr(const string& str);
    string replaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count = -1);
    string stripStr(const string& str, const string& patternstr = " \n\t");
    std::string &ltrim(std::string &s) ;
    std::string &rtrim(std::string &s) ;
    std::string &trim(std::string &s) ;
    unsigned int countStrDistance(const string& A, const string& B);
    unsigned int countStrSimilarity(const string& A, const string& B);


    bool uniStrToVec(const string& str, Unicode& vec);
    string uniVecToStr(const Unicode& vec);

    inline uint16_t twocharToUint16(char high, char low)
    {
        return (((uint16_t(high) & 0x00ff ) << 8) | (uint16_t(low) & 0x00ff));
    }

    inline pair<char, char> uint16ToChar2(uint16_t in)
    {
        pair<char, char> res;
        res.first = (in>>8) & 0x00ff; //high
        res.second = (in) & 0x00ff; //low
        return res;
    }

    inline void printUnicode(const Unicode& unicode)
    {
        cout<<uniVecToStr(unicode)<<endl;
    }

    inline bool strStartsWith(const string& str, const string& prefix)
    {
        //return str.substr(0, prefix.size()) == prefix;
        if(prefix.length() > str.length())
        {
            return false;
        }
        return 0 == str.compare(0, prefix.length(), prefix);
    }

    inline bool strEndsWith(const string& str, const string& suffix)
    {
        if(suffix.length() > str.length())
        {
            return false;
        }
        return 0 == str.compare(str.length() -  suffix.length(), suffix.length(), suffix);
    }

    inline bool isInStr(const string& str, char ch)
    {
        return str.find(ch) != string::npos;
    }

    inline void extractWords(const string& sentence, vector<string>& words)
    {
        bool flag = false;
        uint lhs = 0, len = 0;
        for(uint i = 0; i < sentence.size(); i++)
        {
            char x = sentence[i];
            if((0x0030 <= x && x<= 0x0039) || (0x0041 <= x && x <= 0x005a ) || (0x0061 <= x && x <= 0x007a))
            {
                if(flag)
                {
                    len ++;
                }
                else
                {
                    lhs = i;
                    len = 1;
                }
                flag = true;
            }
            else
            {
                if(flag)
                {
                    words.push_back(string(sentence, lhs, len));
                }
                flag = false;
            }
        }
        if(flag)
        {
            words.push_back(string(sentence, lhs, len));
        }
    }


}
#endif
