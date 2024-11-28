#include "Strings.h"
#include <fstream>
#include <iostream>
#include "Exception.h"
#include <string>

Strings::Strings()
{
    std::cout << "Strings default constructor called\n";
}

Strings::~Strings()
{
    std::cout << "Strings default destructor called\n";
}

void Strings::checkFile(const std::string& file)
{
    std::ifstream gin;
    gin.open(file);
    if (!gin)
        throw Exception("There is no such file in the directory!\n");
    std::string text, line;
    std::cout << "\nSentences starting with a dash: \n";
    while (std::getline(gin,line))
    {
        text += line;
    }
    bool flag = false;
    bool space = false;
    std::string line_rem = "";
    for (int i=0; i<text.size(); i++)
    {
        
        if (text[i] == '-' && space == true )
        {
            flag = true;

        }
        if (text[i] == ' ' || text[i] == '\t')
        {
            space = true;

        }
        else
        {
            space = false;
        }
        if (flag)
        {
            if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' || text[i] == ' ' || text[i] == '-' || text[i] == ',' || text[i] == '.')
                line_rem += text[i];


            if (text[i] == '.')
            {
                std::cout << line_rem << std::endl;
                line_rem = "";
                flag = 0;
            }
        }
            
    }
    std::cout << "\n";
    gin.close();
}
