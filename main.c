#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini saklamak icin struct tanimliyoruz(cunku hepsini tekrardan cagiracagız)
struct tarihBilgisi {
    int yil, ay, gun, saat, dakika, saniye;
};

// Epoch zamanini saklamak icin union kullaniyoruz
union EpochZamani {
    time_t epoch;
};

// Kullanicinin girdigi tarih ve saat bilgisini epoch'a ceviren fonksiyon
time_t epochaDonustur(struct tarihBilgisi tb) {
    struct tm zaman = {0};
    zaman.tm_year = tb.yil - 1900;
    zaman.tm_mon = tb.ay - 1;
    zaman.tm_mday = tb.gun;
    zaman.tm_hour = tb.saat;
    zaman.tm_min = tb.dakika;
    zaman.tm_sec = tb.saniye;
    return mktime(&zaman);
}

int main() {
    struct tarihBilgisi tarih1, tarih2;
    union EpochZamani epoch1, epoch2;
    printf("Iki Tarih Arasindaki Farki Hesaplayan Program\n");

    // Kullanicidan iki tarih aliniyor
// Birinci tarihi alma
    printf("Birinci tarihi girin:\n");
    do {
        printf("Yil (Epoch zamani 1 Ocak 1970 tarihinden baslar): ");
        scanf("%d", &tarih1.yil);
    } while (tarih1.yil < 1970);

    do {
        printf("Ay (1-12): ");
        scanf("%d", &tarih1.ay);
    } while (tarih1.ay < 1 || tarih1.ay > 12);

    do {
        printf("Gun (1-31): ");
        scanf("%d", &tarih1.gun);
    } while (tarih1.gun < 1 || tarih1.gun > 31);

    do {
        printf("Saat (0-23): ");
        scanf("%d", &tarih1.saat);
    } while (tarih1.saat < 0 || tarih1.saat > 23);

    do {
        printf("Dakika (0-59): ");
        scanf("%d", &tarih1.dakika);
    } while (tarih1.dakika < 0 || tarih1.dakika > 59);

    do {
        printf("Saniye (0-59): ");
        scanf("%d", &tarih1.saniye);
    } while (tarih1.saniye < 0 || tarih1.saniye > 59);

    // Ikinci tarihi alma
    printf("Ikinci tarihi girin:\n");
    do {
        printf("Yil:(Epoch zamani 1 Ocak 1970 tarihinden baslar)");
        scanf("%d", &tarih2.yil);
    } while (tarih2.yil < 1970);

    do {
        printf("Ay (1-12): ");
        scanf("%d", &tarih2.ay);
    } while (tarih2.ay < 1 || tarih2.ay > 12);

    do {
        printf("Gun (1-31): ");
        scanf("%d", &tarih2.gun);
    } while (tarih2.gun < 1 || tarih2.gun > 31);

    do {
        printf("Saat (0-23): ");
        scanf("%d", &tarih2.saat);
    } while (tarih2.saat < 0 || tarih2.saat > 23);

    do {
        printf("Dakika (0-59): ");
        scanf("%d", &tarih2.dakika);
    } while (tarih2.dakika < 0 || tarih2.dakika > 59);

    do {
        printf("Saniye (0-59): ");
        scanf("%d", &tarih2.saniye);
    } while (tarih2.saniye < 0 || tarih2.saniye > 59);
    
    // Epoch zamanlarina donusturuluyor
    epoch1.epoch = epochaDonustur(tarih1);
    epoch2.epoch = epochaDonustur(tarih2);

    // Epoch farki hesaplaniyor
    double fark = difftime(epoch2.epoch, epoch1.epoch);

    if (fark < 0) {
        fark = -fark;
    }

    // Sonuclar ekrana yazdiriliyor
    printf("Birinci tarih Epoch: %ld\n", epoch1.epoch);
    printf("Ikinci tarih Epoch: %ld\n", epoch2.epoch);
    printf("Zaman farki: %.0f saniye\n", fark);
    printf("Zaman farki: %.2f dakika\n", fark/60);
    printf("Zaman farki: %.2f saat\n", fark/3600);
    printf("Zaman farki: %.2f gun\n",fark/(3600*24));
    
    

    return 0;
}
