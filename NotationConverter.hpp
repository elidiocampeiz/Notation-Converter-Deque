#ifndef NOTATIONCONVERTER_HPP
#define NOTATIONCONVERTER_HPP

#include "NotationConverterInterface.hpp"

class NotationConverter : public NotationConverterInterface
{
public:
    std::string postfixToInfix(std::string inStr) override;
    std::string postfixToPrefix(std::string inStr) override;
    std::string infixToPostfix(std::string inStr) override;
    std::string infixToPrefix(std::string inStr) override;
    std::string prefixToInfix(std::string inStr) override;
    std::string prefixToPostfix(std::string inStr) override;
    int is_operator(char a);                 //check if operator
    int priority(char a);                    //check priority between operators
    void replace_parentesis(std::string &a); //invert parenthesis
    bool isValid(std::string a);             //check valid string
    bool checkChar(char b);                  //check valid char
};

#endif
