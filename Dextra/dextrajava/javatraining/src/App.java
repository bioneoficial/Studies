public class App {
    public static void main(String[] args) throws Exception {
        String playerName = "Joao Bione";
        int score = calculateHighScorePosition(50);
       
        
        displayHighScorePosition(playerName, score);
    }

    public static void displayHighScorePosition(String playerName, int position){

        System.out.printf("%s managed to get into position %d on the high score table",playerName,position);
    }
    public static int calculateHighScorePosition(int score){
        if( score >= 1000){
            return 1;
        }else if(score >= 500){
            return 2;
        }else if(score >= 100){
            return 3;
        }
            return 4;

    }
}
