import java.util.*;

public class LeftRotateArray {
    public static void main( String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        if (x < 10 || y < 10) {
            return x * y;
        }

        int length= Math.max(long.toString(x).length(), long.toString(y).length());
        int halfLength = length/2;

        int max1 = x / (long) Math.pow(10, halfLength);
        int min1 = x % (long) Math.pow(10, halfLength);
        int max2 = y / (long) Math.pow(10, halfLength);
        int min2 = y % (long) Math.pow(10, halfLength);

        long ac = karat(max1, max2);
        long bd = karat(min1, min2);
        long ab_cd = karat(max1 + min1, max2 + min2) - ac - bd;


        return (ac * (long Math.pow(10, 2*halfLength )) + ())
    }
}