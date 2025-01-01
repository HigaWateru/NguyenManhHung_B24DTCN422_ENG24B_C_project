#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataType.h"
//Các hàm chức năng hỗ trợ
void cinString(char *a, int length){
    fgets(a,length,stdin);
    if(strlen(a)>0&&a[strlen(a)-1]=='\n')a[strlen(a)-1]='\0';
}
void cin(int *a){
    scanf("%d",a);
    getchar();
}
void swap(category *a, category *b){
    category temp= *a;
    *a=*b;
    *b=temp;
}

// Vào ra với file.bin
void inputFile(category *a, int *size, char *fileName){
    FILE *file = fopen(fileName,"rb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fread(size,sizeof(int),1,file);
    if(strcmp(fileName,"category.bin")==0)fread(a,sizeof(category),*size,file);
    else if(strcasecmp(fileName,"product.bin")==0)fwrite(a,sizeof(product),*size,file);
    else printf("File he thong khong ton tai!\nVui long tao file va dong bo file!\n");
    fclose(file);
}
void outputFile(category *a, int *size, char *fileName){
    FILE *file = fopen(fileName,"wb");
    if(file==NULL){
        printf("File he thong khong ton tai!\nVui long tao file va dong bo file vao he thong!\n");
        return;
    }
    fwrite(size,sizeof(int),1,file);
    if(strcmp(fileName,"category.bin")==0)fwrite(a,sizeof(category),*size,file);
    else if(strcasecmp(fileName,"product.bin")==0)fwrite(a,sizeof(product),*size,file);
    else printf("File he thong khong ton tai!\nVui long tao file va dong bo file!\n");
    fclose(file);
}
void printStructure(category *a, int size){
    printf("\n\n******Danh sach danh muc******\n");
    printf("======================================\n");
    printf("| STT |    ID    |    Ten danh muc   |\n");
    printf("======================================\n");
    for(int i=0;i<size;i++){
        printf("|%5d|%10s|%19s|\n",i+1,a[i].id,a[i].categoryName);
        printf("--------------------------------------\n");
    }
    printf("\n\n");

}

//Xử lý mảng cấu trúc
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
}
//Product
void addProduct(product *a, int pos){
    printf("Ten san pham: ");
    cinString(a[pos].productName,20);
    printf("Gia nhap hang: ");
    cin(&a[pos].priceImport);
    printf("Gia ban: ");
    cin(&a[pos].priceSale);
    printf("So luong: ");
    cin(&a[pos].quantity);
    printf("ID danh muc: ");
    cinString(a[pos].categoryID,10);
    printf("---------------------------------------\n");

}

//Kiểm tra tên tìm kiếm, xử lý chuỗi kí tự
bool search(char nameCheck[], char nameSearch[]){
    char name_check[20],name_search[20];
    strcpy(name_check,nameCheck);
    strcpy(name_search,nameSearch);
    for(int i=0;i<strlen(name_check);i++)if(name_check[i]>='a'&&name_check[i]<='z')name_check[i]-=32;
    for(int i=0;i<strlen(name_search);i++)if(name_search[i]>='a'&&name_search[i]<='z')name_search[i]-=32;
    for(int i=0;i<strlen(name_check);i++)if(name_check[i]!=name_search[i])return 0;
    return 1;
}

//Sắp xếp 
void selectionSortUp(category *a, int size){
    for(int i=0;i<size-1;i++){
        int x=i;
        char chx=a[x].categoryName[0];
        if(chx>='a'&&chx<='z')chx-=32;
        for(int j=i+1;j<size;j++){
            char chj=a[j].categoryName[0];
            if(chj>='a'&&chj<='z')chj-=32;
            if(chx<chj)x=j;
        }
        swap(&a[i],&a[x]);
    }
    printStructure(a,size);
}
void selectionSortDown(category *a, int size){
    for(int i=0;i<size-1;i++){
        int x=i;
        char chx=a[x].categoryName[0];
        if(chx>='a'&&chx<='z')chx-=32;
        for(int j=i+1;j<size;j++){
            char chj=a[j].categoryName[0];
            if(chj>='a'&&chj<='z')chj-=32;
            if(chx>chj)x=j;
        }
        swap(&a[i],&a[x]);
    }
    printStructure(a,size);
}



// Kiểm chứng admin (đang đớ)
char account[]="Nguyen Manh Hung";
char password[]="b24dtcn422";
char checkAccount[50],checkPass[50];
void verifyADMIN(){
    printf("\n      Dang nhap admin\n==============================\n");
    printf("Ten dang nhap: ");
    cinString(checkAccount,50);
    if(strcmp(checkAccount,account)!=0)printf("==============================\nTen dang nhap khong hop le! Vui long thu lai.\n");
    else{
        printf("Mat khau: ");
        cinString(checkPass,50);
        if(strcmp(checkPass,password)!=0)printf("==============================\nSai mat khau! Vui long thu lai.\n");
        else printf("==============================\nDang nhap thanh cong!\n");
    }
}

