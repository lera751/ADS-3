#include <iostream>
#include "tstack.h"
#include <string>
using namespace std;

std::string infx2pstfx(std::string inf)
int prior(char ck)
{
    switch (ck)
    {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default: return -1;
    }
}

string infx2pstfx(string inf)
{
    TStack<char> stack1;
    string tmp = "";
    for (int i = 0; i < inf.size(); i++)
    {
        char ck = inf[i];
        int k = prior(ck);

        if (k == -1)
            tmp.append(string(1, ck));
        else
            if (stack1.isEmpty() || k == 0 || k > prior(stack1.get()))
                stack1.push(ck);
            else
            {
                if (ck == ')')
                    while (true)
                    {
                        char sym = stack1.get();
                        stack1.pop();
                        if (sym != '(')
                            tmp.append(string(1, sym));
                        else
                            break;
                    }
                else
                {
                    while (!stack1.isEmpty())
                    {
                        char lastStackEl = stack1.get();
                        stack1.pop();
                        if (prior(lastStackEl) >= k)
                            tmp.append(string(1, lastStackEl));
                    }
                    stack1.push(ck);
                }
            }
    }
    while (!stack1.isEmpty())
    {
        char lastStackEl = stack1.get();
        stack1.pop();
        tmp.append(string(1, lastStackEl));
    }
    return tmp;
}

int excute_calc(int k1, int k2, char pst)
{
    switch (pst)
    {
    case '+': return k1 + k2;
    case '-': return k1 - k2;
    case '*': return k1 * k2;
    case '/': return k1 / k2;
    default: return -1;
    }
}

int eval(std::string pst)
int eval(string pst)
{
    TStack<int> stack2;
    for (int i = 0; i < pst.size(); i++)
    {
        char ch = pst[i];
        int priority = prior(ch);

        if (priority == -1)
            stack2.push(ch - 48);
        else
        {
            int  k1 = stack2.get();
            stack2.pop();

            int k2 = stack2.get();
            stack2.pop();

} 
            int res = excute_calc(k2, k1, ch);
            stack2.push(res);
        }

    }
    return stack2.get();
}
