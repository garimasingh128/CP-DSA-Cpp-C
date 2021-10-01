import java.util.* ;
class timeconverter {
    public static void main (String args[]){
        
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter Total Seconds: ");
        int seconds = sc.nextInt();

        int n1 = seconds / 60 ;

        int n2 = seconds % 60 ;

        int n3 = n1 % 60;
   int hours  = n1 / 60;
   System.out.println ("your answer is as follows " + hours + " hours \n" + n3 + " minutes \n" + n2 + " seconds\n" );

        

    }
}