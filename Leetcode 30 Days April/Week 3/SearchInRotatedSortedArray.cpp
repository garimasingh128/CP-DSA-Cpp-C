class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right)/2;
            int midElement = nums[mid], curLeft = nums[left], curRight = nums[right];

            if(midElement == target)
                return mid;


            if(midElement < curLeft)
            {
                if (target <= curRight and target > midElement)
                    left = mid +1;
                else right = mid-1;
            }
            else if(midElement > curRight)
            {
                if (target >= curLeft and target < midElement)
                    right = mid -1;
                else left = mid +1;
            }
            else
            {
                if(target > midElement)
                    left = mid + 1;
                else
                    right = mid -1;
            }
        }
        return -1;

    }
};
