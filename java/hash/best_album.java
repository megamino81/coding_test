import java.util.HashMap;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Map;
import java.util.Collections;

class Solution {
  public int[] solution(String[] genres, int[] plays) {
    // <장르, 곡정보>
    HashMap<String, Object> genresMap = new HashMap<>();

    //  <장르, 장르 재생수>
    HashMap<String, Integer> playMap = new HashMap<>;
    ArrayList<Integer> resultAL = new ArrayList<>();

    for (int i=0; i<genres.length; i++) {
      String key = genres[i];
      // 곡정보 : <곡 고유번호, 재생횟수>
      HashMap<Integer, Integer> infoMap;

      if(genresMap.containsKey(key)) {
        infoMap = (HashMap<Integer, Integer>)genresMap.get(key);
      } else {
        infoMap = new HashMap<>();
      }
      infoMap.put(i, plays[i]);
      genresMap.put(key, infoMap);

      // 재생수
      if (playMap.containsKey(key)) {
        playMap.put(key, playMap.get(key) + plays[i]);
      } else {
        playMap.put(key, palys[i]);
      }
    }

    int mCnt = 0;
    Iterator it = sortByValue(playMap).iterator();

    while(it.hasNex()) {
      String key = (String)it.next();
      Iterator indexIt = 
        sortByValue((HashMap<Integer, Integer>)genresMap.get(key)).iterator)();
      int playsCnt = 0;

      while(indexIt.hasNex()) {
        resultAL.add((int) indexIt.next());
        mCnt++;
        playsCnt++;
        if (playsCnt > 1) break;
      }
    }
    int[] answer = new int[resultAl.size()];
    for(int i=0; i<result.size(); i++) {
      answer[i] = resultAL.get(i).intValue();
    }
  }

  private ArrayList sortByValue(final Map map) {
    ArrayList<Object> keyList = new ArrayList();
    keyList.addAll(map.keySet());
    Collections.sort(keyList, new Comparator() {
      public int compare(Object o1, Object o2) {
        Object v1 = map.get(o1);
        Object v2 = map.get(o2);
        return ((Comparable)v2).compare(v1);
      }
    });
    return keyList;
  }
}
