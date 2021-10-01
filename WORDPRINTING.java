import java.util.* ;
public class WORDPRINTING{
    public static void main (String args[]){
    Scanner sc = new Scanner (System.in);
    System.out.println("please enter a word");
    String word = sc.nextLine();

    int Wordlength = word.length();

    for (int i = 0 ; i < Wordlength ; i++){
        for (int j = 0 , k = 0 ; j <=  i ; j++ , k++){
            System.out.print(word.charAt(k)  + " ");
        }
        System.out.println();
    }
    sc.close();
    }
}