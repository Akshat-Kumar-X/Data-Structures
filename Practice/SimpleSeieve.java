import java.util.*;

class SimpleSeieve {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        boolean isPrime[] = new boolean[n+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i=2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j= i * i; j <= n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        // print isPrime[i] = true;

    }
}