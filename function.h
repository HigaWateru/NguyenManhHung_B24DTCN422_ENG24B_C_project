#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataType.h"

//Ham ho tro
void cinString(char *a, int length){
    bool foundString = false;
    do{
        fgets(a,length,stdin);
        if(strlen(a)>0&&a[strlen(a)-1]=='\n')a[strlen(a)-1]='\0';
        int lenStr=strlen(a);
        for(int i=strlen(a);i>=0;i--)if(a[i]==' ')lenStr--;
        if(lenStr==0)printf("Du lieu khong duoc de trong!\nVui long nhap lai: ");
        else foundString=true;
    }while(!foundString);
    
}
void cin(int *a){
    scanf("%d",a);
    getchar();
}
// vao ra voi file
void inputFileCategory(category *a, int *size){
    FILE *file = fopen("category.bin","rb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fread(size,sizeof(int),1,file);
    fread(a,sizeof(category),*size,file);
    fwrite(a,sizeof(product),*size,file);
    fclose(file);
}
void outputFileCategory(category *a, int *size){
    FILE *file = fopen("category.bin","wb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fwrite(size,sizeof(int),1,file);
    fwrite(a,sizeof(category),*size,file);
    fclose(file);
}
void printCategory(category *a, int size){
    if(size==0)printf("Khong co thong tin danh muc!\n");
    else{
        printf("\n******Danh sach danh muc******\n");
        printf("======================================\n");
        printf("| STT |    ID    |    Ten danh muc   |\n");
        printf("======================================\n");
        for(int i=0;i<size;i++){
            printf("|%5d|%10s|%19s|\n",i+1,a[i].id,a[i].categoryName);
            printf("--------------------------------------\n");
        }
    }
}
void inputFileProduct(product *a, int *size){
    FILE *file = fopen("product.bin","rb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fread(size,sizeof(int),1,file);
    fread(a,sizeof(product),*size,file);
    fclose(file);
}

void outputFileProduct(product *a, int *size){
    FILE *file = fopen("product.bin","wb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fwrite(size,sizeof(int),1,file);
    fwrite(a,sizeof(product),*size,file);
    fclose(file);
}
bool checkCategoryID(char *id){
    category a[100];
    int size=0;
    inputFileCategory(a,&size);
    for(int i=0;i<size;i++)if(strcmp(a[i].id,id)==0)return true;
    return false;
}


// Dang thu nghiep ham con tro
char *findCategoryName(char *id){
    category a[100];
    int size=0;
    inputFileCategory(a,&size);
    char *result=(char *)malloc(strlen(id)+1);
    for(int i=0;i<size;i++)if(strcmp(a[i].id,id)==0){
        strcpy(result,a[i].categoryName);
        return result;
    }
    return "Khong co thong tin";
}

void printProduct(product *a, int *size){
    if(*size==0)printf("\nKhong co thong tin san pham!\n---------------------------------------\n");
   else{
        printf("\n******Danh sach san pham******\n");
        printf("=====================================================================================================\n");
        printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |    Ten danh muc   |\n");
        printf("=====================================================================================================\n");
        for(int i=0;i<*size;i++)if(checkCategoryID(a[i].categoryID)){
                printf("|%5d|%10s|%20s|%11d VND|%10d VND|%10d|%19s|\n",i+1,a[i].id,a[i].productName,a[i].priceImport,a[i].priceSale,a[i].quantity,findCategoryName(a[i].categoryID));
        printf("-----------------------------------------------------------------------------------------------------\n");
        }
   }

}

//Xu ly mang cau truc
//Category
void addInfo(category *a, int *size){
    printf("ID danh muc: ");
    bool found = false;
    cinString(a[*size].id,10);
    for(int i=0;i<*size;i++)if(strcmp(a[i].id,a[*size].id)==0){
        found = true;
        break;
    }
    if(found)printf("ID danh muc da ton tai!\n");
    else{
        found = false;
        printf("Ten danh muc: ");
        cinString(a[*size].categoryName,20);
        for(int i=0;i<*size;i++)if(strcmp(a[*size].categoryName,a[i].categoryName)==0){
            found=true;
            break;
        }
        if(found)printf("Ten danh muc da ton tai!\n");
        else{
            printf("Them danh muc thanh cong!\n\n");
            (*size)++;
        }
    }
    printf("---------------------------------------------------\n");
}
//Product
void addProduct(product *a, int *pos){
    printf("Ten san pham: ");
    cinString(a[*pos].productName,20);
    printf("Gia nhap hang: ");
    cin(&a[*pos].priceImport);
    printf("Gia ban: ");
    cin(&a[*pos].priceSale);
    printf("So luong: ");
    cin(&a[*pos].quantity);
    do{
        printf("ID danh muc: ");
        cinString(a[*pos].categoryID,10);
        if(!checkCategoryID(a[*pos].categoryID))printf("ID danh muc khong ton tai!\n");
    }while(!checkCategoryID(a[*pos].categoryID));
    printf("---------------------------------------\n");
}


//Tim kiem, xu ly xau
bool search(char nameCheck[], char nameSearch[]){
    char name_check[20],name_search[20];
    strcpy(name_check,nameCheck);
    strcpy(name_search,nameSearch);
    for(int i=0;i<strlen(name_check);i++)if(name_check[i]>='a'&&name_check[i]<='z')name_check[i]-=32;
    for(int i=0;i<strlen(name_search);i++)if(name_search[i]>='a'&&name_search[i]<='z')name_search[i]-=32;
    for(int i=0;i<strlen(name_check);i++)if(name_check[i]!=name_search[i])return 0;
    return 1;
}

//Sort + swap
void swap1(category *a, category *b){
    category temp= *a;
    *a=*b;
    *b=temp;
}
void swap2(product *a, product *b){
    product temp= *a;
    *a=*b;
    *b=temp;
}
void selectionSortDown(category *a, int size){
    for(int i=0;i<size-1;i++){
        int x=i;
        char chx=a[x].categoryName[0];
        if(chx>='a'&&chx<='z')chx-=32;
        for(int j=i+1;j<size;j++){
            char chj=a[j].categoryName[0];
            if(chj>='a'&&chj<='z')chj-=32;
            if(chx<chj)x=j;
        }
        swap1(&a[i],&a[x]);
    }
    printCategory(a,size);
}
void selectionSortUp(category *a, int size){
    for(int i=0;i<size-1;i++){
        int x=i;
        char chx=a[x].categoryName[0];
        if(chx>='a'&&chx<='z')chx-=32;
        for(int j=i+1;j<size;j++){
            char chj=a[j].categoryName[0];
            if(chj>='a'&&chj<='z')chj-=32;
            if(chx>chj)x=j;
        }
        swap1(&a[i],&a[x]);
    }
    printCategory(a,size);
}
void sortPriceImport(product *a, int size, bool direction){
    for(int i=0;i<size-1;i++){
        int x=i;
        if(direction){
            for(int j=i+1;j<size;j++)if(a[j].priceImport<a[x].priceImport)x=j;
            swap2(&a[i],&a[x]);
        }
        else{
            for(int j=i+1;j<size;j++)if(a[j].priceImport>a[x].priceImport)x=j;
            swap2(&a[i],&a[x]);
        }
    }
    printProduct(a,&size);
}
void sortPriceSale(product *a, int size, bool direction){
    for(int i=0;i<size-1;i++){
        int x=i;
        if(direction){
            for(int j=i+1;j<size;j++)if(a[j].priceSale<a[x].priceSale)x=j;
            swap2(&a[i],&a[x]);
        }
        else{
            for(int j=i+1;j<size;j++)if(a[j].priceSale>a[x].priceSale)x=j;
            swap2(&a[i],&a[x]);
        }
    }
    printProduct(a,&size);
}
void searchPrice(product *a, int size, int start, int end, bool choisePrice){
    bool found=false;
    if(choisePrice){
        for(int i=0;i<size;i++)if(a[i].priceImport>=start&&a[i].priceImport<=end){
            found=true;
            break;
        }
        if(found){
            int c=1;
            system("cls");
            printf("\n***THONG TIN SAN PHAM TAM GIA %lld VND - %lld VND (theo gia nhap hang)***\n",start,end);
            printf("=====================================================================================================\n"); 
            printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |    Ten danh muc   |\n");
            printf("=====================================================================================================\n");            
            for(int i=0;i<size;i++)if(a[i].priceImport>=start&&a[i].priceImport<=end){
                printf("|%5d|%10s|%20s|%11lld VND|%10lld VND|%10d|%19s|\n",c,a[i].id,a[i].productName,a[i].priceImport,a[i].priceSale,a[i].quantity,findCategoryName(a[i].categoryID));
            printf("-----------------------------------------------------------------------------------------------------\n");
                c++;
            }
        }
        else printf("\nKhong tim thay san pham nao trong khoang gia nhap hang tu %lld VND - %lld VND!\n",start,end);
    }
    else{
        for(int i=0;i<size;i++)if(a[i].priceSale>=start&&a[i].priceSale<=end){
            found=true;
            break;
        }
        if(found){
            int c=1;
            system("cls");
            printf("\n***THONG TIN SAN PHAM TAM GIA %lld VND - %lld VND (theo gia ban)***\n",start,end);
            printf("=====================================================================================================\n");
            printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |    Ten danh muc   |\n");
            printf("=====================================================================================================\n");            
            for(int i=0;i<size;i++)if(a[i].priceSale>=start&&a[i].priceSale<=end){
                printf("|%5d|%10s|%20s|%11lld VND|%10lld VND|%10d|%19s|\n",c,a[i].id,a[i].productName,a[i].priceImport,a[i].priceSale,a[i].quantity,findCategoryName(a[i].categoryID));
            printf("-----------------------------------------------------------------------------------------------------\n");
                c++;
            }
        }
        else printf("\nKhong tim thay san pham nao trong khoang gia ban tu %lld VND - %lld VND!\n",start,end);
    }
}


#endif // FUNCTION_H
