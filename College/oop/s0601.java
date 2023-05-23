public class App {

    public static class Retangulo {
        private double largura;
        private double altura;

        public Retangulo(double largura, double altura) {
            this.largura = largura;
            this.altura = altura;
        }

        public double calcularArea() {
            return this.largura * this.altura;
        }

        public double calcularPerimetro() {
            return 2 * (this.largura + this.altura);
        }
    }

    public static class ContaBancaria {
        private int numeroConta;
        private double saldo;
        private String titular;

        public ContaBancaria(int numeroConta, String titular) {
            this.numeroConta = numeroConta;
            this.titular = titular;
        }

        public void depositar(double valor) {
            this.saldo += valor;
        }

        public void sacar(double valor) {
            if (valor > this.saldo) {
                throw new IllegalArgumentException("Saldo insuficiente!");
            }
            this.saldo -= valor;
        }

        public double consultarSaldo() {
            return this.saldo;
        }
    }

    public static class Aluno {
        private String nome;
        private int matricula;
        private String curso;

        public Aluno(String nome, int matricula, String curso) {
            this.nome = nome;
            this.matricula = matricula;
            this.curso = curso;
        }

        public Aluno(String nome, int matricula) {
            this(nome, matricula, "");
        }

        public Aluno(String nome) {
            this(nome, 0, "");
        }
    }

    public static class CalculadoraEstatistica {
        public static double media(int[] numeros) {
            double soma = 0;
            for (int numero : numeros) {
                soma += numero;
            }
            return soma / numeros.length;
        }

        public static int maximo(int[] numeros) {
            int maximo = Integer.MIN_VALUE;
            for (int numero : numeros) {
                if (numero > maximo) {
                    maximo = numero;
                }
            }
            return maximo;
        }

        public static int minimo(int[] numeros) {
            int minimo = Integer.MAX_VALUE;
            for (int numero : numeros) {
                if (numero < minimo) {
                    minimo = numero;
                }
            }
            return minimo;
        }
    }

    interface Animal {
        void emitirSom();
    }

    abstract static class Mamifero implements Animal {
        private String nome;

        public Mamifero(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }
    }

    static class Cachorro extends Mamifero {
        public Cachorro(String nome) {
            super(nome);
        }

        @Override
        public void emitirSom() {
            System.out.println("Oomph!");
        }
    }

    static class Gato extends Mamifero {
        public Gato(String nome) {
            super(nome);
        }

        @Override
        public void emitirSom() {
            System.out.println("Meow!");
        }
    }

    static class Passaro implements Animal {
        private String nome;

        public Passaro(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        @Override
        public void emitirSom() {
            System.out.println("Piu!");
        }
    }

    public static void main(String[] args) {

        Retangulo retangulo = new Retangulo(5, 6);
        System.out.println("Área do retângulo: " + retangulo.calcularArea());
        System.out.println("Perímetro do retângulo: " + retangulo.calcularPerimetro());

        ContaBancaria conta = new ContaBancaria(1234, "João");
        conta.depositar(500);
        System.out.println("Saldo: " + conta.consultarSaldo());
        conta.sacar(200);
        System.out.println("Saldo após saque: " + conta.consultarSaldo());

        Aluno aluno1 = new Aluno("Joao", 5678, "Ciências da Computação");
        Aluno aluno2 = new Aluno("Bione", 1234);

        int[] numeros = { 5, 10, 15, 20 };
        System.out.println("Média: " + CalculadoraEstatistica.media(numeros));
        System.out.println("Máximo: " + CalculadoraEstatistica.maximo(numeros));
        System.out.println("Mínimo: " + CalculadoraEstatistica.minimo(numeros));

        Cachorro cachorro = new Cachorro("Welton");
        Gato gato = new Gato("Nathan");
        Passaro passaro = new Passaro("Matheus");
        cachorro.emitirSom();
        gato.emitirSom();
        passaro.emitirSom();
    }
}
