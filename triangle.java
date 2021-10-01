import java.util.* ;
class triangle {
    public static void main (String args[]){
        int a , b , c ;
         
         int peri;
         double area ;
         
         Scanner sc = new Scanner (System.in);
         System.out.println("enter first side");
         a = sc.nextInt();

System.out.println("enter second number");
         b = sc.nextInt();

System.out.println("enter third number");
         c = sc.nextInt();
System.out.println("enter 1 for finding perimeter, 2 for area and 3 for both");

int x = sc.nextInt();
double s = (a + b + c) / 2 ;



switch (x)
{
    case 1 :
    peri = a + b + c;
    System.out.println("the value is " +peri);
    break ;


    case 2 :
 area = Math.sqrt(s*(s-a)*(s-b)*(s-c)) ;
 System.out.println("the value is " +area );
 break ;

 case 3 :
   peri = a + b + c;

 System.out.println("perimeter is"  +peri);
  
  area = Math.sqrt(s*(s-a)*(s-b)*(s-c)) ;
System.out.println("your area is " +area);
break ;

 default :
 System.out.println("nothing");
    
}
    }

}