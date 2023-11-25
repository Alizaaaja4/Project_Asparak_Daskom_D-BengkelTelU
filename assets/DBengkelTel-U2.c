#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login_admin();
    void menu_admin();
        void tambah_bengkel();
        void hapus_bengkel();
        void list_bengkel();
            void bubblesort_list_mobil();
            void tampilan_bubblesort_list_mobil();
            
            void bubblesort_list_motor();
            void tampilan_bubblesort_list_motor();

            void bubblesort_list_sepeda();
            void tampilan_bubblesort_list_sepeda();

        void review_orderan();
            void bubblesort_orderan();
            void tampilan_bubblesort_orderan(); 
        void review_feedback();

void dashboard_user();
    void registrasi_user ();
        void login_user();
            void menu_user();
                    void lihat_jasa();
                        void pesanbengkel_mobil();
                        void pesanbengkel_motor();
                        void pesanbengkel_sepeda();
                        void lihat_status();
                    void kasih_feedback();
void logout();

void header();

FILE *DataBengkelMotor;
FILE *DataBengkelMotor_backup;

FILE *DataBengkelMobil;
FILE *DataBengkelMobil_backup;

FILE *DataBengkelSepeda;
FILE *DataBengkelSepeda_backup;

FILE *OrderDiterima;
FILE *OrderDiKonfirmasi;

FILE *ReviewOrderan;

FILE *DaftarAkunuser;

// ini punya bengkel mobil
struct DataMobil{
    char namatoko[100], nama[100], montir[20], alamat[200], kontak[50], waktu[50];
}listMobil[1000];

struct DataMobil temp;
struct DataMobil mobil;

// ini punya bengkel motor
struct DataMotor{
    char namatoko[100], nama[100], montir[20], alamat[200], kontak[50], waktu[50];
}listmotor[1000];

struct DataMotor temp1;
struct DataMotor motor;

// ini punya bengkel sepeda
struct DataSepeda{
    char namatoko[100], nama[100], montir[20], alamat[200], kontak[50], waktu[50];
}listsepeda[1000];

struct DataSepeda temp2;
struct DataSepeda sepeda;

// ini punya orderan
struct DataOrder{
    char kategori[100], pesanan[100], waktu[100], namabengkel[100], namabengkel_2[50], namacustomer[50], kendaraan[30], plat[30], deskripsi[100], feedback[100];
}listorder[1000];

struct DataOrder temp3;
struct DataOrder order;

//ini punya user
struct DataUser{
    char nama[50], username[50], password[50], kendaraan[50], kontak[50];
}akunuser[1000];

struct DataUser temp4;
struct DataUser User;

char confirm[50];

int main (){ //ini menu utama
    system("cls");

    int menu;

    printf("= = = = = = = = = = = = = = = = \n");
    printf("= = =  ~ D'BENGKEL TelU ~ = = =\n");
    printf("= = = = = = = = = = = = = = = = \n");
    printf("= = 1. ADMIN                = =\n");
    printf("= = 2. USER                 = =\n");
    printf("= = 99. EXIT                = =\n");
    printf("= = = = = = = = = = = = = = = = \n");
    printf("Pilih menu /> "); scanf("%d", &menu); getchar();

        switch (menu){
            case 1: system("cls");
                    login_admin(1);
                    break;

            case 2: system("cls");
                    dashboard_user();
                    break;  

            case 99: system("cls");
                     printf("===============================\n");
                     printf("Anda telah keluar dari Program\n\tTerimakasih!!\n");
                     break;

            default: printf("Inputan anda tidak ada dalam menu !!\n");
                     system("pause");
                     system("cls");

                     main();
                     break;
        }

    return 0;
}

void login_admin(int percobaan){
    char username[50], password[50];

    printf("-=====-----=====-----=====-----\n");
    printf("===     ~ Login Admin ~     ===\n");
    printf("-=====-----=====-----=====-----\n");
    printf("Username: "); gets(username);
    printf("Password: "); gets(password);

    if (strcmp(username, "admin")==0 && strcmp(password, "123")==0){
        printf("\n -------------------------------- \n");
        printf("Anda berhasil login sebagai Admin ^_^\n");
        system("pause");
        system("cls");
        menu_admin();
    }
    else{
         printf("\n -------------------------------- \n");
         printf("Anda gagal login !!\n Tersisa %d kesempatan lagi !!", 3-percobaan);
         if (percobaan < 3){
            system("pause");
            system("cls");
            login_admin(percobaan+1);

         }else{
            printf("\n -------------------------------- \n");
            printf("Akun anda kami banned, karena sudah melebihi limit !!\n");
            printf("Terimakasih ^_^\n");
            system("pause");
            system("cls");
            main ();
         }
    }
}

void menu_admin(){
    int menu;

    printf("- - - - - - - - - - - - - - - - \n");
    printf("======   ~ D'BengkelTelU ~  =====\n");
    printf("- - - - - - - - - - - - - - - - \n");
    printf("-> 1. Tambah Toko Bengkel   <-\n");
    printf("-> 2. Hapus Toko Bengkel    <-\n");
    printf("-> 3. Daftar Toko Bengkel   <-\n");
    printf("-> 4. Review Orderan        <-\n");
    printf("-> 5. Review Feedback       <-\n");
    printf("-> 0. Keluar                <-\n");
    printf("- - - - - - - - - - - - - - - - \n\n");

    printf("Pilih menu /> "); scanf("%d", &menu); getchar();

    switch(menu){
        case 1: tambah_bengkel();
                break;
        case 2: hapus_bengkel();
                break;
        case 3: list_bengkel();
                break;
        case 4: review_orderan();
                break;
        case 5: review_feedback();
                break;
        case 0: system("pause");
                system("cls");
                main(); 
                break;

        default: printf("Inputan anda tidak ada dalam menu !!\n");
                system("pause");
                system("cls");
                menu_admin();
                break;
    }

}

void tambah_bengkel(){
    system("cls");

    int menu;

    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("======   ~ ++ D'BengkelTelU ~  =====\n");
    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("-> 1. Bengkel Mobil                <-\n");
    printf("-> 2. Bengkel Motor                <-\n");
    printf("-> 3. Bengkel Sepeda               <-\n");
    printf("-> 0. Keluar                       <-\n");
    printf("Pilih menu /> "); scanf("%d", &menu); getchar();

    switch (menu){
    case 1: DataBengkelMobil = fopen("Daftar Bengkel Mobil.dat", "ab");

            printf("\n Masukan Identitas Bengkel\n");
            printf("Nama Toko     : "); gets(mobil.namatoko);
            printf("Nama Boss     : "); gets(mobil.nama);
            printf("Jumlah Montir : "); gets(mobil.montir);
            printf("No Hp         : "); gets(mobil.kontak);
            printf("Alamat        : "); gets(mobil.alamat);
            printf("Waktu Buka    : "); gets(mobil.waktu);
            printf("\n");

            fwrite(&mobil, sizeof(struct DataMobil), 1, DataBengkelMobil);

            fclose(DataBengkelMobil);

            printf("======================================\n");
            printf("Bengkel telah berhasil ditambahkan !!\n");
            
            system("pause");
            system("cls");

            tambah_bengkel();
        break;
    
    case 2: DataBengkelMotor = fopen("Daftar Bengkel Motor.dat", "ab");

            printf("\n Masukan Identitas Bengkel\n");
            printf("Nama Toko     : "); gets(motor.namatoko);
            printf("Nama Boss     : "); gets(motor.nama);
            printf("Jumlah Montir : "); gets(motor.montir);
            printf("No Hp         : "); gets(motor.kontak);
            printf("Alamat        : "); gets(motor.alamat);
            printf("Waktu Buka    : "); gets(motor.waktu);
            printf("\n");

            fwrite(&motor, sizeof(struct DataMotor), 1, DataBengkelMotor);

            fclose(DataBengkelMotor);

            printf("======================================\n");
            printf("Bengkel telah berhasil ditambahkan !!\n");
            
            system("pause");
            system("cls");

            tambah_bengkel();
        break;
    
    case 3: DataBengkelSepeda = fopen("Daftar Bengkel Sepeda.dat", "ab");

            printf("\n Masukan Identitas Bengkel\n");
            printf("Nama Toko     : "); gets(sepeda.namatoko);
            printf("Nama Boss     : "); gets(sepeda.nama);
            printf("Jumlah Montir : "); gets(sepeda.montir);
            printf("No Hp         : "); gets(sepeda.kontak);
            printf("Alamat        : "); gets(sepeda.alamat);
            printf("Waktu Buka    : "); gets(sepeda.waktu);
            printf("\n");

            fwrite(&sepeda, sizeof(struct DataSepeda), 1, DataBengkelSepeda);

            fclose(DataBengkelSepeda);

            printf("======================================\n");
            printf("Bengkel telah berhasil ditambahkan !!\n");
            
            system("pause");
            system("cls");

            tambah_bengkel();
        break;
    
    case 0: system("pause");
            system("cls");

            menu_admin();
        break;

    default: printf("Inputan anda tidak ada dalam menu !!\n");
             system("pause");
             system("cls");
             tambah_bengkel();
        break;
    }
}

void hapus_bengkel(){
    char hapusbengkel[100];
    int menu, ditemukan = 0;

    system("cls");

    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("======   ~ -- D'BengkelTelU ~  =====\n");
    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("-> 1. Bengkel Mobil                <-\n");
    printf("-> 2. Bengkel Motor                <-\n");
    printf("-> 3. Bengkel Sepeda               <-\n");
    printf("-> 0. Keluar                       <-\n");
    printf("Pilih menu /> "); scanf("%d", &menu); getchar();

    switch(menu){
        case 1: DataBengkelMobil = fopen("Daftar Bengkel Mobil.dat", "rb");
                DataBengkelMobil_backup = fopen("Daftar Bengkel Mobil Backup.dat", "wb");

                printf("\nMasukan Nama Bengkel yang ingin dihapus\n");
                printf("/> "); gets(hapusbengkel);

                while(fread(&mobil,sizeof(struct DataMobil), 1, DataBengkelMobil)==1){
                    if(strcmp(mobil.namatoko, hapusbengkel) !=0){
                        fwrite(&mobil, sizeof(struct DataMobil), 1, DataBengkelMobil_backup);
                    } else{
                        ditemukan = 1;
                    }
                }

                fclose(DataBengkelMobil);
                fclose(DataBengkelMobil_backup);

                remove("Daftar Bengkel Mobil.dat");
                rename("Daftar Bengkel Mobil Backup.dat", "Daftar Bengkel Mobil.dat");

                if(ditemukan == 1){
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s berhasil dihapuskan !!\n", hapusbengkel);
                } else{
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s tidak ditemukan dalam database !!\n", hapusbengkel);
                }

                system("pause");
                hapus_bengkel();
            break;

        case 2: DataBengkelMotor = fopen("Daftar Bengkel Motor.dat", "rb");
                DataBengkelMotor_backup = fopen("Daftar Bengkel Motor Backup.dat", "wb");

                printf("\nMasukan Nama Bengkel yang ingin dihapus\n");
                printf("/> "); gets(hapusbengkel);

                while(fread(&motor,sizeof(struct DataMotor), 1, DataBengkelMotor)==1){
                    if(strcmp(motor.namatoko, hapusbengkel)!=0){
                        fwrite(&motor, sizeof(struct DataMotor), 1, DataBengkelMotor_backup);
                    } else{
                        ditemukan = 1;
                    }
                }

                fclose(DataBengkelMotor);
                fclose(DataBengkelMotor_backup);

                remove("Daftar Bengkel Motor.dat");
                rename("Daftar Bengkel Motor Backup.dat", "Daftar Bengkel Motor.dat");

                if(ditemukan == 1){
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s berhasil dihapuskan !!\n", hapusbengkel);
                } else{
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s tidak ditemukan dalam database !!\n", hapusbengkel);
                }

                system("pause");
                hapus_bengkel();
            break;

        case 3: DataBengkelSepeda = fopen("Daftar Bengkel Sepeda.dat", "rb");
                DataBengkelSepeda_backup = fopen("Daftar Bengkel Sepeda Backup.dat", "wb");

                printf("\nMasukan Nama Bengkel yang ingin dihapus\n");
                printf("/> "); gets(hapusbengkel);

                while(fread(&sepeda,sizeof(struct DataSepeda), 1, DataBengkelSepeda)==1){
                    if(strcmp(sepeda.namatoko, hapusbengkel)!=0){
                        fwrite(&sepeda, sizeof(struct DataSepeda), 1, DataBengkelSepeda_backup);
                    } else{
                        ditemukan = 1;
                    }
                }

                fclose(DataBengkelSepeda);
                fclose(DataBengkelSepeda_backup);

                remove("Daftar Bengkel Sepeda.dat");
                rename("Daftar Bengkel Sepeda Backup.dat", "Daftar Sepeda Motor.dat");

                if(ditemukan == 1){
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s berhasil dihapuskan !!\n", hapusbengkel);
                } else{
                    printf("= = = = = = = = = = = = = = = = = = = =\n");
                    printf("Bengkel %s tidak ditemukan dalam database !!\n", hapusbengkel);
                }

                system("pause");
                hapus_bengkel();
            break;

        case 0: system("pause");
                system("cls");

                menu_admin();
            break;

        default: printf("Inputan anda tidak ada dalam menu !!\n");
                 system("pause");
                 system("cls");

                 hapus_bengkel();
            break;
    }
}

void list_bengkel(){
    int menu, banyakdata = 0;

    system("cls");

    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("======   ~ <> D'BengkelTelU ~  =====\n");
    printf("- - - - - - - - - - - - - - - - - - - \n");
    printf("-> 1. Bengkel Mobil                <-\n");
    printf("-> 2. Bengkel Motor                <-\n");
    printf("-> 3. Bengkel Sepeda               <-\n");
    printf("-> 0. Back                         <-\n");
    printf("Pilih menu /> "); scanf("%d", &menu); getchar();

    switch (menu){
    case 1: DataBengkelMobil = fopen("Daftar Bengkel Mobil.dat", "rb");

            if (DataBengkelMobil == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                list_bengkel();
            }

            while(fread(&listMobil[banyakdata],sizeof(struct DataMobil), 1, DataBengkelMobil)== 1){
                banyakdata++;
            }

            fclose(DataBengkelMobil);

            bubblesort_list_mobil(banyakdata, listMobil);

            printf("\n Daftar Bengkel Mobil\n");
            tampilan_bubblesort_list_mobil(banyakdata, listMobil);

            system("pause");
            list_bengkel();
        break;
    
    case 2: DataBengkelMotor = fopen("Daftar Bengkel Motor.dat", "rb");

            if(DataBengkelMotor == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                list_bengkel();
            }

           while (fread(&listmotor[banyakdata],sizeof(struct DataMotor), 1, DataBengkelMotor)==1){
                banyakdata++;
           }

           fclose(DataBengkelMotor);

            bubblesort_list_motor(banyakdata, listmotor);

            printf("\n Daftar Bengkel Motor\n");
            tampilan_bubblesort_list_motor(banyakdata, listmotor);

            system("pause");
            list_bengkel();
        break;
    
    case 3: DataBengkelSepeda = fopen("Daftar Bengkel Sepeda.dat", "rb");

            if(DataBengkelSepeda == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                list_bengkel();
            }

           while (fread(&listsepeda[banyakdata],sizeof(struct DataSepeda), 1, DataBengkelSepeda)==1){
                banyakdata++;
           }

           fclose(DataBengkelSepeda);

            bubblesort_list_sepeda(banyakdata, listsepeda);

            printf("\n Daftar Bengkel Sepeda\n");
            tampilan_bubblesort_list_sepeda(banyakdata, listsepeda);

            system("pause");
            list_bengkel();
        break;
           
    case 0: system("pause");
            system("cls");

            menu_admin();
            break;
    default: printf("Inputan anda tidak ada dalam menu !!\n");
             system("pause");
             system("cls");

             list_bengkel();
        break;
    }
}

void bubblesort_list_mobil(int banyakdata, struct DataMobil listMobil[]){
    int i, j;

    for(i = 0; i<banyakdata; i++){
        for(j=0; j< banyakdata -i -1; j++){
            if(strcmp(listMobil[j].namatoko, listMobil[j+1].namatoko)> 0){
                temp = listMobil[j];
                listMobil[j] = listMobil[j+1];
                listMobil[j+1] = temp;
            }
        }
    }
}

void tampilan_bubblesort_list_mobil(int banyakdata, struct DataMobil listMobil[]){
    int i;

    for (i=0; i<banyakdata; i++){
        printf("\n%d. -- Data Bengkel Mobil --\n", i+1);
        printf("Nama Toko     : %s\n", listMobil[i].namatoko);
        printf("Nama Boss     : %s\n", listMobil[i].nama);
        printf("Jumlah Montir : %s\n", listMobil[i].montir);
        printf("No Hp         : %s\n", listMobil[i].kontak);
        printf("Alamat        : %s\n", listMobil[i].alamat);
        printf("Waktu Buka    : %s\n", listMobil[i].waktu);
        printf("\n");
    }
}

void bubblesort_list_motor(int banyakdata, struct DataMotor listmotor[]){
    int i, j;

    for(i = 0; i<banyakdata; i++){
        for(j=0; j< banyakdata -i -1; j++){
            if(strcmp(listmotor[j].namatoko, listmotor[j+1].namatoko)> 0){
                temp1 = listmotor[j];
                listmotor[j] = listmotor[j+1];
                listmotor[j+1] = temp1;
            }
        }
    }
}

void tampilan_bubblesort_list_motor(int banyakdata, struct DataMotor listmotor[]){
    int i;

    for (i=0; i<banyakdata; i++){
        printf("\n%d. -- Data Bengkel Motor --\n", i+1);
        printf("Nama Toko     : %s\n", listmotor[i].namatoko);
        printf("Nama Boss     : %s\n", listmotor[i].nama);
        printf("Jumlah Montir : %s\n", listmotor[i].montir); // disini harus bisa ke update otomatis
        printf("No Hp         : %s\n", listmotor[i].kontak);
        printf("Alamat        : %s\n", listmotor[i].alamat);
        printf("Waktu Buka    : %s\n", listmotor[i].waktu);
        printf("\n");
    }
}

void bubblesort_list_sepeda(int banyakdata, struct DataSepeda listsepeda[]){
    int i, j;

    for(i = 0; i<banyakdata; i++){
        for(j=0; j< banyakdata -i -1; j++){
            if(strcmp(listsepeda[j].namatoko, listsepeda[j+1].namatoko)> 0){
                temp2 = listsepeda[j];
                listsepeda[j] = listsepeda[j+1];
                listsepeda[j+1] = temp2;
            }
        }
    }
}

void tampilan_bubblesort_list_sepeda(int banyakdata, struct DataSepeda listsepeda[]){
    int i;

    for (i=0; i<banyakdata; i++){
        printf("\n%d. -- Data Bengkel Sepeda --\n", i+1);
        printf("Nama Toko     : %s\n", listsepeda[i].namatoko);
        printf("Nama Boss     : %s\n", listsepeda[i].nama);
        printf("Jumlah Montir : %s\n", listsepeda[i].montir);
        printf("No Hp         : %s\n", listsepeda[i].kontak);
        printf("Alamat        : %s\n", listsepeda[i].alamat);
        printf("Waktu Buka    : %s\n", listsepeda[i].waktu);
        printf("\n");
    }
}

void review_orderan(){
    system("cls");
    fflush(stdin);
    int banyakorder = 0;

    OrderDiterima = fopen("terima.dat", "rb");

    if (OrderDiterima == NULL){
        printf("Belum ada orderan yang masuk !!\n");
        system("pause");

        menu_admin();
    }
    while (fread(&listorder[banyakorder], sizeof(struct DataOrder), 1, OrderDiterima)== 1){
        banyakorder++;
    }

    fclose(OrderDiterima);

    bubblesort_orderan(banyakorder, listorder);

    printf("\n      Daftar Order Bengkel\n");
    tampilan_bubblesort_orderan(banyakorder, listorder);

    
    system("pause");
    menu_admin();
}

void bubblesort_orderan(int banyakorder, struct DataOrder listorder[]){
    int i, j;

    for (i=0; i<banyakorder; i++){
        for(j=0; j<banyakorder -i -1; j++){

            if(strcmp(listorder[j].namabengkel, listorder[j + 1].namabengkel)> 0){
                temp3 = listorder[j];
                listorder[j] = listorder[ j+1];
                listorder[j+1] = temp3;
            }
        }
    }
}

void tampilan_bubblesort_orderan(int banyakoder, struct DataOrder listorder[]){
    int i;

    for (i=0; i<banyakoder; i++){
        printf("\n%d. -- Data Orderan Bengkel --\n", i+1);
        printf("Nama Customer   : %s\n", listorder[i].namacustomer);
        printf("Jenis Kendaraan : %s\n", listorder[i].kendaraan);
        printf("Plat Kendaraan  : %s\n", listorder[i].plat);
        printf("Waktu Datang    : %s\n", listorder[i].waktu);
        printf("Deskripsi       : %s\n", listorder[i].deskripsi);
        printf("\n");
    }
}

void review_feedback(){
    system("cls");
    fflush(stdin);

    int i=0;
    ReviewOrderan = fopen("Daftar Orderan Bengkel.dat", "rb");

    while (fread(&order, sizeof(order), 1, ReviewOrderan)==1){
        printf("\nList Feedback\n");
        printf("%d. Nama Customer : %s\n ", i+1, order.namacustomer);
        printf("    Nama Toko     : %s\n", order.namabengkel_2);
        printf("    Feedback      : %s\n", order.feedback);
        i++; 
    }
    fclose(ReviewOrderan);       
    
    system("pause");
    menu_admin();
}

void dashboard_user()
{
    int menu;
    dashboard:
    printf("= = = = = = = = = = = = = = = =\n");
    printf("= = =  ~ User Dashboard ~ = = =\n");
    printf("= = = = = = = = = = = = = = = =\n");
    printf("= = 1. Sign Up              = =\n");
    printf("= = 2. Sign In              = =\n");
    printf("= = 0. EXIT                 = =\n");
    printf("= = = = = = = = = = = = = = = =\n");
    printf("Pilih menu /> "); scanf("%d", &menu);
    if(menu==1)
    {
        registrasi_user();
    }
    else if(menu==2)
    {
        login_user(3);
    }
    else if(menu==0)
    {
        printf("Returning to main menu . . .\n");
        system("pause");
        main();  
    }
    else printf("Invalid number, please try again . . .\n"); system("pause"); system("cls"); goto dashboard;  
}

void registrasi_user(){

    DaftarAkunuser = fopen("Daftar Akun User.dat", "ab");

    fflush(stdin);
    printf("\n   Masukan Biodata User\n");
    printf("-----===-----===-----===-----===\n");
    printf("== Nama Lengkap    : "); gets(User.nama);
    printf("== No Hp           : "); gets(User.kontak);
    printf("== Jenis Kendaraan : "); gets(User.kendaraan);
    printf("-----===-----===-----===-----===\n");
    printf("== Username        : "); gets(User.username);
    printf("== Password        : "); gets(User.password);
    printf("\n");

    fwrite(&User, sizeof(struct DataUser), 1, DaftarAkunuser);

    fclose(DaftarAkunuser);

    printf("===============================\n");
    printf("Akun User berhasil ditamahkan!!\n");
    system("pause");
    system("cls");
    dashboard_user();
}

void login_user(int percobaan){
   char username[50], password[50];
    if (percobaan > 0){
    fflush(stdin);
    printf("-=====-----=====-----=====-----\n");
    printf("===     ~ Login User ~     ===\n");
    printf("-=====-----=====-----=====-----\n");
    printf("Username: "); gets(username);
    printf("Password: "); gets(password);
    fread(&akunuser, sizeof(akunuser), 1, DaftarAkunuser) == 0;

    if (strcmp(username, username)==0 && strcmp(password, password)==0){
        printf("\n -------------------------------- \n");
        printf("Anda berhasil login ^_^\n");
        system("pause");
        system("cls");
        menu_user();
    }
    else{
         printf("\n -------------------------------- \n");
         printf("Anda gagal login !!\n Tersisa %d kesempatan lagi !!", 3-percobaan);
         if (percobaan < 3){
            system("pause");
            system("cls");
            login_user(percobaan+1);

         }else{
            printf("\n -------------------------------- \n");
            printf("Akun anda kami banned, karena sudah melebihi limit !!\n");
            printf("Terimakasih ^_^\n");
            system("pause");
            system("cls");
            main ();
         }
    }
    }
}

void menu_user(){
    int menu, n, x, banyakdata = 0;

    printf("- - - - - - - - - - - - - - - - \n");
    printf("======   ~ D'BengkelTelU ~  =====\n");
    printf("- - - - - - - - - - - - - - - - \n");
    printf("-> 1. Lihat Bengkel           <-\n");
    printf("-> 2. Pesan Bengkel           <-\n");
    printf("-> 3. Feedback                <-\n");
    printf("-> 0. Keluar                  <-\n");
    printf("- - - - - - - - - - - - - - - - \n\n");
    printf("Masukan pilihan: ");
    scanf("%d", &menu);
    getchar();
    switch (menu)
    {
    case 1:
        printf("- - - - - - - - - - - - - - - - \n");
        printf("======   ~ D'BengkelTelU ~  =====\n");
        printf("- - - - - - - - - - - - - - - - \n");
        printf("Kategori :\n");
        printf("1. Bengkel Mobil\n");
        printf("2. Bengkel Motor\n");
        printf("3. Bengkel Sepeda\n");
        
        printf("Pilih kategori :");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            DataBengkelMobil = fopen("Daftar Bengkel Mobil.dat", "rb");
            printf("\t>List Bengkel Mobil<\n");
            
            if (DataBengkelMobil == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                menu_user();
            }

            while(fread(&listMobil[banyakdata],sizeof(struct DataMobil), 1, DataBengkelMobil)== 1){
                banyakdata++;
            }

            fclose(DataBengkelMobil);
            bubblesort_list_mobil(banyakdata, listMobil);

            tampilan_bubblesort_list_mobil(banyakdata, listMobil);

            printf("\n");
            system("pause");
            system("cls");
            menu_user();
            break;
        case 2:
            DataBengkelMotor = fopen("Daftar Bengkel Motor.dat", "rb");
            printf("\t>List Bengkel Motor<\n");
            
             if(DataBengkelMotor == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                menu_user();
            }

           while (fread(&listmotor[banyakdata],sizeof(struct DataMotor), 1, DataBengkelMotor)==1){
                banyakdata++;
           }

            fclose(DataBengkelMotor);
            bubblesort_list_motor(banyakdata, listmotor);

            tampilan_bubblesort_list_motor(banyakdata, listmotor);

            printf("\n");
            system("pause");
            system("cls");
            menu_user();
            break;
        case 3:
            DataBengkelSepeda = fopen("Daftar Bengkel Sepeda.dat", "rb");
            printf("\t>List Bengkel Sepeda<\n");
             if(DataBengkelSepeda == NULL){
                printf ("Nama Bengkel tersebut belum ditambahkan !!\n");
                system("pause");

                menu_user();
            }

           while (fread(&listsepeda[banyakdata],sizeof(struct DataSepeda), 1, DataBengkelSepeda)==1){
                banyakdata++;
           }

           fclose(DataBengkelSepeda);

            bubblesort_list_sepeda(banyakdata, listsepeda);

            tampilan_bubblesort_list_sepeda(banyakdata, listsepeda);

            printf("\n");
            system("pause");
            system("cls");
            menu_user();
            break;
        default:
            printf("\tKategori tidak ada.\n");
            system("pause");
            menu_user();
            break;
        }
        break;
    case 2:
        printf("Kategori :\n");
        printf("Mobil / Motor / Sepeda");
        printf("Pilih kategori (ketik): ");
        gets(order.kategori);
        if (strcmp(order.kategori, "Mobil") == 0)
        {
            printf("\t>List Bengkel Mobil<");
            system ("cls");
            pesanbengkel_mobil();
        }
        else if (strcmp(order.kategori, "Motor") == 0)
        {
            printf("\t>List Bengkel Motor<");
            system ("cls");
            pesanbengkel_motor();
        }
        else if (strcmp(order.kategori, "Sepeda") == 0)
        {
            printf("\t>List Bengkel Sepeda<");
            system ("cls");
            pesanbengkel_sepeda();
        }
        else
        {
            printf("\tTolong masukkan kategori dengan benar.\n");
        }
        system ("cls");
        system("pause");
        menu_user();
        break;
    case 3:
        kasih_feedback();
        printf("\nKlik tombol enter untuk melanjutkan\n");
        getchar();
        menu_user();
    case 0:
        logout();
        menu_user();
        break;
    default:
        printf("\n\t\t Menu salah, masukan ulang!");
        getchar();
        main();
        break;
    }
}

void logout()
{
    
    printf("\nApakah anda yakin ingin logout?");
    printf("\nketik 'YA' jika anda yakin\n");
    printf("/> ");
    gets(confirm);
    if (strcmp(confirm, "YA") == 0 || strcmp(confirm, "ya") == 0)
    {
        main();
    }
}

void pesanbengkel_mobil(){
    int x = 0;
    DataBengkelMobil = fopen("Daftar bengkel Mobil.dat", "rb");
    printf("\n   >Masukan nama bengkel yang ingin di cari<");
    printf("\nNama Bengkel : ");
    gets(order.pesanan);
    while (fread(&mobil, sizeof(mobil), 1, DataBengkelMobil) == 1)
    {
        if (strcmp(order.pesanan, mobil.namatoko) == 0)
        {
            x = 1;
        }
    }
    if (x == 1)
    {
        OrderDiterima = fopen("terima.dat", "ab");
        printf("\t>Bengkel ditemukan, Order berhasil<");
        printf("\n\t        >Masukan Data<\n\n");
        printf("============================================\n");
        printf("Nama Pelanggan    : "); gets(order.namacustomer);
        printf("Kendaraan         : "); gets(order.kendaraan);
        printf("Plat              : "); gets(order.plat);
        printf("============================================\n");
        printf("Waktu Datang      : ");gets(order.waktu);
        printf("Deskripsi Masalah : "); gets(order.deskripsi);
        fwrite(&order, sizeof(order), 1, OrderDiterima);
        fclose(OrderDiterima);

        printf("\nPesanan Berhasil Terkirim\n");
        system("pause");
        system("cls");
        menu_user();
    }
    else
    {
        printf("\n\t>Bengkel tidak ditemukan, Order gagal<");
        printf("\nKlik tombol enter untuk melanjutkan\n");
        getchar();
        menu_user();
    }
    fclose(DataBengkelMobil);

}

void pesanbengkel_motor(){
    int x = 0, hasil, banyakdata;
    DataBengkelMotor = fopen("Daftar bengkel Motor.dat", "rb");
    printf("\n   >Masukkan nama bengkel yang ingin di cari<");
    printf("\nNama Bengkel : ");
    gets(order.pesanan);

    while (fread(&motor, sizeof(motor), 1, DataBengkelMotor) == 1)
    {
        if (strcmp(order.pesanan, motor.namatoko) == 0)
        {
            x = 1;
            // Kurangi jumlah montir
            hasil = atoi(motor.montir); // dari string ke int
            if(hasil > 0){
                hasil--;
                sprintf(motor.montir, "%d", hasil);
            } else {
                printf("Tidak ada montir yang tersedia saat ini.\n");
                fclose(DataBengkelMotor);
                return; // Keluar dari fungsi jika tidak ada montir yang tersedia
            }
            // Update jumlah montir dalam struktur listmotor agar perubahan terlihat saat ditampilkan
            // for (int i = 0; i < banyakdata; i++) {
            //     if (strcmp(order.pesanan, listmotor[i].namatoko) == 0) {
            //         strcpy(listmotor[i].montir, motor.montir);
            //         break; // Keluar dari loop setelah update dilakukan
            //     }
            // }
            // break;
        }
    }

    fclose(DataBengkelMotor);

    if (x == 1)
    {
        OrderDiterima = fopen("terima.dat", "ab");
        printf("\t>Bengkel ditemukan, Order berhasil<");
        printf("\n\t        >Masukan Data<\n\n");
        printf("============================================\n");
        printf("Nama Pelanggan    : "); gets(order.namacustomer);
        printf("Kendaraan         : "); gets(order.kendaraan);
        printf("Plat              : "); gets(order.plat);
        printf("============================================\n");
        printf("Waktu Datang      : "); gets(order.waktu);
        printf("Deskripsi Masalah : "); gets(order.deskripsi);

        // Menulis data order ke dalam file
        fwrite(&order, sizeof(order), 1, OrderDiterima);
        fclose(OrderDiterima);

        printf("\nPesanan Berhasil Terkirim\n");
        system("pause");
        system("cls");
        menu_user();
    }
    else
    {
        printf("\n\t>Bengkel tidak ditemukan, Order gagal<");
        printf("\nKlik tombol enter untuk melanjutkan\n");
        getchar();
        menu_user();
    }
}


void pesanbengkel_sepeda(){
    int x = 0;
    DataBengkelSepeda = fopen("Daftar bengkel Sepeda.dat", "rb");
    printf("\n   >Masukan nama bengkel yang ingin di cari<");
    printf("\nNama Bengkel : ");
    gets(order.pesanan);
    while (fread(&sepeda, sizeof(sepeda), 1, DataBengkelMotor) == 1)
    {
        if (strcmp(order.pesanan, sepeda.namatoko) == 0)
        {
            x = 1;
        }
    }
    if (x == 1)
    {
        OrderDiterima = fopen("terima.dat", "ab");
        printf("\t>Bengkel ditemukan, Order berhasil<");
        printf("\n\t        >Masukan Data<\n\n");
        printf("============================================\n");
        printf("Nama Pelanggan     : "); gets(order.namacustomer);
        printf("Kendaraan          : "); gets(order.kendaraan);
        printf("Plat               : "); gets(order.plat);
        printf("============================================\n");
        printf("Waktu Datang       : ");gets(order.waktu);
        printf("Deskripsi Masalah  : "); gets(order.deskripsi);
        fwrite(&order, sizeof(order), 1, OrderDiterima);
        fclose(OrderDiterima);

        printf("\nPesanan Berhasil Terkirim\n");
        system("pause");
        system("cls");
        menu_user();
    }
    else
    {
        printf("\n\t>Bengkel tidak ditemukan, Order gagal<");
        printf("\nKlik tombol enter untuk melanjutkan\n");
        getchar();
        fclose(DataBengkelSepeda);
        menu_user();
    }
    fclose(DataBengkelSepeda);
}

void kasih_feedback(){
    system("cls");
    fflush(stdin);

    ReviewOrderan = fopen("Daftar Orderan Bengkel.dat", "ab");

    printf("\nMasukkan Nama Bengkel yang ingin diberi feedback\n");
    printf("==================================================\n");
    printf("Nama Toko : "); gets(order.namabengkel_2);
    printf("==================================================\n");
    printf("Feedback  : "); gets(order.feedback);

    fwrite(&order, sizeof(order), 1, ReviewOrderan);
    fclose(ReviewOrderan);

    printf("\nFeedback Berhasil Terkirim\n");
    system("pause");
    system("cls");
    menu_user();
}