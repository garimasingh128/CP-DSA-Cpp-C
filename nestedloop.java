import java.util.* ;
public class nestedloop{
    public static void main (String args []){
        Scanner sc = new Scanner (System.in);
int j , i , h;
h = sc.nextInt();

     for ( i = 1; i<= h; i++){
         for (j = 1; j<=i ; j++){
         System.out.print(j);
         }
              
              System.out.println ();
     }
    }
}