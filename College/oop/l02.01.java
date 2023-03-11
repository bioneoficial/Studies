import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the first integer: ");
        int num1 = scan.nextInt();

        System.out.print("Enter the second integer: ");
        int num2 = scan.nextInt();

        int larger = Integer.max(num1, num2);

        System.out.println("The larger number is: " + larger);

        scan.close();
    }
}
