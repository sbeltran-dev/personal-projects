/*
2. Escribir un programa para encontrar la secuencia de Fibonacci. La secuencia es al 
siguiente: 
 
F= 0,1,1,2,3,5,8,13,21,34,55, ......................................., n 
 
El primer elemento es 0, el segundo es 1 y cada elemento restante es la suma de los 
dos anteriores. El programa debe solicitar el número límite de la serie.
*/
import java.util.Scanner;
public class Fibonacci_Sequence {
    public static void main (String[] args) {
        int limit;
        String option = "Y";
        Scanner input = new Scanner(System.in);
        while (option.equalsIgnoreCase("Y")) {
            System.out.println("\nInput a number to establish the limit of the sequence: ");
            limit = input.nextInt();
            int element0 = 0, element1 = 1, sum = 0;
            System.out.printf("%d, %d", element0, element1);
            while (sum < limit) {
                sum = element0 + element1;
                System.out.printf(", %d", sum);
                element0 = element1;
                element1 = sum;
            }
            option = System.console().readLine("\n\nAgain? Y/N: ");
        }
        System.out.println("Thank you for using the program :)");
        input.close();
    }
}