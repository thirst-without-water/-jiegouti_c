#include <stdio.h>
A.主要内容：结构体类型的声明、结构体成员访问、结构体传参
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
//
//
二.结构体成员访问
void print1(struct Peo p)
{
	printf("%s %s %s %d\n",p.name,p.tele,p.sex,p.high); /*结构体变量.成员变量*/
}
void print2(struct Peo* sp)
{
	printf("%s %s %s %d\n",sp->name,sp->tele,sp->sex,sp->high); /*结构体指针->成员变量*/
}
int main()
{
	struct Peo p1 = {“zzl”，“13778066047”，“男”，181}; /*局部变量*/ /*初始化*/
	struct St s = {{“zzl”，“13778066047”，“男”，181},100,3.14f};
	print1(p1);
	print2(&p1);
	return 0;
}
//
//
三.结构体传参
上面的print1和print2函数哪个好些?
	答案是:首选print2函数。
原因:
函数传参的时候，参数是需要压栈的
如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。
结论:
结构体传参的时候，要传结构体的地址。
//
//
B.练习
1.
