package com.company;

public class FirstLastDigitSUm {
    public static int sumFirstAndLastDigit(int number){
        if(number < 0){ return -1;}
        if(number >= 0 && number < 10){
            return number += number;
        }
        int  flag = 0, sum = 0,lastDigit = 0,oldNUmber = number;
        while(oldNUmber >= 10){
            if(flag == 0){ lastDigit = oldNUmber % 10;}
            oldNUmber = oldNUmber / 10;
           // lastDigit  = oldNUmber;
            flag++;
        }
        return  sum += oldNUmber + lastDigit;
    }
}

