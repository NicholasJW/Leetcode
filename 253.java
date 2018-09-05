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
    
    //     private class IntervalCompStart implements Comparator<Interval>{
    //         @Overwrite
    //         public int compare(Interval i1, Interval i2){
    //             return a.start < b.start ? -1 : a.start == b.start ? 0 : 1;    
    //         }    
    //     }
        
    //     private class IntervalCompEnd implements Comparator<Interval>{
    //         @Overwrite
    //         public int compare(Interval i1, Interval i2){
    //             return a.end < b.end ? -1 : a.end == b.end ? 0 : 1;
    //         }
    //     }
        
        public int minMeetingRooms(Interval[] intervals) {
            if (intervals == null || intervals.length == 0)
                return 0;
            
            Arrays.sort(intervals, new Comparator<Interval>(){
                public int compare(Interval a, Interval b){
                    return a.start - b.start;
                }
            });
            
            PriorityQueue<Interval> heap = new PriorityQueue<Interval>(intervals.length, new Comparator<Interval>(){
                public int compare(Interval a, Interval b){
                    return a.end - b.end;
                }
            });
            
            heap.offer(intervals[0]);
            for(int i=1; i < intervals.length; i++){
                Interval inter = heap.poll();
                
                if(inter.end <= intervals[i].start)
                    inter.end = intervals[i].end;
                else
                    heap.offer(intervals[i]);
                
                heap.offer(inter);
            }
            
            return heap.size();
        }
    }