#include <stdio.h>
#include <Windows.h>
#include <string.h>

struct login;
int login_page();
void login_main();
void registerUser();
void save_account();
void load_accounts();
void library_main();
void lib_select();
int checkduplicateID(int id);
void borrowBook();
void returnBook();
void registerBook();
void searchBook();
void markBook();
void calcAccount();
int late_fee();


struct login
{
    int id[10];
    char pw[20];
};

struct creat_account
{
    char name[20];
    int student_id[10];
    char password[20];
    char password_check[20];
    char major[100];
};

struct creat_account accounts[100];
int account_count = 0;

int main(void)
{
    struct login a, b;
    int choice;
    

    load_accounts();
    login_main();

    do
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            login_page();
            library_main();
            lib_select();
            break;
        case 2:
            registerUser();
            save_account();
            break;
        default:
            printf("1(�α���) �Ǵ� 2(ȸ������)�� �Է��Ͻÿ�: ");
            break;
        }
    } while (choice != 1 && choice != 2);
    
    

    return 0;
}

void login_main()
{
    struct login c, b;
    struct creat_account nm, id, pw, re, mj;
    int i = 0;
    printf("�α��� �Ͻðڽ��ϱ�?\n");
    printf("ȸ������ �Ͻðڽ��ϱ�?\n");
    printf("�α���(1) / ȸ������(2)\n");
}

int login_page()
{
    struct login c;

    system("cls");
    while (1)
    {
        printf("ID(�й�) : ");
        scanf("%d", &c.id[0]);
        printf("��й�ȣ :");
        scanf("%s", c.pw);

        for (int i = 0; i < account_count; i++)
        {
            if (c.id[0] == accounts[i].student_id[0] && strcmp(c.pw, accounts[i].password) == 0)
            {
                printf("�α��� �ϼ̽��ϴ�\n");
                system("cls");
                
                return 1;
            }

        }
        printf("���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�\n");

    }
}

void registerUser()
{
    while (1)
    {
        struct login c, b;
        struct creat_account nm, id, pw, re, mj;

        system("cls");

        printf("�̸��� �Է��Ͻÿ� : ");
        scanf("%s", nm.name);
        while (1)
        
        {
            printf("���̵�(�й�)�� �Է��Ͻÿ� : ");
            scanf("%d", &id.student_id[0]);
            if (checkduplicateID(id.student_id[0]))
            {
                printf("�ߺ��� ���̵�(�й�)�Դϴ�. �ٸ� ���̵�(�й�)�� �Է��ϼ���.\n");
            }
            else
                break;
        }
        printf("��й�ȣ�� �Է��Ͻÿ� : ");
        scanf("%s", pw.password);

        while (1)
        {
            printf("��й�ȣ�� �ٽ� �Է��Ͻÿ�: ");
            scanf("%s", re.password_check);
            if (strcmp(pw.password, re.password_check) == 0)
            {
                break;
            }
            else
            {
                printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
            }
        }
        printf("������ �Է��Ͻÿ� : ");
        scanf("%s", mj.major);

        strcpy(accounts[account_count].name, nm.name);
        accounts[account_count].student_id[0] = id.student_id[0];
        strcpy(accounts[account_count].password, pw.password);
        strcpy(accounts[account_count].password_check, re.password_check);
        strcpy(accounts[account_count].major, mj.major);
        account_count++;

        printf("ȸ�������� ���ϵ帳�ϴ�!!\n");
        printf("��� �� �α��� �������� �̵��մϴ�.");
        Sleep(3000);
        system("cls");

        break;
    }
    system("cls");
    login_page();
}

int checkduplicateID(int id)
{
    for (int i = 0; i < account_count; i++)
    {
        if (id == accounts[i].student_id[0])
            return 1;
    }
    return 0;
}

void save_account()
{
    FILE* fp = fopen("accounts.txt", "w");
    if (fp == NULL)
    {
        printf("������ �� �� �����ϴ�.");
        return;
    }

    for (int i = 0; i < account_count; i++)
    {
        fprintf(fp, "%s %d %s %s %s\n", accounts[i].name, accounts[i].student_id[0], accounts[i].password, accounts[i].password_check, accounts[i].major);
    }
    fclose(fp);
}

void load_accounts()
{
    FILE* fp = fopen("accounts.txt", "r");
    if (fp == NULL)
    {
        printf("������ �� �� �����ϴ�.");
        return;
    }

    while (fscanf(fp, "%s %d %s %s %s\n", accounts[account_count].name, &accounts[account_count].student_id[0], accounts[account_count].password, accounts[account_count].password_check, accounts[account_count].major) != EOF)
    {
        account_count++;
    }
    fclose(fp);
}

void library_main()
{
    printf("===== ���� ������ =====\n");
    printf("�̿��� ������ ��ȣ�� ��������.\n ");
    printf("1.���� ����\n ");
    printf("2.���� �ݳ�\n ");
    printf("3.���� ���\n ");
    printf("4.���� �˻�\n ");
    printf("5.��� ã�� ����\n ");
    printf("6.���� ��ü�� �ݾ� Ȯ���ϱ�\n ");

}

void lib_select() 
{
    int book;
      do
    {

          scanf("%d", &book);

        switch (book)
        {
        case 1:
            borrowBook();
            break;
        case 2:
            returnBook();
            break;
        case 3:
            registerBook();
            break;
        case 4:
            searchBook();
            break;
        case 5:
            markBook();
            break;
        case 6:
            calcAccount();
            break;
        default:
            printf("1~6�� �Է��Ͻÿ�: ");
            break;

        }
    }while (book < 1 || book > 6);
}

void borrowBook()
{
    system("cls");
    printf("���� ���� ������");
}
void returnBook()
{
    system("cls");
    printf("���� �ݳ� ������");
}
void registerBook()
{
    system("cls");
    printf("���� ��� ������");
}
void searchBook()
{
    system("cls");
    printf("���� �˻� ������");
}
void markBook()
{
    system("cls");
    printf("���ã�� ���� ������");
}
void calcAccount()
{
    system("cls");
    printf("��ü ���� ������");
    printf("��ü�ݾ��� 8�ð��� 100��, ���� �Ⱓ�� 1��,1�Ǵ� �ΰ��˴ϴ�.\n");
    late_fee();
}


int late_fee()
{
    const int fee = 100; 
    const int Period = 7; 

    int Latehours;
    int Bookcount;

    printf("7���� 168�ð� �Դϴ�.\n");
    printf("168�ð� ���� ��ü�� �ð�(�ð� ����)�� �Է��ϼ���: ");
    scanf("%d", &Latehours);

    printf("������ å�� �Ǽ��� �Է��ϼ���: ");
    scanf("%d", &Bookcount);

    int total = (Latehours / 8) * fee * Bookcount; 

    printf("��ü�� �ݾ�: %d ��\n", total);

    return 0;
}
