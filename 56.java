/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    private class IntervalComparator implements Comparator<Interval> {
        @Override
        public int compare(Interval a, Interval b) {
            return a.start < b.start ? -1 : a.start == b.start ? 0 : 1;
        }
    }
    
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals==null)
            return null;
        
        Collections.sort(intervals, new IntervalComparator());
        
        List<Interval> ans = new ArrayList<Interval>();
        for(Interval inter:intervals){
            if(ans.size()==0){
                ans.add(inter);
            }else{
                Interval last = ans.get(ans.size()-1);
                if(last.end < inter.start){
                    ans.add(inter);
                }else{
                    last.end=Math.max(inter.end, last.end);
                    // ans.set(ans.size()-1, last);
                }
            }
        }
        
        return ans;
    }
}