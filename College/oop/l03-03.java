import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Digite o número da amostra: ");
    int codigoAmostra = scanner.nextInt();

    System.out.print("Digite o conteúdo de carbono: ");
    int conteudoCarbono = scanner.nextInt();

    System.out.print("Digite a dureza Rokwell: ");
    int durezaRokwell = scanner.nextInt();

    System.out.print("Digite a resistência à tração: ");
    int resistenciaTracao = scanner.nextInt();

    Amostra amostra = new Amostra(codigoAmostra, conteudoCarbono, durezaRokwell, resistenciaTracao);
    int grau = amostra.informaGrau();

    System.out.printf("A amostra %d possui grau %d.\n", codigoAmostra, grau);

    scanner.close();
  }

  static class Amostra {
    private int codigoAmostra;
    private int conteudoCarbono;
    private int durezaRokwell;
    private int resistenciaTracao;

    public Amostra(int codigoAmostra, int conteudoCarbono, int durezaRokwell, int resistenciaTracao) {
      this.codigoAmostra = codigoAmostra;
      this.conteudoCarbono = conteudoCarbono;
      this.durezaRokwell = durezaRokwell;
      this.resistenciaTracao = resistenciaTracao;
    }

    public int informaGrau() {
      boolean teste1 = conteudoCarbono < 7;
      boolean teste2 = durezaRokwell > 50;
      boolean teste3 = resistenciaTracao > 80000;

      if (teste1 && teste2 && teste3) {
        return 10;
      } else if (teste1 && teste2) {
        return 9;
      } else if (teste1) {
        return 8;
      } else {
        return 7;
      }
    }
  }
}