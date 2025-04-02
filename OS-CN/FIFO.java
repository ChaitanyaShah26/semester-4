import java.util.*;

class FIFO 
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the length of page frames: ");
        int frame = scanner.nextInt();
        
        System.out.print("Enter the total numbers in the sequence: ");
        int n = scanner.nextInt();
        
        int seq[] = new int[n];
        System.out.print("Enter the sequence of numbers: \n");
        for (int i = 0; i < n; i++) 
        {
            seq[i] = scanner.nextInt();
        }
        
        int page[] = new int[frame];
        for (int i = 0; i < frame; i++) 
        {
            page[i] = -1;
        }
        
        int ptr = 0;
        int pageHit = 0;
        int pageFault = 0;

        for (int i = 0; i < n; i++) 
        {
            boolean hit = false;
            for (int j = 0; j < frame; j++) 
            {
                if (seq[i] == page[j]) 
                {
                    hit = true;
                    pageHit++;
                    break;
                }
            }
            if (!hit) 
            {
                page[ptr] = seq[i];
                pageFault++;
                ptr = (ptr + 1)% frame;
            }

            System.out.print("\nCurrent page frames: ");
            for (int j = 0; j < frame; j++) 
            {
                if (page[j] != -1) 
                {
                    System.out.print(page[j] + " ");
                } 
                else 
                {
                    System.out.print("  ");
                }
            }
        }
        
        System.out.println("\nPage Fault: " + pageFault);
        System.out.println("Page Hit: " + pageHit);
    }
}