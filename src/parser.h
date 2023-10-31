#pragma once

#include <iostream>
#include <cmath>
#include <cctype>

class Parser {
public:
    Parser(const std::string& expression, const double x) : input(expression), pos(0), input_value(x) {}

    double parse() {
        trimWhiteSpace();
        replaceInputValue();
        return parseExpression();
    }

private:
    std::string input;
    std::size_t pos;
    double input_value;

    char getNextToken() {
        if (pos < input.size()) {
            return input[pos++];
        }
        return '\0';
    }

    void trimWhiteSpace() {
        std::string trimmed;
        for (int i=0; i<input.length(); i++) {
            if (input[i] != ' ') {
                trimmed += input[i];
            }
        }
        input = trimmed;
    }

    void replaceInputValue() {
        std::string replacement;
        for (int i=0; i<input.length(); i++) {
            if (input[i] == 'x') {
                replacement += '(';
                replacement += std::to_string(input_value);
                replacement += ')';
            } else {
                replacement += input[i];
            }
        }
        input = replacement;
    }

    // I chose the easy way out
    // This returns exactly 4.44 if you input for example, 4.44.32.45
    // but it doesn't flag inputting that wrong number as an error.
    double parseNumber() {
        std::string num;
        char currentChar = getNextToken();
        while (isdigit(currentChar) || currentChar == '.') {
            num += currentChar;
            currentChar = getNextToken();
        }
        pos--;
        return stod(num);
    }

    double parseAtom() {
        char currentChar = getNextToken();
        if (isdigit(currentChar) || currentChar == '-') {
            pos--;
            return parseNumber();
        } else if (currentChar == '(') {
            double result = parseExpression();
            if (getNextToken() != ')') {
                throw std::runtime_error("Expected closing parenthesis");
            }
            return result;
        } else if (isalpha(currentChar)) {
            pos--;
            return parseFunction();
        } else {
            throw std::runtime_error("Invalid expression");
        }
    }

    double parsePower() {
        double left = parseAtom();
        char currentChar = getNextToken();
        if (currentChar == '^') {
            double right = parsePower();
            return pow(left, right);
        }
        pos--;
        return left;
    }

    double parseFactor() {
        char currentChar = getNextToken();
        if (currentChar == '-') {
            return -parsePower();
        }
        pos--;
        return parsePower();
    }

    double parseTerm() {
        double left = parseFactor();
        char currentChar = getNextToken();
        while (currentChar == '*' || currentChar == '/') {
            if (currentChar == '*') {
                left *= parseFactor();
            } else {
                double divisor = parseFactor();
                if (divisor != 0) {
                    left /= divisor;
                } else {
                    throw std::runtime_error("Division by zero");
                }
            }
            currentChar = getNextToken();
        }
        pos--;
        return left;
    }

    // assumes you don't do double negatives like 23--34
    double parseExpression() {
        double left = parseTerm();
        char currentChar = getNextToken();
        while (currentChar == '+' || currentChar == '-') {
            if (currentChar == '+') {
                left += parseTerm();
            } else {
                left -= parseTerm();
            }
            currentChar = getNextToken();
        }
        pos--;
        return left;
    }

    double parseFunction() {
        std::string funcName;
        char currentChar = getNextToken();
        while (isalpha(currentChar)) {
            funcName += currentChar;
            currentChar = getNextToken();
        }
        if (currentChar != '(') {
            throw std::runtime_error("Expected opening parenthesis after function name");
        }
        double arg = parseExpression();
        if (getNextToken() != ')') {
            throw std::runtime_error("Expected closing parenthesis after function argument");
        }

        // Handle supported functions
        // add a new function by adding an elseif (note: change to switch case later maybe)
        if (funcName == "sin") {
            return sin(arg);
        } else if (funcName == "cos") {
            return cos(arg);
        } else if (funcName == "tan") {
            return tan(arg);
        } else if (funcName == "sqrt") {
            return sqrt(arg);
        }
        else if(funcName == "ln")
        {
            return std::log(arg);
        }
        else {
            throw std::runtime_error("Unsupported function: " + funcName);
        }
    }
};