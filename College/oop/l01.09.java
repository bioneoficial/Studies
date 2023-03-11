import java.util.Scanner;

class Main {
    static double MINI_GAMES_PRICE = 6.95, CALCULATORS_PRICE = 3.50, PENS_PRICE = 1.20;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number of mini-games sold: ");
        int numMiniGames = scan.nextInt();

        System.out.print("Enter the number of calculators sold: ");
        int numCalculators = scan.nextInt();

        System.out.print("Enter the number of pens sold: ");
        int numPens = scan.nextInt();

        double miniGamesRevenue = numMiniGames * MINI_GAMES_PRICE;
        double calculatorsRevenue = numCalculators * CALCULATORS_PRICE;
        double pensRevenue = numPens * PENS_PRICE;

        double totalRevenue = miniGamesRevenue + calculatorsRevenue + pensRevenue;

        System.out.println("Mini-games revenue: $" + miniGamesRevenue);
        System.out.println("Calculators revenue: $" + calculatorsRevenue);
        System.out.println("Pens revenue: $" + pensRevenue);
        System.out.println("Total revenue: $" + totalRevenue);

        scan.close();
    }
}
