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
                if (isdigit(trimmed[i]))
                {
                    parsed.push_back(trimmed[i] - '0');
                    state = 2;
                }
                else
                {
                    throw std::runtime_error("Number expected");
                }
                break;
            case 2:
                if (trimmed[i] == ',')
                {
                    state = 1;
                }
                else if (trimmed[i] == ')')
                {
                    state = 3;
                }
                break;
            case 3:
                throw std::runtime_error(") found too early");
        }
    }
    return parsed;
}