import java.util.Scanner;

class Main {
    static int WIN_POINTS = 3, TIE_POINTS = 1, LOSS_POINTS = 0;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number of wins: ");
        int wins = scan.nextInt();

        System.out.print("Enter the number of ties: ");
        int ties = scan.nextInt();

        System.out.print("Enter the number of losses: ");
        int losses = scan.nextInt();

        int totalGames = wins + ties + losses;
        int totalPoints = totalGames * WIN_POINTS;
        int pointsWon = (wins * WIN_POINTS) + ties;
        int pointsLost = totalPoints - pointsWon;

        System.out.println("Total games played: " + totalGames);
        System.out.println("Total points at stake: " + totalPoints);
        System.out.println("Points won: " + pointsWon);
        System.out.println("Points lost: " + pointsLost);

        scan.close();
    }
}
