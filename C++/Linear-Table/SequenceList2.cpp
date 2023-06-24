// 顺序表（动态分配）
// Sequence list (dynamic allocation)

# include<stdlib.h>
# include<stdio.h> 
# include<iostream>

using namespace std;

//==================================================================//
// 顺序表的定义
// Define the sequence list
// 动态分配
// Dynamic allocation
typedef int ElemType;
# define Initsize 10
typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
} SqList;


//==================================================================//
// 初始化顺序表
// Initialize the sequence list
void InitList(SqList &L) {
    L.data = (ElemType *)malloc(Initsize * sizeof(ElemType));
    L.length = 0;
    L.MaxSize = Initsize;
    cout << "The sequence list is initialized." << endl;
    cout << "The initial max length of the sequence list is " << L.MaxSize << endl;
}

// ================================================================ //
// 增加动态分配的顺序表的长度
// Increase the length of the dynamically allocated sequence list
void IncreaseSize(SqList &L, int len) {
    ElemType *p = L.data;   // 保留原顺序表的首地址  // Save the first address of the original sequence list
    L.data = (ElemType *)malloc((L.MaxSize + len) * sizeof(ElemType));  // 重新分配空间  // Reallocate space
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];   // 将数据复制到新区域  // Copy data to new area
    }
    L.MaxSize = L.MaxSize + len;    // 顺序表最大长度增加len  // The maximum length of the sequence list increases by len
    free(p);    // 释放原来的顺序表空间  // Release the original sequence list space
    cout << "The max length of the sequence list is increased to " << L.MaxSize << endl;
}

// ================================================================ //
// 判断顺序表是否为空
// Determine if the sequence list is empty
bool ListEmpty(SqList &L) {
    if (L.length == 0) {
        return true;
    } else {
        return false;
    }
}

// ================================================================ //
// 求顺序表的长度
// Get the length of the sequence list
void ListLength(SqList &L) {
    cout << "The length of the sequence list is " << L.length << endl;
}

// ================================================================ //
// 输出顺序表
// Output the sequence list
void PrintList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// ================================================================ //
// 求顺序表中某个数据元素值
// Get the value of an element in the sequence list
void GetElem(SqList &L, int i) {
    if (i < 1 || i > L.length) {
        cout << "The " << i << "th element does not exist." << endl;
    } else {
        cout << "The " << i << "th element is " << L.data[i - 1] << endl;
    }
}

// ================================================================ //
// 按元素值查找
// Search by element value
void LocateElem(SqList &L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            break;
        }
    }
    if (i == L.length) {
        cout << "The element " << e << " does not exist." << endl;
    } else {
        cout << "The element " << e << " is the " << i + 1 << "th element." << endl;
    }
}

// ================================================================ //
// 指定位置插入元素
// Insert an element at the specified position
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {    // 判断i值的合法性  // Determine the legality of i
        cout << "The " << i << "th position does not exist." << endl;
        return false;
    }
    if (L.length >= L.MaxSize) {  // 判断顺序表是否已满  // Determine if the sequence list is full
        IncreaseSize(L, 1);    // 若顺序表已满，则增加其长度  // If the sequence list is full, increase its length
    }
    for (int j = L.length; j >= i; j--) {   // 将第i个元素及之后的元素后移  // Move the i-th element and subsequent elements back
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;  // 在位置i处放入e  // Put e at position i
    L.length++;
    cout << "The element " << e << " is inserted at the " << i << "th position." << endl;
    return true;
}

// 在顺序表的末尾插入元素
// Insert an element at the end of the sequence list
void ListInsert(SqList &L, ElemType e) {
    if (L.length >= L.MaxSize) {  // 判断顺序表是否已满  // Determine if the sequence list is full
        IncreaseSize(L, 1);    // 若顺序表已满，则增加其长度  // If the sequence list is full, increase its length
    }
    L.data[L.length] = e;  // 在顺序表的末尾插入元素  // Insert an element at the end of the sequence list
    L.length++;
    cout << "The element " << e << " is inserted at the end of the sequence list." << endl;
}

// ================================================================ //、
// 指定位置删除元素
// Delete an element at the specified position
bool ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) {    // 判断i值的合法性  // Determine the legality of i
        cout << "The " << i << "th position does not exist." << endl;
        return false;
    }
    for (int j = i; j < L.length; j++) {   // 将第i个元素之后的元素前移  // Move the elements after the i-th element forward
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// ================================================================ //
// 修改指定位置元素
// Modify the element at the specified position
bool ListChange(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length) {    // 判断i值的合法性  // Determine the legality of i
        cout << "The " << i << "th position does not exist." << endl;
        return false;
    }
    L.data[i - 1] = e;
    cout << "The " << i << "th element is changed to " << e << endl;
    return true;
}

// ================================================================ //
// 销毁顺序表
// Destroy the sequence list
bool DestroyList(SqList &L) {
    free(&L);
    cout << "The sequence list is destroyed." << endl;
    return true;
}

// ================================================================ //
// 主函数
// Main function
int main(){
    SqList L;
    // 初始化顺序表  // Initialize the sequence list
    InitList(L);  

    // 判断顺序表是否为空  // Determine if the sequence list is empty
    if (ListEmpty(L)==true){
        cout << "The sequence list is empty." << endl;
    } else {
        cout << "The sequence list is not empty." << endl;
    };   

    cout << endl;

    // 插入元素  // Insert elements
    ListInsert(L, 9);
    ListInsert(L, 8);
    ListInsert(L, 7);
    ListInsert(L, 6);
    ListInsert(L, 5);

    // 输出顺序表  // Output the sequence list
    ListLength(L);
    cout << "The sequence list is ";
    PrintList(L);

    cout << endl;

    // 指定位置插入元素  // Insert an element at the specified position
    ListInsert(L, 3, 14);
    ListInsert(L, 1, -3);
    ListInsert(L, 9, 1);   // 此时位置9不存在  // Position 9 does not exist
    ListInsert(L, 5, 2);
    ListInsert(L, 6, 0);
    ListInsert(L, 7, 0);   
    ListInsert(L, 8, 88);   // 此时顺序表已满  // The sequence list is full

    // 输出顺序表  // Output the sequence list
    ListLength(L);
    cout << "The sequence list is ";
    PrintList(L);

    cout << endl;

    // 指定位置修改元素  // Modify the element at the specified position
    ListChange(L, 5, 99);

    // 按元素值查找  // Search by element value
    LocateElem(L, 99);

    // 指定位置删除元素  // Delete an element at the specified position
    ListDelete(L, 5);

    // 输出顺序表  // Output the sequence list
    ListLength(L);
    cout << "The sequence list is ";
    PrintList(L);

}