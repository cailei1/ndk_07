#include <stdio.h>

void add(int num1, int num2) {
    printf("num1+num2=%d \n", num1 + num2);
}

void mins(int num1, int num2) {
    printf("num1-num2=%d \n", num1 - num2);
}

void operate(void *(method)(int, int), int num1, int num2) {
    method(num1, num2);
}

void call_back(int current, int total) {
    printf("压缩的进度是:%d/%d", current, total);
}

void compress(char* file_name, void(call_back)(int,int)){
    call_back(12,24);
}

int main() {

    //二级指针
    int num = 12;
    int *p = &num;
    int **s_p = &p;

    printf("p 的值是:%p \n s_p的值是:%p", p, s_p);

    //数组
    int arr[] = {1, 2, 3, 4};


    //数组遍历 Linux 可能会有问题
    for (int i = 0; i < 4; i++) {
        printf("%d \n", arr[i]);
    }


    //for 循环再c 和 c++正确写法

    int i = 0;
    for (; i < 4; i++) {
        printf("%d \n", arr[i]);
    }

    printf("arr 的值:%p \n", arr);
    printf("&arr 的值:%p \n", &arr);
    printf("&arr[0] 的值:%p \n", &arr[0]);

    //arr 的值:0x7ffeeb906870
    //&arr 的值:0x7ffeeb906870
    //&arr[0] 的值:0x7ffeeb906870
    //int *q =&arr[0]=arr

    int *arr_p = arr;


    printf("%d", *arr);


    //数组指针赋值
    int j = 0;
    for (; j < 4; j++) {
        //读取数组的方式
        printf("位置%d的值是%d \n", j, *(arr_p + j));
        printf("位置%d的值是%d \n", j, *(arr + j));
        printf("位置%d的值是%d \n", j, arr_p[j]);
    }

    //指针为啥要有类型  指针其实就是一块地址而且他的值都差不多 因为指针偏移需要知道偏移几个字节
//    int number = 12;
//    double *pDouble = &number;


//函数指针（回调）

    add(1, 2);

    //方法指针的定义 方法的返回值+*，方法的名称可以随便取：add_p  ,方法的参数
//    void *(add_p)=add;
    operate(add, 1, 2);



    compress("sss",call_back);
    return 0;
}


