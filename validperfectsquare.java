public class validperfectsquare {
    public static void main(String[] args) {
        int num=16;
        boolean ans= isPerfectSquare( num);
        System.out.println(ans);
    }
    public static boolean isPerfectSquare(int num) {
        long start=0;
        long end=num;

        while(start<=end)
        {
            long mid= start+(end-start)/2;
            if(mid*mid==num)
                return true;
            else if(num>mid*mid)
                start=mid+1;
            else
                end=mid-1;
        }
        return false;
    }
}