import java.util.* ;
public class commisionforworkers {
    public static void main (String args[]){
Scanner sc = new Scanner (System.in) ;

System.out.println("enter the number of hours");
double hours = sc.nextDouble();
System.out.println("enter the sales") ;
double sales = sc.nextDouble();
double wage = hours * 500 ;
double c = 0;
if (sales < 100 )
c = 0 ;
else if (sales < 1000)
c = 1 ;
else if (sales < 10000)
c = 2 ;
else if (sales <250000)
c = 3 ;
else 
c = 3.5 ;
double comm = c *sales / 100 ;
wage  = comm + hours ;
System.out.println("your answer is "+ wage );



        
    }
}