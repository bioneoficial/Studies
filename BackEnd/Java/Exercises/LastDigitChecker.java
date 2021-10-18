package com.company;

public class LastDigitChecker {
    public static boolean hasSameLastDigit(int p1, int p2, int p3){
        if(isValid(p1) && isValid(p2) && isValid(p3)){
            int p1Last = p1 % 10;
            int p2Last = p2 % 10;
            int p3Last = p3 % 10;
            return   p1Last == p2Last || p1Last == p3Last || p2Last == p3Last ? true:false;
        }
        return false;
    }
    public static boolean isValid(int num){
        return  num >= 10 && num <= 1000 ? true: false;
    }

