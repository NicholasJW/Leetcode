class Solution{
    public int myAtoi(String str){
        if(str == null || str.length() == 0)
            return 0;
        
        while(str.charAt(0) == ' ' ){
            str = str.substring(1);
            if(str.length() == 0)
                return 0;
        }
        
        char sign = str.charAt(0);
        int s=1;
        ArrayList<Integer> list = new ArrayList<Integer>();
        if(sign == '+'){
            s = 1;
            str = str.substring(1);
        }else if(sign == '-'){
            s = -1;
            str = str.substring(1);
        }else if(sign < 48 || sign > 57){
            return 0;
        }else{
            // System.out.println(str);
            list.add((int) sign-48);
            str = str.substring(1);
            // System.out.println(str);
        }
        
        while((str.length()!=0) && str.charAt(0)<58 && str.charAt(0)>47){
            list.add((int) str.charAt(0)-48);
            str = str.substring(1);
        }
        
        // System.out.println(list.size());
        
        // BigInteger ans = new BigInteger(0);
        long ans = 0;
        while(!list.isEmpty()){
            ans += list.get(0) * Math.pow(10, list.size()-1);
            // if(ans > INT_MAX)
                // if(s == 1)
                    // return INT_MAX;
                // else
                    // return INT_MIN;
            // System.out.println(ans);
            list.remove(0);
        }
        ans *= s;
        if(ans >= Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        if(ans <= Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return (int)ans;
    }
}