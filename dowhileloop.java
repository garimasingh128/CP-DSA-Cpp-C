import java.util.* ;
class dowhileloop {
    public static void main (String args []){
 Scanner sc = new Scanner (System.in);

 int sum = 0;
 int i = 1;

        System.out.println("Enter a number");
        int num =  sc.nextInt();

        do {
            if (num % i == 0)
            sum += i;
          i++;
        }
        while (i <= num/2);


        if (sum == num)
                      System.out.println("This number is perfect");
                      else 
                              System.out.println("this number is not perfect");



    }
}