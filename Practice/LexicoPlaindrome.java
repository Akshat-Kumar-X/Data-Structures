import java.util.*;

class Practice {
    static String fun ( String s ) {
        s = s.toLowerCase();
        int freq[] = new int[256];
        Arrays.fill(freq, 0);

        for (int i=0; i<s.length(); i++) {
            freq[s.charAt(i)] += 1;
        }

        int oddCount = 0;
        int oddIndex = 0;
        for (int i=0; i<256; i++) {
            if (freq[i]%2 != 0){ 
                oddCount++;
                oddIndex = i;
            }
        }
        if (oddCount > 1) return "Not Possible";


        String ans = "";
        for (int i=0; i<256; i++) {
            int n = freq[i]/2;
            while(n != 0) {
                ans += (char) i;
                n--;
            }
        }

        if (oddIndex != -1) {
            ans += (char) oddIndex;
        }

        for (int i=255; i>=0; i--) {
            int n = freq[i]/2;
            while(n != 0) {
                ans += (char) i;
                n--;
            }
        }
        return ans;
    }
    public static void main(String args []) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();
        System.out.print(fun(s));
    }
}