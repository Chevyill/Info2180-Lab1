//Q1

#include <stdio.h>

int main() {
    float a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    float b[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    float c[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resulting matrix c:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//2

int compare(const void *a, const void *b) {
	return (*(char *)a - *(char *)b);
}

int main()
{
  char input[31];

  printf("Please enter a string: ");
  fgets(input, sizeof(input), stdin);
  size_t count = strlen(input);

	if (count > 0 && input[count - 1] == '\n') {
        input[count - 1] = '\0';
        count --;
  }
  qsort (input, count, sizeof(char), compare);
  printf("Sorted characters: %s\n", input);

}

//3

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide command line arguments.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        for (int j = i + 1; j < argc; j++) {
            if (strcmp(argv[i], argv[j]) == 0) {
                printf("Matching argument: '%s' at positions %d and %d\n", argv[i], i, j);
            }
        }
    }

}


//4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
    char name[30];
    char address[30];
    char phone[8];
};

void addEntry(struct PhoneBookEntry **book, int *count);
void displayEntries(struct PhoneBookEntry *book, int count);
struct PhoneBookEntry* findEntryByName(struct PhoneBookEntry *book, int count, const char *name);

int main() {
    struct PhoneBookEntry *phoneBook = NULL;
    int entryCount = 0;
    int choice;

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Find Entry by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEntry(&phoneBook, &entryCount);
                break;
            case 2:
                displayEntries(phoneBook, entryCount);
                break;
            case 3: {
                char name[30];
                printf("Enter the name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                struct PhoneBookEntry *foundEntry = findEntryByName(phoneBook, entryCount, name);
                if (foundEntry) {
                    printf("Found Entry:\nName: %s\nAddress: %s\nPhone: %s\n", foundEntry->name, foundEntry->address, foundEntry->phone);
                } else {
                    printf("No entry found for %s\n", name);
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                free(phoneBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEntry(struct PhoneBookEntry **book, int *count) {
    *book = realloc(*book, (*count + 1) * sizeof(struct PhoneBookEntry));
    if (*book == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter name: ");
    fgets((*book)[*count].name, sizeof((*book)[*count].name), stdin);
    (*book)[*count].name[strcspn((*book)[*count].name, "\n")] = 0;

    printf("Enter address: ");
    fgets((*book)[*count].address, sizeof((*book)[*count].address), stdin);
    (*book)[*count].address[strcspn((*book)[*count].address, "\n")] = 0;

    printf("Enter phone number (7 digits): ");
    fgets((*book)[*count].phone, sizeof((*book)[*count].phone), stdin);
    (*book)[*count].phone[strcspn((*book)[*count].phone, "\n")] = 0;

    (*count)++;
}

void displayEntries(struct PhoneBookEntry *book, int count) {
    if (count == 0) {
        printf("No entries in the phone book.\n");
        return;
    }
    printf("\nPhone Book Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", book[i].name);
        printf("Address: %s\n", book[i].address);
        printf("Phone: %s\n", book[i].phone);
    }
}

struct PhoneBookEntry* findEntryByName(struct PhoneBookEntry *book, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            return &book[i];
        }
    }
    return NULL;
}


//5

#include <stdio.h>

struct point {
    int x, y;
};

struct rect {
    struct point ne;
    struct point se;
    struct point sw;
    struct point nw;
};

int RectArea(struct rect r) {
    int width = r.se.x - r.sw.x;
    int height = r.nw.y - r.sw.y;
    
    return width * height;
}

int main() {
    struct rect myRectangle;

    myRectangle.nw.x = 1; myRectangle.nw.y = 4;
    myRectangle.ne.x = 4; myRectangle.ne.y = 4;
    myRectangle.se.x = 4; myRectangle.se.y = 1;
    myRectangle.sw.x = 1; myRectangle.sw.y = 1;

    int area = RectArea(myRectangle);
    printf("The area of the rectangle is: %d\n", area);

    return 0;
}
