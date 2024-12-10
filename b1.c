#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// cau truc ngan xep
typedef struct Stack{
    int array[MAX];
    int top;
}Stack; 

// khoi tao stack rong
void inital(Stack* stack){
    stack->top=-1;
}

// check xem stack co rong khong , nếu rỗng trả về 1
int isEmpty(Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

// check xem stack có đầy không, đầy thì trả về 1
int isFull(Stack* stack){
    if(stack->top >= MAX - 1){
        return 1;
    }
    return 0;
}

// hàm thêm phần tử vào stack
void push(Stack* stack, int value){
    if(isFull(stack) == 1){
        printf("Ngan xep da day");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}
// in ra stack
void printStack(Stack* stack) {
    printf("\n==================== Danh sách ngăn xếp ====================\n");
    if (isEmpty(stack)) {
        printf("|                    Ngăn xếp rỗng                      |\n");
    } else {
        printf("----------------------------------------------------------\n");
        for (int i = stack->top; i >= 0; i--) {
            // Chiều rộng ô cố định là 52, căn giữa giá trị
            int width = 52;
            printf("|%*d%*s|\n", (width / 2) + 1, stack->array[i], (width / 2) - 1, " ");
            printf("----------------------------------------------------------\n");
        }
    }
}
int main(){
    int value;
    Stack stack;
    inital(&stack);
    do{
        printf("==================================Menu===============================");
        printf("\n1. Thêm phần tử vào ngăn xếp");
        printf("\n2. In ra ngăn xếp");
        printf("\n0. Thoát");
        printf("\n Mời bạn chọn ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1: 
                printf("Nhap vao gia tri can them \n");
                scanf("%d", &value);
                push(&stack,value);
                break;
            case 2: 
            printStack(&stack);
            break;
            default:
            printf("Moi ban chon lai");
    }
    }while(1==1);
    return 0;
}