#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 1000

typedef struct {
    int day;
    int month;
    int year;
}Day;

typedef struct  {
    int bookId;
    char title[50];
    char author[50];
    int publishYear;
    int quantity;
}Book;
Book listBook[MAX];

 Book listBook[MAX]={{1,"To Kill a Mockingbird","Harper Lee",1960,3},
                  {2,"Pride and Prejudice","Jane Austen",1913,5},
                  {3,"The Great Gatsby","F. Scott Fitzgerald",1925,4},
                  {4,"One Hundred Years of Solitude","Gabriel Garcia Marquez",1967,1},
                  {5,"The Catcher in the Rye","J.D. Salinger",1951,7},
                  {6,"The Hobbit","J.R.R. Tolkien",1937,4},
                  {7,"The Alchemist","Paulo Coelho",1988,5},
                  {8,"Crime and Punishment","Fyodor Dostoevsky",1966,2},
                  {9,"The Old Man and the Sea","Ernest Hemingway",1952,1},
                  {10,"War and Peace","Leo Tolstoy",1969,6},
                  {11,"Brave New World","Aldous Huxley",1932,3},
                  {12,"The Lord of the Rings","J.R.R. Tolkien",1954,8},
                  {13,"Jane Eyre","Charlotte Bronte",1947,5},
                  {14,"Wuthering Heights","Emily Bronte",1947,3},
                  {15,"The Brothers Karamazov","Fyodor Dostoevsky",1980,1},
                  {16,"Les Miserables","Victor Hugo",1962,5},
                  {17,"Don Quixote","Miguel de Cervantes",1905,7},
                  {18,"Fahrenheit 451","Ray Bradbury",1953,2},
                  {19,"The Divine Comedy","Dante Alighieri",1999,8},
                  {20,"Anna Karenina","Leo Tolstoy",1977,2},
                  {21,"The Grapes of Wrath","John Steinbeck",1939,5},
                  {22,"The Odyssey","Homer",2000,1},
                  {23,"Moby-Dick","Herman Melville",1951,9},
                  {24,"Hamlet","William Shakespeare",2003,7},
                  {25,"The Iliad","Homer",1970,3},
                  {26,"Great Expectations","Charles Dickens",1961,2},
                  {27,"The Kite Runner","Khaled Hosseini",2003,1},
                  {28,"Life of Pi","Yann Martel",2001,5},
                  {29,"Beloved","Toni Morrison",1987,3},
                  {30,"Catch-22","Joseph Heller",1961,5},
                  {31,"Dracula","Bram Stoker",1997,6},
                  {32,"Frankenstein","Frankenstein",1918,1},
                  {33,"The Sound and the Fury","William Faulkner",1929,8},
                  {34,"Slaughterhouse-Five","Kurt Vonnegut",1969,6},
                  {35,"The Picture of Dorian Gray","Oscar Wilde",1990,2}
    };

typedef struct {
    int day;
    int month;
    int year;
}Date;

typedef struct {
    int borrowId;
    int bookId;
    Date borrowDate;
    Date borrowReturn;
    char borrowerName[50];
    int status;
}Borrow;
Borrow listBorrow[MAX];

Borrow listBorrow[MAX]={
{1,1,10,10,2024,11,11,2025,"Do Tien Nam",1},
{2,2,10,10,2024,11,11,2025,"Do Tien Nam",0},
{3,4,10,10,2024,11,11,2025,"Do Tien Nam",0},
{4,1,10,10,2024,11,11,2025,"Do Tien Nam",0},
{5,6,10,10,2024,11,11,2025,"Do Tien Nam",1},
{6,22,10,10,2024,11,11,2025,"Do Tien Nam",0},
{7,18,10,10,2024,11,11,2025,"Do Tien Nam",0},
{8,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
{9,36,10,10,2024,11,11,2025,"Do Tien Nam",1},
{10,6,10,10,2024,11,11,2025,"Do Tien Nam",0},
{11,22,10,10,2024,11,11,2025,"Do Tien Nam",0},
{12,18,10,10,2024,11,11,2025,"Do Tien Nam",1},
{13,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
{14,36,10,10,2024,11,11,2025,"Do Tien Nam",0},
{15,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
{16,1,10,10,2024,11,11,2025,"Do Tien Nam",0},
{17,2,10,10,2024,11,11,2025,"Do Tien Nam",1},
{18,4,10,10,2024,11,11,2025,"Do Tien Nam",1},
{19,1,10,10,2024,11,11,2025,"Do Tien Nam",0},
{20,6,10,10,2024,11,11,2025,"Do Tien Nam",1},
{21,22,10,10,2024,11,11,2025,"Do Tien Nam",0},
{22,18,10,10,2024,11,11,2025,"Do Tien Nam",0},
{23,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
{24,36,10,10,2024,11,11,2025,"Do Tien Nam",0},
{25,6,10,10,2024,11,11,2025,"Do Tien Nam",1},
{26,22,10,10,2024,11,11,2025,"Do Tien Nam",0},
{27,18,10,10,2024,11,11,2025,"Do Tien Nam",1},
{28,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
{29,36,10,10,2024,11,11,2025,"Do Tien Nam",1},
{30,14,10,10,2024,11,11,2025,"Do Tien Nam",0},
};

void addNewBook();
void updateBook();
void displayBook();
void deleteBook();
void searchBook();
void addNewBorrow();
void returnBorrow();
void displayBorrow();

int existedTitle(char title[]);
int existedId(int bookId);
int validateDay(int day, int month, int year);
int validateMonth(int month);
int validateYear(int year);
int existedIdBorrow(int bookId);
int checkReturnDateValid(Date returnDate, Date borrowDate);

int n_book=35;
int bookId=36;
int page=1;
int booksPerPage=10;
int borrowId=31;
int n_borrow = 30;

int main() {
    system("cls");
    int choice;

do {
    printf("\n");
    printf("\n|--------------MENU---------------|\n");
    printf("|1.Them moi sach                  |\n");
    printf("|2.Cap nhat thong tin sach        |\n");
    printf("|3.Hien thi danh sach sach        |\n");
    printf("|4.Xoa thong tin sach             |\n");
    printf("|5.Tim kiem sach                  |\n");
    printf("|6.Them moi phieu muon            |\n");
    printf("|7.Tra sach                       |\n");
    printf("|8.Hien thi danh sach phieu muon  |\n");
    printf("|9.Thoat                          |\n");
    printf("|---------------------------------|\n");
    printf("\n");
    int lastCharChoice=0;

    do {
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        lastCharChoice=getchar();
        fflush(stdin);
        if (lastCharChoice!='\n') {
            printf("Moi ban nhap lai lua chon!!!\n");
        }
    }while(lastCharChoice!='\n');

    switch(choice) {
        case 1:
            system("cls");
            addNewBook();
            printf("\n");
            printf("Nhap enter de tiep tuc!!!");
            getchar();
            break;
        case 2:
            system("cls");
            updateBook();
            printf("\n");
            printf("Nhap enter de tiep tuc!!!");
            getchar();
            break;
        case 3:
            system("cls");
            displayBook();
            break;
        case 4:
            system("cls");
            deleteBook();
            break;
        case 5:
            system("cls");
            searchBook();
            printf("\n");
            printf("Nhap enter de tiep tuc!!!");
            getchar();
            break;
        case 6:
            system("cls");
            addNewBorrow();
            printf("\n");
            printf("Nhap enter de tiep tuc!!!");
            getchar();
            break;
        case 7:
            system("cls");
            returnBorrow();
            printf("\n");
            printf("Nhap enter de tiep tuc!!!");
            getchar();
            break;
        case 8:
            system("cls");
            displayBorrow();
            break;
        case 9:
            printf("Cam on vi da su dung!!!");
            exit(0);

    }
}while(1);
}

void addNewBook() {
    if (n_borrow==MAX) {
        printf("Kho sach da day!!!");
        printf("\nMoi ban xoa sach truoc khi them!!!!");
        return;
    }

    printf("\n Ma so sach: %d\n",bookId);
    Book b;
    do {
        printf("Nhap tieu de sach: ");
        gets(b.title);
        if (strlen(b.title)==0 || strcasecmp(b.title," ")==0) {
            printf("Tieu de khong duoc de trong!!!\n");
            printf("Them sach that bai\n");
        }else {
            if (existedTitle(b.title)==0) {
                printf("Tieu de khong dc trung\n");
                printf("Them sach that bai\n");
            }
        }
    }while (strlen(b.title)==0 || strcasecmp(b.title," ")==0 || existedTitle(b.title)==0);

    int statusY=0;
    char lastCharY=0;
    do {
        printf("Nhap nam phat hanh: ");
        statusY= scanf("%d",&b.publishYear);
        lastCharY= getchar();
        fflush(stdin);
        if (b.publishYear<1900 || b.publishYear > 2025) {
            printf("Nam khong hop le!!!\n");
            printf("Them sach that bai\n");
        }else {
            if (statusY == 0 || lastCharY != '\n') {
                printf("Nhap so nguyen cua nam!!!\n");
                printf("Them sach that bai\n");
            }
        }
    }while (b.publishYear<1900 || b.publishYear > 2025 || statusY == 0 || lastCharY != '\n');

    do {
        printf("Nhap ten tac gia: ");
        gets(b.author);
        if (strlen(b.author)==0 || strcasecmp(b.author," ")==0) {
            printf("Tac gia khong duoc de trong!!!\n");
            printf("Them sach that bai\n");
        }
    }while (strlen(b.author)==0 || strcasecmp(b.author," ")==0);

    int statusQ;
    char lastCharQ;
    do {
        printf("Nhap so luong sach: ");
        statusQ = scanf("%d", &b.quantity);
        lastCharQ = getchar();
        fflush(stdin);
        if (b.quantity<0 || b.quantity > MAX) {
            printf("So sach khong hop le!!!\n");
            printf("Them sach that bai\n");
        }else {
            if (statusQ == 0 || lastCharQ != '\n') {
                printf("Nhap so nguyen cua sach!!!\n");
                printf("Them sach that bai\n");
            }
        }
    }while (statusQ == 0 || lastCharQ != '\n' || b.quantity < 0 || b.quantity > MAX);

    printf("Da them sach thanh cong\n");
    b.bookId=bookId;
    listBook[n_book]=b;
    n_book++;
    bookId++;
}

void updateBook() {
    int updateId;
    int index=-1;
    Book b;
    if (n_book==0) {
        printf("So sach trong\n");
        printf("Moi ban nhap them sach!!!\n");
        return ;
    }
    int statusI=0;
    int lastcharI=0;
    do {
        printf("Nhap ma so sach ban can cap nhat: ");
        statusI= scanf("%d", &updateId);
        lastcharI= getchar();
        fflush(stdin);
        if (existedId(updateId)==1) {
            printf("Khong ton tai ma so sach trong kho\n");
        }else {
            if (statusI == 0 || lastcharI != '\n') {
                printf("Nhap ma so sach that bai\n");
            }
        }
    }while (existedId(updateId)==1 || statusI == 0 || lastcharI != '\n');

    for (int i=0;i<n_book;i++) {
        if (listBook[i].bookId==updateId) {
            index=i;
        b.bookId = listBook[index].bookId;
        printf("Ma so sach %d\n",updateId);
        printf("Ten sach ban dau: %s\n",listBook[index].title);
        printf("Nam phat hanh ban dau: %d\n",listBook[index].publishYear);
        printf("Tac gia ban dau: %s\n",listBook[index].author);
        printf("So luong sach ban dau: %d\n",listBook[index].quantity);
        printf("\n");

        do {
            printf("Nhap tieu de sach: ");
            gets(b.title);
            if (strlen(b.title)==0 || strcasecmp(b.title," ")==0) {
                printf("Tieu de khong duoc de trong!!!\n");
                printf("Cap nhat sach that bai\n");
                return;
            }
        for (int i=0;i<n_book;i++) {
                if (strcasecmp(b.title,listBook[i].title)==0 && listBook[i].bookId != updateId) {
                    printf("Tieu de khong dc trung\n");
                    printf("Cap nhat sach that bai\n");

                }
            }
        }while (strlen(b.title)==0 || strcasecmp(b.title," ")==0 || (strcasecmp(b.title,listBook[i].title)==0 && b.bookId!=updateId));

        int statusY=0;
        char lastCharY=0;
        do {
            printf("Nhap nam phat hanh moi: ");
            statusY= scanf("%d",&b.publishYear);
            lastCharY= getchar();
            fflush(stdin);
            if (b.publishYear<1900 || b.publishYear > 2025) {
                printf("Nam khong hop le!!!\n");
                printf("Them sach that bai\n");
            }else {
                if (statusY == 0 || lastCharY != '\n') {
                    printf("Nhap so nguyen cua nam!!!\n");
                    printf("Cap nhat sach that bai\n");
                }
            }
        }while (b.publishYear<1900 || b.publishYear > 2025 || statusY == 0 || lastCharY != '\n');

        do {
            printf("Nhap ten tac gia moi: ");
            gets(b.author);
            if (strlen(b.author)==0 || strcasecmp(b.author," ")==0) {
                printf("Tac gia khong duoc de trong!!!\n");
                printf("Cap nhat sach that bai\n");
            }
        }while (strlen(b.author)==0 || strcasecmp(b.author," ")==0);

        int statusQ=0;
        char lastCharQ=0;
        do {
            printf("Nhap so luong sach moi:");
            statusQ = scanf("%d", &b.quantity);
            lastCharQ = getchar();
            fflush(stdin);
            if (b.quantity<0 || b.quantity > MAX) {
                printf("So sach khong hop le!!!\n");
                printf("Cap nhat sach that bai\n");
            }else {
                if (statusQ == 0 || lastCharQ != '\n') {
                    printf("Nhap so nguyen cua sach!!!\n");
                    printf("Cap nhat sach that bai\n");
                }
            }
        }while (statusQ == 0 || lastCharQ != '\n' || b.quantity < 0 || b.quantity > MAX);

        printf("Da cap nhat sach thanh cong\n");
        listBook[index]=b;
        }
    }
}

    void displayBook() {
    if (n_book==0) {
        printf("So sach trong\n");
        printf("Moi ban nhap them sach!!!\n");
        return ;
    }
    int noBack=1;
    int choicePage;
    int totalPages = n_book/booksPerPage + (n_book%booksPerPage==0?0:1);
    while (noBack) {
        printf("Tong so trang %d, trang danh sach thu %d\n",totalPages,page);
        for(int i=1;i<=116;i++){
            printf("-");
        }
        printf("\n|%-15s|%-35s|%-15s|%-25s|%-20s|\n","Ma so sach","Tieu de sach","Nam phat hanh","Tac gia","So luong");
        for(int i=1;i<=116;i++){
            printf("-");
        }
        for(int i= (page-1)*booksPerPage;i<page*booksPerPage;i++){
            Book b = listBook[i];
            if(i<n_book){
                printf("\n|%-15d|%-35s|%-15d|%-25s|%-20d|\n",b.bookId,b.title,b.publishYear,b.author,b.quantity);
                for(int i=1;i<=116;i++){
                    printf("-");
                }
            }
        }
        int continueDisplay = 1;
        while(continueDisplay) {
            printf("\nNhap 1 de quay lai trang truoc\n");
            printf("nhap 2 de thoat\n");
            printf("nhap 3 de sang trang tiep theo\n");
            printf("nhap lua chon: ");
            scanf("%d",&choicePage);
            switch(choicePage) {
                case 1:
                    system("cls");
                    if (page==1) {
                        break;
                    }else{
                        page--;
                    }
                    continueDisplay = 0;
                    printf("\n");
                    printf("Nhap enter de tiep tuc!!!");
                    getchar();
                    break;
                case 2:
                    system("cls");
                    noBack=0;
                    continueDisplay = 0;
                    printf("\n");
                    printf("Nhap enter de tiep tuc!!!");
                    getchar();
                    break;
                case 3:
                    system("cls");
                    if (page==totalPages) {
                        break;
                    }else {
                        page++;
                    }
                    continueDisplay = 0;
                    printf("\n");
                    printf("Nhap enter de tiep tuc!!!");
                    getchar();
                    break;
                default:
                    printf("Loi! Moi ban nhap tu 1-3!!\n");
                    printf("\n");
            }
        }
    }
}

void deleteBook() {
    int statusI=0;
    int lastcharI=0;
    int deleteId;
    if (n_book==0) {
        printf("So sach trong\n");
        printf("Moi ban nhap them sach!!!\n");
        return ;
    }

    do {
        printf("Nhap ma so sach ban can xoa: ");
        statusI= scanf("%d", &deleteId);
        lastcharI= getchar();
        fflush(stdin);
        if (existedId(deleteId)==1) {
            printf("Khong ton tai ma so sach trong kho\n");
        }else {
            if (statusI == 0 || lastcharI != '\n') {
                printf("Nhap ma so sach that bai\n");
            }
        }
    }while (existedId(deleteId)==1 || statusI == 0 || lastcharI != '\n');
    for (int i=0;i<n_book;i++) {
        if (deleteId==listBook[i].bookId) {
            printf("\n|%-15s|%-30s|%-15s|%-20s|%-20s|\n","Ma so sach","Tieu de sach","Nam phat hanh","tac gia","So luong");
            for(int j=1;j<=106;j++){
                printf("-");
            }
            printf("\n|%-15d|%-30s|%-15d|%-20s|%-20d|\n",listBook[i].bookId,listBook[i].title,listBook[i].publishYear,listBook[i].author,listBook[i].quantity);
            for(int j=1;j<=106;j++){
                printf("-");
            }
        }
    }
    for (int i=0;i<n_borrow;i++) {
        if (listBorrow[i].bookId == deleteId && listBorrow[i].status == 1) {
            printf("\nSach dang duoc muon khong the xoa!!!");
            printf("\n");
            printf("\nNhap enter de tiep tuc!!!");
            getchar();
            return;
        }
    }
    char confirm;
    printf("\nBan co chac muon xoa khong?(y/n) ");
    fflush(stdin);
    scanf("%c",&confirm);
    if (confirm=='y' || confirm=='Y') {
        for (int i=0; i<n_book; i++) {
            if (listBook[i].bookId==deleteId) {
                for (int j=i;j<n_book-1;j++) {
                    listBook[j]=listBook[j+1];
                }
                n_book--;
                printf("Da xoa sach thanh cong!!!\n");

                break;
            }
        }
    }else if (confirm=='n' || confirm=='N') {
        return;
    }else {
        printf("Nhap sai!!!\n");
    }
}

void searchBook() {
    char bookSearch[20];
    if (n_book==0) {
        printf("Kho sach trong\n");
        printf("Moi ban nhap nhap them sach!!!\n");
        return;
    }
    printf("\nNhap ten sach can tim kiem: ");
    gets(bookSearch);
    for (int i=0;i<strlen(bookSearch);i++) {
        bookSearch[i]=toupper(bookSearch[i]);
    }
    char temp[50];
    if (strlen(bookSearch)==0 || strcmp(bookSearch," ")==0) {
        printf("Ten tim kiem khong duoc de trong!!!\n");
    }
    printf("\n");
    printf("Ket qua tim kiem:\n");
    int check=0;
    for (int i=0;i<n_book;i++) {
        strcpy(temp,listBook[i].title);
        for (int j=0;j<strlen(temp);j++) {
            temp[j]=toupper(temp[j]);
        }
        if (strstr(temp,bookSearch)!=NULL) {
            check=1;
        }
        if (check==1) {
            printf("\n|%-15s|%-30s|%-15s|%-20s|%-20s|\n","Ma so sach","Tieu de sach","Nam phat hanh","tac gia","So luong");
            for(int j=1;j<=106;j++) {
                printf("-");
            }
            printf("\n|%-15d|%-30s|%-15d|%-20s|%-20d|\n",listBook[i].bookId,listBook[i].title,listBook[i].publishYear,listBook[i].author,listBook[i].quantity);
            for(int j=1;j<=106;j++){
                printf("-");
            }
           printf("\n\n");
        }
    }
    if (check==0) {
        for (int i=0;i<strlen(bookSearch);i++) {
            bookSearch[i]=tolower(bookSearch[i]);
        }
        printf("\n");
        printf("Khong tim thay %s trong danh sach!\n",bookSearch);
    }
}

  void addNewBorrow() {
    int check=0;
    int bookIdR=0;
    if (n_book==0) {
        printf("Moi ban nhap them sach!!!\n");
        return;
    }
        int lastcharB=0;
        int statusB=0;
        Borrow b;
        do {
            printf("Nhap ma so sach can muon: ");
            statusB= scanf("%d",&bookIdR);
            lastcharB=getchar();
            fflush(stdin);
            if (statusB==0 || lastcharB != '\n') {
                printf("Nhap ma so sach that bai!!!\n");
            }
        }while (lastcharB!='\n' || statusB==0);

        for (int i=0;i<n_book;i++) {
        if (bookIdR==listBook[i].bookId) {
            printf("\n|%-15s|%-30s|%-15s|%-20s|%-20s|\n","Ma so sach","Tieu de sach","Nam phat hanh","tac gia","So luong");
            for(int j=1;j<=106;j++){
                printf("-");
            }
            printf("\n|%-15d|%-30s|%-15d|%-20s|%-20d|\n",listBook[i].bookId,listBook[i].title,listBook[i].publishYear,listBook[i].author,listBook[i].quantity);
            for(int j=1;j<=106;j++){
                printf("-");
            }
            if (listBook[i].quantity==0) {
                printf("\nDa het sach trong thu vien.");
                return;
            }
            char confirm;
            int flag=1;

            do {
                printf("\nBan co muon muon sach tren khong(c/k)? ");
                scanf("%c",&confirm);
                fflush(stdin);
                if (confirm=='c' || confirm=='C') {
                    b.borrowId = borrowId;
                    b.bookId = listBook[i].bookId;

                    do{
                        printf("Nhap ngay muon: ");
                        scanf("%d",&b.borrowDate.day);
                        printf("Nhap thang: ");
                        scanf("%d",&b.borrowDate.month);
                        printf("Nhap nam: ");
                        scanf("%d",&b.borrowDate.year);
                        fflush(stdin);
                        if(!validateDay(b.borrowDate.day,b.borrowDate.month,b.borrowDate.year) || !validateMonth(b.borrowDate.month) || !validateYear(b.borrowDate.year)){
                            printf("Ngay thang nam muon khong hop le!\n");
                        }
                    }while(!validateDay(b.borrowDate.day,b.borrowDate.month,b.borrowDate.year) || !validateMonth(b.borrowDate.month) || !validateYear(b.borrowDate.year));

                    do {
                        printf("\nNhap ten nguoi muon: ");
                        gets(b.borrowerName);
                        if (strlen(b.borrowerName)==0 || strcmp(b.borrowerName,"")==0) {
                            printf("Ten khong duoc de trong!!!!\n");
                        }
                    }while (strlen(b.borrowerName)==0 || strcmp(b.borrowerName,"")==0);

                    printf("\n");
                    printf("*** Muon sach thanh cong ***");
                    printf("\nDa lay ra khoi thu vien");
                    listBook[i].quantity--;
                    b.status=1;
                    listBorrow[n_borrow]=b;
                    bookId++;
                    n_borrow++;
                    check=1;
                    flag=0;
                }else if (confirm== 'k' || confirm=='K') {
                    return;
                }else {
                    printf("Nhap sai!!\n");
                }
            }while (flag==1);
        }
    }
    if (check==0){
        printf("Ma so sach khong ton tai\n");
    }
}

void returnBorrow() {
    int returnBookId;
    int statusR = 0;
    int lastcharR = 0;
    int found = 0;
    int borrowIndex = -1;
    if (n_borrow == 0) {
        printf("Chua co sach muon\n");
        return;
    }

    do {
        printf("Nhap ma phieu muon can tra: ");
        statusR = scanf("%d", &returnBookId);
        lastcharR = getchar();
        fflush(stdin);
        if (statusR == 0 || lastcharR != '\n') {
            printf("Nhap so nguyen cho ma so sach!!!\n");
        }
    } while (statusR == 0 || lastcharR != '\n');

    for (int i = 0; i < n_borrow; i++) {
        if (listBorrow[i].borrowId == returnBookId && listBorrow[i].status == 1) {
            borrowIndex = i;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Khong tim thay phieu muon hoac sach da duoc tra!!!\n");
        return;
    }
    printf("\n=== THONG TIN PHIEU MUON ===\n");
    printf("Ma phieu muon: %d\n", borrowIndex + 1);
    printf("Ma so sach: %d\n", listBorrow[borrowIndex].bookId);
    printf("Ten nguoi muon: %s\n", listBorrow[borrowIndex].borrowerName);
    printf("Ngay muon: %d/%d/%d\n",listBorrow[borrowIndex].borrowDate.day,listBorrow[borrowIndex].borrowDate.month,listBorrow[borrowIndex].borrowDate.year);
    int bookIndex = -1;
    for (int i = 0; i < n_book; i++) {
        if (listBook[i].bookId == returnBookId) {
            bookIndex = i;
            break;
        }
    }
    if (bookIndex != -1) {
        printf("Ten sach: %s\n", listBook[bookIndex].title);
        printf("Tac gia: %s\n", listBook[bookIndex].author);
    }
    Date returnDate;
    int validReturn = 0;

    do {
        printf("\n--- NHAP NGAY TRA ---\n");
        printf("Nhap ngay: ");
        scanf("%d", &returnDate.day);
        printf("Nhap thang: ");
        scanf("%d", &returnDate.month);
        printf("Nhap nam: ");
        scanf("%d", &returnDate.year);
        fflush(stdin);
        if (!validateDay(returnDate.day, returnDate.month, returnDate.year) || !validateMonth(returnDate.month) || !validateYear(returnDate.year)) {
            printf("Ngay thang nam tra khong hop le!\n");
            continue;
        }
        if (returnDate.year < listBorrow[borrowIndex].borrowDate.year ||
            (returnDate.year == listBorrow[borrowIndex].borrowDate.year &&
             returnDate.month < listBorrow[borrowIndex].borrowDate.month) ||
            (returnDate.year == listBorrow[borrowIndex].borrowDate.year &&
             returnDate.month == listBorrow[borrowIndex].borrowDate.month &&
             returnDate.day < listBorrow[borrowIndex].borrowDate.day)) {
            printf("Ngay tra khong the truoc ngay muon!\n");
            printf("Ngay muon: %02d/%02d/%d\n",listBorrow[borrowIndex].borrowDate.day,listBorrow[borrowIndex].borrowDate.month,listBorrow[borrowIndex].borrowDate.year);
            continue;
        }
        validReturn = 1;
    } while (!validReturn);


    char confirm;
    int validConfirm = 0;

    do {

        printf("\nXac nhan tra sach? (c/k): ");
        scanf("%c", &confirm);
        fflush(stdin);
        if (confirm == 'c' || confirm == 'C') {
            listBorrow[borrowIndex].borrowReturn = returnDate;
            listBorrow[borrowIndex].status = 0;
            if (bookIndex != -1) {
                listBook[bookIndex].quantity++;
            }
            printf("\n*** Tra sach thanh cong ***\n");
            printf("Da cap nhat lai so luong sach trong kho.\n");
            validConfirm = 1;
        } else if (confirm == 'k' || confirm == 'K') {
            printf("Da huy tra sach.\n");
            validConfirm = 1;
        } else {
            printf("Nhap sai! Vui long nhap y hoac n.\n");
        }
    } while (!validConfirm);
}

void displayBorrow() {
    if (n_borrow==0) {
        printf("Chua co ai muon sach ca!!!");
        return;
    }
    int noBack=1;
    int choice;
    int totalPagesR = n_borrow/booksPerPage + (n_borrow%booksPerPage==0?0:1);
    char returnDateStr[20];
    char statusStr[20];
    char borrowDateStr[20];

    while (noBack) {
        printf("Tong so trang %d, trang danh sach thu %d\n",totalPagesR,page);
        for(int i=1;i<=127;i++){
            printf("-");
        }
        printf("\n|%-12s|%-12s|%-35s|%-20s|%-15s|%-15s|%-11s|\n","Ma so muon","Ma so sach","Ten sach","Nguoi muon","Ngay muon","Ngay tra","Tinh trang");
        for(int i=1;i<=127;i++){
            printf("-");
        }
        for(int i= (page-1)*booksPerPage;i<page*booksPerPage;i++){
            char currentBookTitle[30];
            Borrow b = listBorrow[i];
            for(int j = 0; j < n_book; j++) {
                if(listBook[j].bookId == b.bookId) {
                    strcpy(currentBookTitle, listBook[j].title);
                    break;
                }
            }
           sprintf(borrowDateStr, "%02d/%02d/%04d", b.borrowDate.day, b.borrowDate.month, b.borrowDate.year);
                        if (b.status == 1) {
                            strcpy(statusStr, "Dang muon");
                            strcpy(returnDateStr, "----------");
                        } else {
                            strcpy(statusStr, "Da tra");
                            sprintf(returnDateStr, "%02d/%02d/%04d", b.borrowReturn.day, b.borrowReturn.month, b.borrowReturn.year);
                        }
            if(i<n_borrow){
                printf("\n|%-12d|%-12d|%-35s|%-20s|%-15s|%-15s|%-11s|\n",b.borrowId,b.bookId,currentBookTitle,b.borrowerName,borrowDateStr,returnDateStr,statusStr);
                for(int i=1;i<=127;i++){
                    printf("-");
                }
            }
        }
        int continueDisplay = 1;
        while(continueDisplay) {

            printf("\nNhap 1 de quay lai trang truoc\n");
            printf("nhap 2 de thoat\n");
            printf("nhap 3 de sang trang tiep theo\n");
            printf("nhap lua chon: ");
            scanf("%d",&choice);
            switch(choice) {
                case 1:
                    system("cls");
                    if (page==1) {
                        break;
                    }else{
                        page--;
                    }
                    continueDisplay = 0;
                    printf("\n");
                    printf("Nhap enter de tiep tuc!!!");
                    getchar();
                    break;
                case 2:
                    noBack=0;
                    continueDisplay = 0;
                    break;
                case 3:
                    system("cls");
                    if (page==totalPagesR) {
                        break;
                    }else {
                        page++;
                    }
                    continueDisplay = 0;
                    printf("\n");
                    printf("Nhap enter de tiep tuc!!!");
                    getchar();
                    break;
                default:
                    printf("Loi! Moi ban nhap tu 1-3!!\n");
                    printf("\n");
            }
        }
    }
}

int existedTitle(char title[]) {
    for (int i = 0; i < n_book; i++) {
        if (strcasecmp(listBook[i].title, title)==0) {
            return 0;
        }
    }
    return 1;
}

int existedId(int bookId) {
    for (int i = 0; i < n_book; i++) {
        if (listBook[i].bookId==bookId) {
            return 0;
        }
    }
    return 1;
}

int validateDay(int day, int month, int year){
    if(day<1){
        return 0;
    }
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        if(day>31){
            return 0;
        }
    }
    if(month==4 || month==6 || month==9 || month==11){
        if(day>30){
            return 0;
        }
    }
    if(month==2){
        if(year%4==0 || (year%400 == 0 && year%100 != 0)) {
            if(day>29){
                return 0;
            }
        }else{
            if(day>28){
                return 0;
            }
        }
    }
    return 1;
}

int validateMonth(int month){
    if(month<1 || month>12){
        return 0;
    }
    return 1;
}

int validateYear(int year){
    if(year<1900 || year>2025){
        return 0;
    }
    return 1;
}

int existedIdBorrow(int bookId) {
    for (int i = 0; i < n_borrow; i++) {
        if (listBorrow[i].bookId==bookId) {
            return 0;
        }
    }
    return 1;
}

int checkReturnDateValid( Date borrowDate, Date borrowReturn) {
    if (borrowReturn.year < borrowDate.year) {
        return 0;
    }
    if (borrowReturn.year > borrowDate.year) {
        return 1;
    }
    if (borrowReturn.month < borrowDate.month) {
        return 0;
    }
    if (borrowReturn.month > borrowDate.month) {
        return 1;
    }
    if (borrowReturn.day < borrowDate.day) {
        return 0;
    }
    return 1;
}
