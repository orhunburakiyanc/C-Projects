/*Bir buz pateni kar��la�mas�nda,bir yar��mac�n�n performans� 6.00 �zerinden puanlanarak 10 hakem taraf�ndan
    de�erlendirilmektedir.Yar��mac�n�n performans puan� ise hakemlerin vermi� oldu�u en d���k ve en y�ksek puan
    at�l�p,geri kalan puanlar�n aritmetik ortlamas� al�narak bulunmaktad�r.Yazaca��n�z programda yar��mac�n�n
    ad�,soyad� performans puan�n� hesaplay�p ekranda g�r�nt�leyiniz.Performans hesaplamas�n� tek parametreli
    bir fonksiyonda yap�n�z.Bu fonksiyon yar��mac�ya ait yap�y� parametre olarak almal� ve performans puan�n�
    hesaplayarak geri d�nd�rmelidir.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //NOT !!= STRUCT'A YAZDDIGIN DESG�SKENLER� B�R DEGERE ES�TLERSEN AYVAY� YERS�N
typedef struct {
    char adi[10],soyad[10];
    int puan,hakem[10];
}bilgiler;

int puanhesapla(bilgiler x)
{
    x.puan=0;
    int p,max,min,sonuc;
    printf("Please write the judge's points==>THE MAX GIVEABLE POINT IS 6<==\n");
    for(p=0,max=x.hakem[0],min=0;p<10;p++)
    {
        do{
        printf("****Judge-%d=",p+1);
        scanf("%d",&x.hakem[p]);
        }while(x.hakem[p]>6);
    }
    for(p=0,max=x.hakem[0],min=0;p<10;p++)
    {
        if(max<x.hakem[p])
        {
            max=x.hakem[p];
        }
        if(min>x.hakem[p])
        {
            min=x.hakem[p];
        }
        x.puan+=x.hakem[p];
    }
    sonuc=(x.puan-min-max)/8;
    return sonuc;
}

int main()
{
    int sonuc;
    bilgiler yarismaci1;
    sonuc=puanhesapla(yarismaci1);
    printf("\nYarismacinin Adi = %s\nYarismacinin Soyadi = %s\n",strcpy(yarismaci1.adi,"Burak"),strcpy(yarismaci1.soyad,"Kiyanc"));
    printf("Yarismacinin Puani = %d",sonuc);
}

