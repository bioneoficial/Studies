package com.company;

public class NumberPalindrome {
    public static boolean isPalindrome(int number){
        int reverse = 0;
        int lastDigit;
        int oldNUmber = number;
    if(number < 10 && number > -10){
        System.out.printf("oie");
        return false;
    } if(oldNUmber > 0){
            while(oldNUmber >= 10){
                lastDigit = oldNUmber % 10;
                oldNUmber = oldNUmber / 10;
                reverse += lastDigit;
                reverse *= 10;
            }
            reverse += oldNUmber;
        }else{
            while(oldNUmber >= -10){
                lastDigit = oldNUmber % 10;
                oldNUmber = oldNUmber / 10;
                reverse -= lastDigit;
                reverse *= 10;
            }
            reverse += oldNUmber;
        }
        return reverse == number ? true:false;
    }
}
