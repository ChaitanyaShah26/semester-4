import java.util.*;

class ErrorDetectionCorrection 
{
    public static Scanner sc = new Scanner(System.in);

    // Parity Check Method
    public static void performParityCheck() 
    {
        System.out.print("Enter sent data (binary): ");
        String sentData = sc.nextLine();
        
        // Generate parity bit
        String parityBit = generateParityBit(sentData);
        System.out.println("Parity Bit: " + parityBit);
        
        System.out.print("Enter received data (binary): ");
        String receivedData = sc.nextLine();
        
        boolean isError = detectParityError(sentData, receivedData);
        System.out.println(isError ? "Error Detected!" : "No Error Detected.");
    }

    // Generate even parity bit
    private static String generateParityBit(String data) 
    {
        int count = 0;
        // Count number of 1s in the data
        for (char bit : data.toCharArray()) 
        {
            if (bit == '1') 
            {
                count++;
            }
        }
        
        // Return parity bit (0 for even, 1 for odd)
        return (count % 2 == 0) ? "0" : "1";
    }

    // Detect error in parity check
    private static boolean detectParityError(String sentData, String receivedData) 
    {
        String sentParityBit = generateParityBit(sentData);
        String receivedParityBit = generateParityBit(receivedData);
        
        return !sentParityBit.equals(receivedParityBit);
    }

    // CRC Error Detection Method
    public static void performCRCCheck() 
    {
        System.out.print("Enter sent data (binary): ");
        String sentData = sc.nextLine();
        
        System.out.print("Enter generator polynomial (binary): ");
        String generator = sc.nextLine();
        
        // Perform CRC
        String crcResult = performCRCDivision(sentData, generator);
        System.out.println("CRC: " + crcResult);
        
        System.out.print("Enter received data (binary): ");
        String receivedData = sc.nextLine();
        
        boolean isError = detectCRCError(sentData, receivedData, generator);
        System.out.println(isError ? "Error Detected!" : "No Error Detected.");
    }

    // Perform XOR division for CRC
    private static String performCRCDivision(String data, String generator) 
    {
        // Append zeros to data based on generator length
        String extendedData = data + String.join("", java.util.Collections.nCopies(generator.length() - 1, "0"));
        
        // Convert to char arrays for easier manipulation
        char[] dataArray = extendedData.toCharArray();
        char[] generatorArray = generator.toCharArray();
        
        // Perform XOR division
        for (int i = 0; i < dataArray.length - generatorArray.length + 1; i++) 
        {
            if (dataArray[i] == '1') 
            {
                // XOR the generator with current segment
                for (int j = 0; j < generatorArray.length; j++) 
                {
                    dataArray[i + j] = (char) (((dataArray[i + j] - '0') ^ (generatorArray[j] - '0')) + '0');
                }
            }
        }
        
        // Return remainder (last generator.length() - 1 bits)
        return new String(dataArray, dataArray.length - generatorArray.length + 1, generatorArray.length - 1);
    }

    // Detect error in CRC
    private static boolean detectCRCError(String sentData, String receivedData, String generator) 
    {
        String sentCRC = performCRCDivision(sentData, generator);
        String receivedCRC = performCRCDivision(receivedData, generator);
        
        return !sentCRC.equals(receivedCRC);
    }

    // Hamming Code Method
    public static void performHammingCodeCorrection() 
    {
        System.out.print("Enter received Hamming Code: ");
        String receivedCode = sc.nextLine();
        
        // Correct Hamming Code
        String result = correctHammingCode(receivedCode);
        
        if (!result.equals(receivedCode)) 
        {
            System.out.println("Error Detected and Corrected!");
            System.out.println("Corrected Code: " + result);
        } else 
        {
            System.out.println("No Error Detected.");
        }
    }

    // Detect and correct error in Hamming Code
    private static String correctHammingCode(String receivedCode) 
    {
        int r = 0;
        while (Math.pow(2, r) < receivedCode.length() + 1) 
        {
            r++;
        }
        
        // Calculate error position
        int errorPos = 0;
        for (int i = 0; i < r; i++) 
        {
            int pos = (int) Math.pow(2, i);
            int count = 0;
            
            for (int x = pos - 1; x < receivedCode.length(); x += 2 * pos) 
            {
                for (int y = x; y < x + pos && y < receivedCode.length(); y++) 
                {
                    if (receivedCode.charAt(y) == '1') 
                    {
                        count++;
                    }
                }
            }
            
            if (count % 2 != 0) 
            {
                errorPos += pos;
            }
        }
        
        // Correct bit if error detected
        if (errorPos > 0) 
        {
            char[] correctedCode = receivedCode.toCharArray();
            correctedCode[errorPos - 1] = (correctedCode[errorPos - 1] == '0') ? '1' : '0';
            return new String(correctedCode);
        }
        
        return receivedCode;
    }

    public static void main(String[] args) 
    {
        while (true) 
        {
            System.out.println("\n--- Error Detection and Correction ---");
	        System.out.println("1. Parity Check");
	        System.out.println("2. CRC (Cyclic Redundancy Check)");
	        System.out.println("3. Hamming Code");
	        System.out.println("4. Exit");
	        System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume newline
            
            switch (choice) 
            {
                case 1:
                    performParityCheck();
                    break;

                case 2:
                    performCRCCheck();
                    break;

                case 3:
                    performHammingCodeCorrection();
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}