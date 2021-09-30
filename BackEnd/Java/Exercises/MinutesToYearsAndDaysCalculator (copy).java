public class MinutesToYearsDaysCalculator {
    public static void printYearsAndDays(long minutes){
        if(minutes &lt; 0){
            System.out.printf("Invalid Value\n");
        }else{
        long hour = minutes /60;
        long days = hour / 24;
        hour = hour % 24;
        long years = days / 365;
        days = days % 365;
        System.out.printf("%d min = %d y and %d d\n",minutes,years,days);
        }
    }
}
