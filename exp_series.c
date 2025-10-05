/* ---------------------------------------------------------------
   Homework 1 – Structured Program Development in C
   Question: 3.45(c) (e^x serisi)
   Author: Bahtınur Şener

   Description:
       Bu program, e^x değerini seriler yardımıyla yaklaşık olarak hesaplar.

       Matematiksel formül:
           e^x ≈ Σ (x^k / k!) ,  k = 0..N

       Yani:
           e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^N/N!

       ⚙️ Hesaplama yöntemi:
       - Her terim, bir önceki terimin x/k ile çarpılmasıyla bulunur.
           term(k) = term(k-1) × (x / k)
       - Böylece pow(x,k) ve faktöriyel ayrı ayrı hesaplanmaz,
         daha **verimli** ve **doğruluğu yüksek** bir yöntem elde edilir.

       💡 Not:
       - N değeri arttıkça sonuç, gerçek e^x değerine yaklaşır.
       - Örneğin: x = 1 ve N = 20 → e^1 ≈ 2.718281828459

   ---------------------------------------------------------------- */

#include <stdio.h>  // printf, scanf fonksiyonları için standart kütüphane

int main(void) {
    double x;          // Üs değeri (x)
    unsigned int N;    // Toplam terim sayısı

    // Kullanıcıdan x değeri al
    printf("x degerini giriniz (ornek: 1.0):\n");
    if (scanf("%lf", &x) != 1) {        // Geçersiz giriş kontrolü
        printf("Gecersiz giris.\n");
        return 0;
    }

    // Kullanıcıdan toplam terim sayısını al
    printf("Toplam terim sayisini giriniz (N):\n");
    if (scanf("%u", &N) != 1) {         // Geçersiz giriş kontrolü
        printf("Gecersiz giris.\n");
        return 0;
    }

    double sum = 0.0;   // e^x toplamını biriktiren değişken
    double term = 1.0;  // İlk terim (k=0 için): x^0 / 0! = 1

    // Seri toplamı: k=0'dan N'e kadar
    for (unsigned int k = 0; k <= N; ++k) {
        if (k == 0)
            term = 1.0;                // İlk terim sabit 1
        else
            term *= x / (double)k;     // Her adımda term = term × (x / k)
        
        sum += term;                   // Toplamı güncelle
    }

    // Sonucu ekrana yazdır
    printf("e^%.6f icin (N=%u) yaklasik deger: %.15f\n", x, N, sum);

    return 0;  // Program başarıyla sonlandı
}
