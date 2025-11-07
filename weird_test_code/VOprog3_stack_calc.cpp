/* Victor Omenya
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 *
 * Main program to test Stack Calculator functions
 */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

#include "Stack.h"
#include "Node.h"

string postfix(string in) {
    Stack <char> arithOp;
    string postfixForm;
    char temp;
    int strlen = in.length();

    for (int i = 0; i < strlen; i++) {
        temp = (in.at(i));

        if (isdigit(temp)) {
            postfixForm += in.at(i);

        }

        else if (!isdigit(temp)) {
            if (temp == '(') {
                arithOp.push(temp);
            }

            else if ((temp == '*') || (temp == '/')) {
                if (arithOp.empty()) {
                    arithOp.push(temp);
                    // cout << arithOp.getTop();
                }
                else if ((arithOp.getTop() == '*') || (arithOp.getTop() == '/')) {
                    postfixForm += arithOp.getTop();
                    //postfixForm += ' ';
                    arithOp.pop();
                    arithOp.push(temp);
                    //cout << arithOp.getTop();
                }
                else if (arithOp.getTop() == '(') {
                    arithOp.push(temp);
                    //postfixForm += arithOp.getTop();
                }
                else if ((arithOp.getTop() == '+') || (arithOp.getTop() == '-')) {
                    arithOp.push(temp);
                }
            }

            else if ((temp == '+') || (temp == '-')) {
                if (arithOp.empty()) {
                    arithOp.push(temp);
                    // cout << arithOp.getTop();
                }
                else if ((arithOp.getTop() == '*') || (arithOp.getTop() == '/') || (arithOp.getTop() == '+') || (arithOp.getTop() == '-')) {
                    postfixForm += arithOp.getTop();
                    //postfixForm += ' ';
                    arithOp.pop();
                    arithOp.push(temp);
                    //cout << arithOp.getTop();
                }
                else if (arithOp.getTop() == '(') {
                    arithOp.push(temp);
                    //postfixForm += arithOp.getTop();
                }
            }

            else if (temp == ')') {
                while (arithOp.getTop() != '(') {
                    postfixForm += ' ';
                    postfixForm += arithOp.getTop();
                    postfixForm += ' ';
                    arithOp.pop();
                    //cout << arithOp.getTop();
                }
                if (arithOp.getTop() == '(') {
                    arithOp.pop();
                    //postfixForm += ' ';
                    /*if (!arithOp.empty()){
                        postfixForm += arithOp.getTop();
                     }*/
                     //cout << arithOp.getTop();
                }

            }
            else if (temp == ' ') {
                postfixForm += ' ';
            }
        }
    }
    //postfixForm += ' ';
    while (!arithOp.empty()) {
        postfixForm += ' ';
        postfixForm += arithOp.getTop();
        arithOp.pop();
    }
    return postfixForm;
}

int postfixEval(string postfixIn) {
    int result = 0;
    int currnumVal = 0;
    int numVal1 = 0;
    int numVal2 = 0;
    char inVal;
    Stack <int> postfixNum;
    int strlen2 = postfixIn.length();
    
    for (int j = 0; j < strlen2; j++) {
        inVal = postfixIn.at(j);

        if (isdigit(inVal)) {
            currnumVal = inVal - '0';// int(inVal);
            postfixNum.push(currnumVal);
            //cout << postfixNum.getTop() << endl;
             
        }

        else if (!isdigit(inVal)) {
            if (inVal == '*') {
                numVal2 = postfixNum.getTop();
                postfixNum.pop();
                numVal1 = postfixNum.getTop();
                postfixNum.pop();

                result = numVal1 * numVal2;
                postfixNum.push(result);
            }

            else if (inVal == '/') {
                numVal2 = postfixNum.getTop();
                postfixNum.pop();
                numVal1 = postfixNum.getTop();
                postfixNum.pop();

                result = numVal1 / numVal2;
                postfixNum.push(result);
            }

            else if (inVal == '+') {
                numVal2 = postfixNum.getTop();
                postfixNum.pop();
                numVal1 = postfixNum.getTop();
                postfixNum.pop();

                result = numVal1 + numVal2;
                postfixNum.push(result);
            }

            else if (inVal == '-') {
                numVal2 = postfixNum.getTop();
                postfixNum.pop();
                numVal1 = postfixNum.getTop();
                postfixNum.pop();

                result = numVal1 - numVal2;
                postfixNum.push(result);
            }
        }
    }
    postfixNum.pop();

    return result;
}

int main() {
    string input = "none";
    char firstChar;

    do {
        cout << "Enter expression (or exit to end): ";
        getline(cin, input);
        firstChar = input.at(0);

        if ((!isdigit(firstChar)) && (firstChar != '(')) {
            if ((isalpha(firstChar)) && (firstChar != 'e')) {
                cout << "Invalid expression" << endl;
            }
            else if (!isalpha(firstChar)) {
                cout << "Invalid expression" << endl;
            }
        }

        else {
            if (input == "exit") {
                cout << "Exiting program ..." << endl;

            }
            else {
                cout << "Expression: " << input << endl;
                cout << "Postfix form: " << postfix(input) << endl;
                cout << "Result: " << postfixEval(postfix(input)) << endl;
            }

        }

    } while (input != "exit");


    return 0;
}