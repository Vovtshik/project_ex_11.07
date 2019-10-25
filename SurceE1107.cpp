#include "../std_lib_facilities.h"

string Punctuation_for_spaces(const string& str);  // The function replaces punctuation marks (.,;? - ') 
                                                   // with spaces (does not change characters between pairs
                                                   // of double quotes (")).

int main()
{
    string str = " - don't use the \"as-if\" rule.";
    cout << str << '\n';
    cout << Punctuation_for_spaces(str) << '\n';
    return 0;
}

string Punctuation_for_spaces(const string& str)
{
 string temp;
    bool flag = false;
    stringstream ss(str);
    for(char ch; ss.get(ch);)
    {
        if(ch == '"')
        {
            flag = flag?false : true;
            temp = temp + '"';
        }
        else if(flag)
            temp = temp + ch;
        else if(!flag)
        {
            if(ch == '.' || ch == ';' || ch == ',' || ch == '?' || ch == '-' || ch == (char)39)
                temp = temp + ' ';
            else
                temp = temp + ch;
        }  
    }
    return temp;
}