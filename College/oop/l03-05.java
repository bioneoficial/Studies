import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Digite a massa inicial em gramas: ");
    float massaInicial = scanner.nextFloat();

    Massa massa = new Massa(massaInicial);
    massa.calculaTempo();

    System.out.printf("Massa inicial: %.2f g\n", massa.getMassaInicial());
    System.out.printf("Massa final: %.2f g\n", massa.getMassaFinal());
    System.out.printf("Tempo necessário: %d segundos\n", massa.getTempo());

    scanner.close();
  }

  static class Massa {
    private float massaInicial;
    private float massaFinal;
    private int tempo;

    public Massa(float massaInicial) {
      this.massaInicial = massaInicial;
      this.massaFinal = massaInicial;
      this.tempo = 0;
    }

    public void calculaTempo() {
      while (massaFinal >= 0.5) {
        massaFinal /= 2;
        tempo += 50;
      }
    }

    public float getMassaInicial() {
      return massaInicial;
    }

    public float getMassaFinal() {
      return massaFinal;
    }

    public int getTempo() {
      return tempo;
    }
  }
}