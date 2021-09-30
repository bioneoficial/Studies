package com.company;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    /*  public class FuncionarioClass {
          String name;
          double salarioBruto;
      } */
    static ArrayList<String> funcList = new ArrayList<String>();
    static ArrayList<Double> salarioBrutoList = new ArrayList<Double>();
    static ArrayList<Double> inssList = new ArrayList<Double>();
    static ArrayList<Double> irrfList = new ArrayList<Double>();
    static ArrayList<Double> salarioLiquidoList = new ArrayList<Double>();
    static ArrayList<String> nameList = new ArrayList<String>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Scanner scanName = new Scanner(System.in);
        while (true) {
            System.out.println("Insira o número:\n 1 - Cadastrar funcionário;\n 2 - para imprimir contracheque;\n 3- Encerrar Programa");
            byte OpFromMenu = scan.nextByte();
            if (OpFromMenu == 1) {
                System.out.println("Insira nome:");
                String nomeCad = scanName.nextLine();
                System.out.println("Insira Salario Bruto:");
                double salarioBrutoCad = scan.nextDouble();
                cadastro(nomeCad, salarioBrutoCad);
            } else if (OpFromMenu == 2) {
                imprimir();
            } else if (OpFromMenu == 3) {
                System.out.println("Programa encerrado.");
                break;
            } else {
                System.out.println("opção invalida, tente novamente");
            }
        }
    }

    public static void cadastro(String nomeCad, double salarioBrutoCad) {
        nameList.add(nomeCad);
        salarioBrutoList.add(salarioBrutoCad);
        funcList.add("Funcionario " + nomeCad + ", SalarioBruto: " + salarioBrutoCad + ", foi adicionado com sucesso!");
        inssList.add(0d);
        irrfList.add(0d);
        salarioLiquidoList.add(0d);
    }

    public static void imprimir() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Insira o index do funcionario:");
        short index = scan.nextShort();
        System.out.println((nameList.get(index)) + "  NOME");
        System.out.println(salarioBrutoList.get(index) + "  BRUUUTO");
        irrfCalc(index, inssCalc(index));
        System.out.println((inssList.get(index)) + "  INSSS");
        System.out.println(irrfList.get(index) + "  IRRF");
        System.out.println(salarioLiquidoList.get(index) + "  LIQ");
    }

    public static double inssCalc(short index) {
        double salarioBruto = salarioBrutoList.get(index), inssDesc;
        if (salarioBruto <= 1100) { //OK
            inssDesc = salarioBruto * (7.5 / (double) 100);
        } else if (salarioBruto <= 2203.48) { //OK
            inssDesc = (salarioBruto - 1100.01) * (9 / (double) 100);
            inssDesc += 82.50;
        } else if (salarioBruto <= 3305.22) { //ok
            inssDesc = (salarioBruto - 2203.49) * (12 / (double) 100);
            inssDesc += 82.50 + 99.31;
        } else if (salarioBruto <= 6433.57) { //ok
            inssDesc = (salarioBruto - 3305.23) * (14 / (double) 100);
            inssDesc +=  82.50 + 99.31 + 132.21;
        } else {
            inssDesc = 751.99;
        }
        inssList.set(index, inssDesc);
        return inssDesc;
    }

    public static double irrfCalc(short index, double DescInss) { //2750 44.58
        double salarioBrutoDescInss = salarioBrutoList.get(index) - DescInss, irrfDesc = 0.0, salarioLiquido = 0.0;
        if (salarioBrutoDescInss <= 1903.38) {
            irrfList.set(index, irrfDesc);
            salarioLiquidoList.set(index, salarioBrutoDescInss - irrfDesc);
            irrfDesc =0d;
        } else if (salarioBrutoDescInss <= 2826.65) {
            irrfDesc = salarioBrutoDescInss * (7.5 / (double) 100) - 142.80;//
        } else if (salarioBrutoDescInss <= 3751.05) {
            irrfDesc = salarioBrutoDescInss * (15 / (double) 100) - 354.80;//
        } else if (salarioBrutoDescInss <= 4664.68) { // entra aqui
            irrfDesc = salarioBrutoDescInss * (22.5 / (double) 100) - 636.13;//
        } else {
            irrfDesc = salarioBrutoDescInss * (27.5 / (double) 100) - 869.36; //
        }
        irrfList.set(index, irrfDesc);
        salarioLiquidoList.set(index, salarioBrutoDescInss - irrfDesc);
        return irrfDesc;
   }
}