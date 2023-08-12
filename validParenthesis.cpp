#include<iostream>
#include<stack>
#include<map>
using namespace std;

/*
()
{[()]}
()[]
(]{}[)
*/

bool isValid(string s){

    map<char, char> map;
    map['{'] = '}';
    map['['] = ']';
    map['('] = ')';

    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        } else if(map[st.top()] == s[i]){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main() {

    string str;
    cin >> str;

    bool valid = isValid(str);
    cout << valid << endl;

    return 0;
}