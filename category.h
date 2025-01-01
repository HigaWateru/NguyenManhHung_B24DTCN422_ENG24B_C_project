#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"
char idCheck[10],name[20],opsion[5];
bool found,choise;
category ctg[100];
int n,choose,count;
void mainCategory(){
    printf("*******HE THONG QUAN LY DANH MUC*******\n");
    do{
        printf("_____________THONG TIN DANH MUC________________\n");
        printf("===============================================\n");
        printf("[1] Them danh muc.\n");
        printf("[2] Hien thi thong tin toan bo danh muc.\n");
        printf("[3] Sua thong tin danh muc.\n");
        printf("[4] Xoa danh muc.\n");
        printf("[5] Tim kiem danh muc theo ten.\n");
        printf("[6] Sap xep danh muc theo ten:\n");
        printf("[0] Thoat he thong quan ly danh muc.\n");
        printf("===============================================\n");
        printf("Lua chon cua ban: ");
        cin(&choose);
        switch(choose){
            case 0:
                break;
            case 1:
                inputFile(ctg,&count,"category.bin");
                printf("\n\n***THEM DANH MUC***\n\n");
                addInfo(ctg,&count);
                outputFile(ctg,&count,"category.bin");
                break;
            case 2:
                inputFile(ctg,&count,"category.bin");
                printStructure(ctg,count);
                break;
            case 3:
                inputFile(ctg,&count,"category.bin");
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
                    outputFile(ctg,&count,"category.bin");
                }else printf("ID danh muc khong ton tai!\n\n");
                break;
            case 4:
                inputFile(ctg,&count,"category.bin");
                printf("\n\n***XOA DANH MUC***\n\n");
                printf("Nhap ID  danh muc can xoa: ");
                cinString(idCheck,10);
                found=0;
                for(int i=0;i<count;i++){
                    if(strcmp(ctg[i].id,idCheck)==0){
                        found=1;
                        printf("Ban co chac chan xoa danh muc?\n");
                        do{
                            printf("[0] Khong       [1] Co\n");
                            printf("Lua chon cua ban: ");
                            cin(&choise);
                            if(choise){
                                for(int j=i;j<count-1;j++)ctg[j]=ctg[j+1];
                                count--;
                                break;
                            }
                        }while(choise!=0&&choise!=1);
                    }
                }
                if(found&&choise){
                    printf("Xoa danh muc thanh cong!\n\n");
                    outputFile(ctg,&count,"category.bin");
                }else if(found&&!choise)printf("Da huy xoa danh muc!\n\n");
                else printf("ID danh muc khong ton tai!\n\n");
                break;
            case 5:
                inputFile(ctg,&count,"category.bin");
                printf("\n\n***TIM KIEM DANH MUC THEO TEN***\n\n");
                printf("Nhap ten danh muc can tim kiem: ");
                cinString(name,20);
                for(int i=0;i<count;i++)if(search(name,ctg[i].categoryName)){
                    found=true;
                    break;
                }
                printf("%d\n",found);
                if(found){
                    printf("\n\n******Danh sach danh muc theo ten \"%s\"******\n",name);
                    printf("======================================\n");
                    printf("| STT |    ID    |    Ten danh muc   |\n");
                    printf("======================================\n");
                    for(int i=0;i<count;i++)if(search(name,ctg[i].categoryName)){
                        printf("|%5d|%10s|%19s|\n",i+1,ctg[i].id,ctg[i].categoryName);
                        printf("--------------------------------------\n");
                    }
                    printf("\n\n");
                }
                else printf("Khong tim thay danh muc co ten \"%s\" trong danh sach!\n\n",name);
                break;
            case 6:
                inputFile(ctg,&count,"category.bin");
                printf("\n\n***SAP XEP DANH MUC THEO TEN***\n\n");
                do{
                    printf("===============================================\n");
                    printf("[a] [A-Z]\n");
                    printf("[b] [Z-A]\n");
                    printf("[...] Thoat sap xep\n");
                    printf("===============================================\n");
                    printf("Lua chon cua ban: ");
                    cinString(opsion,5);
                    printf("===============================================\n");
                    if(strcmp(opsion,"a")==0){
                        selectionSortUp(ctg,count);
                        printf("Sap xep danh muc thanh cong theo thu tu A-Z!\n\n");
                        break;
                    }
                    else if(strcmp(opsion,"b")==0){
                        selectionSortDown(ctg,count);
                        printf("Sap xep danh muc thanh cong theo thu tu Z-A!\n\n");
                        break;
                    }
                    else if(strcmp(opsion,"Exit")==0||strcmp(opsion,"Esc")==0)break;
                    else printf("Nhap sai! Vui long nhap lai.\n");
                }while(opsion!="a"&&opsion!="b"&&opsion!="Exit"&&opsion!="Esc");
                break;
            default:
                break;
        }
    }while(choose!=0);
}