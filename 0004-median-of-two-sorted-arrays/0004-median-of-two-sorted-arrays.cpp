class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // bf
        // merging both and finding median;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merged(n1+n2);
        int i=0;
        int j=0;
        int idx = 0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                merged[idx++] = nums1[i++];
            }else{
                merged[idx++] = nums2[j++];
            }
        }
        while(i<n1) merged[idx++] = nums1[i++];
        while(j<n2) merged[idx++] = nums2[j++];

        int n = n1+n2;
        if(n%2!=0) return merged[n/2];
        else return (double)(merged[n/2]+merged[n/2-1])/2; 
    }
};