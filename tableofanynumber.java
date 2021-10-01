import java.util.* ;
public class tableofanynumber{
public static void main (String args []){
    Scanner sc = new Scanner (System.in);
    int num = sc.nextInt();
    System.out.println("the table of " +num  +"is : ");
    
     for (int i = 1 ; i <= 10 ; i++)
     {
         System.out.println(num +"x" +i  +"=" +(num * i) );
     }
}
}