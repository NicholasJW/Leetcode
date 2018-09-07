class Solution {
    
    private class Pair{
        public Integer num;
        public Integer count;
        public Pair(int a, int b){num=new Integer(a);count=new Integer(b);}
    }
    
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(){};
        for(int i:nums){
            Integer I = new Integer(i);
            if(map.containsKey(I))
                map.put(I, map.get(I)+1);
            else
                map.put(I, new Integer(1));
        }
        
        PriorityQueue<Pair> set = new PriorityQueue<Pair>(new Comparator<Pair>(){
            public int compare(Pair a, Pair b){
                return b.count.intValue() - a.count.intValue();
            }
        });
        
        for(Integer key:map.keySet()){
            set.offer(new Pair(key.intValue(), map.get(key).intValue()));
        }
        
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0; i<k; i++){
            list.add(set.poll().num);
        }
        
        return list;
    }
}