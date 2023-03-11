import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double largest = Double.MIN_VALUE;
        double smallest = Double.MAX_VALUE;
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter a grade: ");
            double grade = scan.nextDouble();
            largest = Math.max(largest, grade);
            smallest = Math.min(smallest, grade);
        }

        System.out.println("The largest grade is: " + largest);
        System.out.println("The smallest grade is: " + smallest);

        scan.close();
    }
}
