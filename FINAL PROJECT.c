#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void tampilkanMenu();
void kalkulatorHukumOhm();
void kalkulatorDayaListrik();
void kalkulatorResistorSeri();
void kalkulatorResistorParalel();
void konversiDesimalKeBasisLain();
void konversiBinerKeDesimal();
void konversiOktalKeDesimal();
void konversiHeksadesimalKeDesimal();

void clearInputBuffer();
void tekanEnterUntukLanjut();
void clearScreen();

void desimalKeBasis(long long desimal, int basis, char *hasil);
int nilaiDigitHeksadesimal(char c);

int main() {
    int pilihan;

    do {
        clearScreen();
        tampilkanMenu();
        printf("\nMasukkan pilihan Anda (1-9) : ");
        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput tidak valid. Harap masukkan angka 1-9.\n");
            clearInputBuffer();
            tekanEnterUntukLanjut();
            continue;
        }
        clearInputBuffer();

        switch (pilihan) {
            case 1:
                kalkulatorHukumOhm();
                break;
            case 2:
                kalkulatorDayaListrik();
                break;
            case 3:
                kalkulatorResistorSeri();
                break;
            case 4:
                kalkulatorResistorParalel();
                break;
            case 5:
                konversiDesimalKeBasisLain();
                break;
            case 6:
                konversiBinerKeDesimal();
                break;
            case 7:
                konversiOktalKeDesimal();
                break;
            case 8:
                konversiHeksadesimalKeDesimal();
                break;
            case 9:
                printf("\nTerima kasih telah menggunakan Toolkit Aslab Elektro!\n");
                printf("Sampai jumpa lagi.\n");
                break;
            default:
                printf("\nPilihan di luar jangkauan. Silakan pilih 1-9.\n");
                break;
        }

        if (pilihan != 9) {
            tekanEnterUntukLanjut();
        }

    } while (pilihan != 9);

    return 0;
}

void tampilkanMenu() {
    printf("=====================================================\n");
    printf("          TOOLKIT ASLAB LABORATORIUM ELEKTRO         \n");
    printf("                       by Kelompok 14                \n");
    printf("=====================================================\n");
    printf("  [ Verifikasi Rangkaian Elektrik ]\n");
    printf("    1. Kalkulator Hukum Ohm (V = I * R)\n");
    printf("    2. Kalkulator Daya Listrik (P = V * I)\n");
    printf("    3. Kalkulator Resistor Seri\n");
    printf("    4. Kalkulator Resistor Paralel\n");
    printf("\n");
    printf("  [ Utilitas Sistem Digital ]\n");
    printf("    5. Desimal -> Biner / Oktal / Heksadesimal\n");
    printf("    6. Biner -> Desimal\n");
    printf("    7. Oktal -> Desimal\n");
    printf("    8. Heksadesimal -> Desimal\n");
    printf("\n");
    printf("    9. Keluar dari Program\n");
    printf("-----------------------------------------------------\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void tekanEnterUntukLanjut() {
    printf("\nTekan Enter untuk kembali ke menu utama...");
    getchar();
}

void clearScreen() {
    system("cls||clear");
}

void kalkulatorHukumOhm() {
    int pilihan;
    double V, I, R;

    clearScreen();
    printf("=== Kalkulator Hukum Ohm ===\n");
    printf("Pilih besaran yang ingin dihitung:\n");
    printf("  1. Tegangan (V)\n");
    printf("  2. Arus (I)\n");
    printf("  3. Hambatan (R)\n");
    printf("Masukkan pilihan (1-3): ");

    if (scanf("%d", &pilihan) != 1) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    switch (pilihan) {
        case 1:
            printf("Masukkan arus (I) dalam Ampere : ");
            if (scanf("%lf", &I) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            printf("Masukkan hambatan (R) dalam Ohm : ");
            if (scanf("%lf", &R) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();
            V = I * R;
            printf("\nTegangan (V) = I * R = %.4f Volt\n", V);
            break;

        case 2:
            printf("Masukkan tegangan (V) dalam Volt : ");
            if (scanf("%lf", &V) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            printf("Masukkan hambatan (R) dalam Ohm : ");
            if (scanf("%lf", &R) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();
            if (R == 0) {
                printf("\nHambatan tidak boleh 0 (pembagian dengan nol).\n");
                return;
            }
            I = V / R;
            printf("\nArus (I) = V / R = %.4f Ampere\n", I);
            break;

        case 3:
            printf("Masukkan tegangan (V) dalam Volt : ");
            if (scanf("%lf", &V) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            printf("Masukkan arus (I) dalam Ampere : ");
            if (scanf("%lf", &I) != 1) {
                printf("Input tidak valid.\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();
            if (I == 0) {
                printf("\nArus tidak boleh 0 (pembagian dengan nol).\n");
                return;
            }
            R = V / I;
            printf("\nHambatan (R) = V / I = %.4f Ohm\n", R);
            break;

        default:
            printf("Pilihan di luar jangkauan.\n");
            break;
    }
}

void kalkulatorDayaListrik() {
    double V, I, P;

    clearScreen();
    printf("=== Kalkulator Daya Listrik ===\n");
    printf("Masukkan Tegangan (V) dalam Volt   : ");
    if (scanf("%lf", &V) != 1) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    printf("Masukkan Arus (I) dalam Ampere     : ");
    if (scanf("%lf", &I) != 1) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    P = V * I;
    printf("\nDaya Listrik (P) = V * I = %.4f Watt\n", P);
}

void kalkulatorResistorSeri() {
    int n, i;
    double nilai, total = 0.0;

    clearScreen();
    printf("=== Kalkulator Resistor Seri ===\n");
    printf("Masukkan jumlah resistor : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. Jumlah resistor harus > 0.\n");
        clearInputBuffer();
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm) : ", i);
        if (scanf("%lf", &nilai) != 1) {
            printf("Input tidak valid.\n");
            clearInputBuffer();
            return;
        }
        total += nilai;
    }
    clearInputBuffer();

    printf("\nTotal Hambatan Seri = %.4f Ohm\n", total);
}

void kalkulatorResistorParalel() {
    int n, i;
    double nilai, sumKebalikan = 0.0;
    double total;

    clearScreen();
    printf("=== Kalkulator Resistor Paralel ===\n");
    printf("Masukkan jumlah resistor : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. Jumlah resistor harus > 0.\n");
        clearInputBuffer();
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm) : ", i);
        if (scanf("%lf", &nilai) != 1) {
            printf("Input tidak valid.\n");
            clearInputBuffer();
            return;
        }
        if (nilai == 0) {
            printf("Nilai resistor tidak boleh 0.\n");
            clearInputBuffer();
            return;
        }
        sumKebalikan += 1.0 / nilai;
    }
    clearInputBuffer();

    if (sumKebalikan == 0) {
        printf("\nTerjadi kesalahan (pembagian nol).\n");
        return;
    }

    total = 1.0 / sumKebalikan;
    printf("\nTotal Hambatan Paralel = %.4f Ohm\n", total);
}

void konversiDesimalKeBasisLain() {
    long long desimal;
    char biner[70], oktal[70], heksa[70];

    clearScreen();
    printf("=== Konversi dari Desimal ===\n");
    printf("Masukkan bilangan desimal (>= 0) : ");
    if (scanf("%lld", &desimal) != 1 || desimal < 0) {
        printf("Input tidak valid. Harus bilangan bulat >= 0.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    desimalKeBasis(desimal, 2, biner);
    desimalKeBasis(desimal, 8, oktal);
    desimalKeBasis(desimal, 16, heksa);

    printf("\nHasil Konversi:\n");
    printf("  Biner        : %s\n", biner);
    printf("  Oktal        : %s\n", oktal);
    printf("  Heksadesimal : %s\n", heksa);
}

void desimalKeBasis(long long desimal, int basis, char *hasil) {
    char temp[70];
    int index = 0;
    long long sisa;
    long long n = desimal;

    if (n == 0) {
        temp[index++] = '0';
    } else {
        while (n > 0) {
            sisa = n % basis;
            if (sisa < 10) {
                temp[index++] = '0' + (int)sisa;
            } else {
                temp[index++] = 'A' + (int)(sisa - 10);
            }
            n /= basis;
        }
    }

    int i;
    for (i = 0; i < index; i++) {
        hasil[i] = temp[index - 1 - i];
    }
    hasil[index] = '\0';
}

void konversiBinerKeDesimal() {
    long long biner;
    long long n;
    int posisi = 0;
    long long digit;
    long long desimal = 0;

    clearScreen();
    printf("=== Konversi Biner ke Desimal ===\n");
    printf("Masukkan bilangan biner (hanya 0 dan 1) : ");
    if (scanf("%lld", &biner) != 1 || biner < 0) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    n = biner;
    while (n > 0) {
        digit = n % 10;
        if (digit != 0 && digit != 1) {
            printf("\nDigit bukan biner (0/1).\n");
            return;
        }
        desimal += digit * (long long)pow(2, posisi);
        posisi++;
        n /= 10;
    }

    printf("\nHasil Desimal : %lld\n", desimal);
}

void konversiOktalKeDesimal() {
    long long oktal;
    long long n;
    int posisi = 0;
    long long digit;
    long long desimal = 0;

    clearScreen();
    printf("=== Konversi Oktal ke Desimal ===\n");
    printf("Masukkan bilangan oktal (digit 0-7) : ");
    if (scanf("%lld", &oktal) != 1 || oktal < 0) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    n = oktal;
    while (n > 0) {
        digit = n % 10;
        if (digit < 0 || digit > 7) {
            printf("\nDigit bukan oktal (0-7).\n");
            return;
        }
        desimal += digit * (long long)pow(8, posisi);
        posisi++;
        n /= 10;
    }

    printf("\nHasil Desimal : %lld\n", desimal);
}

int nilaiDigitHeksadesimal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    c = toupper((unsigned char)c);
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    return -1;
}

void konversiHeksadesimalKeDesimal() {
    char heksa[70];
    int panjang, i, nilai;
    long long desimal = 0;
    int posisi = 0;

    clearScreen();
    printf("=== Konversi Heksadesimal ke Desimal ===\n");
    printf("Masukkan bilangan heksadesimal (0-9, A-F) : ");
    if (scanf("%69s", heksa) != 1) {
        printf("Input tidak valid.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    panjang = (int)strlen(heksa);

    for (i = panjang - 1; i >= 0; i--) {
        nilai = nilaiDigitHeksadesimal(heksa[i]);
        if (nilai == -1) {
            printf("\nDigit '%c' bukan digit heksadesimal yang valid.\n", heksa[i]);
            return;
        }
        desimal += (long long)nilai * (long long)pow(16, posisi);
        posisi++;
    }

    printf("\nHasil Desimal : %lld\n", desimal);
}

