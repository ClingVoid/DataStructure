#include<stdio.h>
#define MAXSIZE 100
typedef int elemtype;
typedef struct seqlist{
    elemtype data[MAXSIZE];
    int length;
}seqlist;
void init(seqlist* list) {
    list->length = 0;
    printf("初始化成功储存元素个数为%d", list->length);
    printf("初始化内存大小为%zu", sizeof(list->data));
}
int appendelem(seqlist* list,elemtype element) {//在尾部增加元素
    if (list->length == MAXSIZE) {
        printf("满了不能添加了");
        return 0;
    }
    list->data[list->length] = element;
    list->length++;
    return 1;
}
void listelem(seqlist* list) {//遍历列表
    for (int i = 0; i < list->length;i++) {
        printf("列表中的元素%d", list->data[i]);
    }
    printf("\n");
}
int insertelement(seqlist* list,int position,elemtype element) {//在中间插入元素
    if (list->length > MAXSIZE) {
        printf("满了不能添加了");
        return 0;
    }
    if (position > list->length) {
        printf("输入错误");
        return 0;
    }
    if (position < list->length) {
        for (int i = list->length; i >= position; i--) {
            list->data[i] = list->data[i-1];
        }
        list->data[position-1] = element;
        list->length++;
        return 1;
    }
}
int deleteelement(seqlist* list,int position) {//删除元素
    if (list->length ==0) {
        printf("空表没有可以删的");
        return 0;
    }
    if (position > list->length) {
        printf("输入错误");
        return 0;
    }
    if (position < list->length) {
        for (int i =position; i<list->length; i++) {
            list->data[i - 1] = list->data[i];
        }
        list->length--;
        return 1;
    }
}
int findelement(seqlist* list, elemtype element) {//查找
    for (int i = 0; i < list->length;i++) {
        if (list->data[i] == element) {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    int position;
    elemtype element;
    printf("请输入要添加的元素");
    scanf("%d", &element);
    seqlist list;
    init(&list);
    appendelem(&list,element);
    listelem(&list);
    printf("请输入要添加的位置");
    scanf("%d", &position);
    insertelement(&list,position,element);
    listelem(&list);
}