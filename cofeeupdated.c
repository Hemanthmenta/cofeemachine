#include <stdio.h>
#include <stdlib.h>

struct shop
{
    int ptr_tea;
    int ptr_coffee;
    int ptr_lemontea;
    int ptr_cafelatte;
    char str[10];
    int amount;
};


struct shop *ptr;


void make(int *machine, int required, const char *teaorcofeename)
{

    if (*machine >= required)
    {
        *machine -= required;
        printf("%s prepared successfully\n", teaorcofeename);
        printf("The level of %s in machine is: %d\n\n\n", teaorcofeename, *machine);
    }
    else
    {
        printf("Not sufficient %s to give \n", teaorcofeename);
        printf("The %s level in %s machine is: %d\n", teaorcofeename,teaorcofeename, *machine);
        printf("The %s level at %s machine is low, so please fill the water to the machine \n\n\n", teaorcofeename,teaorcofeename);
    }
}

int main()
{
    ptr = (struct shop *)malloc(sizeof(struct shop));
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    
    ptr->ptr_tea = 5000;
    ptr->ptr_coffee = 5000;
    ptr->ptr_lemontea = 5000;
    ptr->ptr_cafelatte = 5000;
    
    

    int choice, loop = 1;

    while (loop)
    {
        // Display menu
        printf("\t\tMenu:\n");
        printf("1. Make Tea\n");
        printf("2. Make Coffee\n");
        printf("3. Make Lemonade\n");
        printf("4. Make Cafe Latte\n");
        printf("0. Exit\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            make(&ptr->ptr_tea, 500, "Tea");
            break;

        case 2:
            make(&ptr->ptr_coffee, 500, "Coffee");
            break;

        case 3:
            make(&ptr->ptr_lemontea, 500, "Lemontea");
            break;

        case 4:
            make(&ptr->ptr_cafelatte, 500, "Cafe Latte");
            break;

        case 0:
            loop = 0;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n\n\n");
        }

        
        
        
            printf("\n\n\n1.Continue\t0.Exit\n");
            scanf("%d", &loop);
      }

    free(ptr);

    return 0;
}

