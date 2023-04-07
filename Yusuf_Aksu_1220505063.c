#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

bool palindrom(struct Dugum* baslangic) {
    struct Dugum* yavas = baslangic;
    struct Dugum* hizli = baslangic;
    struct Dugum* onceki = NULL;
    struct Dugum* sonraki;

    // Bağlı listenin orta noktasına gelinir.
    while (hizli != NULL && hizli->sonraki != NULL) {
        hizli = hizli->sonraki->sonraki;

        sonraki = yavas->sonraki;
        yavas->sonraki = onceki;
        onceki = yavas;
        yavas = sonraki;
    }

    // Hızlı pointer null değilse yavaş pointer'ı bir sonraki elemana kaydır.
    if (hizli != NULL) {
        yavas = yavas->sonraki;
    }

    // İlk yarı ile ikinci yarı karşılaştırılır.
    while (yavas != NULL) {
        if (yavas->veri != onceki->veri) {
            return false;
        }
        yavas = yavas->sonraki;
        onceki = onceki->sonraki;
    }

    return true;
}

int main() {
    struct Dugum* baslangic = NULL;
    struct Dugum* ikinci = NULL;
    struct Dugum* ucuncu = NULL;
    struct Dugum* dorduncu = NULL;

    baslangic = (struct Dugum*)malloc(sizeof(struct Dugum));
    ikinci = (struct Dugum*)malloc(sizeof(struct Dugum));
    ucuncu = (struct Dugum*)malloc(sizeof(struct Dugum));
    dorduncu = (struct Dugum*)malloc(sizeof(struct Dugum));

    baslangic->veri = 3;
    baslangic->sonraki = ikinci;

    ikinci->veri = 4;
    ikinci->sonraki = ucuncu;

    ucuncu->veri = 4;
    ucuncu->sonraki = dorduncu;

    dorduncu->veri = 3;
    dorduncu->sonraki = NULL;

    if (palindrom(baslangic)) {
        printf("Verilen bagli liste palindromdur.\n");
    } else {
        printf("Verilen bagli liste palindrom degildir.\n");
    }

    return 0;
}
