import java.util.*;
class hello {
    public static void main (String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter your first number");
        int a = sc.nextInt();
        System.out.println("enter your second number");
        int b = sc.nextInt ();
        int x;


        char c;
        System.out.println("select which operand you want you use");
        c = sc.next().charAt(0);

        switch(c) {
            case '+' :
             x = a + b;
            System.out.println("your answer is   " +x);
            break;
         case '-' :
         x = a - b;
         System.out.println("your answer is " +x);
         break;
         case '*':
         x = a * b;
    
         System.out.println("your answer is " +x);
         break;
       


           case '/':
             if (b == 0){
               System.out.println("second number input is zero so the output is undefined");
           }

           x = a / b;
           System.out.println("your answer is  " +x); 
           break ;
           
          
        }

    }
}