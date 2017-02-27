import java.util.Scanner;
public class HW0{  
public static void main(String[] args){
   Scanner scanner = new Scanner(System.in);   
   int numProblems = scanner.nextInt();   
   for(int i = 0; i < numProblems; ++i){    
    int a = scanner.nextInt();    
    int b = scanner.nextInt();    
    int g = gcd(a,b);     
    int l = lcm(a,b);    
    System.out.println(g + " " + l);  }  
    }
public static int gcd(int a, int b){   

    while(a!=b){
          if (a > b){
             a = a-b; 
          }
          else{
             b = b-a; 
          }
    }
      return a;
    

   }
 public static int lcm(int a, int b){ 
   int gcd= gcd(a,b);
   return ((a*b)/gcd);

   }
}