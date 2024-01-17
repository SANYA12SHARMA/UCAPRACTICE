package Array;
public class nextPermutation {
    public void rev(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return;
    }

    public void nextPermutation(int[] nums) {
        int idx = -1;
        int len = nums.length;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            rev(nums, 0, len - 1);
            return;
        }
        for (int i = len - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
                break;
            }
        }
        rev(nums, idx + 1, len - 1);
    }
}
