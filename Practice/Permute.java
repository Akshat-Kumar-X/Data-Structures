import java.util.*;

class Permute {
    static void fun(String str, String chosen, Set<String> permutations) {
        if (str.length() == 0) {
            permutations.add(chosen);
            return;
        }

        for (int i=0; i< str.length(); i++) {
            char c = str.charAt(i);
            String remaining = str.substring(0, i) + str.substring(i+1);
            fun(remaining, chosen + c, permutations);
        }
    }
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        Set<String> permutations = new TreeSet<>();
        fun(s, "", permutations);
        for (String perm: permutations) {
            System.out.print(perm + " ");
        }
    }
}