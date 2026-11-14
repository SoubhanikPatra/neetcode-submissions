class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){return false;}
        std::array<int, 26> freq{};
        for(char chS: s){
            freq[chS - 'a']++;
        }
        for(char chT: t){
            freq[chT - 'a']--;
        }
        for(int i: freq){
            if(i!=0){return false;}
        }
        return true;
    }
};
