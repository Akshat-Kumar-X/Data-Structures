import java.util.Scanner;

public class SwapNibbles {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a byte value (0-255): ");
        int byteValue = scanner.nextInt();

        // Swapping the nibbles
        int swapped = ((byteValue & 0x0F) << 4) | ((byteValue & 0xF0) >> 4);

        System.out.println("Original byte: " + byteValue);
        System.out.println("Byte after swapping nibbles: " + swapped);

        scanner.close();
    }
}
