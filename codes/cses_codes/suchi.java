import java.util.Scanner;
import java.util.*;
interface UNbodies
{
  int GA=193;
  int SC=15;
  int ESC=54;
  
  default void WelcomeMsg()
  {
    System.out.println("welcome to UN");
  }
  void functionOfBody();
}
class General_assembly implements UNbodies
{
  String resp;
 public void functionOfBody()
  {
    resp="policymaking";
    
    System.out.println("Number of members: "+GA);
    System.out.println("Responsibility: "+resp);
  }
}
class Security_Council implements UNbodies
{
  String resp;
 public void functionOfBody()
  {
    resp="Maintenance of international peaces and security";
   System.out.println("Number of members: "+SC);
    System.out.println("Responsibility: "+resp);
  }
}
class Economic_social_council implements UNbodies
{
  String resp;
 public void functionOfBody()
  {
    resp="Co ordination,policy review,policy dialouge and recommendations on economic ,social,and environmental issues";
    System.out.println("Number of members: "+ESC);
    System.out.println("Responsibility: "+resp);
  }
}
 class Test
 {
   public static void main(String args[])
   { 
     int option;
   General_assembly g1=new General_assembly();
   Economic_social_council e1=new Economic_social_council();
   Security_Council s1=new Security_Council();
   g1.WelcomeMsg();
  System.out.println("Enter option:");
  System.out.println("1.General Assembly details");
     System.out.println("2.Securty Council details");
     System.out.println("3.Economic_social_council");
     System.out.println("4.EXIT");
   Scanner sc=new Scanner(System.in);
   
   option=sc.nextInt();
   //System.out.println("");
   do
   {
   switch(option)
   {
     
     case 1:
       System.out.println("General Assembled");
        g1.functionOfBody();
      break;
     case 2:
        System.out.println("Security Council");
        s1.functionOfBody();
        break;
      case 3:
        System.out.println("Economic and social Council");
        e1.functionOfBody();
        break;
        default:
          System.out.println("Enter correct option");
          break;
       
   }
   System.out.println("1.General Assembly details");
     System.out.println("2.Securty Council details");
     System.out.println("3.Economic_social_council");
     System.out.println("4.EXIT");
    option=sc.nextInt();
   }while(option!=4);
   
   }
 }