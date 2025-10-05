/* ---------------------------------------------------------------
   Homework 1 – Structured Program Development in C
   Question: 3.45(a) (Faktöriyel Hesaplama)
   Author: Bahtınur Şener

   Description:
       Bu program, 0 ≤ n ≤ 20 aralığında girilen bir tamsayının faktöriyelini hesaplar.
       Faktöriyel, n! = n × (n−1) × (n−2) × ... × 1 formülüyle tanımlanır.

       ⚙️ Neden 0 ile 20 arası?
       - Faktöriyel fonksiyonu çok hızlı büyür (örneğin 20! ≈ 2.43×10^18).
       - Program sonucu "unsigned long long" (64-bit) değişkeninde saklar.
       - Bu türün maksimum değeri ≈ 1.84×10^19’dur, dolayısıyla 20! güvenle sığar.
       - Ancak 21! ≈ 5.1×10^19 olur ve belleğe sığmaz (overflow hatası verir).
       Bu nedenle, program doğru sonuç verebilmek için n değerini 0–20 ile sınırlar.

       Ek Bilgi:
       0! tanımı gereği 1’dir, çünkü faktöriyel tanımı n! = n × (n−1)! eşitliğini
       1! = 1 × 0! durumunda da tutarlı kılmak için 0! = 1 olarak tanımlanır.
   ---------------------------------------------------------------- */

#include <stdio.h>  // printf ve scanf fonksiyonları için standart kütüphane

int main(void) {
    unsigned int n;  // Kullanıcının gireceği sayı (0–20 arası)

    // Kullanıcıdan giriş al
    printf("n degerini giriniz (0 <= n <= 20):\n");

    // Giriş kontrolü: scanf başarısızsa veya n > 20 ise hata mesajı göster
    if (scanf("%u", &n) != 1 || n > 20) {
        printf("Gecersiz giris (0..20 araliginda olmalidir).\n");
        return 0;  // Programı hatalı giriş nedeniyle sonlandır
    }

    // Faktöriyel değeri burada tutulacak
    // 1ULL = 1 (Unsigned Long Long) → 64-bit başlangıç değeri
    unsigned long long fact = 1ULL;

    // 2’den n’e kadar döngüyle çarpma işlemi yap
    for (unsigned int i = 2; i <= n; ++i) {
        fact *= i;  // fact = fact × i
    }

    // Sonucu ekrana yazdır
    printf("%u! = %llu\n", n, fact);

    return 0;  // Program başarılı şekilde sonlandı
}
