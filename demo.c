#include<stdio.h>
#include<stdlib.h>
#define MAX 5

// cấu trúc về ngăn xếp
typedef struct{
    int array[MAX];
    int top;
}Stack;

//khởi tạo 1 stack rỗng 
void inital(Stack* stack){
    stack->top = -1;
}

//  kiểm tra stack xem rỗng. hay không
int isEmpty(Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

// kiểm tra ngăn xếp có bị đầy không
int isFull(Stack* stack){
    if(stack->top >= MAX - 1){
        return 1;
    }
    return 0;
}
// them vào stack
void push(Stack* stack, int value){
    if(isFull(stack)==1){
        printf("Ngăn xếp đã đầy\n");
        return;
    }
    stack->array[++(stack->top)] = value;
}

// hàm xoá stack
void delete(Stack* stack){
    if(isFull(stack)){
        printf("Ngan xep bi rong");
        return;
    }
printf("Đã xóa phần tử: %d\n", stack->array[stack->top]);
    stack->top--; // Giảm chỉ số top}
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
// lay ra phan tu cuoi trong danh sach
// Lấy phần tử trên cùng của ngăn xếp
int printLast(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng!\n");
        return -1; // Trả về -1 để biểu thị lỗi
    }
    int result = stack->array[stack->top];
    printf("%d\n", result);
    return result; 
}

int main(){
    int  value;
    Stack stack ;
    inital(&stack);
    do{
        printf("==================================Menu===============================");
        printf("\n1. Thêm phần tử vào ngăn xếp");
        printf("\n2. In ra ngăn xếp");
        printf("\n3. Xoa phan tu cuoi");
        printf("\n4. Lay ra phan tu cuoi");
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
            delete(&stack);
            break;
            case 4:
            printLast(&stack);
            break;
            default:
            printf("Moi ban chon lai");
    }
    }while(1==1);
   return 0; 
}