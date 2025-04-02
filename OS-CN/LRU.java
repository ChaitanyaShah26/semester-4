import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of page frames: ");
        int frame = scanner.nextInt();

        System.out.print("Enter the total numbers in the sequence: ");
        int n = scanner.nextInt();

        int[] seq = new int[n];
        System.out.print("Enter the sequence of numbers: \n");
        for (int i = 0; i < n; i++) {
            seq[i] = scanner.nextInt();
        }

        int[] page = new int[frame];
        int[] lastUsed = new int[frame];
        for (int i = 0; i < frame; i++) {
            page[i] = -1; // Initialize page frames as empty
            lastUsed[i] = 0; // Initialize usage tracking
        }

        int pageFault = 0, pageHit = 0;

        for (int i = 0; i < n; i++) {
            boolean hit = false;
            // Check if the page is already in the frame (page hit)
            for (int j = 0; j < frame; j++) {
                if (page[j] == seq[i]) {
                    hit = true;
                    pageHit++;
                    lastUsed[j] = i; // Update the last usage time
                    break;
                }
            }

            if (!hit) {
                pageFault++;
                int replaceIndex = -1;
                int oldest = Integer.MAX_VALUE;

                // Find the least recently used page
                for (int j = 0; j < frame; j++) {
                    if (page[j] == -1) { // If there's an empty frame, use it
                        replaceIndex = j;
                        break;
                    }
                    if (lastUsed[j] < oldest) {
                        oldest = lastUsed[j];
                        replaceIndex = j;
                    }
                }

                // Replace the page
                page[replaceIndex] = seq[i];
                lastUsed[replaceIndex] = i; // Update the usage time
            }

            // Print current page frames
            System.out.print("\nCurrent page frames: ");
            for (int j = 0; j < frame; j++) {
                if (page[j] != -1) {
                    System.out.print(page[j] + " ");
                } else {
                    System.out.print("  ");
                }
            }
        }

        System.out.println("\nPage Fault: " + pageFault);
        System.out.println("Page Hit: " + pageHit);
    }
}
