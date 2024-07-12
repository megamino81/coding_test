import java.util.HashSet;

// HashSet
//  중복제거
//  sorting
class Solution {
  public int solution(int[] nums) {
    HashSet<Integer> hs = new HashSet<>();

    for (int i=0; i<nums.length; i++) {
      hs.add(nums[i]);
    }

    System.out.println(hs);

    if (hs.size() > nums.length/2)
      return nums.length/2;
  }
  return hs.size();
}

