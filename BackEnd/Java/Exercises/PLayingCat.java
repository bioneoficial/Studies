public class PlayingCat {
   public static boolean isCatPlaying(boolean summer, int temperature){
    return   summer ?  temperature &gt;= 25 &amp;&amp; temperature &lt;= 45 ? true:false: 
    temperature &gt;= 25 &amp;&amp; temperature &lt;= 35 ? true:false;
   }
}
/* public class PlayingCat {
   public static boolean isCatPlaying(boolean summer, int temperature){
       if(summer){
          return temperature &gt;= 25 &amp;&amp; temperature &lt;= 45 ? true;false;
       }
       
       return temperature &gt;= 25 &amp;&amp; temperature &lt;= 35 ? true;false;
   }
} */
