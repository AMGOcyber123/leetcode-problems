class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int i = 0, j = nums1.size();
        // bianry search boundary condition 
        while(i<=j)
        {
            // initial mid 
            int mid = (j-i)/2+i;
            // next mid to consider between the given mid of num1 and mid between num1 and num2
            int mid2 = (nums1.size()+nums2.size()+1)/2-mid;
            // checking if mid == 0
            // initialise l1
            int l1 = (mid==0)?INT_MIN:nums1[mid-1];
            // intialise l2
            int l2 = (mid2==0)?INT_MIN:nums2[mid2-1];
            //  initialise r1 and r2
            int r1 = (mid==nums1.size())?INT_MAX:nums1[mid];   
            int r2 = (mid2==nums2.size())?INT_MAX:nums2[mid2];
            // check if lvalues are smaller than or equal to the rvalues 
            if(l1<=r2 && l2<=r1)
            {
                // return the max value of the lvalues and its odd 
                if((nums1.size()+nums2.size()) & 1)
                    return (double) max(l1,l2) ;
                // return max lvalue and min rvalue 
                else 
                    return ((double(max(l1,l2)+min(r1,r2))))/2;
            }
            // changing the boundary values acc to the conditions 
            else if(l1 > r2)
                j = mid-1;
            else
                i = mid+1;
        }
        return -1.0;
    }
};
