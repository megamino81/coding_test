import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections; 
public class SortArrayList {    
    public static void main(String[] args) {         
        // ArrayList 준비        
        ArrayList<String> list = new ArrayList<>(Arrays.asList("C", "A", "B", "a"));        
        System.out.println("원본 : " + list); // [C, A, B, a]         
        
        // 오름차순으로 정렬        
        Collections.sort(list);        
        System.out.println("오름차순 : " + list); // [A, B, C, a]         
        
        // 내림차순으로 정렬        
        Collections.sort(list, Collections.reverseOrder());        
        System.out.println("내림차순 : " + list); // [a, C, B, A]         
        
        // 대소문자 구분없이 오름차순        
        Collections.sort(list, String.CASE_INSENSITIVE_ORDER);        
        System.out.println("대소문자 구분없이 오름차순 : " + list); // [a, A, B, C]         
        
        // 대소문자 구분없이 내림차순        
        Collections.sort(list, Collections.reverseOrder(String.CASE_INSENSITIVE_ORDER));        
        System.out.println("대소문자 구분없이 내림차순 : " + list); // [C, B, a, A]    
    }
}

// https://hianna.tistory.com/569
