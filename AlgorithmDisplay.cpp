// coding: gbk_2312

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>

using namespace std;

bool M[30][30];
int num[30];

void Display()
{
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            if(M[i][j]){
                printf("¡ö");
            }
            else {
                printf("¡¡");
            }
        }
        printf("\n");
    }
    return;
}

void Fill(){
    for(int j = 0; j < 30; j++){
        if(num[j] == 0){
            for(int i = 0; i < 30; i++){
                M[i][j] = false;
            }
        }
        else{
            for(int i = 0; i < num[j] ; i++){
                M[i][j] = false;
            }
            for(int i = num[j]; i < 30; i++) {
                M[i][j] = true;
            }

        }

    }
}

void Initialize(){
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            M[i][j] = false;
        }
    }
    srand(time(0));
    for(int i = 0; i < 30; i++){
        int r = rand() % 30;
        num[i] = r;
        printf("%d\n", r);
    }
    return;
}

int main()
{
    Initialize();
    Fill();
    Display();
    sort(num, num + 30);
    printf("\n--------------\n");
    Fill();
    Display();
    return 0;
}
