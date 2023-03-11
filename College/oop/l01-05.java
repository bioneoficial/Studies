import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a, b, c, delta;

        System.out.print("Digite o valor de A: ");
        a = scan.nextDouble();
        System.out.print("Digite o valor de B: ");
        b = scan.nextDouble();
        System.out.print("Digite o valor de C: ");
        c = scan.nextDouble();

        delta = Math.pow(b, 2) - 4 * a * c;

        System.out.printf("O valor do delta e %.2f", delta);
    }
}
