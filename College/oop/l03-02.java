import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    class Forma {
      private float ladoX;
      private float ladoY;
      private float ladoZ;

      public Forma(float ladoX, float ladoY, float ladoZ) {
        this.ladoX = ladoX;
        this.ladoY = ladoY;
        this.ladoZ = ladoZ;
      }

      public String verificaForma() {
        if (ladoX + ladoY > ladoZ && ladoX + ladoZ > ladoY && ladoY + ladoZ > ladoX) {
          if (ladoX == ladoY && ladoY == ladoZ) {
            return "Triângulo Equilátero";
          } else if (ladoX == ladoY || ladoX == ladoZ || ladoY == ladoZ) {
            return "Triângulo Isósceles";
          } else {
            return "Triângulo Escaleno";
          }
        } else {
          return "Os lados não formam um triângulo";
        }
      }
    }
    Scanner scanner = new Scanner(System.in);

    System.out.println("Digite o valor do lado X: ");
    float ladoX = scanner.nextFloat();

    System.out.println("Digite o valor do lado Y: ");
    float ladoY = scanner.nextFloat();

    System.out.println("Digite o valor do lado Z: ");
    float ladoZ = scanner.nextFloat();

    Forma forma = new Forma(ladoX, ladoY, ladoZ);

    String resultado = forma.verificaForma();
    System.out.println(resultado);

    scanner.close();
  }
}
