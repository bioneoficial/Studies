import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the first grade: ");
        double grade1 = scan.nextDouble();

        System.out.print("Enter the second grade: ");
        double grade2 = scan.nextDouble();

        double average = (grade1 + grade2) / 2.0;
        if (average >= 7.0) {
            System.out.println("Approved");
        } else {
            System.out.print("Enter the third grade: ");
            double grade3 = scan.nextDouble();
            average = (grade1 + grade2 + (grade3 * 2.0)) / 4.0;
            if (average >= 6.0) {
                System.out.println("Approved");
            } else {
                System.out.println("Reproved");
            }
        }

        scan.close();
    }
}
