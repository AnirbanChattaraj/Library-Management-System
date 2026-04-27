#include <stdio.h>
struct book
{
    char name[50];
    int id;
};
struct book s;
void addbooks()
{
    struct book s;
    FILE *fp;
    fp = fopen("inventory.txt", "a");
    if (fp == NULL)
    {
        printf("Invalid file");
        return;
    }
    printf("Enter your book name:");
    scanf("%s", s.name);
    printf("Enter book id:");
    scanf("%d", &s.id);
    fprintf(fp, "%s %d\n", s.name, s.id);
    fclose(fp);
    printf("Book added succesfully\n");
}
void displaybooks()
{
    struct book s;
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL)
    {
        printf("Invalid file");
        return;
    }
    printf("\n--- Book List ---\n");

    while (fscanf(fp, "%s%d ", s.name, &s.id) != EOF)
    {
        printf("Name: %s | Id: %d \n",
               s.name, s.id);
    }
    fclose(fp);
    printf("Books displayed succesfully\n");
}
void searchbooks()
{
    struct book s;
    FILE *fp = fopen("inventory.txt", "r");
    int searchId, found = 0;

    if (fp == NULL)
    {
        printf("No records found\n");
        return;
    }
    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(fp, "%s %d", s.name, &s.id) != EOF)
    {
        if (s.id == searchId)
        {
            printf("Book Found: %s | Id: %d\n", s.name, s.id);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Book not found\n");
    }

    fclose(fp);
}
void count()
{
    struct book s;
    FILE *fp;
    int count = 0;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL)
    {
        printf("Invalid file");
        return;
    }
    while (fscanf(fp, "%s %d", s.name, &s.id) != EOF)
    {
        count++;
    }

    printf("Total books: %d\n", count);

    fclose(fp);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nWelcome to Library Management Systems\n");
        printf("1.Add Book\n");
        printf("2.Display Books\n");
        printf("3.Search Book by ID\n");
        printf("4.Total Books\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        if (choice == 5)
        {
            break;
        }
        else if (choice == 1)
        {
            addbooks();
        }
        else if (choice == 2)
        {
            displaybooks();
        }
        else if (choice == 3)
        {
            searchbooks();
        }
        else if (choice == 4)
        {
            count();
        }
    }
    return 0;
}