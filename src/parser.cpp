#include "parser.h"

std::vector<float> vector_parser(const std::string& expression)
{
    std::vector<float> parsed;
    std::string trimmed;
    for (int i=0; i<expression.length(); i++)
    {
        if (expression[i] != ' ')
        {
            trimmed += expression[i];
        }
    }
    int state = 0;
    std::string current;
    bool seen_decimal = false;
    for (int i=0; i<trimmed.length(); i++)
    {
        switch (state)
        {
            case 0:
                if (trimmed[i] == '(')
                {
                    state = 1;
                }
                else 
                {
                    throw std::runtime_error("Expected open (");
                }
                break;
            case 1:
                if (trimmed[i] == '-')
                {
                    current += trimmed[i];
                    state = 2;
                }
                else {
                    i--;
                    state = 2;
                }
                break;
            case 2:
                if (isdigit(trimmed[i]))
                {
                    current += trimmed[i];
                }
                else if (trimmed[i] == '.' && ! seen_decimal)
                {
                    current += trimmed[i];
                    seen_decimal = true;
                }
                else if (trimmed[i] == ',')
                {
                    parsed.push_back(std::stof(current));
                    current = "";
                    seen_decimal = false;
                }
                else if (trimmed[i] == ')')
                {
                    parsed.push_back(std::stof(current));
                    current = "";
                    seen_decimal = false;
                }
                else
                {
                    throw std::runtime_error("Vector Number Input Error");
                }
                break;
        }
    }
    return parsed;
}
