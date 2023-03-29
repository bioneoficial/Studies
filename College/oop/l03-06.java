import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Digite o valor de X1: ");
    float pontoX1 = scanner.nextFloat();

    System.out.print("Digite o valor de Y1: ");
    float pontoY1 = scanner.nextFloat();

    System.out.print("Digite o valor de X2: ");
    float pontoX2 = scanner.nextFloat();

    System.out.print("Digite o valor de Y2: ");
    float pontoY2 = scanner.nextFloat();

    Ponto ponto = new Ponto(pontoX1, pontoY1, pontoX2, pontoY2);
    float distancia = ponto.calculaDistancia();

    System.out.printf("A distância entre os pontos é: %.2f\n", distancia);

    scanner.close();
  }

  static class Ponto {
    private float pontoX1;
    private float pontoY1;
    private float pontoX2;
    private float pontoY2;

    public Ponto(float pontoX1, float pontoY1, float pontoX2, float pontoY2) {
      this.pontoX1 = pontoX1;
      this.pontoY1 = pontoY1;
      this.pontoX2 = pontoX2;
      this.pontoY2 = pontoY2;
    }

    public float calculaDistancia() {
      float deltaX = pontoX2 - pontoX1;
      float deltaY = pontoY2 - pontoY1;
      return (float) Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }
  }
}