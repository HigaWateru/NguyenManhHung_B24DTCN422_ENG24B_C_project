#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"
product prd[1000];
bool choise;
int n, choose;
void mainProduct(){
    printf("*******HE THONG QUAN LY HANG HOA*******\n");
    do{
        printf("_________________MENU__________________\n");
        printf("=======================================\n");
        printf("[1] Nhap lai thong tin san pham.\n");
        printf("[2] Hien thi thong tin toan bo san pham.\n");
        printf("[3] Them san pham\n");
        printf("[4] Sua thong tin san pham.\n");
        printf("[5] Xoa san pham.\n");
        printf("[6] Tim kiem san pham theo ten.\n");
        printf("[7] Sap xep san pham:\n");
        //option...
        printf("[n]\n");
        printf("[0] Thoat he thong.\n");
        printf("=======================================\n");
        printf("Lua chon cua ban: ");
        cin(&choose);
        switch(choose){
            case 1:
                printf("\n\n***THONG TIN CAC SAN PHAM***\n\n");
                printf("Nhap so luong mat hang: ");
                cin(&n);
                for(int i=0;i<n;i++){
                    printf("\n\n___Nhap thong tin san pham thu %d___\n",i+1);
                    printf("ID san pham: ");
                    cinString(prd[i].id,10);
                    addProduct(prd,i);
                }
                printf("\n");
                printf("Them thong tin san pham thanh cong!\n\n");
                outputFile(prd,&n,"product.bin");
                break;
            case 2:
                inputFile(prd,&n,"product.bin");
                printf("\n\n******Danh sach san pham******\n");
                printf("===============================================================================================\n");
                printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |   Danh muc  |\n");
                printf("===============================================================================================\n");
                for(int i=0;i<n;i++){
                    printf("|%5d|%10s|%20s|%11d VND|%10d VND|%10d|%13s|\n",i+1,prd[i].id,prd[i].productName,prd[i].priceImport,prd[i].priceSale,prd[i].quantity);
                    printf("-----------------------------------------------------------------------------------------------\n");
                }
                printf("\n\n");
                break;
            case 3:
                inputFile(prd,&n,"product.bin");
                printf("\n\n**NHAP THONG TIN SAN PHAM MOI**\n");
                printf("ID san pham: ");
                cinString(prd[n].id,10);
                if(exitString(prd[n].id))break;
                addProduct(prd,n);
                n++;
                outputFile(prd,&n,"product.bin");
                printf("Thong tin san pham da duoc cap nhat");
                break;
            case 4:
                printf("\n\n****SUA THONG TIN SAN PHAM****\n\n");
                inputFile(prd,&n,"product.bin");
                printf("ID san pham: ");
                cinString(idCheck,10);
                if(exitString(idCheck))break;
                found=false;
                for(int i=0;i<n;i++)if(strcmp(prd[i].id,idCheck)==0){
                    printf("Thong tin san pham can sua:\n");
                    found=true;
                    addProduct(prd,i);
                    break;
                }
                if(found){
                    outputFile(prd,&n,"product.bin");
                    printf("Da cap nhat thong tin san pham!\n");
                }
                else printf("ID san pham khong ton tai.\n\n");
                break;
            case 5:
                printf("\n\n****XOA THONG TIN SAN PHAM****\n\n");
                inputFile(prd,&n,"product.bin");
                printf("ID san pham: ");
                cinString(idCheck,10);
                if(exitString(idCheck))break;
                found=false;
                for(int i=0;i<n;i++)if(strcmp(prd[i].id,idCheck)==0){
                    found=true;
                    for(int j=i;j<n-1;j++)prd[j]=prd[j+1];
                    n--;
                    break;
                }
                if(found){
                    outputFile(prd,&n,"product.bin");
                    printf("Da xoa san pham ID %s!\n",idCheck);
                }
                else printf("ID san pham khong ton tai.\n\n");
                break;
            case 6:
                printf("\n\n****TIM KIEM SAN PHAM THEO TEN****\n\n");
                inputFile(prd,&n,"product.bin");
                printf("Nhap ten san pham can tim: ");
                found=false;
                cinString(name,20);
                if(exitString(name))break;
                else{
                    for(int i=0;i<n;i++)if(search(name,prd[i].productName))found=true;
                    if(!found)printf("Khong tim thay ten san pham!\n");
                    else{
                        printf("\n\n******Danh sach san pham ten \"%s\"******\n",name);
                        printf("=================================================================================\n");
                        printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |\n");
                        printf("=================================================================================\n");
                        for(int i=0;i<n;i++)if(search(name,prd[i].productName)){
                            printf("|%5d|%10s|%20s|%11d VND|%10d VND|%10d|\n",i+1,prd[i].id,prd[i].productName,prd[i].priceImport,prd[i].priceSale,prd[i].quantity);
                            printf("---------------------------------------------------------------------------------\n");
                        }
                    }
                }
            case 7:

            default:
                break;
        }
    }while(choose!=0);
}