#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<dirent.h>
struct Noktalar
{

    float x3,y3,z3;







};
struct Noktalar2
{

    float x4,y4,z4;
    int r4,g4,b4;




};

int main()
{
    DIR *klasor=opendir("C:\\Users\\Berkay\\Desktop\\PROJEBS1");

    struct dirent *dosyalar;
    char string[100][100];
    char *arama;
    char kontrol[100];
    int s=0;

    FILE *cikti=fopen("output.nkt","w");
    if(cikti==NULL)
    {

        printf("Dosya acilamadi.\n");
        exit(1);

    }

    fclose(cikti);



    if(klasor==NULL)
    {
        printf("Klasor acilamadi \n");
    }
    if(klasor != NULL)
    {
        while((dosyalar = readdir(klasor)) != NULL)
        {
            strcpy(kontrol,dosyalar->d_name);

            arama=strstr(kontrol,".nkt");

            if(arama!=NULL)
            {

                strcpy(string[s],kontrol);
                //printf("%s\n",string[i]);
                s++;
            }
        }
    }



    for(int a=0; a<s; a++)
    {
        if(strstr(string[a],"output.nkt"))
        {

            a++;


        }

        printf("%s\n",string[a]);

        FILE *cikti = fopen("output.nkt","a");
        fprintf(cikti,"%s\n",string[a]);
        fclose(cikti);


        FILE * dosya;
        char buf[100];
        char rgb[100];
        char satir1[100]= {"# Noktalar dosya format"};
        char satir2[100]= {"VERSION 1"};
        char satir3[100]= {"ALANLAR x y z r g b"};
        char satir3a[100]= {"ALANLAR x y z"};
        char satir4[100]= {"NOKTALAR"};
        char satir5[100]= {"DATA ascii"};
        char satir5a[100]= {"DATA binary"};
        char nokta[100];
        int j=0;
        int hata[1000];
        int rgb_kontrol=0;
        int tam;
        int f,o,h,u;
        int hata_satir=0;
        int format_kontrol=0;
        int baslik_kontrol1=0;
        int baslik_kontrol2=0;
        int baslik_kontrol3=0;
        int baslik_kontrol3a=0;
        int baslik_kontrol4=0;
        int baslik_kontrol5=0;
        int baslik_kontrol5a=0;
        int kelime_kontrol1=1;
        int kelime_kontrol3=1;
        int satir=0;
        int q=0;
        int v=0;
        int w=0;
        int bs;
        float x,y,z;
        float x1,y1,z1;
        float x2,y2,z2;
        float sonuc,sonuc1;
        float en_uzak=0;
        float en_yakin=200000;
        float r,g,b;
        float e_u_x=0,e_u_y=0,e_u_z=0;
        float s_x=0,s_y=0,s_z=0;
        float bx=0,by=0,bz=0;
        float e_k_matris[1][3];
        float e_b_matris[1][3];
        float uzaklik=0;
        float cember[1][3];
        float cember_yaricap;
        float cember_sonuc;
        double toplam=0;
        double toplam3=0;



        if ((dosya = fopen(string[a], "r")) == NULL)
        {
            printf("dosya acilamadi!\n");
            exit(1);
        }


        while ( fgets(buf, 100, dosya) != NULL )
        {
            satir++;


        }
        fclose(dosya);
        satir=satir-5;



        float koordinat1[satir][6];





        if ((dosya = fopen(string[a], "r")) == NULL)
        {
            printf("dosya acilamadi!\n");
            exit(1);
        }


        fgets(buf,100,dosya);

        puts(buf);

        for(int i=0; i<strlen(satir1); i++)
        {


            if(buf[i]==satir1[i])
            {
                baslik_kontrol1++;

            }
            else
            {

                break;
            }


        }
        if(baslik_kontrol1==strlen(satir1))
        {
            format_kontrol++;
        }


        fgets(buf,100,dosya);

        puts(buf);

        for(int i=0; i<strlen(satir2); i++)
        {


            if(buf[i]==satir2[i])
            {
                baslik_kontrol2++;

            }
            else
            {

                break;
            }


        }
        if(baslik_kontrol2==strlen(satir2))
        {
            format_kontrol++;
        }


        fgets(buf,100,dosya);

        puts(buf);
        for(int i=0; i<strlen(buf); i++)
        {

            rgb[i]=buf[i];


        }

        const char *ayrac = " ";
        char *kelime = strtok(rgb, ayrac);


        while (kelime != NULL)
        {
            kelime = strtok(NULL, ayrac);
            kelime_kontrol3++;
        }


        for(int i=0; i<strlen(satir3); i++)
        {


            if(buf[i]==satir3[i])
            {
                baslik_kontrol3++;

            }
            else
            {

                break;
            }
        }
        for(int i=0; i<strlen(satir3a); i++)
        {


            if(buf[i]==satir3a[i])
            {
                baslik_kontrol3a++;

            }
            else
            {

                break;
            }



        }
        if(baslik_kontrol3==strlen(satir3)||baslik_kontrol3a==strlen(satir3a))
        {
            format_kontrol++;
        }



        fgets(buf,100,dosya);

        puts(buf);



        for (int i=9; i<15; i++)
        {

            nokta[j]=buf[i];
            j++;


        }

        bs=atoi(nokta);

        float noktalar[10][3];
        float noktalar2[10][3];
        int brgb[10][3];



        for(int i=0; i<8; i++)
        {


            if(buf[i]==satir4[i])
            {
                baslik_kontrol4++;

            }
            else
            {

                break;
            }


        }


        if(baslik_kontrol4==8)
        {
            format_kontrol++;
        }



        fgets(buf,100,dosya);

        puts(buf);


        for(int i=0; i<strlen(satir5); i++)
        {
            if(buf[i]==satir5[i])
            {
                baslik_kontrol5++;

            }
            else
            {

                break;
            }
        }

        for(int i=0; i<strlen(satir5a); i++)
        {


            if(buf[i]==satir5a[i])
            {
                baslik_kontrol5a++;

            }
            else
            {

                break;
            }



        }

        if(baslik_kontrol5==strlen(satir5)||baslik_kontrol5a==strlen(satir5a))
        {
            format_kontrol++;
        }


        if(baslik_kontrol5a==strlen(satir5a))
        {


            struct Noktalar binary;
            struct Noktalar2 binary2;


            if(kelime_kontrol3==5)
            {
                while(fread(&binary,sizeof(struct Noktalar),1,dosya))
                {

                    noktalar[v][0]=binary.x3;
                    noktalar[v][1]=binary.y3;
                    noktalar[v][2]=binary.z3;

                    v++;





                }

            }
            if(kelime_kontrol3==8)
            {
                while(fread(&binary2,sizeof(struct Noktalar2),1,dosya))
                {

                    noktalar2[v][0]=binary2.x4;
                    noktalar2[v][1]=binary2.y4;
                    noktalar2[v][2]=binary2.z4;
                    brgb[v][3]=binary2.r4;
                    brgb[v][4]=binary2.g4;
                    brgb[v][5]=binary2.b4;


                    v++;





                }
            }





        }




        for (int k=0; k<satir; k++)
        {

            fgets(buf,100,dosya);

            const char *ayrac = " ";
            char *kelime = strtok(buf, ayrac);
            x=atof(kelime);

            while (kelime != NULL)
            {


                kelime = strtok(NULL, ayrac);
                kelime_kontrol1++;


                if(kelime_kontrol1==2)
                {
                    y=atof(kelime);
                }
                if(kelime_kontrol1==3)
                {
                    z=atof(kelime);

                }
                if (kelime_kontrol1==4)
                {
                    r=atof(kelime);

                }
                if(kelime_kontrol1==5)
                {

                    g=atof(kelime);

                }

                if(kelime_kontrol1==6)
                {

                    b=atof(kelime);
                }

            }

            if(kelime_kontrol3==8)
            {
                if(kelime_kontrol1!=7)
                {

                    rgb_kontrol++;
                    hata[hata_satir]=q;
                    hata_satir++;



                }

            }
            kelime_kontrol1=1;
            koordinat1[q][0]=x;

            koordinat1[q][1]=y;

            koordinat1[q][2]=z;

            koordinat1[q][3]=r;

            koordinat1[q][4]=g;

            koordinat1[q][5]=b;
            q++;

        }








        for(int i=0; i<100; i++)
        {

            printf("\n1.SECIM\n");
            printf("2.SECIM\n");
            printf("3.SECIM\n");
            printf("4.SECIM\n");
            printf("5.SECIM\n");
            printf("Cikmak icin 6'ya basiniz\n");
            printf("*************************\n");
            int secim;
            printf("Yapmak istediginiz islemi seciniz:");
            scanf("%d",&secim);
            printf("----------------------------------------------------------\n");


            if(secim==1)
            {
                FILE *cikti=fopen("output.nkt","a");
                fprintf(cikti,"1.SECIM\n");

                if(format_kontrol==5)
                {

                    printf("Dosya baslik formati uygun\n");
                    fprintf(cikti,"Dosya baslik formati uygun\n");



                }
                else
                {

                    printf("Dosya baslik formati uygun degil dosya  okunmayacak\n");

                    fprintf(cikti,"Dosya baslik formati uygun degil dosya  okunmayacak\n");
                    break;
                }

                tam=atoi(nokta);
                if(baslik_kontrol5==strlen(satir5))
                {
                    if(tam==satir)
                    {
                        printf("Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni\n");
                        fprintf(cikti,"Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni\n");

                    }

                    else
                    {

                        printf("Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni degil.\n");
                        fprintf(cikti,"Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni degil.\n");

                    }
                }

                if(baslik_kontrol5a==strlen(satir5a))
                {

                    if(bs==atoi(nokta))
                    {

                        printf("Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni\n");
                        fprintf(cikti,"Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni\n");



                    }
                    else
                    {

                        printf("Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni degil.\n");
                        fprintf(cikti,"Baslikta verilen nokta sayisi ile okunan nokta sayisi ayni degil.\n");


                    }



                }

                if(baslik_kontrol5==strlen(satir5))
                {
                    if(kelime_kontrol3==8)
                    {


                        if(rgb_kontrol==0)
                        {

                            printf("Satirlarin rgb bilgilerinde hata bulunmamaktadir.....\n");
                            fprintf(cikti,"Satirlarin rgb bilgilerinde hata bulunmamaktadir.....\n");


                        }

                        if(rgb_kontrol!=0)
                        {

                            for(int i=0; i<hata_satir; i++)
                            {

                                printf("%d . satirdaki rgb bilgileri hatali veya eksik verilmistir....\n",hata[i]+1);
                                fprintf(cikti,"%d . satirdaki rgb bilgileri hatali veya eksik verilmistir....\n",hata[i]+1);


                            }


                        }




                    }

                }

                fclose(cikti);

            }

            if(secim==2)
            {
                FILE *cikti=fopen("output.nkt","a");
                fprintf(cikti,"2.SECIM\n");

                if(baslik_kontrol5a==strlen(satir5a))
                {

                    if(kelime_kontrol3==5)
                    {
                        for(int k=0; k<atoi(nokta); k++)
                        {

                            x1=noktalar[k][0];

                            y1=noktalar[k][1];

                            z1=noktalar[k][2];



                            for(int l=(k+1); l<atoi(nokta); l++)
                            {

                                x2=noktalar[l][0];

                                y2=noktalar[l][1];

                                z2=noktalar[l][2];

                                sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                                sonuc1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );

                                if(sonuc>en_uzak)
                                {

                                    en_uzak=sonuc;
                                    f=k;
                                    o=l;



                                }
                                if(sonuc1<en_yakin)
                                {

                                    en_yakin=sonuc1;
                                    h=k;
                                    u=l;
                                }


                            }


                        }
                        printf("En Uzak=%f\n",en_uzak);
                        fprintf(cikti,"En Uzak=%f\n",en_uzak);
                        printf("%d ve %d Noktalari\n",f,o);
                        fprintf(cikti,"%d ve %d Noktalari\n",f,o);
                        printf("%f %f %f \n",noktalar[f][0],noktalar[f][1],noktalar[f][2]);
                        fprintf(cikti,"%f %f %f \n",noktalar[f][0],noktalar[f][1],noktalar[f][2]);
                        printf("%f %f %f \n",noktalar[o][0],noktalar[o][1],noktalar[o][2]);
                        fprintf(cikti,"%f %f %f \n",noktalar[o][0],noktalar[o][1],noktalar[o][2]);
                        printf("En Yakin=%f\n",en_yakin);
                        fprintf(cikti,"En Yakin=%f\n",en_yakin);
                        printf("%d ve %d Noktalari\n",h,u);
                        fprintf(cikti,"%d ve %d Noktalari\n",h,u);
                        printf("%f %f %f \n",noktalar[h][0],noktalar[h][1],noktalar[h][2]);
                        fprintf(cikti,"%f %f %f \n",noktalar[h][0],noktalar[h][1],noktalar[h][2]);
                        printf("%f %f %f \n",noktalar[u][0],noktalar[u][1],noktalar[u][2]);
                        fprintf(cikti,"%f %f %f \n",noktalar[u][0],noktalar[u][1],noktalar[u][2]);

                    }
                    if(kelime_kontrol3==8)
                    {

                        for(int k=0; k<atoi(nokta); k++)
                        {

                            x1=noktalar2[k][0];

                            y1=noktalar2[k][1];

                            z1=noktalar2[k][2];



                            for(int l=(k+1); l<atoi(nokta); l++)
                            {

                                x2=noktalar2[l][0];

                                y2=noktalar2[l][1];

                                z2=noktalar2[l][2];

                                sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                                sonuc1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );

                                if(sonuc>en_uzak)
                                {

                                    en_uzak=sonuc;
                                    f=k;
                                    o=l;



                                }
                                if(sonuc1<en_yakin)
                                {

                                    en_yakin=sonuc1;
                                    h=k;
                                    u=l;
                                }


                            }


                        }
                        printf("En Uzak=%f\n",en_uzak);
                        fprintf(cikti,"En Uzak=%f\n",en_uzak);
                        printf("%d ve %d Noktalari\n",f,o);
                        fprintf(cikti,"%d ve %d Noktalari\n",f,o);
                        printf("%f %f %f %d %d %d \n",noktalar2[f][0],noktalar2[f][1],noktalar2[f][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        fprintf(cikti,"%f %f %f %d %d %d \n",noktalar2[f][0],noktalar2[f][1],noktalar2[f][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        printf("%f %f %f %d %d %d \n",noktalar2[o][0],noktalar2[o][1],noktalar2[o][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        fprintf(cikti,"%f %f %f %d %d %d \n",noktalar2[o][0],noktalar2[o][1],noktalar2[o][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        printf("En Yakin=%f\n",en_yakin);
                        fprintf(cikti,"En Yakin=%f\n",en_yakin);
                        printf("%d ve %d Noktalari\n",h,u);
                        fprintf(cikti,"%d ve %d Noktalari\n",h,u);
                        printf("%f %f %f %d %d %d  \n",noktalar2[h][0],noktalar2[h][1],noktalar2[h][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        fprintf(cikti,"%f %f %f %d %d %d  \n",noktalar2[h][0],noktalar2[h][1],noktalar2[h][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        printf("%f %f %f %d %d %d \n",noktalar2[u][0],noktalar2[u][1],noktalar2[u][2],brgb[f][3],brgb[f][4],brgb[f][5]);
                        fprintf(cikti,"%f %f %f %d %d %d \n",noktalar2[u][0],noktalar2[u][1],noktalar2[u][2],brgb[f][3],brgb[f][4],brgb[f][5]);







                    }



                }
                if(baslik_kontrol5==strlen(satir5))
                {


                    for(int k=0; k<satir; k++)
                    {

                        x1=koordinat1[k][0];

                        y1=koordinat1[k][1];

                        z1=koordinat1[k][2];



                        for(int l=(k+1); l<satir; l++)
                        {

                            x2=koordinat1[l][0];

                            y2=koordinat1[l][1];

                            z2=koordinat1[l][2];

                            sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                            sonuc1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );

                            if(sonuc>en_uzak)
                            {

                                en_uzak=sonuc;
                                f=k;
                                o=l;



                            }
                            if(sonuc1<en_yakin)
                            {

                                en_yakin=sonuc1;
                                h=k;
                                u=l;
                            }


                        }


                    }
                    printf("En Uzak=%f\n",en_uzak);
                    fprintf(cikti,"En Uzak=%f\n",en_uzak);
                    printf("%d ve %d Noktalari\n",f,o);
                    fprintf(cikti,"%d ve %d Noktalari\n",f,o);
                    printf("%f %f %f \n",koordinat1[f][0],koordinat1[f][1],koordinat1[f][2]);
                    fprintf(cikti,"%f %f %f \n",koordinat1[f][0],koordinat1[f][1],koordinat1[f][2]);
                    printf("%f %f %f \n",koordinat1[o][0],koordinat1[o][1],koordinat1[o][2]);
                    fprintf(cikti,"%f %f %f \n",koordinat1[o][0],koordinat1[o][1],koordinat1[o][2]);
                    printf("En Yakin=%f\n",en_yakin);
                    fprintf(cikti,"En Yakin=%f\n",en_yakin);
                    printf("%d ve %d Noktalari\n",h,u);
                    fprintf(cikti,"%d ve %d Noktalari\n",h,u);
                    printf("%f %f %f \n",koordinat1[h][0],koordinat1[h][1],koordinat1[h][2]);
                    fprintf(cikti,"%f %f %f \n",koordinat1[h][0],koordinat1[h][1],koordinat1[h][2]);
                    printf("%f %f %f \n",koordinat1[u][0],koordinat1[u][1],koordinat1[u][2]);
                    fprintf(cikti,"%f %f %f \n",koordinat1[u][0],koordinat1[u][1],koordinat1[u][2]);

                }
                fclose(cikti);
            }




            if(secim==3)
            {
                FILE *cikti=fopen("output.nkt","a");
                fprintf(cikti,"3.SECIM\n");

                if(baslik_kontrol5a==strlen(satir5a))
                {
                    if(kelime_kontrol3==5)
                    {


                        for (int i=0; i<atoi(nokta); i++)
                        {

                            for(int j=i+1; j<atoi(nokta); j++)
                            {

                                s_x= fabs(noktalar[i][0]- noktalar[j][0]);
                                s_y= fabs(noktalar[i][1]- noktalar[j][1]);
                                s_z= fabs(noktalar[i][2]- noktalar[j][2]);
                                if(e_u_x<s_x)
                                {
                                    e_u_x=s_x;
                                    if(noktalar[i][0]<noktalar[j][0])
                                    {
                                        e_k_matris[0][0]= noktalar[i][0];
                                        e_b_matris[0][0]= noktalar[j][0];
                                    }
                                    if(noktalar[i][0]>noktalar[j][0])
                                    {
                                        e_b_matris[0][0]= noktalar[i][0];
                                        e_k_matris[0][0]= noktalar[j][0];
                                    }

                                }
                                if(e_u_y<s_y)
                                {
                                    e_u_y=s_y;
                                    if(noktalar[i][1]<noktalar[j][1])
                                    {
                                        e_k_matris[0][1]= noktalar[i][1];
                                        e_b_matris[0][1]= noktalar[j][1];
                                    }
                                    if(noktalar[i][1]>noktalar[j][1])
                                    {
                                        e_b_matris[0][1]= noktalar[i][1];
                                        e_k_matris[0][1]= noktalar[j][1];
                                    }

                                }
                                if(e_u_z<s_z)
                                {
                                    e_u_z=s_z;
                                    if(noktalar[i][2]<noktalar[j][2])
                                    {
                                        e_k_matris[0][2]= noktalar[i][2];
                                        e_b_matris[0][2]= noktalar[j][2];
                                    }
                                    if(noktalar[i][2]>noktalar[j][2])
                                    {
                                        e_b_matris[0][2]= noktalar[i][2];
                                        e_k_matris[0][2]= noktalar[j][2];
                                    }

                                }

                            }
                        }

                        bx=e_b_matris[0][0]- e_k_matris[0][0];
                        by=e_b_matris[0][1]- e_k_matris[0][1];
                        bz=e_b_matris[0][2]- e_k_matris[0][2];


                        if(bx>by && bx>bz)
                        {
                            uzaklik=bx;

                        }
                        if(by>bx && by>bz)
                        {
                            uzaklik=by;

                        }
                        if(bz>by && bz>bx)
                        {
                            uzaklik=bz;

                        }
                        if(bx==by&&bx==bz){

                            uzaklik=bx;
                        }
                        printf("Kupun kenar uzunlugu= %f\n",uzaklik);
                        fprintf(cikti,"Kupun kenar uzunlugu= %f\n",uzaklik);

                        printf("Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");
                        fprintf(cikti,"Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");

                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);

                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);

                    }
                    if(kelime_kontrol3==8)
                    {

                        for (int i=0; i<atoi(nokta); i++)
                        {

                            for(int j=i+1; j<atoi(nokta); j++)
                            {

                                s_x= fabs(noktalar2[i][0]- noktalar2[j][0]);
                                s_y= fabs(noktalar2[i][1]- noktalar2[j][1]);
                                s_z= fabs(noktalar2[i][2]- noktalar2[j][2]);
                                if(e_u_x<s_x)
                                {
                                    e_u_x=s_x;
                                    if(noktalar2[i][0]<noktalar2[j][0])
                                    {
                                        e_k_matris[0][0]= noktalar2[i][0];
                                        e_b_matris[0][0]= noktalar2[j][0];
                                    }
                                    if(noktalar2[i][0]>noktalar2[j][0])
                                    {
                                        e_b_matris[0][0]= noktalar2[i][0];
                                        e_k_matris[0][0]= noktalar2[j][0];
                                    }

                                }
                                if(e_u_y<s_y)
                                {
                                    e_u_y=s_y;
                                    if(noktalar2[i][1]<noktalar2[j][1])
                                    {
                                        e_k_matris[0][1]= noktalar2[i][1];
                                        e_b_matris[0][1]= noktalar2[j][1];
                                    }
                                    if(noktalar2[i][1]>noktalar2[j][1])
                                    {
                                        e_b_matris[0][1]= noktalar2[i][1];
                                        e_k_matris[0][1]= noktalar2[j][1];
                                    }

                                }
                                if(e_u_z<s_z)
                                {
                                    e_u_z=s_z;
                                    if(noktalar2[i][2]<noktalar2[j][2])
                                    {
                                        e_k_matris[0][2]= noktalar2[i][2];
                                        e_b_matris[0][2]= noktalar2[j][2];
                                    }
                                    if(noktalar[i][2]>noktalar[j][2])
                                    {
                                        e_b_matris[0][2]= noktalar2[i][2];
                                        e_k_matris[0][2]= noktalar2[j][2];
                                    }

                                }

                            }
                        }

                        s_x=fabs(e_b_matris[0][0]-e_k_matris[0][0]);
                        s_y=fabs(e_b_matris[0][1]-e_k_matris[0][1]);
                        s_z=fabs(e_b_matris[0][2]-e_k_matris[0][2]);
                        if(s_x>s_y && s_x>s_z)
                        {
                            uzaklik=s_x;
                        }
                        else if(s_y>s_x && s_y>s_z)
                        {
                            uzaklik=s_y;
                        }
                        if(s_z>s_y && s_z>s_x)
                        {
                            uzaklik=s_z;
                        }
                        if(s_x==s_y&&s_x==s_z){

                            uzaklik=s_x;
                        }
                        printf("Kupun kenar uzunlugu= %f\n",uzaklik);
                        fprintf(cikti,"Kupun kenar uzunlugu= %f\n",uzaklik);

                        printf("Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");
                        fprintf(cikti,"Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");

                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);

                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                        printf("Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                        fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);












                    }

                }
                if(baslik_kontrol5==strlen(satir5))
                {
                    for (int i=0; i<satir; i++)
                    {

                        for(int j=i+1; j<satir; j++)
                        {

                            s_x= fabs(koordinat1[i][0]- koordinat1 [j][0]);
                            s_y= fabs(koordinat1[i][1]- koordinat1 [j][1]);
                            s_z= fabs(koordinat1[i][2]- koordinat1 [j][2]);
                            if(e_u_x<s_x)
                            {
                                e_u_x=s_x;
                                if(koordinat1[i][0]<koordinat1[j][0])
                                {
                                    e_k_matris[0][0]= koordinat1[i][0];
                                    e_b_matris[0][0]= koordinat1[j][0];
                                }
                                if(koordinat1[i][0]>koordinat1[j][0])
                                {
                                    e_b_matris[0][0]= koordinat1[i][0];
                                    e_k_matris[0][0]= koordinat1[j][0];
                                }

                            }
                            if(e_u_y<s_y)
                            {
                                e_u_y=s_y;
                                if(koordinat1[i][1]<koordinat1[j][1])
                                {
                                    e_k_matris[0][1]= koordinat1[i][1];
                                    e_b_matris[0][1]= koordinat1[j][1];
                                }
                                if(koordinat1[i][1]>koordinat1[j][1])
                                {
                                    e_b_matris[0][1]= koordinat1[i][1];
                                    e_k_matris[0][1]= koordinat1[j][1];
                                }

                            }
                            if(e_u_z<s_z)
                            {
                                e_u_z=s_z;
                                if(koordinat1[i][2]<koordinat1[j][2])
                                {
                                    e_k_matris[0][2]= koordinat1[i][2];
                                    e_b_matris[0][2]= koordinat1[j][2];
                                }
                                if(koordinat1[i][2]>koordinat1[j][2])
                                {
                                    e_b_matris[0][2]= koordinat1[i][2];
                                    e_k_matris[0][2]= koordinat1[j][2];
                                }

                            }

                        }
                    }

                    s_x=fabs(e_b_matris[0][0]-e_k_matris[0][0]);
                    s_y=fabs(e_b_matris[0][1]-e_k_matris[0][1]);
                    s_z=fabs(e_b_matris[0][2]-e_k_matris[0][2]);
                    if(s_x>s_y && s_x>s_z)
                    {
                        uzaklik=s_x;
                    }
                    else if(s_y>s_x && s_y>s_z)
                    {
                        uzaklik=s_y;
                    }
                    if(s_z>s_y && s_z>s_x)
                    {
                        uzaklik=s_z;
                    }
                    printf("Kupun kenar uzunlugu= %f\n",uzaklik);
                    fprintf(cikti,"Kupun kenar uzunlugu= %f\n",uzaklik);

                    printf("Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");
                    fprintf(cikti,"Verilen noktalardan olusabilicek en kucuk kupun kordinatlari;\n");

                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0],e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);

                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f\n",e_k_matris[0][0]+uzaklik,e_k_matris[0][1],e_k_matris[0][2]+uzaklik);
                    printf("Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);
                    fprintf(cikti,"Kupun koseleri= x=%f,y=%f,z=%f",e_k_matris[0][0]+uzaklik,e_k_matris[0][1]+uzaklik,e_k_matris[0][2]+uzaklik);

                }
                fclose(cikti);
            }

            if(secim==4)
            {
                FILE *cikti=fopen("output.nkt","a");
                fprintf(cikti,"4.SECIM\n");
                if(baslik_kontrol5a==strlen(satir5a))
                {
                    if(kelime_kontrol3==5)
                    {

                        printf("Cemberin sirasiyla x y z kordinatlarini giriniz:");
                        scanf("%f %f %f",&cember[0][0],&cember[0][1],&cember[0][2]);
                        printf("Cemberin yaricapini giriniz:");
                        scanf("%f",&cember_yaricap);
                        printf("Cemberin icindeki noktalar:\n");
                        for(int i=0; i<atoi(nokta); i++)
                        {
                            cember_sonuc= sqrt((cember[0][0]-noktalar[i][0])*(cember[0][0]-noktalar[i][0])+(cember[0][1]-noktalar[i][1])*(cember[0][1]-noktalar[i][1])+(cember[0][2]-noktalar[i][2])*(cember[0][2]-noktalar[i][2] ));

                            if(kelime_kontrol3==8)
                            {
                                if( cember_sonuc<=cember_yaricap)
                                {
                                    for(int j=0; j<=5; j++)
                                    {
                                        printf("%f ",noktalar[i][j]);
                                        fprintf(cikti,"%f ",noktalar[i][j]);
                                    }
                                    printf("\n");
                                    fprintf(cikti,"\n");

                                }
                            }
                            else
                            {


                                if( cember_sonuc<=cember_yaricap)
                                {
                                    for(int j=0; j<=2; j++)
                                    {
                                        printf("%f ",noktalar[i][j]);
                                        fprintf(cikti,"%f ",noktalar[i][j]);
                                    }
                                    printf("\n");
                                    fprintf(cikti,"\n");


                                }



                            }

                        }


                    }

                    if(kelime_kontrol3==8)
                    {
                        printf("Cemberin sirasiyla x y z kordinatlarini giriniz:");
                        scanf("%f %f %f",&cember[0][0],&cember[0][1],&cember[0][2]);
                        printf("Cemberin yaricapini giriniz:");
                        scanf("%f",&cember_yaricap);
                        printf("Cemberin icindeki noktalar:\n");
                        for(int i=0; i<atoi(nokta); i++)
                        {
                            cember_sonuc= sqrt((cember[0][0]-noktalar2[i][0])*(cember[0][0]-noktalar2[i][0])+(cember[0][1]-noktalar2[i][1])*(cember[0][1]-noktalar2[i][1])+(cember[0][2]-noktalar2[i][2])*(cember[0][2]-noktalar2[i][2] ));

                            if(kelime_kontrol3==8)
                            {
                                if( cember_sonuc<=cember_yaricap)
                                {
                                    for(int j=0; j<=2; j++)
                                    {
                                        printf("%f ",noktalar2[i][j]);
                                        fprintf(cikti,"%f ",noktalar2[i][j]);
                                    }
                                    printf("\n");
                                    fprintf(cikti,"\n");

                                }
                            }
                            else
                            {


                                if( cember_sonuc<=cember_yaricap)
                                {
                                    for(int j=0; j<=2; j++)
                                    {
                                        printf("%f ",noktalar2[i][j]);
                                        fprintf(cikti,"%f ",noktalar2[i][j]);
                                    }
                                    printf("\n");
                                    fprintf(cikti,"\n");

                                }



                            }

                        }







                    }


                }



                if(baslik_kontrol5==strlen(satir5))
                {
                    printf("Cemberin sirasiyla x y z kordinatlarini giriniz:");
                    scanf("%f %f %f",&cember[0][0],&cember[0][1],&cember[0][2]);
                    printf("Cemberin yaricapini giriniz:");
                    scanf("%f",&cember_yaricap);
                    printf("Cemberin icindeki noktalar:\n");
                    for(int i=0; i<satir; i++)
                    {
                        cember_sonuc= sqrt((cember[0][0]-koordinat1[i][0])*(cember[0][0]-koordinat1[i][0])+(cember[0][1]-koordinat1[i][1])*(cember[0][1]-koordinat1[i][1])+(cember[0][2]-koordinat1[i][2])*(cember[0][2]-koordinat1[i][2] ));

                        if(kelime_kontrol3==8)
                        {
                            if( cember_sonuc<=cember_yaricap)
                            {
                                for(int j=0; j<=5; j++)
                                {
                                    printf("%f ",koordinat1[i][j]);
                                    fprintf(cikti,"%f ",koordinat1[i][j]);
                                }
                                printf("\n");
                                fprintf(cikti,"\n");

                            }
                        }
                        else
                        {


                            if( cember_sonuc<=cember_yaricap)
                            {
                                for(int j=0; j<=2; j++)
                                {
                                    printf("%f ",koordinat1[i][j]);
                                    fprintf(cikti,"%f ",koordinat1[i][j]);
                                }
                                printf("\n");
                                fprintf(cikti,"\n");

                            }



                        }

                    }

                }

                fclose(cikti);

            }

            if(secim==5)
            {
                FILE *cikti=fopen("output.nkt","a");
                fprintf(cikti,"5.SECIM\n");
                if(baslik_kontrol5a==strlen(satir5a))
                {
                    if(kelime_kontrol3==5)
                    {

                        for(int k=0; k<atoi(nokta); k++)
                        {

                            x1=noktalar[k][0];

                            y1=noktalar[k][1];

                            z1=noktalar[k][2];



                            for(int l=(k+1); l<atoi(nokta); l++)
                            {

                                x2=noktalar[l][0];

                                y2=noktalar[l][1];

                                z2=noktalar[l][2];

                                sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                                toplam=toplam+sonuc;

                            }



                        }


                        double toplam1=(double)(atoi(nokta)/2)*(double)(atoi(nokta)+1);


                        printf("Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam/toplam1);
                        fprintf(cikti,"Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam/toplam1);


                    }

                    if(kelime_kontrol3==8)
                    {
                        for(int k=0; k<atoi(nokta); k++)
                        {

                            x1=noktalar2[k][0];

                            y1=noktalar2[k][1];

                            z1=noktalar2[k][2];



                            for(int l=(k+1); l<atoi(nokta); l++)
                            {

                                x2=noktalar2[l][0];

                                y2=noktalar2[l][1];

                                z2=noktalar2[l][2];

                                sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                                toplam3=toplam3+sonuc;

                            }



                        }

                        double toplam1=(double)(atoi(nokta)/2)*(double)(atoi(nokta)+1);

                        printf("Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam3/toplam1);
                        fprintf(cikti,"Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam3/toplam1);




                    }

                }


                if(baslik_kontrol5==strlen(satir5))
                {

                    for(int k=0; k<satir; k++)
                    {

                        x1=koordinat1[k][0];

                        y1=koordinat1[k][1];

                        z1=koordinat1[k][2];



                        for(int l=(k+1); l<satir; l++)
                        {

                            x2=koordinat1[l][0];

                            y2=koordinat1[l][1];

                            z2=koordinat1[l][2];

                            sonuc=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
                            toplam=toplam+sonuc;
                        }



                    }


                    double toplam1=(double)(satir/2)*(double)(satir+1);
                    printf("Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam/toplam1);
                    fprintf(cikti,"Noktalarin birbirine olan uzakliklarinin ortalamasi:%f\n",toplam/toplam1);


                }

                fclose(cikti);
            }







            if(secim==6)
            {

                break;

            }








        }









        fclose(dosya);


    }















    return 0;
}



