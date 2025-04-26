#include <iostream>
#include <cctype>   
using namespace std;

char stack[20];
int top = -1;
string stackOutput = "";

void push(char val) {
    stack[++top] = val;
    stackOutput += val;
}

char pop() {
    stackOutput.erase(stackOutput.size() - 1, 1);
    char val = stack[top--];
    return val;
}

char peek() {
    return stack[top];
}

int checkLevel(char operation) {
    if (operation == '(' || operation == ')') {
        return 0;
    } else if (operation == '^') {
        return 3;
    } else if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '+' || operation == '-') {
        return 1;
    }
    return -1;
}

void convertToPostfix(string input) {
    string output = "";

    cout << "| Input | Stack | Output |" << endl;
    cout << "____________________________" << endl;

    for (int i = 0; i < input.length(); i++) {

        cout << "| " << input[i] << "     | " << stackOutput << "    | " << output << "    |" << endl;
        cout << "______________________" << endl;

        if (isdigit(input[i])) {
            output += input[i];
        }
         
        else if (input[i] == '(') {
            push(input[i]);
        }
         
        else if (input[i] == ')') {
            while (top >= 0 && peek() != '(') {
                output += pop();
            }
            pop();  
        }
 
        else {
            while (top >= 0 && checkLevel(peek()) >= checkLevel(input[i])) {
                output += pop();
            }
            push(input[i]);
        }
    }

    
    while (top >= 0) {
        output += pop();
    }

    cout << "The equivalent postfix is: " << output << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
}

int main() {
    string input = "(2+3)-5*4/5"; 
    string input2 = "(5+5)*(8-2)";
    string input3 = "5+5+3*4-7";
    string input4 = "(5+6)*2+1"; 
    string input5 = "(5+6)*(2+1)";
    

    convertToPostfix(input);
    convertToPostfix(input2);
    convertToPostfix(input3);
    convertToPostfix(input4);
    convertToPostfix(input5);

    return 0;
}