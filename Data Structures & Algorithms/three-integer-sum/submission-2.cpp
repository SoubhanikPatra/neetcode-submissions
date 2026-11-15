// sort the array
// take each element and check for pairs greater than the current element
// skip over duplicates for both current element and pair of elements
// similar to sorted 2sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // N(logN)
        std::vector<std::vector<int>> result;
        for(int i=0; i<nums.size(); i++){
            int left = i+1;
            int right = nums.size()-1;
            if(i>0 && nums[i-1]==nums[i]){continue;} // handle duplicates for current element
            while(left < right){
                // store the sum at every step
                int sum = nums[i]+nums[left]+nums[right];
                // check 3 sum condition
                if(sum==0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    // handle duplicates for pair of elements - skip all consecutive duplicates
                    while(left<right && nums[left]==nums[left+1]){left++;}
                    while(left<right && nums[right]==nums[right-1]){right--;}
                    left++;
                    right--;
                }
                else if(sum>0){right--;}
                else if(sum<0){left++;}
            }
        }
        return result;
    }
};
