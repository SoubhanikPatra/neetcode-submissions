class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a hashmap that has sorted string as key and corresponding anagrams as values
        std::unordered_map<std::string, std::vector<string>> groups;
        for(std::string str: strs){
            // set the sorted string as the key
            std::string key = str;
            std::sort(key.begin(), key.end());
            // add str to the list if key exists otherwise create new key and add
            groups[key].push_back(str);
        }
        // create a 2D array that stores the groups of anagrams
        std::vector<std::vector<std::string>> result;
        for(auto& pair: groups){
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
