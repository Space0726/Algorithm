class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int prev = 0, next = 0, size = nums.size();
            if (!size) return 0;
            while (++next < size)
                if (nums[prev] != nums[next])
                    nums[++prev] = nums[next];
            return prev + 1;
        }
};
