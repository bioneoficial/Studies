import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("KM inicial:");
        double kmInicial = scan.nextDouble();

        System.out.println("KM final:");
        double kmFinal = scan.nextDouble();

        double kmPercorridos = kmFinal - kmInicial;

        System.out.println("kmPercorridos " + km);

        scan.close();
    }
}
