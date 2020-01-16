//

//the Pourpose of this program is to define the methods to the NotationConverter class declared in MyDeque.hpp

#include "NotationConverter.hpp"
#include "MyDeque.hpp"
#include <algorithm>

using namespace std;
//postToIn
string NotationConverter::postfixToInfix(string inStr)
{
    if (!isValid(inStr)) //check if input is valid
    {
        throw out_of_range("invalid expression");
    }
    //use predefined functions
    //postToIn = PreToIn(PostToPre)
    return prefixToInfix(postfixToPrefix(inStr));
}
//postToPre
string NotationConverter::postfixToPrefix(string inStr)
{

    if (!isValid(inStr)) //check if input is valid
    {
        throw out_of_range("invalid expression");
    }
    MyDeque stack;

    string out;
    //iterate
    for (auto a = inStr.begin(); a != inStr.end(); ++a)
    {
        //If the symbol is an operand, then push it onto the Stack
        if (is_operator(*a))
        {
            //first pop two operands
            string b = stack.top();
            stack.pop();
            string c = stack.top();
            stack.pop();
            string out = string(1, *a) + " " + c + " " + b; //operator + operand + operand
            stack.push(out);
        }
        //else, its an operand, just add to stack
        else if (*a != ' ')
        {

            stack.push(string(1, *a));
        }
    }
    return stack.top();
}
//inToPos
string NotationConverter::infixToPostfix(string inStr)
{

    //) Get Postfix
    if (!isValid(inStr))
    {
        throw out_of_range("invalid expression");
    }
    MyDeque stack;
    string out;
    //iterate through
    for (char a : inStr)
    {
        //if '(' push into stack
        if (a == '(')
        {
            stack.push(string(1, a));
        }
        else if (a == ')')
        {
            //look for the last '('
            while (!stack.isEmpty() && stack.top() != "(")
            {

                out += stack.top(); //add everyting to the out string

                stack.pop(); //pop it from stack
            }
            stack.pop(); //remove the initial '('
        }
        //if its an operator '*' '/' '+' '-'
        else if (is_operator(a))
        {
            //while the operand has lower priority than the character at top of stack (operator have value 0)
            while (priority(a) <= priority(stack.top().at(0)))
            {

                out += stack.top(); //add it to out string

                stack.pop(); // pop it from stack
            }
            //then, push the current operand into the stack
            stack.push(" ");
            stack.push(string(1, a));
        }
        //if its an operand just add it to the string followed by a white space
        else if (a != ' ')
        {
            out += (string(1, a) + ' ');
        }
    }
    return out; // return expression
}
//InToPre
string NotationConverter::infixToPrefix(string inStr)
{
    //0) Check for valid input
    //1) Reverse the String
    //2) Replace all '(' with ')' and vice versa
    //3) Get Postfix expresion
    //4) Reverse the previously obtained Postfix
    if (!isValid(inStr))
    {
        throw out_of_range("invalid expression");
    }
    string out(inStr);
    reverse(out.begin(), out.end());
    replace_parentesis(out); //take care of the inversed parenthesis

    string a = infixToPostfix(out);
    reverse(a.begin(), a.end());
    return a;
}
string NotationConverter::prefixToInfix(string inStr)
{
    //check for valid input
    if (!isValid(inStr))
    {
        throw out_of_range("invalid expression");
    }
    // reverse the string
    string str(inStr);
    reverse(str.begin(), str.end());
    MyDeque stack;
    //iterate through the string
    for (int i = 0; i < str.size(); i++)
    {

        if (is_operator(str[i]))
        {
            //pop last 2 expresions and add the operator between them and parenthesis
            string b = stack.top();
            stack.pop();
            string c = stack.top();
            stack.pop();
            //format the expressions according to assignment's requirements
            string out = "(" + b + " " + str[i] + " " + c + ")";
            stack.push(out);
        }
        else if (str[i] != ' ') // if its not white space then its an operand
        {
            //push into the cumulated string

            stack.push(string(1, str[i]));
        }
    }
    return stack.top();
}
string NotationConverter::prefixToPostfix(string inStr)
{

    if (!isValid(inStr)) //check input
    {
        throw out_of_range("invalid expression");
    }
    //use pre defined functions to implement prefix to postfix
    //preToPost = PreToIn -> InToPost
    return infixToPostfix(prefixToInfix(inStr));
}
//return whether the given char is an operand or not
int NotationConverter::is_operator(char a)
{
    //use a switch statement to figure out the return value
    switch (a)
    {
    case '-':
    case '+':
    case '*':
    case '/':
        return 1;
    default:
        return 0;
    }
}
//function to get a priority of the operators
int NotationConverter::priority(char a)
{
    switch (a)
    {
    case '+': //1
    case '-': //1
        return 1;
        break;
    case '*': //2
    case '/': //2
        return 2;
        break;

    default: //0
        return 0;
        break;
    }
}
//function to convert all '(' with ')' and vise versa
void NotationConverter::replace_parentesis(string &a)
{
    for (char &i : a) //use a reference to change the string
    {
        if (i == '(')
        {
            i = ')';
        }
        else if (i == ')')
        {
            i = '(';
        }
    }
}
//input validation functions
bool NotationConverter::isValid(string a) //iterate through the string usign the check char function
{
    for (auto b : a)
    {
        if (!checkChar(b))
            return false; //if not valid return false
    }
    return true; //else is valid, return true
}
bool NotationConverter::checkChar(char b) //check if given character is valid
{
    //if char is valid return true
    if ((b <= 'z' && b >= 'a') || (b <= 'Z' && b >= 'A') || b == '+' || b == '-' || b == '*' || b == '/' || b == '(' || b == ')' || b == ' ')
        return true;
    //else return false
    else
        return false;
}