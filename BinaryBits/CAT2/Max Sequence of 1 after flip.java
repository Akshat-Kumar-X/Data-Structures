import java.util.Scanner;

public class MaximumConsecutiveOnes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the binary string: ");
        String s = scanner.nextLine();

        int n = s.length();
        int prevLength = 0;
        int currLength = 0;
        int maxLength = 0;
        boolean hasZero = false;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                currLength++;
            } else {
                maxLength = Math.max(maxLength, prevLength + currLength + 1);
                prevLength = currLength;
                currLength = 0;
                hasZero = true;
            }
        }
        
        if (hasZero) {
            maxLength = Math.max(maxLength, prevLength + currLength+ 1);
        } else {
            maxLength = currLength;
        }

        System.out.println(maxLength);
    }
}
