import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int sum = 0;
        for (int i = 0; i < 15; i++) {
            System.out.print("Enter the age of person " + (i + 1) + ": ");
            int age = scan.nextInt();
            sum += age;
        }

        double average = (double) sum / 15.0;
        System.out.println("The average age is: " + average);

        scan.close();
    }
}
