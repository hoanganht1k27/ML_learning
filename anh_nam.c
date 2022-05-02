#include<stdio.h>

typedef struct Sanpham
{
    int id;
    int price;
    struct Sanpham * next;
} Node;

Node *l;

int main() {
    // Nhap thong tin san pham

    Node * nx;
    nx = l;

    while(nx->next != NULL) {
        if(nx->price >= 300) nx->price = 0.2 * nx->price;
        else nx->price = 0.1 * nx->price;
        nx = nx->next;
    }
}

