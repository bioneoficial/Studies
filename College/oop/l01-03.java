import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double nota1, nota2, nota3, avg;

        System.out.println("primeira nota: ");
        nota1 = scan.nextDouble();
        System.out.println("segunda nota:");
        nota2 = scan.nextDouble();
        System.out.println("terceira nota:");
        nota3 = scan.nextDouble();

        avg = (nota1 + nota2 + nota3) / 3;

        System.out.println("media %.2f", avg);
        scan.close();
    }
}
