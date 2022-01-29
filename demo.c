#include <conio.h>
#include "dateconv.c"
int main()
{
    system("cls");
    int choice;
    char date[15], c;
    Date converted;
    printf("Welcome to Date Convertor:\n 1.BS to AD \n 2.AD to BS\n Choice:");
    scanf("%d", &choice);
    printf("Choice:");
    if (choice == 1)
    {

        printf("-Bs to AD\n");
    }
    else if (choice == 2)
    {

        printf("-AD to BS\n");
    }
    else
    {
        printf("-Invalid Choice");

        main();
        return 0;
    }
    printf("Enter date(YYYY-MM-DD):");
    scanf("%s", date);

    if (choice == 1)
    {
        converted = Bs2Ad(date);
    }
    else
    {
        converted = Ad2Bs(date);
    }
    if (strlen(converted.error))
    {
        printf("%s", converted.error);
    }
    else
    {
        if (choice == 1)
        {

            printf("Date in AD:\n");
        }
        else
        {

            printf("Date in BS:\n");
        }
        printf("%d %s %d, %s\n", converted.day, converted.Month, converted.year, converted.Day);
    }
    printf("Press w to continue!!");
    c = getch();
    if (c == 'w')
    {

        main();
    }
    return 0;
}