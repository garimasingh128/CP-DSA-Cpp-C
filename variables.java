import java.util.* ;
public class variables {
    public static double celsiusToFahrenheit(double celsius){ 
        double f ;
f =celsius * 1.8 + 32;
return f ; 
    }
    public static double fahrenheitToCelsius(double fahrenheit){
        double c;
        c =  (fahrenheit - 32) /1.8 ;
        return c ;
    }
    public static void main (String args []){
double x , h;
x = variables.celsiusToFahrenheit (5);
System.out.println("the value is " +x);
h = variables.fahrenheitToCelsius (10);
System.out.println("the value is " +h);
    }
     
    
}