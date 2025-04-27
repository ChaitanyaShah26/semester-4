import java.util.Scanner;

class LRU 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of page frames: ");
        int frame = scanner.nextInt();

        System.out.print("Enter the total numbers in the sequence: ");
        int n = scanner.nextInt();

        int[] seq = new int[n];
        System.out.print("Enter the sequence of numbers: \n");
        for (int i = 0; i < n; i++) 
        {
            seq[i] = scanner.nextInt();
        }

        int[] page = new int[frame];
        int[] lastUsed = new int[frame];
        for (int i = 0; i < frame; i++) 
        {
            page[i] = -1; 
            lastUsed[i] = 0; 
        }

        int pageFault = 0, pageHit = 0;

        for (int i = 0; i < n; i++) 
        {
            boolean hit = false;
            
            for (int j = 0; j < frame; j++) 
            {
                if (page[j] == seq[i]) 
                {
                    hit = true;
                    pageHit++;
                    lastUsed[j] = i; 
                    break;
                }
            }

            if (!hit) 
            {
                pageFault++;
                int replaceIndex = -1;
                int oldest = Integer.MAX_VALUE;

                
                for (int j = 0; j < frame; j++) 
                {
                    if (page[j] == -1) 
                    { 
                        replaceIndex = j;
                        break;
                    }
                    if (lastUsed[j] < oldest) 
                    {
                        oldest = lastUsed[j];
                        replaceIndex = j;
                    }
                }

                
                page[replaceIndex] = seq[i];
                lastUsed[replaceIndex] = i; 
            }

            
            System.out.print("\nCurrent page frames: ");
            for (int j = 0; j < frame; j++) 
            {
                if (page[j] != -1) 
                {
                    System.out.print(page[j] + " ");
                } else 
                {
                    System.out.print("  ");
                }
            }
        }

        System.out.println("\nPage Fault: " + pageFault);
        System.out.println("Page Hit: " + pageHit);
    }
}
