#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

// Cấu trúc ngăn xếp
typedef struct Stack {
    char array[MAX];
    int top;
} Stack;

// Khởi tạo ngăn xếp rỗng
void initial(Stack* stack) {
    stack->top = -1;
}

// Kiểm tra ngăn xếp có rỗng không
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Thêm phần tử vào stack (push)
void push(Stack* stack, char value) {
    if (stack->top >= MAX - 1) {
        printf("Ngăn xếp đã đầy!\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Lấy phần tử từ stack (pop)
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Trả về ký tự rỗng nếu ngăn xếp rỗng
    }
    return stack->array[stack->top--];
}

// Hàm kiểm tra tính hợp lệ của dấu ngoặc trong biểu thức
bool isValidExpression(const char* expression) {
    Stack stack;
    initial(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        if (current == '(' || current == '{' || current == '[') {
            // Nếu là dấu ngoặc mở, push vào ngăn xếp
            push(&stack, current);
        } else if (current == ')' || current == '}' || current == ']') {
            // Nếu là dấu ngoặc đóng, kiểm tra với phần tử trên đỉnh stack
            if (isEmpty(&stack)) {
                return false; // Ngăn xếp rỗng, không hợp lệ
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return false; // Dấu ngoặc không khớp
            }
        }
    }

    // Nếu ngăn xếp rỗng sau khi duyệt xong biểu thức thì hợp lệ
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    // Nhập biểu thức từ người dùng
    printf("Nhập biểu thức: ");
    fgets(expression, MAX, stdin);

    // Xóa ký tự newline nếu có
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    // Kiểm tra tính hợp lệ của biểu thức và in kết quả
    if (isValidExpression(expression)) {
        printf("Biểu thức hợp lệ\n");
    } else {
        printf("Biểu thức không hợp lệ\n");
    }

    return 0;
}
