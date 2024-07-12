import java.util.Arrays:

// Arrays
//  sort

class Solution {
  public boolean solution(String[] phoneBook) {
    Arrays.sort(phoneBook);
    boolean result = true;

    for (int i=0; i<phoneBook.length-1; i++) {
      if (phoneBook[i+1].startsWith(phoneBook[i+1])) {
        result = false;
        break;
      }
    }
    return result;
  }
}