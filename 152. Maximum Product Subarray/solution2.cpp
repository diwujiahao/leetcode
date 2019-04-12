class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front_product = 1;
        int back_prodect = 1;
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            front_product *= nums[i];
            back_prodect *= nums[nums.size()-1-i];
            result = max(result, max(front_product, back_prodect));
            front_product = (front_product == 0) ? 1 : front_product;
            back_prodect = (back_prodect == 0) ? 1 : back_prodect;
        }
        return result;
    }
};