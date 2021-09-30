public class EvenDigitSum {
    public static int getEvenDigitSum(int number){
        if(number &lt; 0){ return -1;}
        int newNumber = number, digit = 0, sum = 0;
        while(newNumber &gt; 9){
            digit = newNumber % 10;
            newNumber /= 10;
            if(digit % 2 == 0){ sum += digit;}
        }
        if(newNumber % 2 == 0){ sum += newNumber;}
        return sum;
    }
}
