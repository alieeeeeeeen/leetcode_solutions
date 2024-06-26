class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0; // note that 0 is not positive
        bucketSort(nums);
        for(; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }
private:
    void bucketSort(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] > 0 && nums[i] < nums.size() && 
            nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                // note that we use the built-int swap, 
                // if you want to write the swap function in other language
                // you need to initialize the tmp, and use the tmp as the index
            }
            i++;
        }
    }
};