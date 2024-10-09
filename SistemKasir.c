#include <stdio.h>
//Definisikan Maksimum Jumlah Barang
#define MAKSIMUM_BARANG 10

struct Barang
{
    char nama[50];
    float harga;
    int kuantitas;
    float diskon;
};

int main()
{
    struct Barang barang[MAKSIMUM_BARANG];
    int n;
    float total_harga  = 0.0;

    //Input Jumlah Barang
    printf("Input jumlah barang: "); scanf("%i",&n);

    //Input Detail Barang
    for(int i = 0; i < n; i++)
    {
        printf("\nInput detail untuk barang %i\n",i + 1);

        printf("Nama: "); scanf("%s",&barang[i].nama);
        printf("Harga: "); scanf("%f",&barang[i].harga);
        printf("Kuantitas: "); scanf("%i",&barang[i].kuantitas);
        printf("Diskon (%%): "); scanf("%f",&barang[i].diskon);
    }
    //Output Struk
    printf("\nStruk:\n");
    printf("==================================================\n");
    printf("No.\tNama\tHarga\tKuantitas\tDiskon\tTotal\n");
    printf("==================================================\n");

    for (int i = 0; i < n; i++)
    {
        //Harga Sebelum Diskon
        float harga_sebelum_diskon = barang[i].harga * barang[i].kuantitas;
        //Harga Setelah Diskon
        float jumlah_diskon = harga_sebelum_diskon * (barang[i].diskon / 100);
        //Harga Total
        float harga_total = harga_sebelum_diskon - jumlah_diskon;

        //Output Informasi Barang
        printf("%i\t%s\t%.2f\t%i\t\t%.2f%%\t%.2f\n",i + 1,barang[i].nama,barang[i].harga,barang[i].kuantitas,barang[i].diskon,harga_total);

        total_harga += harga_total;
    }

    printf("==================================================\n");
    printf("Total Harga: %.2f\n",total_harga);

    return 0;
}
