import java.util.*;

class WeightedString {
    static String fun(int w) {
        int arr[] = new int[27];
        int weight = w;

        String s = "";
        while (w > 0) {
            boolean flag = false;
            for (int i=1; i<27; i++) {
                if (i > w) {
                    flag = true;
                    int n = w/(i-1);
                    while (n > 0) {
                        s += (char) (97 + (i-2));
                        n--;
                    }
                    w = w%(i-1);
                    break;
                }
            }
            if (!flag) {
                int n = w/(26);
                while (n > 0) {
                    s += (char) (97 + 25);
                    n--;
                }
                w = w%26;
            }
        }
        return s;
    }
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String 
        System.out.print(fun(weight));
    }
}