package com.company;
import java.util.Scanner;
public class SortedArray {

   static Scanner scan = new Scanner(System.in);

    public static int[] getIntegers(int length){
        int[] values = new int[length];
        for(int i = 0; i < values.length; i++){
            values[i] = scan.nextInt();
        }
        return values;
    }
    public static int[] sortIntegers(int[] oi){
        int flag = 1,temp;
        int[] newArr = oi;
        while(flag == 1){
            flag = 0;
            for(int i = 0; i < newArr.length -1;i++){
                if(newArr[i] < newArr[i+1]){
                    temp = newArr[i];
                    newArr[i] = newArr[i +1];
                    newArr[i +1] = temp;
                    flag = 1;
                }
            }
        }
        return newArr;
    }
    public static void printArray(int[] arr){
        for(int i = 0; i < arr.length;i++){
            System.out.println("Element " + i + " contents " + arr[i]);
        }
    }
}
