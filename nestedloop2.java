import java.util.* ;
public class nestedloop{
    public static void main (String args []){
        Scanner sc = new Scanner (System.in);
int i , h , rows ;
System.out.println("Enter the number of rows - ");
rows = sc.nextInt ();
int num = 1;
for (i = 1 ; i<=rows ; i++){
    for (h = 1 ; h<=i ; h++){
        System.out.print( num);
        num++ ;
    }
    System.out.println();
}
     }
    }
