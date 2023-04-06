#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
A。主要内容：结构体类型的声明、结构体初始化、结构体成员访问、结构体传参
一.结构体的声明
i).结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。
struct tag
{
	member-list;
}variable-list;
不推荐用
struct Peo
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
}p1,p2; /*pl和p2是使用struct Peo结构类型创建的2个变量*/
推荐用
struct Peo
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
};
int main()
{
	struct Peo p1 = {0}; /*结构体变量的创建*/
	return 0;
}
ii).结构的成员可以是标量、数组、指针，甚至是其他结构体。
struct St
{
	struct Peo p;
	int num;
	float f;
};
iii).结构体变量的定义和初始化
struct Peo
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
}p3,p4; /*全局变量*/

struct Peo p5,p6; /*全局变量*/

int main()
{
	struct Peo p1 = {“zzl”，“13778066047”，“男”，181}; /*局部变量*/ /*初始化*/
	printf("%s %s %s %d\n",p1.name,p1.tele,p1.sex,p1.high);
	return 0;
}
嵌套结构体的初始化：
struct St
{
	struct Peo p;
	int num;
	float f;
};
int main()
{
	struct St s = {{“zzl”，“13778066047”，“男”，181},100,3.14f};
	
	return 0;
}
二.结构体成员访问
