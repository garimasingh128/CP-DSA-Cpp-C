import java.util.* ;
public class static_non_static
{
    public static int power (int a , int b){
int power ;
power = a^b ;
return power;
    }
    public int nonpower (int a , int b){

int power ;
power = a^b ;
return power;
    }
    
    public static void main (String  args [])
    {
        int x  , h;
        x = static_non_static.power (9 , 8);
        System.out.println("the value is "  +x);
        static_non_static classObject = new static_non_static () ;
        h = classObject.nonpower (16 , 2);
        System.out.println("the value is " +h);
    }

        
    
}