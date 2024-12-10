#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Cấu trúc dữ liệu cho Stack
typedef struct Stack {
    char array[MAX];
    int top;
} Stack;

// Khởi tạo ngăn xếp rỗng
void initial(Stack* stack) {
    stack->top = -1;
}

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Kiểm tra ngăn xếp đã đầy chưa
int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

// Thêm ký tự vào stack
void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngăn xếp đã đầy!\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

// Lấy ký tự ra từ stack (pop)
// Lấy ký tự ra từ stack (pop)
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng!\n");
        return '\0';  // Trả về ký tự rỗng nếu ngăn xếp rỗng
    }
    return stack->array[stack->top--];
}


// Hàm đảo ngược chuỗi từ stack
void reverseString(char* str) {
    Stack stack;
    initial(&stack);

    // Thêm từng ký tự của chuỗi vào stack
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    // Lấy các ký tự ra từ stack để tạo chuỗi đảo ngược
    printf("Chuỗi đảo ngược là: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char input[MAX];

    // Nhập chuỗi từ người dùng
    printf("Nhập một chuỗi có độ dài không quá 100 ký tự: ");
    fgets(input, MAX, stdin);

    // Xóa ký tự newline nếu có
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Gọi hàm để đảo ngược chuỗi
    reverseString(input);

    return 0;
}
