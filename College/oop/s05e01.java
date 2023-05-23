public class App {
    public static class Calculadora {
        public static double somar(double num1, double num2) {
            return num1 + num2;
        }
    }

    public static void main(String[] args) throws Exception {

        class Circulo {
            private double raio;

            public Circulo(double raio) {
                if (raio <= 0) {
                    throw new IllegalArgumentException("Raio deve ser maior que zero");
                }
                this.raio = raio;
            }

            public double calcularArea() {
                return Math.PI * Math.pow(this.raio, 2);
            }

            public double calcularPerimetro() {
                return 2 * Math.PI * this.raio;
            }

            public double getRaio() {
                return this.raio;
            }

            public void setRaio(double raio) {
                if (raio <= 0) {
                    throw new IllegalArgumentException("Raio deve ser maior que zero");
                }
                this.raio = raio;
            }
        }

        class Livro {
            private String titulo;
            private String autor;
            private int anoPublicacao;

            public Livro(String titulo, String autor, int anoPublicacao) {
                this.titulo = titulo;
                this.autor = autor;
                this.anoPublicacao = anoPublicacao;
            }

            public Livro(String titulo, String autor) {
                this(titulo, autor, 0);
            }

            public Livro(String titulo) {
                this(titulo, "Desconhecido", 0);
            }

            public String getTitulo() {
                return titulo;
            }

            public void setTitulo(String titulo) {
                this.titulo = titulo;
            }

            public String getAutor() {
                return autor;
            }

            public void setAutor(String autor) {
                this.autor = autor;
            }

            public int getAnoPublicacao() {
                return anoPublicacao;
            }

            public void setAnoPublicacao(int anoPublicacao) {
                this.anoPublicacao = anoPublicacao;
            }
        }

        interface Transporte {
            void mover();
        }

        abstract class Veiculo implements Transporte {
            private String marca;

            public Veiculo(String marca) {
                this.marca = marca;
            }

            public String getMarca() {
                return this.marca;
            }

            public void setMarca(String marca) {
                this.marca = marca;
            }
        }

        class Carro extends Veiculo {
            public Carro(String marca) {
                super(marca);
            }

            @Override
            public void mover() {
                System.out.println("O carro está movendo-se para frente");
            }
        }

        class Moto extends Veiculo {
            public Moto(String marca) {
                super(marca);
            }

            @Override
            public void mover() {
                System.out.println("A moto está movendo-se para frente");
            }
        }

        class Bicicleta extends Veiculo {
            public Bicicleta(String marca) {
                super(marca);
            }

            @Override
            public void mover() {
                System.out.println("A bicicleta está movendo-se para frente");
            }
        }

        Carro carro = new Carro("Ferrari");
        carro.mover();

        Moto moto = new Moto("Harley");
        moto.mover();

        Bicicleta bicicleta = new Bicicleta("Trek");
        bicicleta.mover();
        Livro livro1 = new Livro("1984", "George Orwell", 1949);
        System.out.println("Título: " + livro1.getTitulo() + ", Autor: " + livro1.getAutor() + ", Ano de Publicação: "
                + livro1.getAnoPublicacao());

        System.out.println("Resultado da soma: " + Calculadora.somar(5, 7));

        Circulo circulo1 = new Circulo(15);
        System.out.println("Área do círculo1: " + circulo1.calcularArea());
        System.out.println("Perímetro do círculo1: " + circulo1.calcularPerimetro());
    }
}
