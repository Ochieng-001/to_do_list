#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

// Structure for a task
typedef struct {
    char task[TASK_LENGTH];
} ToDo;

ToDo tasks[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void addTask();
void deleteTask();
void editTask();
void displayTasks();

int main() {
    int choice;

    while (1) {
        printf("\n--- To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Edit Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline after scanf

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                printf("Exiting To-Do List Application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

// Add a new task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter the task: ");
    fgets(tasks[taskCount].task, TASK_LENGTH, stdin);
    tasks[taskCount].task[strcspn(tasks[taskCount].task, "\n")] = 0; // Remove newline character
    taskCount++;
    printf("Task added successfully!\n");
}

// Delete a task by its index
void deleteTask() {
    int taskIndex;
    
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the task number to delete (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    getchar(); // To consume newline

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = taskIndex - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i].task, tasks[i + 1].task);
    }
    taskCount--;
    printf("Task deleted successfully!\n");
}

// Edit an existing task by its index
void editTask() {
    int taskIndex;

    if (taskCount == 0) {
        printf("No tasks to edit.\n");
        return;
    }

    printf("Enter the task number to edit (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    getchar(); // To consume newline

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    printf("Enter the new task: ");
    fgets(tasks[taskIndex - 1].task, TASK_LENGTH, stdin);
    tasks[taskIndex - 1].task[strcspn(tasks[taskIndex - 1].task, "\n")] = 0; // Remove newline character
    printf("Task edited successfully!\n");
}

// Display the list of tasks
void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i].task);
    }
}
