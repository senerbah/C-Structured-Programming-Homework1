/* ---------------------------------------------------------------
   Homework 1 – Structured Program Development in C
   Question: 3.35 (Binary to Decimal Conversion)
   Author: Bahtınur Şener

   Description:
       Bu program, kullanıcıdan alınan en fazla 5 basamaklı binary (ikilik) sayıyı
       ondalık (decimal) değere çevirir.

       Binary sayı yalnızca 0 ve 1 rakamlarından oluşabilir.
       Örnek: 1101 (binary) = 13 (decimal)

       ⚙️ Neden en fazla 5 basamak?
       - 5 basamaklı bir binary sayının maksimum değeri 11111₂ = 31₁₀'dur.
       - Bu sınır, programın basit, kontrollü ve elle test edilebilir bir
         örnek aralıkta kalmasını sağlar.
       - Ayrıca, kullanıcı hatalarını (ör. fazla basamak, 2 gibi geçersiz rakam)
         kolayca yakalamak için giriş doğrulaması yapılır.

       Program ayrıca hatalı girişleri tespit eder:
       - Negatif sayı girilirse: reddedilir.
       - 0 veya 1 dışında bir rakam içerirse: reddedilir.
       - 5’ten fazla basamaklıysa: reddedilir.
   ---------------------------------------------------------------- */

#include <stdio.h>  // Standart giriş-çıkış fonksiyonları (printf, scanf)

int main(void) {
    long input;  // Kullanıcıdan alınacak binary (ikilik) sayı değişkeni

    // Kullanıcıdan girdi iste
    printf("Binary bir sayi giriniz (en fazla 5 basamak, sadece 0 ve 1):\n");
    
    // scanf başarısızsa (ör. harf girilirse) veya negatif sayı girilirse hata ver
    if (scanf("%ld", &input) != 1 || input < 0) {
        printf("Gecersiz giris.\n");
        return 0;  // Programı sonlandır
    }

    int digits = 0;      // Girilen sayının basamak sayısını tutar
    long temp = input;   // Orijinal sayıyı bozmadan kontrol için geçici değişken

    // Her basamağı kontrol et (sadece 0 ve 1 olmalı)
    while (temp > 0) {
        int d = temp % 10;  // En sağdaki basamağı al
        if (d != 0 && d != 1) {  // 0 veya 1 dışında bir basamak varsa hata
            printf("Gecersiz giris: sadece 0 ve 1 kullanilabilir.\n");
            return 0;
        }
        digits++;      // Basamak sayısını artır
        temp /= 10;    // Bir sonraki basamağa geç
    }

    // Basamak sayısı 5'ten fazlaysa hatalı giriş
    if (digits > 5) {
        printf("Gecersiz giris: en fazla 5 basamak olmalidir.\n");
        return 0;
    }

    // Binary → Decimal dönüşümü için hazırlık
    long n = input;      // Orijinal sayı
    int multiplier = 1;  // 2'nin kuvveti (2^0, 2^1, 2^2, ...)
    int decimal = 0;     // Sonuç olarak hesaplanacak ondalık sayı

    // Sağdan sola doğru her bitin değerini 2'nin kuvvetiyle çarparak toplar
    while (n > 0) {
        int bit = n % 10;            // En sağdaki binary basamağı al
        decimal += bit * multiplier; // O bitin değerini toplama ekle
        multiplier *= 2;             // Bir sonraki bit için 2 katına çık
        n /= 10;                     // Bir basamak sola kay
    }

    // Sonucu ekrana yazdır
    printf("Binary %ld sayisinin ondalik karsiligi: %d\n", input, decimal);

    return 0;  // Program başarıyla sonlandı
}
