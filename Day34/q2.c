#include <ctype.h>

int calculate(char * s) {
    long num = 0, last = 0, res = 0;
    char op = '+';

    for(int i = 0; s[i]; i++) {
        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {
            if(op == '+') {
                res += last;
                last = num;
            }
            else if(op == '-') {
                res += last;
                last = -num;
            }
            else if(op == '*') {
                last = last * num;
            }
            else if(op == '/') {
                last = last / num;
            }

            op = s[i];
            num = 0;
        }
    }

    return res + last;
}