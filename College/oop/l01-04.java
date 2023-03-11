import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double salarioBruto, desconto, salarioLiquido;
        salarioBruto = scan.nextDouble();
        desconto = salarioBruto * 0.08;
        salarioLiquido = salarioBruto - desconto;

        System.out.println("Salario bruto: R$ %.2f R$ %.2f R$ %.2f", salarioBruto, desconto, salarioLiquido);

        scan.close();
    }
}
