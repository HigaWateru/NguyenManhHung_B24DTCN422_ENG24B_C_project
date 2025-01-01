#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "category.h"
#include "product.h"
int choose;
int main(){
    do{
        printf("*** HE THONG QUAN LY ***\n");
        printf("=================================================\n");
        printf("[1] Quan ly danh muc\n");
        printf("[2] Quan ly san pham\n");
        printf("[3] Quan ly hoa don\n");
        printf("[0] Thoat he thong\n");
        printf("=================================================\n");
        printf("Lua chon cua ban: ");
        cin(&choose);
        switch(choose){
                case 0:
                    printf("=====CAM ON DA SU DUNG HE THONG=====\n");
                    printf("===========HEN GAP LAI==============\n");
                case 1:
                    mainCategory();
                    break;
                case 2:
                    mainProduct();
                    break;
        }
    }while(choose!=0);
    return 0;
}
