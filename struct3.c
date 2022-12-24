/*Bir ��retmen 30 ki�ilik s�n�fa 10 soruluk �oktan se�meli sorulardan olu�an bir s�nav vermi�tir.
    Bu s�navda her sorunun 4 ��kk�(A B C D) bulunmakta ve 4 yanl�� bir do�ruyu g�t�rmektedir.Bu programda
    bir ��rencinin okul numaras�n� ve cevaplar�n� i�eren bir yap� tan�mlay�n�z ve s�n�fta bulunan her ��rencinin
    okul numaras�n� ve cevaplar�n� bu yap� dizisine okutunuz.Daha sonra ��retmenin haz�rlad��� cevap anahtar�n�
    bir karakter dizisine okuyunuz ve her ��rencinin 10 �zerinden ald��� notu hesaplay�n�z.Her ��rencinin okul numaras�
    ile,hesaplanan s�nav sonucunu bir ba�ka yap� dizisinde tutunuz ve sonu�lar� ekranda g�r�nt�leyiniz.*/
#include <stdio.h>
#include <stdlib.h>
typedef union{
    int okul_numarasi;
    char cevaplar[10];
    int sonuc;
}ogrencibilgi;

void cevapislemleri(ogrencibilgi x[5])
{
    srand(time(0));
    printf("----Please Enter the students' answers----\n");
    printf(">Students' number will be determining by the computer!!\n\n");
    for(int a=0;a<5;a++)
    {
        printf("*** Student %d  *** \n\n",a+1);
        x[a].okul_numarasi=rand()%100;
        for(int b=0;b<10;b++)
        {
            printf("%d-",b+1);
            scanf("%s",&x[a].cevaplar[b]);
        }
    }

}
void kontrolfonk(ogrencibilgi x[5],char cvpanhtr[10])
{
    int dogru,yanlis;
    for(int b=0;b<5;b++)
    {
        printf("\n\n*** Student %d , School number = %d *** \n\n",b+1,x[b].okul_numarasi);
        for(int a=0;a<10;a++)
        {
            if(x[b].cevaplar[a]==cvpanhtr[a])
            {
                printf("Question %d = CORRECT + \n",a+1);
                dogru++;
            }
            else
            {
                printf("Question %d = WRONG - \n",a+1);
                yanlis++;
                if(yanlis%4==0)
                {
                    dogru--;
                }                                                   // THE PROBLEM OCCUR WITH
            }

        }
        x[b].sonuc=dogru;
        dogru=0;
        yanlis=0;
    }
    printf("\n");
    for(int k=0;k<5;k++)
        {
            printf("Student %d has %d/10 points !!\n",k+1,x[k].sonuc);
        }

}

int main()
{
    char cevap_anahtari[]="ABBDCADCDB";
    ogrencibilgi ogrenci[5];
    printf("Please determine of the questions' answers \n\n");
    cevapislemleri(ogrenci);
    kontrolfonk(ogrenci,cevap_anahtari);
}
