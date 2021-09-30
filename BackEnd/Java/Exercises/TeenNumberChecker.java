public class TeenNumberChecker {
    public static boolean hasTeen(int a,int b,int c){
        return (a &gt;= 13 &amp;&amp; a &lt;= 19 || b &gt;= 13 &amp;&amp; b &lt;= 19 || c &gt;= 13 &amp;&amp; c &lt;= 19) ? true:false;
    }
    public static boolean isTeen(int a){
        return a &gt;= 13 &amp;&amp; a &lt;= 19 ? true:false;
    }
 
}
