import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String[] daysOfWeek = { "Invalid Day", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
                "Sunday" };

        System.out.println("Enter a number between 1 and 7: ");
        int num = scan.nextInt();

        String day = daysOfWeek[num];

        if (num > 7 || num < 1) {
            System.out.println(daysOfWeek[0]);
        } else {
            System.out.println(day);
        }

        scan.close();
    }
}
