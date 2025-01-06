#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dataType.h"
#include "function.h"
char idCheck[10],name[20],opsion[5];
bool found;
category ctg[100];
int n,chooseCategory,count,choiseCategory;

void lastChoise(int *choiseCategory){
    do{
        printf("[1] Tiep tuc he thong quan ly danh muc.\n");
        printf("[0] Thoat he thong quan ly danh muc.\n");
        printf("Lua chon cua ban: ");
        cin(&choiseCategory);
        if(choiseCategory==1)break;
        else if(choiseCategory==0){
            chooseCategory=0;
            break;
        }
        else printf("Lua chon khong hop le!\n");
        printf("--------------------------------------\n");
    }while(choiseCategory!=0&&choiseCategory!=1);
}
void mainCategory(){
    printf("*******HE THONG QUAN LY DANH MUC*******\n");
    do{
        system("cls");
        printf("_____________THONG TIN DANH MUC________________\n");
        printf("===============================================\n");
        printf("[1] Them danh muc.\n");
        printf("[2] Hien thi thong tin toan bo danh muc.\n");
        printf("[3] Sua thong tin danh muc.\n");
        printf("[4] Xoa danh muc.\n");
        printf("[5] Tim kiem danh muc theo ten.\n");
        printf("[6] Sap xep danh muc theo ten.\n");
        printf("[0] Thoat he thong quan ly danh muc.\n");
        printf("===============================================\n");
        printf("Lua chon cua ban: ");
        cin(&chooseCategory);
        printf("\n");
        switch(chooseCategory){
            case 0:
                break;
            case 1:
                inputFileCategory(ctg,&count);
                system("cls");
                printf("\n***THEM DANH MUC***\n\n");
                addInfo(ctg,&count);
                outputFileCategory(ctg,&count);
                lastChoise(&choiseCategory);
                break;
            case 2:
                inputFileCategory(ctg,&count);
                printCategory(ctg,count);
                lastChoise(&chooseCategory);
                break;
            case 3:
                inputFileCategory(ctg,&count);
                printf("\n\n***SUA THONG TIN DANH MUC***\n\n");
                printf("Nhap ID  danh muc can sua: ");
                cinString(idCheck,10);
                found=0;
                for(int i=0;i<count;i++){
                    if(strcmp(ctg[i].id,idCheck)==0){
                        found=1;
                        printf("Nhap ten danh muc moi: ");
                        cinString(ctg[i].categoryName,20);
                        break;
                    }
                }
                if(found){
                    printf("Sua thong tin danh muc thanh cong!\n\n");
                    outputFileCategory(ctg,&count);
                }else printf("ID danh muc khong ton tai!\n\n");
                lastChoise(&choiseCategory);
                break;
            case 4:
                inputFileCategory(ctg,&count);
                printf("\n\n***XOA DANH MUC***\n\n");
                printf("Nhap ID  danh muc can xoa: ");
                cinString(idCheck,10);
                int choise=0;
                found=0;
                for(int i=0;i<count;i++)if(strcmp(ctg[i].id,idCheck)==0){
                    printf("================================\n");
                    printf("|    ID    |    Ten danh muc   |\n");
                    printf("================================\n");
                    printf("|%10s|%19s|\n",ctg[i].id,ctg[i].categoryName);
                    printf("--------------------------------\n");
                    found=1;
                    printf("Ban co chac chan xoa danh muc?\n");
                    do{
                        printf("[0] Khong       [1] Co\n");
                        printf("Lua chon cua ban: ");
                        cin(&choise);
                        if(choise==1){
                            for(int j=i;j<count-1;j++)ctg[j]=ctg[j+1];
                            count--;
                            break;
                        }
                    }while(choise!=0&&choise!=1);
                    
                }
                if(found&&choise==1){
                    printf("Xoa danh muc thanh cong!\n\n");
                    outputFileCategory(ctg,&count);
                }else if(found&&choise==0)printf("Da huy xoa danh muc!\n\n");
                else printf("ID danh muc khong ton tai!\n\n");
                lastChoise(&choiseCategory);
                break;
            case 5:
                inputFileCategory(ctg,&count);
                printf("\n\n***TIM KIEM DANH MUC THEO TEN***\n\n");
                printf("Nhap ten danh muc can tim kiem: ");
                cinString(name,20);
                for(int i=0;i<count;i++)if(search(name,ctg[i].categoryName)){
                    found=true;
                    break;
                }
                if(found){
                    int c=1;
                    printf("\n\n******Danh sach danh muc theo ten \"%s\"******\n",name);
                    printf("======================================\n");
                    printf("| STT |    ID    |    Ten danh muc   |\n");
                    printf("======================================\n");
                    for(int i=0;i<count;i++)if(search(name,ctg[i].categoryName)){
                        printf("|%5d|%10s|%19s|\n",c,ctg[i].id,ctg[i].categoryName);
                        printf("--------------------------------------\n");
                        c++;
                    }
                    printf("\n\n");
                }
                else printf("Khong tim thay danh muc co ten \"%s\" trong danh sach!\n\n",name);
                lastChoise(&chooseCategory);
                break;
            case 6:
                inputFileCategory(ctg,&count);
                printf("\n\n***SAP XEP DANH MUC THEO TEN***\n\n");
                do{
                    printf("===============================================\n");
                    printf("[1] [A-Z]\n");
                    printf("[2] [Z-A]\n");
                    printf("[0] Thoat sap xep\n");
                    printf("===============================================\n");
                    printf("Lua chon cua ban: ");
                    cin(&choise);
                    printf("===============================================\n");
                    switch (choise)
                    {
                        case 0:
                            printf("Da thoat chuc nang sap xep!\n");
                            break;
                        case 1:
                            selectionSortUp(ctg,count);
                            printf("Sap xep danh muc thanh cong theo thu tu A-Z!\n\n");
                            break;
                        case 2:
                            selectionSortDown(ctg,count);
                            printf("Sap xep danh muc thanh cong theo thu tu Z-A!\n\n");
                            break;
                        default:
                            printf("Nhap sai! Vui long nhap lai.\n");
                            break;
                    }
                }while(choise!=0);
                lastChoise(&choiseCategory);
                break;
            default:
                break;
        }
    }while(chooseCategory!=0);
}