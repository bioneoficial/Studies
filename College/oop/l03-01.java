import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    class Produto {
      private int codigo;
      private int quantidade;
      private double valorUnitario;
      private int formaPagamento;

      public Produto(int codigo, int quantidade, double valorUnitario, int formaPagamento) {
        this.codigo = codigo;
        this.quantidade = quantidade;
        this.valorUnitario = valorUnitario;
        this.formaPagamento = formaPagamento;
      }

      public double calculaDesconto() {
        double desconto;
        switch (formaPagamento) {
          case 1:
            desconto = 0.10;
            break;
          case 2:
            desconto = 0.02;
            break;
          case 3:
            desconto = 0.05;
            break;
          default:
            desconto = 0;
            break;
        }
        return desconto;
      }

      public double valorFinal() {
        double desconto = calculaDesconto();
        return (quantidade * valorUnitario) * (1 - desconto);
      }
    }

    Scanner scanner = new Scanner(System.in);

    System.out.print("Digite o código do produto: ");

    int codigo = scanner.nextInt();

    System.out.print("Digite a quantidade do produto: ");
    int quantidade = scanner.nextInt();

    System.out.print("Digite o valor unitário do produto: ");
    double valorUnitario = scanner.nextDouble();

    System.out.println("Formas de pagamento:");
    System.out.println("1 - Dinheiro");
    System.out.println("2 - Cheque");
    System.out.println("3 - Cartão débito");
    System.out.println("4 - Cartão crédito");
    System.out.print("Digite a forma de pagamento: ");
    int formaPagamento = scanner.nextInt();

    Produto produto = new Produto(codigo, quantidade, valorUnitario, formaPagamento);

    double desconto = produto.calculaDesconto() * 100;
    double valorFinal = produto.valorFinal();

    System.out.printf("Desconto aplicado: %.2f%%\n", desconto);
    System.out.printf("Valor final a pagar: %.2f\n", valorFinal);

    scanner.close();
  }
}
