class Solution {
    public int solution(String skill, String[] skill_trees) {       
        int count = 0;
        for(String tree : skill_trees) {
            char[] arr = tree.toCharArray();
            String removed = "";
            for (char ch : arr)
                if (skill.contains(ch + "")) removed += ch;

            if (skill.startsWith(removed)) count ++;
        }
        return count;
    }
}
    