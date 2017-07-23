/* reference : https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
 * time : O(log(min(m,n)))
 * space : O(1)
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //guarantee n >= m
        if(m > n){
            nums1.swap(nums2);
            swap(m, n);
        }
        
        int left = 0;
        int right = m;
        int i, j;
        while(left <= right){
            i = (left + right) / 2;
            j = (m + n + 1) / 2 - i;
            //i is too large
            if(i > 0 && nums1[i-1] > nums2[j])
                right = i - 1;
            //i is too small
            else if(i < m && nums2[j-1] > nums1[i])
                left = i + 1;
            // m + n odd : max(nums1[i-1], nums2[j-1]);
            // m+n even : max(nums1[i-1], nums2[j-1]) + min(nums1[i], nums2[j]) / 2;
            else{
                int max_left;
                if(i == 0) max_left = nums2[j-1];
                else if(j == 0) max_left = nums1[i-1];
                else max_left = max(nums1[i-1], nums2[j-1]);
                //cout << i << " " << j << " " << max_left << endl;
                if((m+n)%2) return max_left;
                
                int min_right;
                if(i == m)  min_right = nums2[j];
                else if(j == n) min_right = nums1[i];
                else min_right = min(nums1[i], nums2[j]);
                return (max_left + min_right) / 2.0;
            }
        }
    }
};
