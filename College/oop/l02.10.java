import java.util.Scanner;

class Main {
    static final char MALE = "M";
    static final char FEMALE = "F";

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int numStudents = 30, numMales = 0, numFemales = 0;

        for (int i = 0; i < numStudents; i++) {
            System.out.print("Enter the gender of student " + (i + 1) + " (M/F): ");
            String gender = scan.next().toUpperCase();
            if (gender.equals(MALE)) {
                numMales++;
            } else if (gender.equals(FEMALE)) {
                numFemales++;
            }
        }

        double malePercentage = ((double) numMales / (double) numStudents) * 100.0;
        double femalePercentage = ((double) numFemales / (double) numStudents) * 100.0;

        System.out.println("Male percentage: " + malePercentage + "%");
        System.out.println("Female percentage: " + femalePercentage + "%");

        scan.close();
    }
}
