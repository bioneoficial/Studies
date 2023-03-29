import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Digite o valor do lado A: ");
    float ladoA = scanner.nextFloat();

    System.out.print("Digite o valor do lado B: ");
    float ladoB = scanner.nextFloat();

    System.out.print("Digite o valor do lado C: ");
    float ladoC = scanner.nextFloat();

    Paralelepipedo paralelepipedo = new Paralelepipedo(ladoA, ladoB, ladoC);

    float diagonal = paralelepipedo.calculaDiagonal();

    System.out.printf("A diagonal do paralelepípedo é: %.2f\n", diagonal);

    scanner.close();
  }

  static class Paralelepipedo {
    private float ladoA;
    private float ladoB;
    private float ladoC;

    public Paralelepipedo(float ladoA, float ladoB, float ladoC) {
      this.ladoA = ladoA;
      this.ladoB = ladoB;
      this.ladoC = ladoC;
    }

    public float calculaDiagonal() {
      double L = Math.sqrt(Math.pow(ladoA, 2) + Math.pow(ladoB, 2));
      double diagonal = Math.sqrt(Math.pow(L, 2) + Math.pow(ladoC, 2));
      return (float) diagonal;
    }
  }
}
