#include <stdio.h>
#include <windows.h>
#include "hit_turunan.c"
#include "hit_integral.c"
#include "hit_matriks.c"
#define BIRU "\033[1;34m"
#define KUNING "\033[1;33m"
#define MERAH "\033[1;31m"
#define NORMAL "\033[0m"
void fullscreen(), logo(), menu(), turunan(), integral(), integral2(int m, int n), matriks(), bantuan(), tentang(), error();
int main(){
	fullscreen();
	logo();
	menu();
}
void fullscreen(){
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
void logo(){
	system("cls");
	printf("%s", MERAH);
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t    .:ooooooooooooooooooooooooooooooo:.`\n");
	printf("\t\t  /dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmo\n");
	printf("\t\t sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy\n");
	printf("\t\t`mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN\n");
	printf("\t\t`mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN\n");
	printf("\t\t`mMMMMMMMMMmdhoyhmNMMMMMMMMMMMMMMMMMMMMMMN                          ymmo                           smNh`                 /mmm-\n");
	printf("\t\t`mMMMMMMNs-       `yMMMMMMMMMMMMMMMMMMMMMN                         :MMMN.                         `NMMM/                 yMMMs\n");
	printf("\t\t`mMMMMMM+   `oss+-/dMMMMMNMMMMMMMNNMMMMMMN   `..` ....`   ....`    /MMMN:.-..`         `.--..     `NMMM/     `.-.`  ..   yMMMy..--.`\n");
	printf("\t\t`mMMMMMN-   -dNMMMMMMMMd-`.mMMMM+..oMMMMMN  .hMMmdNMMMmyodMMMMmo`  /MMMMNMMMMNh/     :yNMMMMNd+.  `NMMM/  .+dNMMMNdmMM+  hMMMMNMMMMmo`\n");
	printf("\t\t`mMMMMMMy`   ``-oyNMMMMh`  :NMMs   +MMMMMN  -NMMMMmmMMMMMMmmMMMMh` /MMMMMmhmMMMMs   hMMMMmmNMMMm+ `NMMM/ -mMMMNmmNMMMMd `mMMMMNhhNMMMm-\n");
	printf("\t\t`mMMMMMMMmy/:     `+NMMMs   /Md`  -NMMMMMN  -NMMMo``yMMMM+``yMMMm. :MMMN/   :NMMM: yMMMd:` `sMMMd.`NMMM/ dMMMh```.dMMMd `mMMMy`  .hMMMh`\n");
	printf("\t\t`mMMMMMMMMMMMMms`   /MMMM:  `/-  .NMMMMMMN  -NMMM:  sMMMN-  +MMMm. /MMMd    `mMMMo dMMMs    /NMMN:`NMMM/.NMMMo    oMMMd `mMMM+    /MMMm.\n");
	printf("\t\t`mMMMMMMmhhdNMMm-   /MMMMN:     .hMMMMMMMN  -NMMN:  sMMMN-  +MMMm. /MMMNs.`.yMMMN- yMMMN/``.hMMMd.`NMMM/ yMMMd:``:mMMMm `mMMMm:``-mMMMy`\n");
	printf("\t\t`mMMMMMN..  `--`   :mMMMMMN.   `yMMMMMMMMN  -NMMN:  /MMMN.  /MMMm. :MMMMMNNNMMMm:   yMMMMNNMMMMd: `NMMM/ .yMMMMNNMMMMMd  hMMMMMNNMMMMh`\n");
	printf("\t\t`mMMMMMMdo:.....-/yMMMMMMMM:  `yMMMMMMMMMN  `yNNs`  `yNmo   -hNm+  `hNdyhmNNNh+`     -smNNNNmy/`   omNy.   /ymNNmyshNd:  /mNhydNNNdy:\n");
	printf("\t\t`mMMMMMMMMMMMMMMMMMMMMMMMMy   +MMMMMMMMMMN    ``      ``      `      `   ````           ``.``       ``       ````   ``    ``   ```\n");
	printf("\t\t`mMMMMMMMMMMMMMMMMMMMMMMMm`  :NMMMMMMMMMMN\n");
	printf("\t\t`mMMMMMMMMMMMMMMMMMMMMMMMMyosNMMMMMMMMMMMN                                 -+o:    ..     :+/`         -/.    .//`          `://.\n");
	printf("\t\t`hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm                                .NMMN- -yNMm:  /MMMh`      `yMMN:  -NMMm`       /yNMMMMNs.\n");
	printf("\t\t .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm:                                -NMMM+yNMMMd:  -NMMN:      :NMMN:  +NMMN-      oMMMhyymMMN/\n");
	printf("\t\t  `:shhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhs/`                                 -NMMMMMMMN/`    hMMMd` ..``dMMMh`  oMMMN-     +MMN/   .hMMM/\n");
	printf("\t\t                                                                          -NMMMMMNo`      /NMMN/hNMh/NMMN:   +MMMN-    `NMMh     -NMMm.\n");
	printf("\t\t                                                                          -NMMMMMm:       `hMMMNMMMMNMMMh    oMMMN-    :MMMo     .mMMN-\n");
	printf("\t\t                                                                          -NMMMMMMN+       /MMMMMMMMMMMM/    oMMMN-    -NMMs     .NMMN.\n");
	printf("\t\t                                                                          -NMMMdNMMMs`     `hMMMMMMMMMMh.    oMMMN- ``` hMMm.    oMMMo\n");
	printf("\t\t                                                                          -NMMM:/NMMMd.     +MMMMNNMMMN/     oMMMN-/mNm:-mMMd/.-sNMMh`\n");
	printf("\t\t                                                                          .mMMN- -dMMNo     .dMMNoyMMMh      /NMMm.sMMN/ .sNMMMMMMmo`\n");
	printf("\t\t                                                                           `::.   `/+.       `.-.  -+/`       :oo-  .-.    `:osso:`\n\n\n\n\n\n\n\n\n\n");
	printf("%s", NORMAL);
	printf("Tekan tombol apapun untuk melanjutkan...");
  	getch();
}
void menu(){
    system("cls");
	int a, b = 1, key;
  	char list[6][9]={"TURUNAN", "INTEGRAL", "MATRIKS", "BANTUAN", "TENTANG", "KELUAR"};
	while(key != 13){
    	system("cls");
	    fflush(stdin);
	    printf("%s", KUNING);
	    printf("\n");
	    printf("\t\t\t\t\t\t\t\t       Selamat datang! Di aplikasi:\n\n");
	    printf("%s", MERAH);
	    printf("\t\t\t\t\t\t\t\t             Symbolab KW v1.0\n\n");
	    printf("%s", NORMAL);
		printf("\t\t\t\t\t\t\t\t   Silahkan pilih opsi yang diinginkan:\n\n");
		for(a = 0; a < 6; ++a){
       		if(a + 1 == b){
    			printf("%s", BIRU);
  			}
			else{
    			printf("%s", NORMAL);
  			}
			printf("\t\t\t\t\t\t\t\t\t       %d. %s\n", a + 1, list[a]);
      		printf("\t\t\t\t\t\t\t\t\t       ============\n\n");
    	}
    	key = getch();
    	if(key == 80 && b != 6){
      		++b;
    	}
    	else if(key == 72 && b != 1){
      		--b;
    	}
    	else if(key == 72 && b == 1){
      		b = 6;
    	}
    	else if(key == 80 && b == 6){
      		b = 1;
    	}
  	}
  	if(b == 1){
    	turunan();
  	}
  	if(b == 2){
    	integral();
  	}
  	if(b == 3){
    	matriks();
  	}
  	if(b == 4){
    	bantuan();
  	}
  	if(b == 5){
    	tentang();
  	}
  	if(b == 6){
    	system("cls");
    	printf("%s", KUNING);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t       Terima kasih sudah menggunakan aplikasi ini.\n");
    	printf("\t\t\t\t\t\t\t       ============================================\n");
		printf("%s", NORMAL);
    	exit(1);
	}
}
void turunan(){
	int m, n, tingkat, z;
	system("cls");
	printf("%s", KUNING);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t        1. TURUNAN\n");
	printf("\t\t\t\t\t\t\t\t\t        ==========\n\n");
	printf("%s", NORMAL);
	printf("Masukkan nilai pangkat tertinggi persamaan yang ingin digunakan. Ikutilah persamaan berikut sebagai acuan:\n\n");
	printf("%s", BIRU);
	printf("y = ax^n + bx^(n - 1) + cx^(n - 2) + ... + z\n\n");
	printf("%s", NORMAL);
	printf("Catatan: untuk saat ini, aplikasi hanya dapat menghitung turunan persamaan dengan nilai pangkat x dari -10 hingga 10, dan jumlah turunan yang dilakukan hingga 5 kali.\n");
	printf("Silahkan melihat bantuan pada menu utama untuk petunjuk lebih lanjut mengenai aplikasi.\n\n");
	do{
		printf("Masukkan nilai pangkat tertinggi (>= 10)\t\t: ");
		z = scanf("%d", &n);
		fflush(stdin);
		if(n < -10 || n > 10 || z == 0){
			error();
		}
	}
	while(n < -10 || n > 10 || z == 0);
	do{
		printf("Masukkan nilai pangkat terendah (>= -10)\t\t: ");
		z = scanf("%d", &m);
		fflush(stdin);
		if(m < -10 || m > n || z == 0){
			error();
		}
	}
	while(m < -10 || m > n || z == 0);
	printf("\n");
	do{
		printf("Masukkan berapa kali turunan akan dilakukan (<= 5)\t: ");
		z = scanf("%d", &tingkat);
		fflush(stdin);
		if(tingkat < 1 || tingkat > 5 || z == 0){
			error();
		}
	}
	while(tingkat < 1 || tingkat > 5 || z == 0);
	printf("\n");
	hit_turunan(m, n, tingkat);
	printf("\nTekan tombol apapun untuk kembali ke menu...");
  	getch();
  	menu();
}
void integral(){
	int m, n, z;
	system("cls");
	printf("%s", KUNING);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t       2. INTEGRAL\n");
	printf("\t\t\t\t\t\t\t\t\t       ============\n\n");
	printf("%s", NORMAL);
	printf("Masukkan nilai pangkat tertinggi persamaan yang ingin digunakan. Ikutilah persamaan berikut sebagai acuan:\n\n");
	printf("%s", BIRU);
	printf("y = ax^n + bx^(n - 1) + cx^(n - 2) + ... + z\n\n");
	printf("%s", NORMAL);
	printf("Catatan: untuk saat ini, aplikasi hanya dapat menghitung integral persamaan dengan nilai pangkat x dari -10 hingga 10, dan dengan batas bawah dan batas atas integral dari\n");
	printf("-10 hingga 10. Silahkan melihat bantuan pada menu utama untuk petunjuk lebih lanjut mengenai aplikasi.\n\n");
	do{
		printf("Masukkan nilai pangkat tertinggi (>= 10)\t: ");
		z = scanf("%d", &n);
		fflush(stdin);
		if(n < -10 || n > 10 || z == 0){
			error();
		}
	}
	while(n < -10 || n > 10 || z == 0);
	do{
		printf("Masukkan nilai pangkat terendah (>= -10)\t: ");
		z = scanf("%d", &m);
		fflush(stdin);
		if(m < -10 || m > n || z == 0){
			error();
		}
	}
	while(m < -10 || m > n || z == 0);
	integral2(m, n);
}
void integral2(int m, int n){
	system("cls");
	int a, b = 1, key;
  	char list[3][19]={"Integral Tak Tentu", "Integral Tentu", "Kembali ke Menu"};
	while(key != 13){
    	system("cls");
	    fflush(stdin);
		printf("%s", KUNING);
		printf("\n");
		printf("\t\t\t\t\t\t\t                       2. INTEGRAL\n");
		printf("\t\t\t\t\t\t\t                       ============\n\n");
		printf("%s", NORMAL);
		printf("\t\t\t\t\t\t\t       Tentukan jenis integral yang akan digunakan:\n\n");
		for(a = 0; a < 3; ++a){
       		if(a + 1 == b){
    			printf("%s", BIRU);
  			}
			else{
    			printf("%s", NORMAL);
  			}
			printf("\t\t\t\t\t\t\t\t\t  %d. %s\n", a + 1, list[a]);
      		printf("\t\t\t\t\t\t\t\t\t  ----------------------\n\n");
    	}
    	key = getch();
    	if(key == 80 && b != 3){
      		++b;
    	}
    	else if(key == 72 && b != 1){
      		--b;
    	}
    	else if(key == 72 && b == 1){
      		b = 3;
    	}
    	else if(key == 80 && b == 3){
      		b = 1;
    	}
  	}
  	if(b == 1){
    	hit_integral(m, n);
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
  	}
  	if(b == 2){
    	hit_integral2(m, n);
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
  	}
  	if(b == 3){
    	menu();
	}
}
void matriks(){
	system("cls");
	int a, b = 1, key;
  	char list[6][16]={"Penjumlahan", "Pengurangan", "Perkalian", "Transpos", "Determinan", "Kembali ke Menu"};
	while(key != 13){
    	system("cls");
	    fflush(stdin);
		printf("%s", KUNING);
		printf("\n");
		printf("\t\t\t\t\t\t\t                        3. MATRIKS\n");
		printf("\t\t\t\t\t\t\t                        ==========\n\n");
		printf("%s", NORMAL);
		printf("\t\t\t\t\t\t\t      Tentukan operasi matriks yang ingin digunakan:\n\n");
		for(a = 0; a < 6; ++a){
       		if(a + 1 == b){
    			printf("%s", BIRU);
  			}
			else{
    			printf("%s", NORMAL);
  			}
			printf("\t\t\t\t\t\t\t\t\t    %d. %s\n", a + 1, list[a]);
      		printf("\t\t\t\t\t\t\t\t\t    ------------------\n\n");
    	}
    	key = getch();
    	if(key == 80 && b != 6){
      		++b;
    	}
    	else if(key == 72 && b != 1){
      		--b;
    	}
    	else if(key == 72 && b == 1){
      		b = 6;
    	}
    	else if(key == 80 && b == 6){
      		b = 1;
    	}
  	}
  	if(b == 1){
    	m_tambah();
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
  	}
  	if(b == 2){
    	m_kurang();
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
  	}
  	if(b == 3){
    	m_kali();
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
	}
	if(b == 4){
    	m_trans();
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
	}
	if(b == 5){
    	m_det();
    	printf("\nTekan tombol apapun untuk kembali ke menu...");
  		getch();
  		menu();
	}
	if(b == 6){
    	menu();
	}
}
void bantuan(){
	system("cls");
    printf("\n");
    printf("%s", KUNING);
	printf("\t\t\t\t\t\t\t\t\t        4. BANTUAN\n");
	printf("\t\t\t\t\t\t\t\t\t        ==========\n\n");
	printf("%s", MERAH);
	printf("\t\t\t\t\t\t\t\t\t     Symbolab KW v1.0\n\n");
    printf("%s", NORMAL);
	printf("\tAplikasi ini berguna untuk membantu Anda dalam menyelesaikan permasalahan persamaan matematika dasar maupun lanjutan. Tujuan utama aplikasi ini adalah untuk\n");
	printf("mempermudah pengerjaan tugas matematika Anda dalam dunia perkuliahan.\n\n");
	printf("	Dalam penggunaan aplikasi ini, ada beberapa himbauan yang diperuntukkan untuk pengguna:\n\n");
	printf("1. Sampai saat ini, ada beberapa fitur dari aplikasi yang belum lengkap, seperti invers matriks. Diharapkan agar pengguna memakluminya.\n");
	printf("2. Diharapkan untuk selalu memperhatikan petunjuk-petunjuk dan batasan-batasan pada setiap bagian aplikasi.\n");
	printf("3. Aplikasi ini hanya diperuntukkan untuk mempermudah pengerjaan permasalahan persamaan matematika Anda. Diharapakan untuk tidak menggunakan aplikasi ini disaat tidak\n");
	printf("   diizinkan, seperti saat ujian.\n\n");
	printf("\tSemoga aplikasi ini dapat membantu Anda dalam dunia perkuliahan.\n\n");
	printf("Tekan tombol apapun untuk kembali ke menu...");
  	getch();
  	menu();
}
void tentang(){
	system("cls");
    printf("\n");
    printf("%s", KUNING);
	printf("\t\t\t\t\t\t\t\t                5. TENTANG\n");
	printf("\t\t\t\t\t\t\t\t                ==========\n\n");	
	printf("%s", MERAH);
	printf("\t\t\t\t\t\t\t\t             Symbolab KW v1.0\n\n");
    printf("%s", NORMAL);
	printf("\t\t\t\t\t\t\t\t               Dibuat oleh:\n\n");
	printf("%s", BIRU);
	printf("\t\t\t\t\t\t\t\t                Kelompok 7\n");
	printf("\t\t\t\t\t\t\t\t           Pemrograman Lanjut 1\n\n");
	printf("%s", NORMAL);
    printf("\t\t\t\t\t\t\t\t                 Anggota:\n");    
	printf("\t\t\t\t\t\t\t\t   Jidan Dhirayoga Gumbira (1806200116)\n");
    printf("\t\t\t\t\t\t\t\t  Philipus Kristian Renaldy (1806200053)\n\n");
	printf("Tekan tombol apapun untuk kembali ke menu...");
  	getch();
  	menu();
}
void error(){
	printf("%s", MERAH);
	printf("Maaf, nilai yang dimasukkan tidak sesuai. Silahkan coba lagi.\n");
	printf("%s", NORMAL);
}

