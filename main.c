#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infos{
    char name[20];
    int hp;
};

void what_is_your_name(struct infos *);
void selecting_person(int,struct infos[],char *);
int searching_person(char[],struct infos[],int);
void game(int,struct infos *);


int main() {
    int n;
    int count = 0;
    struct infos *players;
    char kisi[10];


    printf("Oyunu kac kisi oynayacak ? \n");
    scanf("%d",&n);

    players = (struct infos*)calloc(n,sizeof(struct infos));

    for(int i=0; i<n; i++) {
        printf("Lutfen %d. karakterinizin adini giriniz : \n",i+1);
        what_is_your_name(players[i].name);
        printf("%d. Oyuncu adi : %s\n",i+1,players[i].name);
        players[i].hp = 5;
    }


    while(players[count].hp != 0){

        selecting_person(count,players,kisi);
        game(searching_person(kisi,players,n),players);

        if (count == n-1){
            for(int i = 0;i<n;i++){
                printf("\n %s Oyuncusunun kalan cani = %d \n",players[i].name,players[i].hp);
            }
            count = 0;
        }
        else
            count++;
    }

    return 0;
}

void what_is_your_name(struct infos *players){
    scanf(" %[^\n]s",players->name);
}

void selecting_person(int count,struct infos players[],char *kisi){
    printf("Tur sirasi %s \n",players[count].name);
    printf("Kime saldirmak istersiniz ? \n");
    scanf("%s",kisi);
}

int searching_person(char kisi[],struct infos players[],int n){
    int i = 0;
    while(strcmp(kisi,players[i].name) != 0 && i <= n){
        i++;
    }
    if(i > n){
        printf("Oyuncu bulunamadi. \n");
        exit(1);
    }
    else
        return i;
}

void game(int i,struct infos *players){
    players[i].hp = players[i].hp - 1;
}