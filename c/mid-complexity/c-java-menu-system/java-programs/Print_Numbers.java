/*
5. URlizando el ciclo While imprima en pantalla lo siguiente, solicite al usuario el 
limite: 
 
Limite: 5 
 
1 
22 
333 
4444 
55555 
*/
public class Print_Numbers {
    public static void main(String[] args) {
        String option = "Y";
        while (option.equalsIgnoreCase("Y")) {
            int number = 1;
            int limit = Integer.parseInt(System.console().readLine("\nEstablish limit: "));
            if (limit > 0) {
                while (number <= limit) {
                    int rows = 1;
                    while (rows <= number) {
                        System.out.print(number);
                        rows++;
                    }
                    System.out.println("");
                    number++;
                }
                option = System.console().readLine("\nAgain? Y/N: ");
            } else {
                System.out.println("ERROR. Only positive integers are allowed.");
            }
        }
        System.out.println("Thank you for using the program :)");
    }
}
