#include<bits/stdc++.h>
using namespace std;



    bool CheckBalanced(char *exp)
    {

        stack <int> s;     // Using Stack

        // flag variable
        int x=0;

        // scanning complete expression
        for(int i=0;exp[i]!='\0';i++)
        {

            // First Possibility: If opening bracket is found, push it in the stack
            if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
            {
                s.push(exp[i]);

            }
            // other possibility: If closing bracket is found then
            else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
            {
                    x=1;

                if(s.empty())
                {
                    // as there is no opening bracket in stack but we got closing one so expression is not balanced
                    return false;
                }

                else if(exp[i]==')'&& s.top()=='(' || exp[i]=='}'&& s.top()=='{' || exp[i]==']'&& s.top()=='[' )
                {
                    // if we get matching pairs of bracket i.e closing one matches with top of stack
                    s.pop();
                } else
                {
                    // we do not get matching pairs of bracket i.e closing one does not matches with top of stack
                    return false;
                }
            }
        }

                if(x==0)
                {
                    // no closing bracket present in expression
                    return false;
                }

                if(s.size()==0)
                {
                    // all matching pairs found and stack is empty
                    return true;
                }
                else
                {
                    // stack contains some opening bracket
                    return false;
                }



    }

    int main()
    {
        // No. of expressions we have to check
        long n;
        cin>>n;

        while(n--)
        {


            char input[100000];
          // input given expression
            cin>>input;


            if(CheckBalanced(input))
            {
                // function returns true if expression is balanced
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }


        }

        return 0;

    }
