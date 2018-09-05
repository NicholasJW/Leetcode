class Solution {
    
    public int numDecodings(String s){
        int size = s.length();
        if(size == 0)
            return 0;
        if(size == 1){
            if(s.equals("0"))
                return 0;
            else
                return 1;
        }
        
        int[] array = new int[size];
        
        if(s.charAt(0) == '0')
            return 0;
        else
            array[0] = 1;
        
        int num = ((int) s.charAt(0) - '0') * 10 + ((int) s.charAt(1) - '0');
        if(s.charAt(1) != '0'){
            if(num<=26 && num>0){
                array[1] = 2;
            }else{
                array[1] = 1;
            }
        }else{
            if(num == 10 || num == 20){
                array[1] = 1;
            }else{
                return 0;
            }
        }
        
        for(int i=2; i<size; i++){
            if(s.charAt(i-1) == '0'){
                if(s.charAt(i) == '0')
                    return 0;
                array[i] = array[i-1];
            }else if(s.charAt(i) == '0'){
                if(s.charAt(i-1) == '1' || s.charAt(i-1) == '2')
                    array[i] = array[i-2];
                else
                    return 0;
            }else if(((int) s.charAt(i-1) - '0') * 10 + ((int) s.charAt(i) - '0') < 27){
                array[i] = array[i-1] + array[i-2];
            }else{
                array[i] = array[i-1];
            }
        }
        for(int i=0; i<size; i++)
            System.out.print(array[i] + "   ");
        
        return array[size-1];
    }
}