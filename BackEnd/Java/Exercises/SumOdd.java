public class SumOddRange {
    public static boolean isOdd(int number){
       return  number &gt; 0 &amp;&amp; number % 2 != 0 ? true:false;
    }
    public static int sumOdd(int start, int end){
        int sum = 0;
        if(end&gt;=start &amp;&amp; start &gt; 0 &amp;&amp; end &gt; 0){
        for(int i =start; i &lt;= end; i++){
            if(isOdd(i)){
                sum += i;
            }
        }
        return sum;
        }
        return -1;
    }
}
