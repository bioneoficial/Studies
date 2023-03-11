import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int largest = Integer.MIN_VALUE;
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter a number: ");
            int num = scan.nextInt();
            largest = Math.max(largest, num);
        }

        System.out.println("The largest number is: " + largest);

        scan.close();
    }
}
