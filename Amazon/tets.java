import java.util.*;

public class vinay {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Find Network Address (Classful IPv4)");
            System.out.println("2. Find Subnet Address");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    System.out.print("Enter the IPv4 address ");
                    String ip = scanner.nextLine();
                    findAndDisplayNetworkAddress(ip);
                    break;
                case 2:
                    System.out.print("Enter the IPv4 address ");
                    String subnetIP = scanner.nextLine();
                    System.out.print("Enter the subnet mask ");
                    String subnetMask = scanner.nextLine();
                    findAndDisplaySubnetAddress(subnetIP, subnetMask);
                    break;
                case 3:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    public static boolean isValidIP(String ip) {
        String[] parts = ip.split("\\.");
        if (parts.length != 4)
            return false;
        for (String part : parts) {
            try {
                int num = Integer.parseInt(part);
                if (num < 0 || num > 255) {
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }

    public static int[] convertIPStringToArray(String ip) {
        String[] parts = ip.split("\\.");
        int[] ipArray = new int[4];
        for (int i = 0; i < 4; i++) {
            ipArray[i] = Integer.parseInt(parts[i]);
        }
        return ipArray;
    }

    public static int[] getDefaultSubnetMask(int[] ip) {
        int firstOctet = ip[0];
        int[] subnetMask = new int[4];
        if (firstOctet >= 0 && firstOctet <= 127) {
            subnetMask = new int[] { 255, 0, 0, 0 };
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            subnetMask = new int[] { 255, 255, 0, 0 };
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            subnetMask = new int[] { 255, 255, 255, 0 };
        } else {
            System.out.println("Invalid IP class. Class D and E are not used for networking.");
        }
        return subnetMask;
    }

    public static void findAndDisplayNetworkAddress(String ip) {
        if (!isValidIP(ip)) {
            System.out.println("Invalid IP Address.");
            return;
        }
        int[] ipArray = convertIPStringToArray(ip);
        int[] subnetMask = getDefaultSubnetMask(ipArray);
        if (subnetMask == null)
            return;
        int[] networkAddress = new int[4];
        for (int i = 0; i < 4; i++) {
            networkAddress[i] = ipArray[i] & subnetMask[i];
        }
        if (ipArray[0] >= 128) {
            System.out.println("This network address belongs to class A");
        } else if (ipArray[0] >= 192) {
            System.out.println("This network address belongs to class B");
        } else if (ipArray[0] >= 224) {
            System.out.println("This network address belongs to class C");
        } else {
            System.out.println("This address belongs to class D");
        }
        System.out.println("Network Address: " + networkAddress[0] + "." + networkAddress[1] + "." +
                           networkAddress[2] + "." + networkAddress[3]);
    }

    public static void findAndDisplaySubnetAddress(String ip, String subnetMask) {
        if (!isValidIP(ip) || !isValidIP(subnetMask)) {
            System.out.println("Invalid IP Address or Subnet Mask.");
            return;
        }
        int[] ipArray = convertIPStringToArray(ip);
        int[] subnetMaskArray = convertIPStringToArray(subnetMask);
        int[] subnetAddress = new int[4];
        for (int i = 0; i < 4; i++) {
            subnetAddress[i] = ipArray[i] & subnetMaskArray[i];
        }
        if (ipArray[0] >= 128 && ipArray[0] < 192) {
            System.out.println("This network address belongs to class A");
        } else if (ipArray[0] >= 192 && ipArray[0] < 224) {
            System.out.println("This network address belongs to class B");
        } else if (ipArray[0] >= 224) {
            System.out.println("This network address belongs to class C");
        } else {
            System.out.println("This address belongs to class D");
        }
        System.out.println("Subnet Address: " + subnetAddress[0] + "." + subnetAddress[1] + "." +
                           subnetAddress[2] + "." + subnetAddress[3]);
    }
}
