#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// cau truc du lieu cho Stack
typedef struct Stack{
    int array[MAX];
    int top;
}Stack;

// khoi tao mang rong cho stack
void initial(Stack* stack){
    stack->top = -1;
}

// ham kiem tra nga xep co rong khong
int isEmpty(Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

// ham kiem tra xem ngan xep da day chua
int isFull(Stack* stack){
    if(stack->top >= MAX - 1){
        return 1;
    }
    return 0;
}

// ham them phan vao stack
void push(Stack* stack, int value){
    if(isFull(stack)){
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

void printStack(Stack* stack){
printf("\n==================== Danh sách ngăn xếp ====================\n");
    if (isEmpty(stack)) {
        printf("|                    Ngăn xếp rỗng                      |\n");
    } else {
        printf("----------------------------------------------------------\n");
        for(int i = stack->top; i >= 0 ; i--){
            // Chiều rộng ô cố định là 52, căn giữa giá trị
            int width = 52;
            printf("|%*d%*s|\n", (width / 2) + 1, stack->array[i], (width / 2) - 1, " ");
            printf("----------------------------------------------------------\n");
        }
    }
}
void peek(Stack* stack) {
    if(isEmpty(stack)) {
        return;
    }
    int result;
    result = stack->array[stack->top];
    printf("Phan tu cuoi cung la:%d \n",result );
}
int main(){
    int value;
    Stack stack;
    initial(&stack);
    do{
        printf("==================================Menu===============================");
        printf("\n1. Thêm phần tử vào ngăn xếp");
        printf("\n2. In ra ngăn xếp");
        printf("\n3. In ra phan tu cuoi cung");
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
            case 3:
            peek(&stack);
            break;
            default:
            printf("Moi ban chon lai");
    }
    }while(1==1);
}