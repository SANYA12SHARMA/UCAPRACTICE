import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class threeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        List<List<Integer>> list = new ArrayList<>();
        while (i < (nums.length - 2)) {
            int j = i + 1;
            int k = nums.length - 1;
            if (i != j && j != k && k != i) {
                while (j < k) {

                    if (nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> subList = new ArrayList<>();
                        subList.add(nums[i]);
                        subList.add(nums[j]);
                        subList.add(nums[k]);
                        list.add(subList);
                        while (j < k && nums[j] == nums[j + 1]) {
                            j++;
                        }
                        while (j < k && nums[k] == nums[k - 1]) {
                            k--;
                        }
                        j++;
                        k--;
                    } else if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }

                }
            }
            while (((i + 1) < nums.length) && (nums[i] == nums[i + 1])) {
                i++;
            }
            i++;
        }
        return list;
    }
}
