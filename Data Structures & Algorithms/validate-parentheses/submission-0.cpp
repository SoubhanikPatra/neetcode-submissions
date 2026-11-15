class Solution {
public:
    bool isValid(string s) {
        // handle odd length string
        if(s.size()%2 != 0) {return false;}
        std::stack<char> st;
        for(char c: s){
            // add opening parenthesis to stack
            if(c=='(' || c=='{' || c=='[') { st.push(c);}
            // process the matching parenthesis
            else{
                // handle empty stack
                if(st.empty()){return false;}
                // handle parenthesis mismatch
                if((c==')' && st.top()!='(') ||
                   (c=='}' && st.top()!='{') ||
                   (c==']' && st.top()!='[')) {return false;}
                // when matching parenthesis found
                st.pop();
            }
        }
        // valid only when all opening parenthesis are closed
        return st.empty();
    }
};
