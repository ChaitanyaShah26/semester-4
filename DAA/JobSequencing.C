#include <stdio.h>
#include <stdbool.h>

#define MAX_JOBS 100 // Define a maximum number of jobs

void print_schedule(int schedule[], int jobs, int profit[]) {
    int total_profit = 0; // Variable to accumulate total profit
    for (int i = 0; i < jobs; i++) {
        if (schedule[i] != -1) {
            printf("J%d -> ", schedule[i]);
            total_profit += profit[schedule[i] - 1]; // Add profit of the scheduled job
        }
    }
    printf("NULL\n"); // Indicate the end of the schedule
    printf("Maximum Profit: %d\n", total_profit); // Print total profit
}

void job_sequencing(int deadline[], int index[], int profit[], int jobs) {
    int schedule[MAX_JOBS]; // Fixed-size array for scheduling

    // Initialize the schedule array with -1
    for (int i = 0; i < jobs; i++) {
        schedule[i] = -1;
    }

    // Job sequencing logic
    for (int i = 0; i < jobs; i++) {
        int j = deadline[i];

        // Find a free slot for the job
        while (j > 0 && schedule[j] != -1) {
            j--;
        }
        if (j > 0) {
            schedule[j] = index[i]; // Assign job to the schedule
        }
    }

    print_schedule(schedule, jobs, profit); // Pass profit to print function
}

int main() {
    int jobs, temp;

    printf("Enter the number of jobs (max %d): ", MAX_JOBS);
    scanf("%d", &jobs);

    // Ensure the number of jobs does not exceed the maximum
    if (jobs > MAX_JOBS) {
        printf("Error: Number of jobs exceeds the maximum limit of %d.\n", MAX_JOBS);
        return 1;
    }

    int deadline[MAX_JOBS];
    int profit[MAX_JOBS];
    int index[MAX_JOBS];

    // Input job details
    for (int i = 0; i < jobs; i++) {
        printf("Enter deadline and profit for J%d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
        index[i] = i + 1; // Store job index (1-based)
    }

    // Sort jobs based on profit in descending order using bubble sort
    for (int i = 0; i < jobs; i++) {
        for (int j = 0; j < jobs - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profits
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap deadlines
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                // Swap indices
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    // Perform job sequencing
    job_sequencing(deadline, index, profit, jobs);

    return 0;
}