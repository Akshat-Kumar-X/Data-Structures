import java.util.*;

class StroboGramatic {
    public static void main(String args []) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String s = Interger.toString(n);

        Map<Character, Character> map = new HashMap<>();
        map.put('6', '9');
        map.put('9', '6');
        map.put('0', '0');
        map.put('1', '1');
        map.put('8', '8');

        int l = 0;
        int r = s.length() - 1;

        while (l <= r) {
            if (!map.containsKey(s.charAt(l))) return false;
            if (map.get(s.charAt(i)) != s.charAt(r)) return false;
            l++; r--;
        }
        return true;
    }
}