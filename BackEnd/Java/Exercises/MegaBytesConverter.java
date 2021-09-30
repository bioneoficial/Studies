package com.company;

public class MegaBytesConverter {
    public static void printMegaBytesAndKiloBytes(int kiloBytes){
        short megaBytes = (short) (kiloBytes / 1024);
        short remainingKiloBytes = (short) (kiloBytes % 1024);
        if(kiloBytes < 0){
            System.out.println("Invalid Value");
        }else{
            System.out.println(kiloBytes + " KB = " + megaBytes + " MB and " + remainingKiloBytes + " KB");
        }
    }
}
