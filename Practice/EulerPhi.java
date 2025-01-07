import java.util.*;

class EulerPhi {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int result = n;

        for (int i=2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                result -= result/i;
            }
        }

        if (n>1) {
            result -= result/n;
        }

        // print result
    }
}