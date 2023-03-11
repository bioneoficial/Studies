import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String result;
        int num = scan.nextInt();

        if (num > 0) {
            result = "Positive";
        } else if (num < 0) {
            result = "Negative";
        } else {
            result = "Zero";
        }
        System.out.println(result);
        scan.close();
    }
}
