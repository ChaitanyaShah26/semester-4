import java.util.*;

class OptimalPageReplacement 
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
                pageFault++;
                
                int emptyIndex = -1;
                for (int j = 0; j < frame; j++) 
                {
                    if (page[j] == -1) 
                    {
                        emptyIndex = j;
                        break;
                    }
                }
                
                if (emptyIndex != -1) 
                {
                    page[emptyIndex] = seq[i];
                } 
                else 
                {
                    int farthestIndex = -1;
                    int pageToReplace = -1;
                    for (int j = 0; j < frame; j++) 
                    {
                        int k;
                        for (k = i + 1; k < n; k++) 
                        {
                            if (page[j] == seq[k]) 
                            {
                                if (farthestIndex < k) 
                                {
                                    farthestIndex = k;
                                    pageToReplace = j;
                                }
                                break;
                            }
                        }
                        if (k == n) 
                        {
                            pageToReplace = j;
                            break;
                        }
                    }
                    page[pageToReplace] = seq[i];
                }
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