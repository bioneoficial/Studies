package com.company;

public class DecimalComparator {
    public static boolean areEqualByThreeDecimalPlaces(double one, double two){
        one = one * 1000;
        two = two * 1000;
      int a,b;
        a = (int) one;
        b = (int)  two;
        if(a == b){
            return true;
        }
        return false;
    }
}
