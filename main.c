#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include "category.h"
#include "product.h"
int chooseMenu;
int main(){
    do{
        system("cls"); 
        printf("*** HE THONG QUAN LY ***\n");
        printf("=================================================\n");
        printf("[1] Quan ly danh muc\n");
        printf("[2] Quan ly san pham\n");
        printf("[3] Quan ly hoa don\n");
        printf("[0] Thoat he thong\n");
        printf("=================================================\n");
        printf("Lua chon cua ban: ");
        cin(&chooseMenu);
        printf("\n");
        switch(chooseMenu){
                case 0:
                    printf("===== CAM ON DA SU DUNG HE THONG =====\n");
                    printf("=========== HEN GAP LAI ==============\n");
                    break;
                case 1:
                    mainCategory();
                    break;
                case 2:
                    mainProduct();
                    break;
                case 3:
                    printf("=========== COMING SOON ==============\n");
                    printf("An phim bat ki de tiep tuc!");
                    _getch();
                    break;
                default:
                    break;
        }
    }while(chooseMenu!=0);
    return 0;
}
