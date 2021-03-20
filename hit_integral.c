#include <math.h>
#define BIRU "\033[1;34m"
#define KUNING "\033[1;33m"
#define MERAH "\033[1;31m"
#define NORMAL "\033[0m"
void hit_integral(int m, int n), hit_integral2(int m, int n), hasil_integral(int m, int n, int x, float koef[21]), hasil_integral2(int m, int n, int p, int q, int x, float koef[21]), error();
void hit_integral(int m, int n){
	int pass, x, z;
	float koef[21];
	memset(koef, 0, sizeof(koef[0]) * 21);
	system("cls");
	printf("%s", KUNING);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t  1. Integral Tak Tentu\n");
    printf("\t\t\t\t\t\t\t\t\t  ----------------------\n");
	printf("%s", NORMAL);
	for(x = 0; (n - x) >= m; ++x){
		do{
			if((n - x) == 0){
				printf("Masukkan nilai konstanta\t: ");
			}
			else if((n - x) == 1){
				printf("Masukkan nilai koefisien untuk x\t\t: ");
			}
			else{
				printf("Masukkan nilai koefisien untuk x^(%d)\t: ", (n - x));
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
	hasil_integral(m, n, x, koef);
}
void hasil_integral(int m, int n, int x, float koef[21]){
	int pass;
	printf("%s", KUNING);
	printf("\nIntegral dari persamaan tersebut:\n");
	printf("%s", NORMAL);
	printf("= ");
	for(x = 0; (n - x) >= m; ++x){
		if(koef[x] == 0){
			continue;
		}
		if(pass == 1){
			printf(" + ");
		}
		if((n - x + 1) == 0){
			if(koef[x] != 1){
				printf("(%.2f)", koef[x]);
			}
			printf("ln(x)");
			continue;
		}
		if((n - x) != 0){
			koef[x] /= (n - x + 1);
		}
		printf("(%.2f)", koef[x]);
		if((n - x + 1) != 0){
			printf("x");
		}
		if((n - x + 1) != 0 && (n - x + 1) != 1){
			printf("^(%d)", (n - x + 1));
		}
		pass = 1;
	}
	if(pass == 1){
		printf(" + ");
	}
	printf("c\n");
}
void hit_integral2(int m, int n){
	int pass, x, z;
	float koef[21], p, q;
	memset(koef, 0, sizeof(koef[0]) * 21);
	system("cls");
	printf("%s", KUNING);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t    2. Integral Tentu\n");
    printf("\t\t\t\t\t\t\t\t\t    ------------------\n");
	printf("%s", NORMAL);
	do{
		printf("Masukkan nilai batas atas integral (<= 10)\t: ");
		z = scanf("%f", &q);
		fflush(stdin);
		if(q < -10 || q > 10 || z == 0){
			error();
		}
	}
	while(q < -10 || q > 10 || z == 0);
	do{
		printf("Masukkan nilai batas bawah integral (>= -10)\t: ");
		z = scanf("%f", &p);
		fflush(stdin);
		if(p < -10 || p > q || z == 0){
			error();
		}
	}
	while(p < -10 || p > q || z == 0);
	printf("\n");
	for(x = 0; (n - x) >= m; ++x){
		do{
			if((n - x) == 0){
				printf("Masukkan nilai konstanta\t\t\t: ");
			}
			else if((n - x) == 1){
				printf("Masukkan nilai koefisien untuk x\t\t: ");
			}
			else{
				printf("Masukkan nilai koefisien untuk x^(%d)\t\t: ", (n - x));
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
	hasil_integral2(m, n, p, q, x, koef);
}
void hasil_integral2(int m, int n, int p, int q, int x, float koef[21]){
	int pass;
	float ba, bb;
	printf("%s", KUNING);
	printf("\nHasil integral dari persamaan tersebut:\n");
	printf("%s", NORMAL);
	printf("= ");
	for(x = 0; (n - x) >= m; ++x){
		if(m < 0){
			break;
		}
		if((n - x + 1) == 0){
			ba += koef[x] * log(q);
			bb += koef[x] * log(p);
			continue;
		}
		ba += (koef[x] / (n - x + 1)) * pow(q, (n - x + 1));
		bb += (koef[x] / (n - x + 1)) * pow(p, (n - x + 1));
	}
	if(m < 0){
		printf("Integral tidak konvergen\n");
	}
	else{
		printf("%.2f\n", ba - bb);
	}	
}

