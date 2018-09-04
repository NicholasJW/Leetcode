class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        
        ArrayList<Integer> list = new ArrayList();
        while(x != 0){
            // System.out.println("x is " + x);
            list.add(0, x%10);
            // System.out.println(list.get(0));
            x = x/10;
        }
        
        int length = list.size();
        while(length > 1){
            if(list.get(0) != list.get(list.size()-1)){
                return false;
            }else{
                list.remove(0);
                list.remove(list.size()-1);
            }
            length = list.size();
        }
        
        return true;
    }
}