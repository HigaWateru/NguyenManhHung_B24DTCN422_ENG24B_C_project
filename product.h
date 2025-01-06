#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dataType.h"
#include "function.h"
product prd[1000];
bool choise,found;
int choise1,choise2;
int n, chooseProduct,choiseProduct;
void lastChoiseProduct(int *choiseProduct){
    do{
        printf("[1] Tiep tuc he thong quan ly san pham!\n");
        printf("[0] Quay lai menu chinh.\n");
        printf("Lua chon cua ban: ");
        cin(&choiseProduct);
        printf("------------------------------------------------------------------------\n");
        if(choiseProduct==0){
            chooseProduct=0;
            break;
        }
        else if(choiseProduct==0)break;
        else printf("Lua chon sai! Vui long chon lai!\n\n");
    }while(choiseProduct!=0&&choiseProduct!=1);
}
void mainProduct(){
    printf("*******HE THONG QUAN LY HANG HOA*******\n");
    do{
        system("cls");
        printf("_________________MENU__________________\n");
        printf("=======================================\n");
        printf("[1] Nhap lai thong tin san pham.\n");
        printf("[2] Hien thi thong tin toan bo san pham.\n");
        printf("[3] Them san pham\n");
        printf("[4] Sua thong tin san pham.\n");
        printf("[5] Xoa san pham.\n");
        printf("[6] Tim kiem san pham theo ten.\n");
        printf("[7] Sap xep san pham:\n");
        printf("[8] Loc san pham\n");
        //option...
        printf("[0] Thoat he thong.\n");
        printf("=======================================\n");
        printf("Lua chon cua ban: ");
        cin(&chooseProduct);
        switch(chooseProduct){
            case 1:
                system("cls");
                printf("\n***THONG TIN CAC SAN PHAM***\n");
                printf("Nhap so luong mat hang: ");
                cin(&n);
                for(int i=0;i<n;i++){
                    printf("\n\n___Nhap thong tin san pham thu %d___\n",i+1);
                    printf("ID san pham: ");
                    cinString(prd[i].id,10);
                    addProduct(prd,&i);
                }
                printf("\n");
                printf("Them thong tin san pham thanh cong!\n\n");
                outputFileProduct(prd,&n);
                lastChoiseProduct(&choiseProduct);
                break;
            case 2:
                system("cls");
                inputFileProduct(prd,&n);
                printProduct(prd,&n);
                lastChoiseProduct(&choiseProduct);
                break;
            case 3:
                system("cls");
                inputFileProduct(prd,&n);
                printf("\n**NHAP THONG TIN SAN PHAM MOI**\n");
                printf("ID san pham: ");
                cinString(prd[n].id,10);
                addProduct(prd,&n);
                n++;
                outputFileProduct(prd,&n);
                printf("Thong tin san pham da duoc cap nhat!\n");
                lastChoiseProduct(&choiseProduct);
                break;
            case 4:
                printf("\n\n****SUA THONG TIN SAN PHAM****\n\n");
                inputFileProduct(prd,&n);
                printf("ID san pham: ");
                cinString(idCheck,10);
                found=false;
                for(int i=0;i<n;i++)if(strcmp(prd[i].id,idCheck)==0){
                    printf("Thong tin san pham can sua:\n");
                    found=true;
                    addProduct(prd,&i);
                    break;
                }
                if(found){
                    outputFileProduct(prd,&n);
                    printf("Da cap nhat thong tin san pham!\n");
                }
                else printf("ID san pham khong ton tai.\n\n");
                lastChoiseProduct(&choiseProduct);
                break;
            case 5:
                printf("\n\n****XOA THONG TIN SAN PHAM****\n\n");
                inputFileProduct(prd,&n);
                printf("ID san pham: ");
                cinString(idCheck,10);
                found=false;
                int choise=0;
                for(int i=0;i<n;i++)if(strcmp(prd[i].id,idCheck)==0){
                    found=true;
                    category ctg[100];
                    int count=0;
                    inputFileCategory(ctg,&count);
                    printf("===============================================================================================\n");
                    printf("|    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |    Ten danh muc   |\n");
                    printf("===============================================================================================\n");
                    for(int j=0;j<count;j++)if(strcmp(prd[i].categoryID,ctg[j].id)==0){
                        printf("|%10s|%20s|%11d VND|%10d VND|%10d|%19s|\n",prd[i].id,prd[i].productName,prd[i].priceImport,prd[i].priceSale,prd[i].quantity,ctg[j].categoryName);
                    printf("-----------------------------------------------------------------------------------------------\n");
                    }
                    do{
                        printf("Ban co muon xoa san pham nay?\n[1] Co     [0] Khong\n");
                        printf("Lua chon cua ban: ");
                        cin(&choise);
                        if(choise==1){
                            for(int j=i;j<n-1;j++)prd[j]=prd[j+1];
                            n--;
                            break;
                        }
                    }while(choise!=1&&choise!=0);
                }
                if(found&&choise==1){
                    outputFileProduct(prd,&n);
                    printf("Da xoa san pham ID %s!\n",idCheck);
                }
                else if(found&&choise==0)printf("Da huy xoa san pham!\n");
                else printf("ID san pham khong ton tai.\n\n");
                lastChoiseProduct(&choiseProduct);
                break;
            case 6:
                printf("\n\n****TIM KIEM SAN PHAM THEO TEN****\n\n");
                inputFileProduct(prd,&n);
                printf("Nhap ten san pham can tim: ");
                found=false;
                cinString(name,20);
                for(int i=0;i<n;i++)if(search(name,prd[i].productName))found=true;
                if(!found)printf("Khong tim thay ten san pham!\n");
                else{
                    int c=1;
                    printf("\n\n******Danh sach san pham ten \"%s\"******\n",name);
                    printf("=====================================================================================================\n");
                    printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |    Ten danh muc   |\n");
                    printf("=====================================================================================================\n");
                    for(int i=0;i<n;i++)if(search(name,prd[i].productName)){
                        printf("|%5d|%10s|%20s|%11d VND|%10d VND|%10d|%19s|\n",c,prd[i].id,prd[i].productName,prd[i].priceImport,prd[i].priceSale,prd[i].quantity,findCategoryName(prd[i].categoryID));
                        printf("-----------------------------------------------------------------------------------------------------\n");
                        c++;
                    }
                }
                lastChoiseProduct(&choiseProduct);
                break;
            case 7:
                inputFileProduct(prd,&n);
                printf("\n\n****SAP XEP SAN PHAM THEO GIA TIEN****\n");
                printf("===============================================\n");
                do{
                    printf("[1] Sap xep theo gia nhap hang\n");
                    printf("[2] Sap xep theo gia ban\n");
                    printf("[0] Thoat sap xep\n");
                    printf("Lua chon cua ban: ");
                    cin(&choise1);
                    if(choise1==1){
                        system("cls");
                        printf("\n**SAP XEP THEO GIA NHAP HANG**\n");
                        printf("=====================================\n");
                        printf("[1] Tang dan\n");
                        printf("[2] Giam dan\n");
                        printf("Lua chon cua ban: ");
                        cin(&choise2);
                        if(choise2==1)sortPriceImport(prd,n,true);
                        else if(choise2==2)sortPriceImport(prd,n,false);
                        else printf("Lua chon khong hop le!\n");                        
                    }
                    else if(choise1==2){
                        system("cls");
                        printf("\n**SAP XEP THEO GIA BAN**\n");
                        printf("==============================\n");
                        printf("[1] Tang dan\n");
                        printf("[2] Giam dan\n");
                        printf("Lua chon cua ban: ");
                        cin(&choise2);
                        if(choise2==1)sortPriceSale(prd,n,true);
                        else if(choise2==2)sortPriceSale(prd,n,false);
                        else printf("Lua chon khong hop le!\n");
                    }
                    else break;
                }while(choise1!=0);
                lastChoiseProduct(&choiseProduct);
                break;
            case 8:
                inputFileProduct(prd,&n);
                system("cls");
                printf("***LOC SAN PHAM***\n");
                printf("==============================\n");
                char id[10];
                category ctg[100];
                int count=0;
                inputFileCategory(ctg,&count);
                do{
                    printf("[1] Theo danh muc\n");
                    printf("[2] Theo gia nhap hang\n");
                    printf("[3] Theo gia ban\n");
                    printf("[...] Thoat loc\n");
                    printf("==============================\n");
                    printf("Lua chon cua ban: ");
                    cin(&choise1);
                    if(choise1==1){
                        printf("Nhap ID danh muc: ");
                        cinString(id,10);
                        found=0;
                        int c=1;
                        for(int i=0;i<count;i++)if(strcmp(ctg[i].id,id)==0){
                            found=1;
                            printf("\n**SAN PHAM THEO DANH MUC \"%s\"**\n",ctg[i].categoryName);
                            printf("=================================================================================\n");
                            printf("| STT |    ID    |    Ten san pham    | Gia nhap hang |    Gia ban   | So luong |\n");
                            printf("=================================================================================\n");
                            for(int j=0;j<n;j++)if(strcmp(prd[j].categoryID,ctg[i].id)==0){
                                printf("|%5d|%10s|%20s|%11d VND|%10d VND|%10d|\n",c,prd[j].id,prd[j].productName,prd[j].priceImport,prd[j].priceSale,prd[j].quantity);
                            printf("---------------------------------------------------------------------------------\n");
                                c++;
                            }
                            break;
                        }
                        if(found==0)printf("Danh muc \"%s\" khong ton tai!\n",id);
                    }
                    else if(choise1==2||choise1==3){
                        long long start, end;
                        printf("Nhap gia bat dau: ");
                        cin(&start);
                        printf("Nhap gia ket thuc: ");
                        cin(&end);
                        if(end<start)printf("Gia nhap vao khong hop le!\n");
                        else{
                            if(choise1==2)searchPrice(prd,n,start,end,1);
                            else searchPrice(prd,n,start,end,0);
                        }
                    }
                    else break;
                }while(choise1!=0);
                lastChoiseProduct(&choiseProduct);
            default:
                break;
        }
    }while(chooseProduct!=0);
}