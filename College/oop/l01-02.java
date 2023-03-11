import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num1 = scan.nextInt();
        int num2 = scan.nextInt();
        double avg = (double) (num1 + num2) / 2;
        double diff = num1 > num2 ? (double) (num1 - num2) / 2 : (double) (num2 - num1) / 2;
        System.out.println(avg + " " + diff);
    }
}
