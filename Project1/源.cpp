#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000  // 总内存大小
#define REQUEST_COUNT 5   // 内存请求数

// 定义空闲分区结构体
typedef struct FreeBlock {
    int start;              // 分区起始地址
    int size;               // 分区大小
    struct FreeBlock* next; // 下一个空闲分区
} FreeBlock;

// 初始化空闲分区
FreeBlock* initialize_memory() {
    FreeBlock* block = (FreeBlock*)malloc(sizeof(FreeBlock));
    block->start = 0;
    block->size = MEMORY_SIZE;
    block->next = NULL;
    return block;
}

// 显示空闲分区情况
void display_memory(FreeBlock* head) {
    FreeBlock* current = head;
    printf("当前空闲分区：\n");
    while (current) {
        printf("起始地址: %d, 大小: %d\n", current->start, current->size);
        current = current->next;
    }
    printf("\n");
}

// 首次适应算法
void first_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * prev = NULL;

    while (current) {
        if (current->size >= request_size) {
            printf("分配 %d 字节到地址 %d (首次适应)\n", request_size, current->start);
            current->start += request_size;
            current->size -= request_size;

            if (current->size == 0) { // 如果空闲分区被完全分配
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    *head = current->next;
                }
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("无法分配 %d 字节 (首次适应)\n", request_size);
}

// 最佳适应算法
void best_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * best = NULL, * prev = NULL, * best_prev = NULL;

    while (current) {
        if (current->size >= request_size && (!best || current->size < best->size)) {
            best = current;
            best_prev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (best) {
        printf("分配 %d 字节到地址 %d (最佳适应)\n", request_size, best->start);
        best->start += request_size;
        best->size -= request_size;

        if (best->size == 0) {
            if (best_prev) {
                best_prev->next = best->next;
            }
            else {
                *head = best->next;
            }
            free(best);
        }
    }
    else {
        printf("无法分配 %d 字节 (最佳适应)\n", request_size);
    }
}

// 最坏适应算法
void worst_fit(FreeBlock** head, int request_size) {
    FreeBlock* current = *head, * worst = NULL, * prev = NULL, * worst_prev = NULL;

    while (current) {
        if (current->size >= request_size && (!worst || current->size > worst->size)) {
            worst = current;
            worst_prev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (worst) {
        printf("分配 %d 字节到地址 %d (最坏适应)\n", request_size, worst->start);
        worst->start += request_size;
        worst->size -= request_size;

        if (worst->size == 0) {
            if (worst_prev) {
                worst_prev->next = worst->next;
            }
            else {
                *head = worst->next;
            }
            free(worst);
        }
    }
    else {
        printf("无法分配 %d 字节 (最坏适应)\n", request_size);
    }
}

// 主程序
int main() {
    int requests[REQUEST_COUNT] = { 200, 300, 100, 50, 250 }; // 内存请求
    FreeBlock* memory = initialize_memory();

    printf("首次适应算法:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        first_fit(&memory, requests[i]);
        display_memory(memory);
    }

    memory = initialize_memory();
    printf("最佳适应算法:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        best_fit(&memory, requests[i]);
        display_memory(memory);
    }

    memory = initialize_memory();
    printf("最坏适应算法:\n");
    for (int i = 0; i < REQUEST_COUNT; i++) {
        worst_fit(&memory, requests[i]);
        display_memory(memory);
    }

    return 0;
}
