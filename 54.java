class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        if(matrix.length == 0 || matrix[0].length == 0)
            return list;
        
        int i=0, j=0;
        int m=matrix.length-1, n=matrix[0].length-1;
        int d=1, r=0;
        
        while(list.size() < (m+1)*(n+1)){
            list.add(new Integer(matrix[i][j]));
            
            switch(d){
                case 1:
                    if(j == n-r){
                        d = 2;
                        i++;
                    }else{
                        j++; 
                    }
                    break;
                case 2:
                    if(i == m-r){
                        d = 3;
                        j--;
                    }else{
                        i++;
                    }
                    break;
                case 3:
                    if(j == r){
                        d = 4;
                        i--;
                    }else{
                        j--;
                    }
                    break;
                case 4:
                    if(i == r+1){
                        d = 1;
                        j++;
                        r++;
                    }else{
                        i--;
                    }
                    break;
            }
            
            for(int p=0; p<list.size(); p++){
                System.out.print(list.get(p) + "   ");
            }
            System.out.print('\n');
        }
        
        return list;
    }
}