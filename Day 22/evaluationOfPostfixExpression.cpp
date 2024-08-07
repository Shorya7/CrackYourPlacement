//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>s;
        for(char c:S){
            if(isdigit(c))
            s.push(c-'0');
            else{
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                switch (c){
                    case '+':
                    s.push(x+y);
                    break;
                    case '-':
                    s.push(y-x);
                    break;
                    case '*':
                    s.push(y*x);
                    break;
                    case '/':
                    s.push(y/x);
                    break;
                }
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends