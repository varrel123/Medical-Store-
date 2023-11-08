#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<omp.h>

void ventry(char t[],int code); //fungsi untuk error handling
void gotoxy(int x, int y); //fungsi untuk menentukan titik 
void main_box(); //fungsi untuk membuat box besar
void main_menu(); // fungsi main menu
void box1(); // fungsi untuk menentukan box kecil diatas box besar
void lbox(); // kotak dalam medicine
int t(void); // fungsi untuk menentukan date dan waktu
void box(); // box dalam report yang lebih tebal
void wbox(); // box di display welcome
void about_name(); // menginput nama untuk display about

/*============================ SUPPLIER ============================*/

void supplier();
void insert_sup(char* sup_id,char* sup_name,char* sup_city,char* sup_no,char* sup_email); //memasukkan node baru
void display_sup();
void search_sup(char* sup_id);
void update_sup(char* sup_id);

/*============================ CUSTOMER ============================*/
void customer();
void insert_cus(char* cust_id,char* cust_name,char* city,char* mob_no,char* email); //memasukkan node baru
void display_cus();
void search_cus(char* cust_id);
void update_cus(char* cust_id);
void report_menu();
void bill();
/*============================ MEDICINE ============================*/
void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();

/*============================ STRUCTURES ============================*/

struct medical
{
    char id[6];
    char medi_name[20];
    int rack;
    char cabnit[2];
    int quantity;
    float sale;
    float total;
    float unit;
    float cost;
    float profit;
    float bye;
    int qty;
    char pur_date[15];
    char exp_date[15];
    char manu_date[15];
    int bill_no;
    char comp_name[20];
    char supp_name[30];
};

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];

struct bill
{
    char billno[6];
    char cname[30];
    char mediname[30];
    int medi_qty;
    float medi_rate;
    float total;
    int day;
    int month;
    int year;
};
struct bill bil;


struct sales_report
{
    char medi_id[6];
    char medir_name[20];
    char cust_name[30];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct purchase_report
{
    char medi_id[6];
    char medir_name[20];
    char supp_name[30];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
    char medi_id[6];
    char medir_name[20];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float unit;
    float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;


struct customer
{
    char cust_id[20];
    char cust_name[30];
    char city[20];
    char mob_no[11];
    char email[50];
    struct cus *next;
}* head1;
FILE*fptr;

struct supplier
{
    char sup_id[20];
    char sup_name[30];
    char sup_city[20];
    char sup_no[11];
    char sup_email[50];
    struct sup *next;
}* head2;

int main()
{
#pragma omp parallel
    {
#pragma omp single
        {
            main_menu(); // memanggil main_menu
        }
    }
}


void wbox()
{
	int i;
	for(i=5;i<=75;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,5);    //the 75th column is reached.
		printf("%c",219);
		gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)      //This 'FOR' loop will print asteriks 'I'
	{                       //vertically till the 17th row is reached.
		gotoxy(5,i);
		printf("%c",219);
		gotoxy(75,i);
		printf("%c",219);
	}
}

void main_menu()
{
    char num;
    
    do
    {
        system("cls");
        printf("  Anggota Kelompok 16 :\n");
        printf("  Mohammad varrel bramasta\t2106733811\n");
        printf("  Rakha Argya Zahran\t\t2106733925\n");
        printf("\n");
        gotoxy(3,8); // berfungsi sebagai menetukan printf 1.S mau di letakan di titik mana
        printf("1.Supplier Info");

        gotoxy(3,11);
        printf("2.Customer Info");

        gotoxy(3,14);
        printf("3.Medicine");

        gotoxy(3,17);
        printf("4.Report");

        gotoxy(3,20);
        printf("5.Bill");

        gotoxy(3,23);
        printf("6.About");

        gotoxy(3,26);
        printf("7.Exit");

        t();   //memanggil fungsi tanggal dan jam
        box1(); // box kecil diatas box besar
        main_box(); // box besar
        gotoxy(27,5);
        printf("Welcome To Medical Store ");
        gotoxy(2,28);

        gotoxy(10,40);
        printf("Press ");
        gotoxy(16,40);
        printf("Number for further Menu  ");
        num=toupper(getche()); // menginput num tanpa harus tekan enter
        switch(num)
        {
            case '1':
                supplier();
                break;
            case '2':
                customer();
                break;
            case '3':
                medicine();
                break;
            case '4':
                report_menu();
                break;
            case '5':
                bill();
                break;
            case '6':
                about_name();
                break;
            case '7':
                exit(0);

            default:
                gotoxy(11,34);
                printf("Plese Enter right character ONLY (1,2,3,4,5,6,7).");
                scanf("%d",&num);
                break;
        }
    }while(num!='7');
}

// FUNC UNTUK MENEMPATKAN CURSOR
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // menentukan posisi cursor
}
// FUNC BOX
void main_box()
{
	
    gotoxy(1,6);
    printf("%c",201);
    int i;
    #pragma omp parallel for
    for(i=1;i<79;i++)
    {
        gotoxy(1+i,6);
        printf("%c",205);
    }

    gotoxy(80,6);
    printf("%c",187);
    gotoxy(1,6);
    #pragma omp parallel for
    for(i=5;i<35;i++)
    {
        gotoxy(1,2+i);
        printf("%c",186);
    }
    gotoxy(1,37);
    printf("%c",200);
    #pragma omp parallel for
    for(i=1;i<79;i++)
    {
        gotoxy(1+i,37);
        printf("%c",205);
    }
    gotoxy(80,37);
    printf("%c",188);
    gotoxy(80,6);
    #pragma omp parallel for
    for(i=5;i<35;i++)
    {
        gotoxy(80,2+i);
        printf("%c",186);
    }
}

void lbox()
{
    gotoxy(25,6);
    printf("%c",201);
    int i;
    for(i=26;i<55;i++)
    {
        gotoxy(i,6);
        printf("%c",205);
    }
    gotoxy(55,6);
    printf("%c",187);
    gotoxy(25,6);
    for(i=6;i<8;i++)
    {
        gotoxy(25,i+1);
        printf("%c",186);
    }
    gotoxy(25,9);
    printf("%c",200);
    for(i=26;i<55;i++)
    {
        gotoxy(i,9);
        printf("%c",205);
    }
    gotoxy(55,9);
    printf("%c",188);
    gotoxy(55,6);
    for(i=6;i<8;i++)
    {
        gotoxy(55,i+1);
        printf("%c",186);
    }

}
//============================small box ===============
void box1()
{
    gotoxy(1,3);
    printf("%c",201);
    int i;
    for(i=1;i<79;i++)
    {
        gotoxy(1+i,3);
        printf("%c",205);
    }

    gotoxy(80,3);
    printf("%c",187);
    gotoxy(1,3);
    for(i=4;i<10;i++)
    {
        gotoxy(1,i);
        printf("%c",186);
    }
    gotoxy(1,9);
    for(i=4;i<8;i++)
    {
        gotoxy(80,i);
        printf("%c",186);
    }
}


//============================ TIME    ===================
int t(void)
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    gotoxy(55,46);
    printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon+1,now->tm_year+1900);
    gotoxy(55,48);
    printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
    return 0;
}

//============================ MENU CUSTOMER    ===================
void customer()
{
    system("cls");
    fptr=fopen("customer.txt","w"); // membuka text Customer untuk di isi data customer
    if (fptr == NULL)
    {
        printf("Could not open file");
    }

    int i;
    char pilihan;
    head1 = NULL;

    char id[128];
    char name[7];
    char kota[20];
    char no[32];
    char mail[20];

    char searching[100];

    do
    {
        box1();
        main_box();
        gotoxy(32,4);
        printf("Customer\n");
        gotoxy(3,8);
        printf("1.untuk memasukkan data Customer\n");
        gotoxy(3,11);
        printf("2.untuk menampilkan data Customer\n");
        gotoxy(3,14);
        printf("3.untuk mencari data Customer\n");
        gotoxy(3,17);
        printf("4.untuk update data Customer\n");
        gotoxy(3,20);
        printf("5.untuk kembali ke main menu\n");
        gotoxy(30,37);
        printf("\n  Pilih berdasarkan nomor urut : ");
        pilihan=toupper(getche());
        switch(pilihan){
            case '1':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Memasukan Data Customer\n");
                gotoxy(3,8);
                printf("Masukkan nama Customer       : ");
                gets(name);


                gotoxy(3,11);
                printf("Masukkan ID Customer         : ");
                gets(id);


                gotoxy(3,14);
                printf("Masukkan Kota Customer       : ");
                gets(kota);


                gotoxy(3,17);
                printf("Jenis Nomor HP Customer      : ");
                gets(no);


                gotoxy(3,20);
                printf("Jenis Email Customer         : ");
                gets(mail);
                fprintf(fptr,"%s %s %s %s %s %s \n",name, id, kota, no, mail);
                
                insert_cus(id,name,kota,no,mail);
                
                break;
            case '2':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Menampilkan Data Customer\n");
                display_cus();
                break;
            case '3':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Mencari data Customer\n");
                gotoxy(3,8);
                printf("Masukan ID Customer yang akan dicari : ");
                gets(searching);
                search_cus(searching);
                break;
            case '4':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Update data Customer\n");
                gotoxy(3,8);
                printf("Masukan ID Customer yang akan di update : ");
                gets(searching);
                update_cus(searching);
                break;
            case '5':
            	main_menu();
            	break;
        }
    }while(pilihan!='0');
}

void insert_cus(char* cust_id,char* cust_name,char* city,char* mob_no,char* email)
{
    //inisialisasi size node
    struct customer * data = (struct customer *) malloc(sizeof(struct customer));
    strcpy(data->cust_id, cust_id); //mengisi data
    strcpy(data->cust_name, cust_name);
    strcpy(data->city, city);
    strcpy(data->mob_no, mob_no);
    strcpy(data->email, email);

    data->next = NULL;

    if(head1==NULL){
        head1 = data; //mengisi head dengan data
    }
    else{
        data->next = (struct cus *) head1;
        head1 = data;
    }

    gotoxy(3,25);
    printf("Enter untuk lanjut");
    getch();
    system("cls");
}

void display_cus()
{
    struct customer * temp = head1;

    while(temp!=NULL){ // mendisplay 

        printf("\n   Nama             : %s\n", temp->cust_name);
        printf("  ID               : %s\n", temp->cust_id);
        printf("  Kota             : %s\n", temp->city);
        printf("  No HP            : %s\n", temp->mob_no);
        printf("  Email            : %s\n\n", temp->email);
        printf("----------------------------------------------\n");
        temp = (struct customer *) temp->next;

    }
    gotoxy(3,25);
    printf("     Enter untuk lanjut");
    getch();
    system("cls");
}

void search_cus(char* cust_id)
{
    int found=0;
    struct customer * temp = head1;
    while(temp!=NULL){
        //jika fungsi searching yg ada di menu customer sama dengan cust id yg ada akan
        //mengprint data yg dicari
        if(strstr(temp->cust_id, cust_id)!=NULL){
            gotoxy(3,11);
            printf("ID ditemukan\n");
            gotoxy(3,15);
            printf("Nama customer            : %s\n", temp->cust_name);
            gotoxy(3,18);
            printf("ID customer              : %s\n", temp->cust_id);
            gotoxy(3,21);
            printf("Kota customer            : %s\n", temp->city);
            gotoxy(3,24);
            printf("No HP customer           : %s\n", temp->mob_no);
            gotoxy(3,27);
            printf("Email customer           : %s\n\n", temp->email);
            found=1;
        }
        temp = (struct customer *) temp->next;
    }
    if(found==0){
        printf("Data dengan ID %s tidak ditemukan !!!\n", cust_id);
    }

    printf("       Enter untuk lanjut");
    getch();
    system("cls");
}

void update_cus(char* cust_id)
{
    char id[128];
    char name[7];
    char kota[20];
    char no[32];
    char mail[20];

    fptr=fopen("customer.txt","w");
    if (fptr == NULL)
    {
        printf("Could not open file");
    }

    int i;
    struct customer* temp = head1;
    while(temp!=NULL){
        // sama seperti fungsi search_cus mencari berdasarkan ID
        if(strstr(temp->cust_id,cust_id)!=NULL){
            for(i=0;i<1;i++){
                printf("    ID ditemukan !!\n");
                gotoxy(3,11);
                printf("Masukkan nama customer       : ");
                gets(name);
                fprintf(fptr,"%d %s",i,name);

                gotoxy(3,14);
                printf("Masukkan ID customer         : ");
                gets(id);
                fprintf(fptr,"%d %s",i,id);

                gotoxy(3,17);
                printf("Masukkan Kota customer       : ");
                gets(kota);
                fprintf(fptr,"%d %s",i,kota);

                gotoxy(3,20);
                printf("Jenis Nomor HP customer      : ");
                gets(no);
                fprintf(fptr,"%d %s",i,no);

                gotoxy(3,23);
                printf("Jenis Email customer         : ");
                gets(mail);
                fprintf(fptr,"%d %s",i,mail);
                insert_cus(id,name,kota,no,mail);
                fclose(fptr);
            }
        }
        temp = (struct customer *) temp->next;
        printf("    Data dengan ID %s tidak ditemukan !!!\n", cust_id);
    }
}
//============================ MENU SUPPLIER    ===================
void supplier()
{

    system("cls");
    FILE*fptr;
    fptr=fopen("supplier.txt","w"); // membuka text supplier untuk di isi data customer
    if (fptr == NULL)
    {
        printf("Could not open file");
    }

    int i;
    char pilihan;
    head2 = NULL;

    char id[128];
    char name[7];
    char kota[20];
    char no[32];
    char mail[20];

    char searching[100];

    do
    {
        box1();
        main_box();
        gotoxy(31,4);
        printf("SUPPLIER\n");
        gotoxy(3,8);
        printf("1.untuk memasukkan data supplier\n");
        gotoxy(3,11);
        printf("2.untuk menampilkan data supplier\n");
        gotoxy(3,14);
        printf("3.untuk mencari data supplier\n");
        gotoxy(3,17);
        printf("4.untuk update data supplier\n");
        gotoxy(3,20);
        printf("5.untuk kembali ke main menu\n");
        gotoxy(30,37);
        printf("\n  Pilih berdasarkan nomor urut : ");
        pilihan=toupper(getche());
        switch(pilihan){
            case '1':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Memasukan Data supplier\n");
                gotoxy(3,8);
                printf("Masukkan nama supplier       : ");
                gets(name);


                gotoxy(3,11);
                printf("Masukkan ID supplier         : ");
                gets(id);


                gotoxy(3,14);
                printf("Masukkan Kota supplier       : ");
                gets(kota);


                gotoxy(3,17);
                printf("Jenis Nomor HP supplier      : ");
                gets(no);


                gotoxy(3,20);
                printf("Jenis Email supplier         : ");
                gets(mail);
                fprintf(fptr,"%s %s %s %s %s %s \n",name, id, kota, no, mail);
                
                insert_sup(id,name,kota,no,mail);
                
                break;
            case '2':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Menampilkan Data Supplier\n");
                display_sup();
                break;
            case '3':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Mencari data supplier\n");
                gotoxy(3,8);
                printf("Masukan ID supplier yang akan dicari : ");
                gets(searching);
                search_sup(searching);
                break;
            case '4':
                system("cls");
                box1();
                main_box();
                gotoxy(32,5);
                printf("Update data supplier\n");
                gotoxy(3,8);
                printf("Masukan ID supplier yang akan di update : ");
                gets(searching);
                update_sup(searching);
                break;
            case '5':
            	main_menu();
            	break;
        }
    }while(pilihan!='0');
}

void insert_sup(char* sup_id,char* sup_name,char* sup_city,char* sup_no,char* sup_email)
{
    //inisialisasi size node
    struct supplier * data = (struct supplier *) malloc(sizeof(struct supplier));
    strcpy(data->sup_id, sup_id); //mengisi data
    strcpy(data->sup_name, sup_name);
    strcpy(data->sup_city, sup_city);
    strcpy(data->sup_no, sup_no);
    strcpy(data->sup_email, sup_email);

    data->next = NULL;

    if(head2==NULL){
        head2 = data; //mengisi head dengan data
    }
    else{
        data->next = (struct sup *) head2;
        head2 = data;
    }
    fclose(fptr);

    gotoxy(3,25);
    printf("Enter untuk lanjut");
    getch();
    system("cls");
}

void display_sup()
{
    struct supplier * temp = head2;

    while(temp!=NULL){ // mendisplay 
        printf("\n  Nama             : %s\n", temp->sup_name);
        printf("  ID               : %s\n", temp->sup_id);
        printf("  Kota             : %s\n", temp->sup_city);
        printf("  No HP            : %s\n", temp->sup_no);
        printf("  Email            : %s\n\n", temp->sup_email);
        printf("----------------------------------------------\n");
        temp = (struct supplier *) temp->next;

    }
    gotoxy(3,25);
    printf("     Enter untuk lanjut");
    getch();
    system("cls");
}

void search_sup(char* sup_id)
{
    int found=0;
    struct supplier * temp = head2;
    while(temp!=NULL){
        if(strstr(temp->sup_id,sup_id)!=NULL){ //mengcompare input nama dengan node nama
            gotoxy(3,11);
            printf("Nama             : %s\n", temp->sup_name);
            gotoxy(3,14);
            printf("ID               : %s\n", temp->sup_id);
            gotoxy(3,17);
            printf("Kota             : %s\n", temp->sup_city);
            gotoxy(3,20);
            printf("No HP            : %s\n", temp->sup_no);
            gotoxy(3,23);
            printf("Email            : %s\n\n", temp->sup_email);
            found=1;
        }
        temp = (struct supplier *) temp->next;
    }
    if(found==0){
        printf("Data dengan ID %s tidak ditemukan !!!\n", sup_id);
    }

    printf("Enter untuk lanjut");
    getch();
    system("cls");
}

void update_sup(char* sup_id)
{
    char id[128];
    char name[7];
    char kota[20];
    char no[32];
    char mail[20];

    fptr=fopen("supplier.txt","w");
    if (fptr == NULL)
    {
        printf("Could not open file");
    }

    int i;
    struct supplier* temp = head2;
    while(temp!=NULL){
        // sama seperti fungsi search_cus mencari berdasarkan ID
        if(strstr(temp->sup_id,sup_id)!=NULL){
            for(i=0;i<1;i++){
                printf("    ID ditemukan !!\n");
                gotoxy(3,11);
                printf("Masukkan nama supplier       : ");
                gets(name);
                fprintf(fptr,"%d %s",i,name);

                gotoxy(3,14);
                printf("Masukkan ID supplier         : ");
                gets(id);
                fprintf(fptr,"%d %s",i,id);

                gotoxy(3,17);
                printf("Masukkan Kota supplier       : ");
                gets(kota);
                fprintf(fptr,"%d %s",i,kota);

                gotoxy(3,20);
                printf("Jenis Nomor HP supplier      : ");
                gets(no);
                fprintf(fptr,"%d %s",i,no);

                gotoxy(3,23);
                printf("Jenis Email supplier         : ");
                gets(mail);
                fprintf(fptr,"%d %s",i,mail);
                insert_cus(id,name,kota,no,mail);
                fclose(fptr);
            }
        }
        temp = (struct supplier *) temp->next;
        printf("    Data dengan ID %s tidak ditemukan !!!\n", sup_id);
    }
}
//============================ MENU OBAT    ===================
void medicine()
{

    char ch;
    do
    {
        system("cls");

        gotoxy(34,3);

        printf("---------------");
        gotoxy(35,4);
        printf("Medicine Menu.");
        gotoxy(34,5);
        printf("---------------");

        gotoxy(3,8);
        printf("1.Beli Obat Baru");

        gotoxy(3,11);
        printf("2.Jual Obat");

        gotoxy(3,14);
        printf("3.Stock Obat");

        gotoxy(3,17);
        printf("4.Cari Obat di stock");

        gotoxy(3,20);
        printf("5.Main Menu");
        main_box();
        gotoxy(10,40);
        printf("Pencet angka yang ingin digunakan  ");


        ch=toupper(getche()); // input tanpa enter
        switch(ch)
        {
            case '1':medi_entry();
                break;
            case '2':medi_sale();
                break;
            case '3':stock();
                break;
            case '4':medi_search();
                break;
            case '5':main_menu();
                break;
            default:
                gotoxy(11,34);
                printf("Pencet angka yang ada saja! (1,2,3,4,5).");
                getch();
        }
    }while(ch!='5');

}

//============================ PEMBELIAN OBAT    ===================
void medi_entry()
{
    char ch,id[6];
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int f;
    FILE *fp;
    FILE *ptrp_r;
    FILE *ptr;
    system("cls");

    ptrp_r=fopen("purreport.txt","a");
    ch='Y';
    while(ch=='Y')
    {
        system("cls");
        box();
        lbox();
        gotoxy(30,8);
        printf(" Pembelian Obat  ");
        {
			gotoxy(7,11);
			printf("MEDICINE ID    : ");

			gotoxy(40,11);
			printf("MEDICINE NAME  : ");

			gotoxy(7,14);
			printf("ENTER RACK NO  : ");

			gotoxy(40,14);
			printf("CABNIT NO      : ");

			gotoxy(7,18);
			printf("COMPANY NAME   : ");

			gotoxy(40,18);
			printf("SUPPLIER NAME  : ");

			gotoxy(7,21);
			printf("UNIT COST   Rp.:  ");

			gotoxy(40,21);
			printf("SALE COST   Rp.: ");

			gotoxy(7,24);
			printf("QUANTITY       :  ");

			gotoxy(7,27);
			printf("MFG.DATE(dd-mm-yyyy): ");

			gotoxy(7,29);
			printf("EXP.DATE(dd-mm-yyyy): ");

            gotoxy(25,11);
            ventry(temp.id,1);
            strcpy(id,temp.id);

            fp=fopen("medical.txt","r");
            while((fread(&temp,sizeof(temp),1,fp))==1)
            {

                if(strcmp(id,temp.id)==0)
                {
                    f=1;
                    break;
                }
            }
            fclose(fp);
            if(f==1)
            {
                gotoxy(20,31);
                printf("ID Sudah Ada");
                getche();
                system("cls");
                medi_entry();
            }
            else
            {
                ptr=fopen("medical.txt","a+b");
                strcpy(temp.id,id);
                strcpy(p_r.medi_id,temp.id);
            }

            gotoxy(58,11);
            ventry(temp.medi_name,0);
            strcpy(p_r.medir_name,temp.medi_name);

            gotoxy(25,14);
            ventry(a,1);
            temp.rack= atoi(a);

            gotoxy(58,14);
            ventry(temp.cabnit,2);

            gotoxy(25,18);
            ventry(temp.comp_name,0);

            gotoxy(58,18);
            ventry(temp.supp_name,0);
            strcpy(p_r.supp_name,temp.supp_name);

            gotoxy(25,21);
            ventry(a,1);
            temp.unit= atof(a);

            p_r.rate=temp.unit;
            gotoxy(58,21);
            ventry(a,1);
            temp.sale= atof(a);

            gotoxy(25,24);
            ventry(a,1);
            temp.quantity= atoi(a);
            p_r.qty=temp.quantity;

            gotoxy(29,27);

            ventry(temp.manu_date,1);
            gotoxy(29,29);

            ventry(temp.exp_date,1);

            gotoxy(7,31);
            printf("==========================================================");
            temp.total=temp.quantity*temp.sale;


            gotoxy(10,33);
            printf("TOTAL SALE COST = Rp. %.2f",temp.total);
            temp.cost=(temp.unit*temp.quantity);
            gotoxy(40,33);
            printf("TOTAL UNIT COST = Rp. %.2f",temp.cost);
            p_r.total=temp.cost;
            p_r.sDay=now->tm_mday;
            p_r.sMonth=now->tm_mon+1;
            p_r.sYear=now->tm_year+1900;
        }
        gotoxy(20,35);

        printf("Save");

        gotoxy(28,35);

        printf("Cancel");

        gotoxy(18,38);
        printf("Press First charecter for the operation : ");


        ch=toupper(getche());

        if(ch=='S')
        {
            fwrite(&temp,sizeof(temp),1,ptr);
            fflush(stdin);

            fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
            system("cls");
            gotoxy(20,20);
            printf("Medicine Added sucessfully!!!!!!");
            gotoxy(20,25);
            printf("More entries  [y/n]");
            ch=toupper(getche());
            if(ch=='Y')
            {
                system("cls");
                medi_entry();
            }
        }

    }
    fclose(ptr);
    fclose(ptrp_r);
}

//===========PENJUALAN OBAT=========================
void medi_sale()
{
    struct bill bil;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int j,n,i,a,billno;
    int d1,m,y;
    float b,total,rate;
    char tar[30],ch,mediname[30],c_name[30],cname[30];
    FILE *fp,*fpc;
    int count=0;
    d1=now->tm_mday;
    m=now->tm_mon+1;
    y=now->tm_year+1900;
    ch='y';
    while(ch=='y')
    {
        fp = fopen("dbbill.txt","a");
        fptr = fopen("customer.txt","r");
        ptr = fopen("medical.txt","r");
        ptrs_r=fopen("saleRpt.txt","a");
        ptrpr_r=fopen("profitRpt.txt","a");
        system("cls");
        box();
        for(i=3;i<=45;i++)
        {
            gotoxy(50,i);
            printf("%c",219);
        }

        gotoxy(9,7);
        printf("Masukan ID obat yang ingin dijual  : ");
        ventry(tar,1);

        j=0;
        while((fread(&temp,sizeof(temp),1,ptr))==1)
        {
            if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
            {
                x[j] = temp;
                j++;
            }
            else if((strcmp(temp.id,tar)==0))
            {

                gotoxy(8,10);
                printf(" Nama Obat        : %s",temp.medi_name);
                gotoxy(8,12);
                printf(" Jumlah dalam stock    : %d",temp.quantity);
                gotoxy(8,14);
                printf(" Harga Jual          : %.2f",temp.sale);
                gotoxy(8,16);
                printf("Masukkan nomor bill     : ");

                ventry(bil.billno,1);

                gotoxy(8,18);
                printf("Masukkan nama pelanggan   : ");

                ventry(c_name,0);

                gotoxy(8,20);
                printf("jumlah yang ingin dijual : ");
                scanf("%d",&a);

                pr_r.profit=(temp.sale-temp.unit)*a;
                x[j]=temp;
                x[j].quantity=(x[j].quantity-a);
                x[j].total=(x[j].quantity*temp.sale);
                x[j].cost=(x[j].quantity*temp.unit);
                x[j].bye=(x[j].sale*a);
                b=x[j].bye;
                x[j].qty=a;
                j++;
                count++;
                strcpy(bil.cname,c_name);
                strcpy(s_r.cust_name,c_name);
                strcpy(bil.mediname,temp.medi_name);
                bil.medi_qty=a;
                bil.medi_rate=temp.sale;
                bil.total=temp.sale*a;

                bil.day=d1;
                bil.month=m;
                bil.year=y;

                fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
                fflush(stdin);

                fclose(fp);

                s_r.sDay=d1;
                s_r.sMonth=m;
                s_r.sYear=y;
                strcpy(s_r.medi_id,tar);
                strcpy(s_r.medir_name,temp.medi_name);
                s_r.qty=a;
                s_r.rate=temp.sale;
                s_r.total=temp.sale*a;


                fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
                fflush(stdin);
                fclose(ptrs_r);


                pr_r.sDay=d1;
                pr_r.sMonth=m;
                pr_r.sYear=y;
                strcpy(pr_r.medi_id,tar);
                strcpy(pr_r.medir_name,temp.medi_name);
                pr_r.qty=a;
                pr_r.rate=temp.sale;
                pr_r.unit=temp.unit;
                fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
                fflush(stdin);
                fclose(ptrpr_r);

            }
        }
        if (count==0)
        {
            system("cls");
            gotoxy(33,10);
            printf("Not in stock!!!!!");
            getch();
            return;
        }
        fclose(fptr);
        fclose(ptr);
        n = j;
        system("cls");
        ptr=fopen("medical.txt","w");
        for(i=0; i<n; i++)
            fwrite(&x[i],sizeof(x[i]),1,ptr);
        fclose(ptr);
        system("cls");
        box();
        gotoxy(8,15);
        printf("* Harga yang dibayar = %.2f",b);
        gotoxy(8,17);
        printf("* jumlah dijual          = %d",a);
        getch();
        gotoxy(10,20);
        printf("more entries=(y/n) :");
        ch=getche();
    }

}
//===========================STOCK OBAT=====================================
void stock()
{
    char ch;
    int i,c;
    do
    {
        system("cls");
        fptr=fopen("medical.txt","r");
        if(fptr==NULL)
        {
            printf("\n\t Can not open File! ");
            exit(1);
        }
        system("cls");
        box();
        lbox();

        gotoxy(30,8);

        printf(" STOCK OBAT ");

        i=14;
        gotoxy(9,10);
        printf("ID.   NAMA Medicine.    QTY     Supplier Name     Exp.Date");
        gotoxy(9,12);
        printf("==================================================================\n");

        while((fread(&temp,sizeof(temp),1,fptr))==1)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.medi_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
        }
        gotoxy(10,42);
        printf("Press [1] for Update Stock obat & [0] for main menu ");
        c = (getche());
        switch (c)
        {
            case '0':
                main_menu();
                break;
            case '1':
                update_stock();
                break;
        }

    }while(c != '1');
    getche();
}
//=============================== PENCARIAN OBAT ====================
void medi_search()
{


    char mid[6];
    int i,c;
    system("cls");
    fptr=fopen("medical.txt","r");
    if(fptr==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    box();

    gotoxy(10,7);
    printf("Masukkan Nama obat yang ingin dicari : ");
    scanf("%s",&mid);
    system("cls");
    box();
    lbox();

    gotoxy(30,8);

    printf(" MEDICINE ");

    i=14;
    gotoxy(9,10);
    printf("ID.   Nama Medicine.    QTY     Supplier Name     Exp.Date");
    gotoxy(9,12);
    printf("==================================================================\n");
    while((fread(&temp,sizeof(temp),1,fptr))==1)
    {
        if(strstr(temp.medi_name,mid)!=NULL)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.medi_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
            break;
        }

    }
    if(strstr(temp.medi_name,mid)==NULL)
    {
        gotoxy(20,20);
        printf("Not in Stock.....");
    }
    getche();

}
//============================ UPDATE STOCK OBAT =====================
void update_stock()
{
    char mid[6];
    int j,a,count=0,n, i;
    system("cls");
    ptr=fopen("medical.txt","r");
    if(ptr==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    box();
    gotoxy(20,45);
    printf("Press Enter to go to MENU ...........");

    gotoxy(27,8);

    printf(" UPDATE JUMLAH OBAT ");

    gotoxy(9,10);
    printf("Masukkan ID Obat: ");
    scanf("%s",&mid);
    j=0;

    while((fread(&temp,sizeof(temp),1,ptr))==1)
    {
        if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
        {
            x[j] = temp;
            j++;
        }
        else
        {
            gotoxy(8,12);
            printf("Nama Obat     : %s",temp.medi_name);
            gotoxy(8,14);
            printf("Jumlah dalam Stock : %d",temp.quantity);
            gotoxy(8,16);
            printf("Jumlah baru : ");
            scanf("%d",&a);
            x[j]=temp;
            x[j].quantity=(x[j].quantity+a);
            x[j].total=(x[j].quantity*temp.sale);
            x[j].cost=(x[j].quantity*temp.unit);
            x[j].bye=(x[j].sale*a);
            x[j].qty=a;
            j++;
            count++;
        }
    }
    if (count==0)
    {
        system("cls");
        gotoxy(33,10);
        printf("Not in stock!!!!!!");
        getch();
        return;
    }
    fclose(ptr);
    n = j;
    system("cls");
    ptr=fopen("medical.txt","w");
    for(i=0; i<n; i++)
        fwrite(&x[i],sizeof(x[i]),1,ptr);
    fclose(ptr);
}
//===================== view report =============================/
void sale_rpt()
{
    char ch;
    int j;
    system("cls");
    ptrs_r=fopen("saleRpt.txt","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    box();
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    lbox();

    gotoxy(30,8);

    printf("Sales Report");

    gotoxy(7,10);
    printf("ID. Nama Medicine.  Nama Pelanggan.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",s_r.medi_id);
        gotoxy(11,j);
        printf("%s",s_r.medir_name);
        gotoxy(28,j);
        printf("%s",s_r.cust_name);
        gotoxy(44,j);
        printf("%d",s_r.qty);
        gotoxy(50,j);
        printf("%.2f",s_r.rate);
        gotoxy(57,j);
        printf("%.2f",s_r.total);
        gotoxy(65,j);
        printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
        j=j+2;
    }
    getche();
}
//======================= VIEW PURCHASE REPORT ===========================
void pur_rpt()
{
    char ch;
    int j;
    system("cls");
    t();
    box();
    ptrp_r=fopen("purreport.txt","r");
    if(ptrp_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");
    lbox();

    gotoxy(30,8);
    printf("Purchase Report");

    gotoxy(7,10);
    printf("ID. Nama Medicine.  Nama Pelanggan.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",p_r.medi_id);
        gotoxy(11,j);
        printf("%s",p_r.medir_name);
        gotoxy(28,j);
        printf("%s",p_r.supp_name);
        gotoxy(44,j);
        printf("%d",p_r.qty);
        gotoxy(50,j);
        printf("%.2f",p_r.rate);
        gotoxy(57,j);
        printf("%.2f",p_r.total);
        gotoxy(65,j);
        printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
        j+=2;
    }
    getche();
}
//========================= report of profit ===========================
void profit_rpt()
{
    char ch;
    int j;
    system("cls");
    t();
    box();
    ptrpr_r=fopen("profitRpt.txt","r");
    if(ptrpr_r==NULL)
    {
        printf("\n\t Can not open File! ");

    }
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");
    lbox();
    gotoxy(30,8);
    printf("Profit Report");
    gotoxy(7,10);
    printf("ID. Nama Medicine.   Date        Qty.  Unit Price  Sale Price. Profit. ");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrpr_r,"%s %s %d %d %d %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
    {
        gotoxy(6,j);

        printf("%s",pr_r.medi_id);
        gotoxy(11,j);
        printf("%s",pr_r.medir_name);
        gotoxy(28,j);
        printf("%d-%d-%d",pr_r.sDay,pr_r.sMonth,pr_r.sYear);
        gotoxy(40,j);
        printf("%d",pr_r.qty);
        gotoxy(48,j);
        printf("%.2f",pr_r.unit);
        gotoxy(60,j);
        printf("%.2f",pr_r.rate);
        gotoxy(70,j);
        printf("%.2f",pr_r.profit);
        gotoxy(10,j);
        printf("%c",124);
        j+=2;

    }
    getche();
}
void sale_rpt_daily()
{
    char ch;
    int j,d,m,y;
    float total=0.00;
    system("cls");
    ptrs_r=fopen("saleRpt.txt","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(15,10);
    printf("Enter Date(dd-mm-yyyy):  ");
    scanf("%d-%d-%d",&d,&m,&y);
    system("cls");
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    box();
    lbox();
    gotoxy(30,8);
    printf("Sales Report");
    gotoxy(7,10);
    printf("ID. Nama Medicine.  Nama Pelanggan.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
        {
            gotoxy(6,j);
            printf("%s",s_r.medi_id);
            gotoxy(11,j);
            printf("%s",s_r.medir_name);
            gotoxy(28,j);
            printf("%s",s_r.cust_name);
            gotoxy(44,j);
            printf("%d",s_r.qty);
            gotoxy(50,j);
            printf("%.2f",s_r.rate);
            gotoxy(57,j);
            printf("%.2f",s_r.total);
            gotoxy(65,j);
            printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
            j=j+2;
            total=total+s_r.total;
        }
    }
    gotoxy(7,42);
    printf("-------------------------------------------------------------------");
    gotoxy(45,43);
    printf("Total:        %.2f",total);
    getche();
}
void pur_rpt_daily()
{
    char ch;
    int j,d,m,y;
    float total=0.00;

    ptrp_r=fopen("purreport.txt","r");
    if(ptrp_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(15,10);
    printf("Enter Date(dd-mm-yyyy):  ");
    scanf("%d-%d-%d",&d,&m,&y);
    system("cls");
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");
    t();
    box();
    lbox();
    gotoxy(30,8);
    printf("Purchase Report");
    gotoxy(7,10);
    printf("ID. Nama Medicine.  Nama Pelanggan.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
    {
        if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
        {
            gotoxy(6,j);
            printf("%s",p_r.medi_id);
            gotoxy(11,j);
            printf("%s",p_r.medir_name);
            gotoxy(28,j);
            printf("%s",p_r.supp_name);
            gotoxy(44,j);
            printf("%d",p_r.qty);
            gotoxy(50,j);
            printf("%.2f",p_r.rate);
            gotoxy(57,j);
            printf("%.2f",p_r.total);
            gotoxy(65,j);
            printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
            j+=2;
            total=total+p_r.total;
        }
    }
    gotoxy(7,42);
    printf("-------------------------------------------------------------------");
    gotoxy(45,43);
    printf("Total:        %.2f",total);
    getche();
}
//=========================For Report ===========================
void report_menu()
{
    char ch;
    do
    {
        system("cls");

        gotoxy(34,3);
        printf("---------------");
        gotoxy(35,4);
        printf("Report Menu.");
        gotoxy(34,5);
        printf("---------------");

        gotoxy(3,8);
        printf("1.Report Pembelian");
        gotoxy(3,11);
        printf("2.Report Penjualan");

        gotoxy(3,14);
        printf("3.Report Keuntungan");

        gotoxy(3,17);
        printf("4.Report Harian Penjualan");

        gotoxy(3,20);
        printf("5.Report Harian Pembelian");

        gotoxy(3,23);
        printf("6.Main Menu");

        main_box();
        gotoxy(10,40);
        printf("Masukkan angka yang ingin ditekan  ");


        ch=toupper(getche());
        switch(ch)
        {
            case '1':pur_rpt();
                break;
            case '2':sale_rpt();
                break;
            case '3':sale_rpt_daily();
                break;
            case '4':profit_rpt();
                break;
            case '5':pur_rpt_daily();
                break;
            case '6':main_menu();
                break;
            default:
                gotoxy(11,34);
                printf("Tekan angka yang ada (1,2,3,4,5,6).");
                getch();
        }
    }while(ch!='M');

}
//========================for bill =============================
void bill()
{

    time_t td = time(0);
    struct tm * now = localtime( & td );

    FILE *ptrbill;
    char id[6];
    int j=1,d1,m,y,k, i;
    float netamt=0.0;
    d1=now->tm_mday;
    m=now->tm_mon+1;
    y=now->tm_year+1900;
    system("cls");
    ptrbill=fopen("dbbill.txt","r");
    gotoxy(13,4);
    printf("Enter bill no : ");
    scanf("%s",&id);
    system("cls");
    gotoxy(25,3);
    box();
    gotoxy(7,7);
    printf("Bill No: ");
    printf(" %s",id);
    gotoxy(7,9);
    printf("Customer Name: ");
    gotoxy(50,7);
    printf("Date : ");
    printf("%d-%d-%d",d1,m,y);
    gotoxy(7,12);
    printf("Sr.No   Nama Obat       Qty          Rate         Total ");
    gotoxy(6,14);
    printf("---------------------------------------------------------------------");

    i=15;
    while(fscanf(ptrbill,"%s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
    {

        do
        {
            if(strcmp(id,bil.billno)==0)
            {
                gotoxy(7,i);
                printf(" %d",j);
                gotoxy(14,i);
                printf(" %s",bil.mediname);
                gotoxy(22,9);
                printf(" %s",bil.cname);
                gotoxy(35,i);
                printf(" %d",bil.medi_qty);
                gotoxy(47,i);
                printf(" %.2f",bil.medi_rate);
                gotoxy(60,i);
                printf(" %.2f",bil.total);
                netamt=netamt+bil.total;
                i++;
                j++;
                gotoxy(35,32);
                printf("                                ");
                gotoxy(20,50);

                printf("Press Any key to go to  MENU ...........");
            }


        }while(feof(ptrbill));

    }


    gotoxy(6,35);
    printf("---------------------------------------------------------------------");
    gotoxy(50,37);
    printf("Net Amount : ");
    printf("%.2f",netamt);

    fclose(ptrbill);
    getch();
    main_menu();
}
//========================= ABOUT MENU ===========================
void about(char arr[100])
{
    system("cls");
    int c,i;
    t();
    box1();
    main_box();
    gotoxy(28,4);
    printf(" MEDICAL STORE ");
    gotoxy(10,8);
    printf("Halo,%s",arr);
    gotoxy(10,10);
    printf("=> Project ini tentang medical store ");
    gotoxy(10,12);
    printf("=> Di projek ini kita dapat menambahkan data supplier dan customer");
    gotoxy(10,14);
    printf("=> Projek ini juga dapat menghapus data yang tersimpan dalam file");
    gotoxy(10,16);
    printf("=> Selain itu projek ini juga dapat melakukan search");

    gotoxy(10,17);
    printf("          <<<<-tekan apa saja untuk lanjut->>>>");
    getche();
    main_menu();

}

//========================= INPUT VALIDATION ===========================
void ventry(char t[],int code)
{
    int i=0;
    // UNTUK INPUT CHAR ONLY
    if(code==0)
    {
        while((t[i]=getch())!='\r' && i<30)
            if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }
        // UNTUK INPUT ANGKA SEBAGAI CHAR
    else if(code==1)
    {
        while((t[i]=getch())!='\r' && i<10 )
            if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }
        //UNTUK INPUT GABUNGAN ANGKA DAN CHAR
    else if(code==2)
    {
        while((t[i]=getch())!='\r' && i<30 )
            if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }

    t[i]='\0';
}

//========================= BOX ===========================
void box()
{
    int i;
    for(i=3;i<=79;i++)
    {
        gotoxy(i,3);
        printf("%c",219);
        gotoxy(78,45);
        printf("%c",219);
        gotoxy(i,45);
        printf("%c",219);
    }

    for(i=3;i<=45;i++)
    {
        gotoxy(3,i);
        printf("%c",219);
        gotoxy(79,i);
        printf("%c",219);
    }
}
//func untuk about
void about_name()
{
    system("cls");
    t();
    box1();
    main_box();
    char arr[100];
    gotoxy(10,8);
    printf("Masukan nama anda : ");
    fflush(stdin);
    gets(arr);
    about(arr);
}