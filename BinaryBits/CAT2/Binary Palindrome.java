import java.util.*;

public class BinaryPalindrome {

    public static boolean isPalindrome(String s) {
        int n = s.length();
        for (int i=0; i<n/2; i++) {
            if (s.charAt(i) != s.charAt(n-i-1)) {
                return false;
            }
        }
        return true;
    }

    public static void main (String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();

        String s = Integer.toBinaryString(num);

        if (isPalindrome(s)) {
            System.out.println("Palindrome");
        } else {
            System.out.println("Not a Palindrome");
        }
    }
}