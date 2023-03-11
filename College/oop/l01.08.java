import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Digite quantidade do sexo masculino: ");
        int qtdMasc = scan.nextInt();

        System.out.print("Digite quantidade do sexo feminino: ");
        int qtdFem = scan.nextInt();

        System.out.print("Digite quantidade de aprovados: ");
        int qtdAprov = scan.nextInt();

        int qtdTotal = qtdMasc + qtdFem;

        double pctMasc = ((double) qtdMasc / qtdTotal) * 100;
        double pctFem = ((double) qtdFem / qtdTotal) * 100;
        double pctAprov = ((double) qtdAprov / qtdTotal) * 100;

        System.out.println("Total de alunos: " + qtdTotal);
        System.out.println("% de alunos masculino: " + pctMasc + "%");
        System.out.println("% de alunos feminino: " + pctFem + "%");
        System.out.println("% de alunos aprovados: " + pctAprov + "%");
        lose();
    }
}
