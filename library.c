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
            printf("1(로그인) 또는 2(회원가입)을 입력하시오: ");
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
    printf("로그인 하시겠습니까?\n");
    printf("회원가입 하시겠습니까?\n");
    printf("로그인(1) / 회원가입(2)\n");
}

int login_page()
{
    struct login c;

    system("cls");
    while (1)
    {
        printf("ID(학번) : ");
        scanf("%d", &c.id[0]);
        printf("비밀번호 :");
        scanf("%s", c.pw);

        for (int i = 0; i < account_count; i++)
        {
            if (c.id[0] == accounts[i].student_id[0] && strcmp(c.pw, accounts[i].password) == 0)
            {
                printf("로그인 하셨습니다\n");
                system("cls");
                
                return 1;
            }

        }
        printf("아이디 또는 비밀번호가 일치하지 않습니다\n");

    }
}

void registerUser()
{
    while (1)
    {
        struct login c, b;
        struct creat_account nm, id, pw, re, mj;

        system("cls");

        printf("이름을 입력하시오 : ");
        scanf("%s", nm.name);
        while (1)
        
        {
            printf("아이디(학번)을 입력하시오 : ");
            scanf("%d", &id.student_id[0]);
            if (checkduplicateID(id.student_id[0]))
            {
                printf("중복된 아이디(학번)입니다. 다른 아이디(학번)을 입력하세요.\n");
            }
            else
                break;
        }
        printf("비밀번호를 입력하시오 : ");
        scanf("%s", pw.password);

        while (1)
        {
            printf("비밀번호를 다시 입력하시오: ");
            scanf("%s", re.password_check);
            if (strcmp(pw.password, re.password_check) == 0)
            {
                break;
            }
            else
            {
                printf("비밀번호가 일치하지 않습니다.\n");
            }
        }
        printf("전공을 입력하시오 : ");
        scanf("%s", mj.major);

        strcpy(accounts[account_count].name, nm.name);
        accounts[account_count].student_id[0] = id.student_id[0];
        strcpy(accounts[account_count].password, pw.password);
        strcpy(accounts[account_count].password_check, re.password_check);
        strcpy(accounts[account_count].major, mj.major);
        account_count++;

        printf("회원가입을 축하드립니다!!\n");
        printf("잠시 후 로그인 페이지로 이동합니다.");
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
        printf("파일을 열 수 없습니다.");
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
        printf("파일을 열 수 없습니다.");
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
    printf("===== 메인 페이지 =====\n");
    printf("이용할 서비스의 번호를 누르세요.\n ");
    printf("1.도서 대출\n ");
    printf("2.도서 반납\n ");
    printf("3.도서 등록\n ");
    printf("4.도서 검색\n ");
    printf("5.즐겨 찾는 도서\n ");
    printf("6.나의 연체된 금액 확인하기\n ");

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
            printf("1~6을 입력하시오: ");
            break;

        }
    }while (book < 1 || book > 6);
}

void borrowBook()
{
    system("cls");
    printf("도서 대출 페이지");
}
void returnBook()
{
    system("cls");
    printf("도서 반납 페이지");
}
void registerBook()
{
    system("cls");
    printf("도서 등록 페이지");
}
void searchBook()
{
    system("cls");
    printf("도서 검색 페이지");
}
void markBook()
{
    system("cls");
    printf("즐겨찾는 도서 페이지");
}
void calcAccount()
{
    system("cls");
    printf("연체 내역 페이지");
    printf("연체금액은 8시간당 100원, 대출 기간은 1주,1권당 부과됩니다.\n");
    late_fee();
}


int late_fee()
{
    const int fee = 100; 
    const int Period = 7; 

    int Latehours;
    int Bookcount;

    printf("7일은 168시간 입니다.\n");
    printf("168시간 이후 연체된 시간(시간 단위)을 입력하세요: ");
    scanf("%d", &Latehours);

    printf("대출한 책의 권수를 입력하세요: ");
    scanf("%d", &Bookcount);

    int total = (Latehours / 8) * fee * Bookcount; 

    printf("연체된 금액: %d 원\n", total);

    return 0;
}
