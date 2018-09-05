class Solution {
    public int search(int[] nums, int target) {
        int length = nums.length;
        if(length==0)
            return -1;
        int start = 0, end = length-1, mid = length/2, pivot = end;
        // int start = nums[0];
        // int end = nums[length-1];
        // int mid = nums[length/2];
        // int pivot;
        if(nums[start] > nums[end]){
            while(end - start > 1){
                if(nums[mid] > nums[start]){
                    start = mid;
                }else{
                    end = mid;
                }
                mid = (start + end)/2;
            }
            pivot = start;
        }
        // System.out.println(pivot);
        // return pivot;
        
        if(target < nums[0]){
            start = pivot; end = length-1; mid = (start+end)/2;
            while(end - start > 1){
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] < target){
                    start = mid;
                }else{
                    end = mid;
                }
                mid = (start+end)/2;
            }
            if(nums[start] == target)
                return start;
            if(nums[end] == target)
                return end;
            return -1;
        }else{
            start = 0; end = pivot; mid = (start+end)/2;
            while(end - start > 1){
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] < target){
                    start = mid;
                }else{
                    end = mid;
                }
                mid = (start+end)/2;
            }
            if(nums[start] == target)
                return start;
            if(nums[end] == target)
                return end;
            return -1;
        }
    }
}