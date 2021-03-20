#define BIRU "\033[1;34m"
#define KUNING "\033[1;33m"
#define MERAH "\033[1;31m"
#define NORMAL "\033[0m"
void hit_turunan(int m, int n, int tingkat), hasil_turunan(int m, int n, int pass, int tingkat, int x, int y, float koef[21]), error();
void hit_turunan(int m, int n, int tingkat){
	int pass, x = 0, y = 0, z;
	float koef[21];
	memset(koef, 0, sizeof(koef[0]) * 21);
	for(x; (n - x) >= m; ++x){
		do{
			if((n - x) == 0){
				printf("Masukkan nilai konstanta\t\t\t\t: ");
			}
			else if((n - x) == 1){
				printf("Masukkan nilai koefisien untuk x\t\t\t: ");
			}
			else{
				printf("Masukkan nilai koefisien untuk x^(%d)\t\t\t: ", (n - x));
			}
			z = scanf("%f", &koef[x]);
			fflush(stdin);
			if(z == 0){
				error();
			}
		}
		while(z == 0);
	}
	printf("%s", KUNING);
	printf("\nPersamaan awal:\n");
	printf("%s", NORMAL);
	printf("= ");
	for(x = 0; (n - x) >= m; ++x){
		if(koef[x] == 0){
			continue;
		}
		if(pass == 1){
			printf(" + ");
		}
		printf("(%.2f)", koef[x]);
		if((n - x) != 0){
			printf("x");
		}
		if((n - x) != 0 && (n - x) != 1){
			printf("^(%d)", (n - x));
		}
		pass = 1;
	}
	if(pass == 0){
		printf("0");
	}
	printf("\n");
	for(y; y < tingkat; ++y){
		hasil_turunan(m, n, pass, tingkat, x, y, koef);
	}
}
void hasil_turunan(int m, int n, int pass, int tingkat, int x, int y, float koef[21]){
	printf("%s", KUNING);
	printf("\nTurunan ke-%d dari persamaan tersebut:\n", y + 1);
	printf("%s", NORMAL);
	printf("= ");
	pass = 0;
	for(x = 0; (n - x) >= m; ++x){
		if(koef[x] == 0 || (n - x - y) == 0){
			koef[x] = 0;
			continue;
		}
		if(pass == 1){
			printf(" + ");
		}
		koef[x] *= (n - x - y);
		printf("(%.2f)", koef[x]);
		if((n - x - y - 1) != 0){
			printf("x");
		}
		if((n - x - y - 1) != 0 && (n - x - y - 1) != 1){
			printf("^(%d)", (n - x - y - 1));
		}
		pass = 1;
	}
	if(pass == 0){
		printf("0");
	}
	printf("\n");
}

