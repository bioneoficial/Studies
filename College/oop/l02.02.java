import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int num = scan.nextInt();

        String result = (num % 2 == 0) ? "EVEN" : "ODD";

        System.out.println(result);
        scan.close();
    }
}
