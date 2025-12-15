[Readme.txt](https://github.com/user-attachments/files/24158864/Readme.txt)
TOOLKIT ASLAB LABORATORIUM ELEKTRO

1. Deskripsi Program

Toolkit Aslab Laboratorium Elektro adalah program berbasis *bahasa C* yang dirancang untuk membantu praktikum *Dasar Pemrograman dan Sistem Digital*. Program ini menyediakan:

Kalkulator rangkaian listrik dasar
Utilitas konversi bilangan (desimal, biner, oktal, heksadesimal)

Program menggunakan menu interaktif dan berjalan terus hingga pengguna memilih keluar.


2. Library yang Digunakan


#include <stdio.h>   // Input-output standar
#include <stdlib.h>  // Fungsi system(), konversi umum
#include <string.h>  // Manipulasi string (strlen)
#include <math.h>    // Fungsi matematika (pow)
#include <ctype.h>   // Manipulasi karakter (toupper)



3. Alur Kerja Program

1. Program menampilkan menu utama
2. Pengguna memilih fitur (1–9)
3. Program memvalidasi input
4. Fungsi sesuai pilihan dijalankan
5. Program kembali ke menu utama
6. Program berhenti jika pengguna memilih *9 (Keluar)*

Alur utama dikendalikan oleh loop do-while pada fungsi main().



4. Penjelasan Fungsi Utama

4.1 int main()

Fungsi utama program.

* Mengontrol alur menu
* Membaca input pilihan user
* Menjalankan fungsi sesuai menu menggunakan switch-case
* Mengulang program sampai user memilih keluar



5. Fungsi Tampilan & Utility

5.1 void tampilkanMenu()

Menampilkan menu utama program yang berisi:

Kalkulator listrik
Konversi bilangan
Opsi keluar program

Tidak memiliki logika perhitungan.


5.2 void clearInputBuffer()

Membersihkan sisa karakter pada buffer input (stdin) setelah scanf.

Tujuan:

 Mencegah input terbaca ganda
 Menghindari error saat input berikutnya



5.3 void tekanEnterUntukLanjut()

Menahan program sampai pengguna menekan tombol Enter.

Digunakan agar hasil perhitungan dapat dibaca sebelum kembali ke menu.



5.4 void clearScreen()

Membersihkan layar terminal.


system("cls||clear");


Mendukung Windows (cls) dan Linux/macOS (clear).



6. Fungsi Kalkulator Listrik

6.1 void kalkulatorHukumOhm()

Menghitung besaran listrik berdasarkan *Hukum Ohm*:

Tegangan (V = I × R)
Arus (I = V ÷ R)
Hambatan (R = V ÷ I)

Dilengkapi validasi pembagian nol.



6.2 void kalkulatorDayaListrik()

Menghitung daya listrik menggunakan rumus:


P = V × I




6.3 void kalkulatorResistorSeri()

Menghitung total hambatan resistor seri:


R_total = R1 + R2 + ... + Rn


Pengguna dapat memasukkan jumlah resistor secara dinamis.



6.4 void kalkulatorResistorParalel()

Menghitung total hambatan resistor paralel:

1/R_total = 1/R1 + 1/R2 + ... + 1/Rn


Program menolak nilai resistor 0 untuk mencegah pembagian nol.



7. Fungsi Konversi Bilangan

7.1 void konversiDesimalKeBasisLain()

Mengonversi bilangan desimal ke:

 Biner (basis 2)
 Oktal (basis 8)
 Heksadesimal (basis 16)

Menggunakan fungsi bantuan desimalKeBasis().



7.2 void desimalKeBasis(long long desimal, int basis, char *hasil)

Fungsi inti konversi desimal ke basis lain.

Langkah kerja:

1. Membagi bilangan dengan basis
2. Menyimpan sisa pembagian
3. Mengonversi sisa ke karakter
4. Membalik urutan digit hasil



7.3 void konversiBinerKeDesimal()

Mengonversi bilangan biner ke desimal menggunakan rumus:


desimal += digit × 2^posisi


Program memvalidasi agar hanya digit 0 dan 1 yang diterima.



7.4 void konversiOktalKeDesimal()

Mengonversi bilangan oktal ke desimal menggunakan rumus:


desimal += digit × 8^posisi


Digit divalidasi agar hanya 0–7.


7.5 int nilaiDigitHeksadesimal(char c)

Mengonversi karakter heksadesimal menjadi nilai numerik:

 '0'–'9' → 0–9
 'A'–'F' → 10–15

Menggunakan toupper() untuk kapital agar huruf kecil tetap valid.


7.6 void konversiHeksadesimalKeDesimal()

Mengonversi bilangan heksadesimal ke desimal menggunakan rumus:


desimal += nilai × 16^posisi


Membaca digit dari kanan ke kiri (LSB ke MSB).
