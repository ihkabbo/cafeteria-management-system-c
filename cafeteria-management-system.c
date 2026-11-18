#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100
#define USER_LEN 50
#define MAX 100

/* LINKED LIST */

typedef struct FoodNode
{
    char name[NAME_LEN];
    int quantity;
    int price;
    struct FoodNode *next;
} FoodNode;

FoodNode *breakfastMenu = NULL;
FoodNode *lunchMenu = NULL;
FoodNode *snacksMenu = NULL;

/* FILE HANDLING */

char* getFileName(FoodNode **menu)
{
    if (menu == &breakfastMenu) return "breakfast.txt";
    if (menu == &lunchMenu) return "lunch.txt";
    return "snacks.txt";
}

void saveMenu(FoodNode *menu, char file[])
{
    FILE *fp = fopen(file, "w");
    if (!fp) return;

    while (menu != NULL)
    {
        fprintf(fp, "%s %d %d\n", menu->name, menu->quantity, menu->price);
        menu = menu->next;
    }
    fclose(fp);
}

void loadMenu(FoodNode **menu, char file[])
{
    FILE *fp = fopen(file, "r");
    if (!fp) return;

    char name[NAME_LEN];
    int qty, price;

    while (fscanf(fp, "%s %d %d", name, &qty, &price) == 3)
    {
        FoodNode *newNode = (FoodNode*)malloc(sizeof(FoodNode));
        strcpy(newNode->name, name);
        newNode->quantity = qty;
        newNode->price = price;
        newNode->next = NULL;

        if (*menu == NULL)
            *menu = newNode;
        else
        {
            FoodNode *temp = *menu;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    fclose(fp);
}

void saveOrder(char user[], int total)
{
    FILE *fp = fopen("orders.txt", "a");
    if (!fp) return;

    fprintf(fp, "%s %d\n", user, total);
    fclose(fp);
}

/* MENU SELECTION */

FoodNode** selectMenu()
{
    int choice;

    while (1)
    {
        printf("\nSelect Category:\n1.Breakfast\n2.Lunch\n3.Snacks\nChoice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) return &breakfastMenu;
        if (choice == 2) return &lunchMenu;
        if (choice == 3) return &snacksMenu;

        printf("Invalid choice!\n");
    }
}

/* FOOD FUNCTIONS */

void addFood()
{
    char name[NAME_LEN];
    int qty, price;

    FoodNode **menu = selectMenu();
    char *file = getFileName(menu);

    printf("Name: ");
    scanf("%s", name);
    printf("Qty: ");
    scanf("%d", &qty);
    printf("Price: ");
    scanf("%d", &price);

    FoodNode *newNode = (FoodNode*)malloc(sizeof(FoodNode));
    strcpy(newNode->name, name);
    newNode->quantity = qty;
    newNode->price = price;
    newNode->next = NULL;

    if (*menu == NULL)
        *menu = newNode;
    else
    {
        FoodNode *temp = *menu;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    saveMenu(*menu, file);
}

void viewFood()
{
    FoodNode **menu = selectMenu();
    FoodNode *temp = *menu;
    int i = 1;

    while (temp != NULL)
    {
        printf("%d) %s | Qty:%d | Price:%d\n",
               i++, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }

    if (i == 1)
        printf("No items available.\n");
}

void deleteFood()
{
    char name[NAME_LEN];

    FoodNode **menu = selectMenu();
    char *file = getFileName(menu);

    if (*menu == NULL)
    {
        printf("Menu empty.\n");
        return;
    }

    printf("Enter item name to delete: ");
    scanf("%s", name);

    FoodNode *temp = *menu;
    FoodNode *prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
                *menu = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            saveMenu(*menu, file);
            printf("Deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Item not found.\n");
}

FoodNode* searchFood(char name[], FoodNode **menu)
{
    FoodNode *temp = *menu;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/* CART  */

typedef struct
{
    char itemName[NAME_LEN];
    int qty;
    int price;
} CartItem;

CartItem stack[MAX];
int top = -1;

void pushCart(char name[], int qty, int price)
{
    if (top == MAX - 1)
    {
        printf("Cart Full\n");
        return;
    }

    top++;
    strcpy(stack[top].itemName, name);
    stack[top].qty = qty;
    stack[top].price = price;
}

void popCart()
{
    if (top == -1)
    {
        printf("Cart Empty\n");
        return;
    }

    printf("Removed: %s\n", stack[top].itemName);
    top--;
}

void removeFromCart()
{
    char name[NAME_LEN];

    if (top == -1)
    {
        printf("Cart Empty\n");
        return;
    }

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i <= top; i++)
    {
        if (strcmp(stack[i].itemName, name) == 0)
        {
            for (int j = i; j < top; j++)
                stack[j] = stack[j + 1];

            top--;
            printf("Item removed.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void viewCart()
{
    int total = 0;

    if (top == -1)
    {
        printf("Cart Empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        int t = stack[i].qty * stack[i].price;
        printf("%s x%d = %d\n", stack[i].itemName, stack[i].qty, t);
        total += t;
    }

    printf("Total = %d\n", total);
}

/*  QUEUE */

typedef struct
{
    char username[USER_LEN];
    int total;
} Order;

Order queue[MAX];
int front = 0, rear = -1;

void enqueueOrder(char user[], int total)
{
    if (rear - front + 1 >= MAX)
    {
        printf("Queue Full\n");
        return;
    }

    rear++;
    strcpy(queue[rear].username, user);
    queue[rear].total = total;
}

void dequeueOrder()
{
    if (front > rear)
    {
        printf("No Orders\n");
        return;
    }

    printf("Serving %s | Total: %d\n",
           queue[front].username, queue[front].total);
    front++;
}

void viewOrders()
{
    if (front > rear)
    {
        printf("No Orders\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%s | %d\n", queue[i].username, queue[i].total);
}

/*  LOGIN */

int login(char file[], char user[], char pass[])
{
    FILE *fp = fopen(file, "r");
    char u[USER_LEN], p[USER_LEN];

    if (!fp) return 0;

    while (fscanf(fp, "%s %s", u, p) == 2)
    {
        if (strcmp(u, user) == 0 && strcmp(p, pass) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void registerUser(char file[])
{
    FILE *fp = fopen(file, "a");
    char u[USER_LEN], p[USER_LEN];

    printf("Username: ");
    scanf("%s", u);
    printf("Password: ");
    scanf("%s", p);

    fprintf(fp, "%s %s\n", u, p);
    fclose(fp);

    printf("Registered!\n");
}

/* STUDENT */

void studentMenu(char user[])
{
    int choice;
    char name[NAME_LEN];
    int qty;

    while (1)
    {
        printf("\n--- STUDENT (%s) ---\n", user);
        printf("1.View Menu\n2.Add to Cart\n3.Undo Last\n4.Remove Item\n5.View Cart\n6.Place Order\n7.Logout\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
            viewFood();

        else if (choice == 2)
        {
            FoodNode **menu = selectMenu();
            char *file = getFileName(menu);

            printf("Item name: ");
            scanf("%s", name);

            FoodNode *f = searchFood(name, menu);

            if (!f)
            {
                printf("Not found\n");
                continue;
            }

            printf("Qty: ");
            scanf("%d", &qty);

            if (qty > f->quantity)
            {
                printf("Not enough stock\n");
                continue;
            }

            pushCart(f->name, qty, f->price);
            f->quantity -= qty;

            saveMenu(*menu, file);
        }

        else if (choice == 3)
            popCart();

        else if (choice == 4)
            removeFromCart();

        else if (choice == 5)
            viewCart();

        else if (choice == 6)
        {
            int total = 0;

            for (int i = 0; i <= top; i++)
                total += stack[i].qty * stack[i].price;

            enqueueOrder(user, total);
            saveOrder(user, total);

            top = -1;
            printf("Order placed!\n");
        }

        else if (choice == 7)
            break;
    }
}

/* ADMIN */

void adminMenu()
{
    int choice;

    while (1)
    {
        printf("\n--- ADMIN ---\n");
        printf("1.Add Food\n2.View Food\n3.Delete Food\n4.View Orders\n5.Serve Order\n6.Logout\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) addFood();
        else if (choice == 2) viewFood();
        else if (choice == 3) deleteFood();
        else if (choice == 4) viewOrders();
        else if (choice == 5) dequeueOrder();
        else if (choice == 6) break;
    }
}

/* MAIN */

int main()
{
    int choice;
    char user[USER_LEN], pass[USER_LEN];

    loadMenu(&breakfastMenu, "breakfast.txt");
    loadMenu(&lunchMenu, "lunch.txt");
    loadMenu(&snacksMenu, "snacks.txt");

   while (1)
{
    printf("\n1.Admin Login\n2.Admin Register\n3.Student Login\n4.Student Register\n5.Exit\nChoice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input! Enter a number.\n");
        while (getchar() != '\n');
        continue;
    }

    if (choice == 1)
    {
        printf("User: ");
        scanf("%s", user);
        printf("Pass: ");
        scanf("%s", pass);

        if (login("admin.txt", user, pass))
            adminMenu();
        else
            printf("Invalid\n");
    }
    else if (choice == 2)
    {
        registerUser("admin.txt");
    }
    else if (choice == 3)
    {
        printf("User: ");
        scanf("%s", user);
        printf("Pass: ");
        scanf("%s", pass);

        if (login("student.txt", user, pass))
            studentMenu(user);
        else
            printf("Invalid\n");
    }
    else if (choice == 4)
    {
        registerUser("student.txt");
    }
    else if (choice == 5)
    {
        break;
    }
    else
    {
        printf("Invalid choice!\n");
    }
}
}
