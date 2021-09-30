public class IntEqualityPrinter {
    public static void printEqual(int a, int b, int c){
        if(a &lt; 0 || b &lt; 0 || c &lt; 0){ System.out.printf("Invalid Value\n");}
        else if(a == b &amp;&amp; b == c){ System.out.printf("All numbers are equal\n");}
        else if(a != b &amp;&amp; a != c &amp;&amp; b != c){ System.out.printf("All numbers are different\n");}
        else{System.out.printf("Neither all are equal or different\n");}
    }
}
