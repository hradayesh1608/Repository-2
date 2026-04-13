#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char name[30];
    char author[30];
    float price;
};

struct Book b[100];
int count = 0;

/* Function Declarations */
void addBook();
void viewBooks();
void searchBook();
void deleteBook();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            viewBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            deleteBook();
            break;

        case 5:
            printf("Thank You!\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}

/* ADD BOOK */
void addBook()
{
    printf("\nEnter Book 🆔 : ");
    scanf("%d", &b[count].id);

    printf("Enter Book Name 🔠: ");
    scanf("%s", b[count].name);

    printf("Enter Author Name ✍️: ");
    scanf("%s", b[count].author);

    printf("Enter Price 💰: ");
    scanf("%f", &b[count].price);

    count++;

    printf("Book Added Successfully!\n");
}

/* VIEW BOOKS */
void viewBooks()
{
    int i;

    if (count == 0)
    {
        printf("No Books Available!\n");
        return;
    }

    printf("\nID\tName\tAuthor\tPrice\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\t%.2f\n",
               b[i].id,
               b[i].name,
               b[i].author,
               b[i].price);
    }
}

/* SEARCH BOOK */
void searchBook()
{
    int id, i, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (b[i].id == id)
        {
            printf("Book Found!\n");
            printf("%d %s %s %.2f\n",
                   b[i].id,
                   b[i].name,
                   b[i].author,
                   b[i].price);

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Book Not Found!\n");
}

/* DELETE BOOK */
void deleteBook()
{
    int id, i, j, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (b[i].id == id)
        {
            for (j = i; j < count - 1; j++)
            {
                b[j] = b[j + 1];
            }

            count--;
            found = 1;
            printf("Book Deleted Successfully!\n");
            break;
        }
    }

    if (found == 0)
        printf("Book Not Found!\n");
}