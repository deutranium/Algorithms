import java.util.*;
class palindrome
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your word");
        String str = sc.nextLine();
        String s = str;
        String st = "";
        char ch;int i;
        for(i=0;i<str.length();i++)
        {
            ch = str.charAt(i);
            st = ch+st;
        }
        if(s.equalsIgnoreCase(st))
            System.out.println("Palindrome word");
        else
            System.out.println("Not a Palindrome word");
    }
}
        