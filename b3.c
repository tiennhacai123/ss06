#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Cấu trúc ngăn xếp
typedef struct Stack {
    int array[MAX];
    int top;
} Stack;

// Khởi tạo stack rỗng
void inital(Stack* stack) {
    stack->top = -1;
}

// Kiểm tra stack có rỗng không, nếu rỗng trả về 1
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Thêm phần tử vào stack
void push(Stack* stack, int value) {
    if (stack->top >= MAX - 1) {
        printf("Ngăn xếp đã đầy!\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

// Hàm chính
int main() {
    Stack stack;
    inital(&stack);

    int n;
    printf("Nhập số lượng phần tử (không quá %d): ", MAX);
    scanf("%d", &n);

    // Kiểm tra số lượng phần tử có hợp lệ không
    if (n < 0 || n > MAX) {
        printf("Số lượng phần tử không hợp lệ!\n");
        return 1;
    }

    // Thêm phần tử vào ngăn xếp nếu n > 0
    if (n > 0) {
        printf("Nhập các phần tử:\n");
        for (int i = 0; i < n; i++) {
            int value;
            printf("Phần tử %d: ", i + 1);
            scanf("%d", &value);
            push(&stack, value);
        }
    }

    // Kiểm tra và in kết quả
    if (isEmpty(&stack)) {
        printf("Ngăn xếp rỗng\n");
    } else {
        printf("Ngăn xếp không rỗng\n");
    }

    return 0;
}
