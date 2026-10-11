#include <iostream>
#define MAX 100
#include <cmath>
using namespace std;

class Stack {
    char s[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool overflow() {
        return top == MAX - 1;
    }

    bool underflow() {
        return top == -1;
    }

    void push(char x) {
        if (!overflow())
            s[++top] = x;
    }

    char pop() {
        if (!underflow())
            return s[top--];
        return -1;
    }

    char peek() {
        if (!underflow())
            return s[top];
        return -1;
    }

    int precedence(char c) {
        if (c == '^' || c == '$') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << s[i];
    }

    // Infix to Postfix
    string infixToPostfix(string exp) {
        Stack st;
        string result = "";

        cout << "\nScan | Postfix | Stack\n";
        cout << "------------------------\n";

        for (int i = 0; i < exp.length(); i++) {
            char c = exp[i];

            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                result += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.underflow() && st.peek() != '(')
                    result += st.pop();
                st.pop();
            }
            else {
                while (!st.underflow() &&
                       precedence(c) <= precedence(st.peek()))
                    result += st.pop();
                st.push(c);
            }

            cout << " " << c << "   |   " << result << "     |     ";
            st.display();
            cout << endl;
        }

        while (!st.underflow())
            result += st.pop();

        cout << "Postfix Expression: " << result << endl;
        return result;
    }

    // Infix to Prefix
    void infixToPrefix(string exp) {
        string temp = "", postfix = "", prefix = "";

        for (int i = exp.length() - 1; i >= 0; i--)
            temp += exp[i];

        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '(') temp[i] = ')';
            else if (temp[i] == ')') temp[i] = '(';
        }

        Stack st;

        cout << "\nScan | Postfix | Stack\n";
        cout << "------------------------\n";

        for (int i = 0; i < temp.length(); i++) {
            char c = temp[i];

            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                postfix += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.underflow() && st.peek() != '(')
                    postfix += st.pop();
                st.pop();
            }
            else {
                while (!st.underflow() &&
                       precedence(c) <= precedence(st.peek()))
                    postfix += st.pop();
                st.push(c);
            }

            cout << " " << c << "   |   " << postfix << "     |     ";
            st.display();
            cout << endl;
        }

        while (!st.underflow())
            postfix += st.pop();

        for (int i = postfix.length() - 1; i >= 0; i--)
            prefix += postfix[i];

        cout << "Prefix Expression: " << prefix << endl;
    }

    int operate(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow(a, b);
        }
        return 0;
    }

    // Postfix Evaluation
    int evaluatePostfix(string exp) {
        int st[MAX], top = -1;

        cout << "\nScan | Stack\n";
        cout << "-------------\n";

        for (int i = 0; i < exp.length(); i++) {
            char c = exp[i];

            if (c >= '0' && c <= '9') {
                st[++top] = c - '0';
            }
            else {
                int b = st[top--];
                int a = st[top--];
                st[++top] = operate(a, b, c);
            }

            cout << " " << c << "   | ";
            for (int j = 0; j <= top; j++)
                cout << st[j];
            cout << endl;
        }

        cout << "Final Result: " << st[top] << endl;
        return st[top];
    }

    // Prefix Evaluation
    int evaluatePrefix(string exp) {
        int st[MAX], top = -1;

        cout << "\nScan | Stack\n";
        cout << "-------------\n";

        for (int i = exp.length() - 1; i >= 0; i--) {
            char c = exp[i];

            if (c >= '0' && c <= '9') {
                st[++top] = c - '0';
            }
            else {
                int a = st[top--];
                int b = st[top--];
                st[++top] = operate(a, b, c);
            }

            cout << " " << c << "   | ";
            for (int j = 0; j <= top; j++)
                cout << st[j];
            cout << endl;
        }

        cout << "Final Result: " << st[top] << endl;
        return st[top];
    }
};

int main() {
    Stack obj;
    string infix, postfix, prefix;
    int choice;

    do {
        cout << "\n-------- MENU --------\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix Evaluation\n";
        cout << "4. Prefix Evaluation\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                postfix = obj.infixToPostfix(infix);
                break;

            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                obj.infixToPrefix(infix);
                break;

            case 3:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                obj.evaluatePostfix(postfix);
                break;

            case 4:
                cout << "Enter prefix expression: ";
                cin >> prefix;
                obj.evaluatePrefix(prefix);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

