/* ---------------------------------------------------------------
   Homework 1 – Structured Program Development in C
   Question: 3.45(b) (e sabitinin seri yaklasimi)
   Author: Bahtınur Şener

   Description:
       Bu program, e (Euler sabiti) sayısının yaklaşık değerini
       seriler yardımıyla hesaplar.

       Matematiksel formül:
           e ≈ Σ (1 / k!)  , k=0..N

       Yani:
           e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/N!

       ⚙️ Neden ardışık güncelleme (term /= k) kullanıyoruz?
       - Her terim bir öncekinin k’ya bölünmesiyle elde edilir:
           1/2! = (1/1!) / 2
           1/3! = (1/2!) / 3
       - Böylece her adımda faktöriyeli sıfırdan hesaplamak gerekmez.
       - Bu yöntem hem daha **hızlıdır** hem de **daha az hata birikimi** sağlar.

       💡 Not:
       - N değeri ne kadar büyük seçilirse, sonuç o kadar gerçeğe yakın olur.
       - Örneğin N=15 veya N=20 genelde 2.718281828459 değerine çok yaklaşır.
   ---------------------------------------------------------------- */

#include <stdio.h>  // printf, scanf fonksiyonları için standart kütüphane

int main(void) {
    unsigned int N;  // Toplam terim sayısı (k serisi için üst sınır)

    // Kullanıcıdan terim sayısını iste
    printf("Toplam terim sayisini giriniz (N, ornek: 10, 15, 20):\n");

    // Geçersiz giriş kontrolü
    if (scanf("%u", &N) != 1) {
        printf("Gecersiz giris.\n");
        return 0;
    }

    double e = 0.0;      // e sabitinin yaklaşıklığı burada biriktirilecek
    double term = 1.0;   // İlk terim: 1/0! = 1

    // Seri toplamı: k=0'dan N'e kadar
    for (unsigned int k = 0; k <= N; ++k) {
        if (k == 0)
            term = 1.0;          // İlk terim 1
        else
            term /= (double)k;   // Her adımda terimi k'ya böl: term = 1/k!
        
        e += term;               // Toplamı güncelle
    }

    // Sonucu 15 basamak duyarlılıkla yazdır
    printf("N=%u icin e yaklasik degeri: %.15f\n", N, e);

    return 0;  // Program başarıyla sonlandı
}
