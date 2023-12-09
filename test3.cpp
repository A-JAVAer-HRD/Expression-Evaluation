//
// Created by huangruidong on 2023/3/3.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct fang_list {
	int bianma;
	char dizhi[10];
	int mengpaihao;
	double price;
	int AN;
	char name[10];
	fang_list* next;
}fang_node;

typedef struct zu_list {
	int id;
	char name[10];
	char jiguan[10];
	int shijian;
	int fangbian;
	int jiaofei;
	zu_list* next;
}zu_node;

typedef struct fandong {
	char name[10];
	char sex[2];
	char dianhua[15];
	fandong* next;
}fangdong_node;

fang_node* headf;
zu_node* headz;
fangdong_node* headfd;


void shoufei();
void tongji();
void fandongxinxi();
void add_fangdong();
void xiugai_fangdong();
void shanchu_fangdong();
void xianshi_fangdong();
void chazhao_fandong();

void fangwuxinxi();
void zuke();
void ruzu();
void add();
void add1();
void xiugai();
void xiugai1();
void shanchu();
void shanchu1();
void xianshi();
void xianshi1();
void chazhao();
void chazhao1();
void guanli();
void cha1();
void cha2();

fang_node* creat_fnode();
fangdong_node* creat_fangdong();
zu_node* creat_znode();
void insert_fnode(fang_node* node);
void insert_znode(zu_node* node);
void insert_fangdong(fangdong_node* node);

int main()
{
	int no = 1;
	int num;
	headf = creat_fnode();
	headz = creat_znode();
	headfd = creat_fangdong();
	while (no)
	{
        setbuf(stdout, 0);
		printf("*************************************\n");
		printf("           房屋租赁信息系统         *\n");
		printf("*************************************\n");
		printf("          1.房屋信息                 \n");
		printf("          2.承租者信息               \n");
		printf("          3.入住管理                 \n");
		printf("          4.退出系统                 \n");
		printf("          5.房东信息\n");
		printf("          6.统计出租数量\n");
		printf("          7.收费管理\n");

		scanf("%d", &num);
		switch (num)
		{
		case 1:fangwuxinxi();
			break;
		case 2:zuke();
			break;
		case 3:guanli();
			break;
		case 4:
		{
			printf("欢迎下次继续使用");
			no = 0;
			return 0;
		}
		case 5:fandongxinxi();
			break;
		case 6:tongji();
			break;
		case 7:shoufei();
			break;
		default:
			break;
		}
	}
}


fang_node* creat_fnode()
{
	fang_node* node = (fang_node*)malloc(sizeof(fang_node));
	if (node == NULL)
	{
		printf("初始化失败");
		exit(0);
	}
	else
	{
		node->next = NULL;
	}
	return node;
}

zu_node* creat_znode()
{
	zu_node* node = (zu_node*)malloc(sizeof(zu_node));
	if (node == NULL)
	{
		printf("初始化失败");
		exit(0);
	}
	else
	{
		node->next = NULL;
	}
	return node;
}

fangdong_node* creat_fangdong()
{
	fangdong_node* node = (fangdong_node*)malloc(sizeof(fangdong_node));
	if (node == NULL)
	{
		printf("初始化失败");
		exit(0);
	}
	else
	{
		node->next = NULL;
	}
	return node;
}

void insert_fnode(fang_node* node)
{
	node->next = headf->next;
	headf->next = node;
}

void insert_znode(zu_node* node)
{
	node->next = headz->next;
	headz->next = node;
}

void insert_fangdong(fangdong_node* node)
{
	node->next = headfd->next;
	headfd->next = node;
}
void fandongxinxi()
{
	int no = 1;
	int f;
	while (no)
	{
		printf("**************************************\n");
		printf("             房东信息                 \n");
		printf("**************************************\n");
		printf("            1.添加房东信息            \n\n");
		printf("            2.修改房东信息            \n\n");
		printf("            3.删除房东信息            \n\n");
		printf("            4.显示房东信息            \n\n");
		printf("            5.查找房东信息            \n\n");
		printf("            6.返回上一界面            \n\n");
		scanf("%d", &f);

		switch (f)
		{
		case 1:add_fangdong();
			break;
		case 2:xiugai_fangdong();
			break;
		case 3:shanchu_fangdong();
			break;
		case 4:xianshi_fangdong();
			break;
		case 5:chazhao_fandong();
			break;
		case 6:no = 0;
			break;
		}
	}
}


void fangwuxinxi() {
	int no = 1;
	int f;
	while (no)
	{
		printf("**************************************\n");
		printf("             房屋信息                 \n");
		printf("**************************************\n");
		printf("            1.添加房屋信息            \n\n");
		printf("            2.修改房屋信息            \n\n");
		printf("            3.删除房屋信息            \n\n");
		printf("            4.显示房屋信息            \n\n");
		printf("            5.查找房屋信息            \n\n");
		printf("            6.返回上一界面            \n\n");
		scanf("%d", &f);
		switch (f)
		{
		case 1:add();
			break;
		case 2:xiugai();
			break;
		case 3:shanchu();
			break;
		case 4:xianshi();
			break;
		case 5:chazhao();
			break;
		case 6:no = 0;
			break;
		}
	}
}

void add_fangdong()
{
	int a = 1;
	char c;
	while (a)
	{
		fangdong_node* node = creat_fangdong();
		printf("输入姓名：\n");
		scanf("%s", node->name);
		printf("输入性别\n");
		scanf("%s", node->sex);
		printf("输入电话\n");
		scanf("%s", node->dianhua);
		insert_fangdong(node);
		printf("是否继续录入？y/n\n\n");
		while (getchar() != '\n');
		scanf(" %c", &c);
		if(c == 'N'||c=='n')
		{
			a = 0;
			printf("输入完成！\n");
			break;
		}
	}
}
void add()//添加
{
	int b = 1;
	char c;
	printf("现在录入数据\n\n");
	while (b)
	{
		fang_node* node = creat_fnode();
		printf("请输入你想录入的房屋编码：\n");
		scanf("%d", &node->bianma);
		printf("请输入房屋地址：\n\n");
		scanf("%s", node->dizhi);
		printf("请输入房屋的门牌号：\n\n");
		scanf("%d", &node->mengpaihao);
		printf("请输入房屋的价格：\n\n");
		scanf("%lf", &node->price);
		printf("请输入房屋是否出租(是为1，否为0)\n\n");
		scanf("%d", &node->AN);
		printf("请输入租房者姓名，没有的话输入无：\n\n");
		scanf("%s", node->name);
		while (getchar() != '\n');
		insert_fnode(node);
		printf("是否继续录入？y/n\n\n");
		scanf(" %c", &c);
		if (c == 'N' || c == 'n')
		{
			b = 0;
			printf("输入完成！\n");
			break;
		}
	}
}

void xiugai_fangdong()
{
	int k = 0, z;
	char name[10];
	char x[20], c[20];
	fangdong_node* node;
	node = headfd->next;
	printf("请输入您想修改的房东姓名：\n");
	scanf("%s",name);
	if (headfd->next == NULL)
	{
		printf("没有任何住房信息，无法修改\n");
		return;
	}
	else
	{

		while (node != NULL)
		{
			if (strcmp(name,node->name)==0)
			{
				k++;
				printf("修改后的姓名；\n");
				scanf("%s", node->name);
				printf("性别\n");
				scanf("%s", node->sex);
				printf("电话\n");
				scanf("%s", node->dianhua);
				break;
			}
			else
			{
				node = node->next;
			}
		}
		if (k == 0)
		{
			printf("没有找到您要修改的房屋信息\n");
		}
	}

}
void xiugai()//修改
{
	int k=0, z;
	char x[20], c[20];
	fang_node* node;
	node = headf->next;
	printf("请输入您想修改的房屋编码：\n");
	scanf("%d", &z);
	if (headf->next==NULL)
	{
		printf("没有任何住房信息，无法修改\n");
		return;
	}
	else
	{

		while (node!=NULL)
		{
			if (z == node->bianma)
			{
				printf("请输入你想录入的房屋编码：\n");
				scanf("%d", &node->bianma);
				printf("请输入房屋地址：\n\n");
				scanf("%s", x);
				strcpy(node->dizhi, x);
				printf("请输入房屋的门牌号：\n\n");
				scanf("%d", &node->mengpaihao);
				printf("请输入房屋的价格：\n\n");
				scanf("%f", &node->price);
				printf("请输入房屋是否出租(是为1，否为0)\n\n");
				scanf("%d", &node->AN);
				printf("请输入租房者姓名，没有的话输入无：\n\n");
				scanf("%s", c);
				strcpy(node->name, c);
				k = -1;
				break;
			}
			else
			{
				node = node->next;
			}
		}
		if (k == 0)
		{
			printf("没有找到您要修改的房屋信息\n");
		}
	}

}
void shanchu_fangdong()
//删除
{
	int k = 0;
	char s[10];
	fangdong_node* node = headfd;
	printf("请输入您想删除的房东姓名：\n");
	scanf("%s", s);

	while (node->next != NULL)
	{
		if (strcmp(node->name,s)==0)
		{
			fangdong_node* temp = node->next;
			node->next = temp->next;
			free(temp);
			k = -1;
			printf("删除成功\n\n");
			break;
		}
		node = node->next;
	}
	if (k == 0)
	{
		printf("没有该房东的具体信息\n\n");
	}
}
void shanchu()//删除
{
	int k = 0, s;
	fang_node* node = headf;
	printf("请输入您想删除的房屋编码：\n");
	scanf("%d", &s);

	while (node->next!= NULL)
	{
		if (s == node->next->bianma)
		{
			fang_node* temp = node->next;
			node->next = temp->next;
			free(temp);
			k = -1;
			printf("删除成功\n\n");
			break;
		}
		node = node->next;
	}
	if (k == 0)
	{
		printf("没有该房屋的具体信息\n\n");
	}
}

void xianshi_fangdong()
//显示
{
	fangdong_node* node = headfd->next;
	printf("名字	性别    	电话 \n");
	printf("------------------------------------------------------------------------------------------\n");
	while (node != NULL)
	{
		printf("%s		%s		%s\n\n",node->name,node->sex,node->dianhua);
		node = node->next;
	}
	return;
}
void xianshi()//显示
{
	fang_node* node = headf->next;
	printf("房屋编码	房屋地址    	房屋门牌号   	房屋价格     	 是否承租    	承租者姓名\n");
	printf("------------------------------------------------------------------------------------------\n");
	while (node != NULL)
	{
		printf("%d		%s		%d		%lf  		%d		%s\n\n", node->bianma, node->dizhi, node->mengpaihao, node->price, node->AN, node->name);
		node = node->next;
	}
	return;
}
void chazhao_fandong()
//查找
{
	char g[10];
	fangdong_node* node = headfd->next;
	printf("请输入您像查看的房东姓名：\n\n");
	scanf("%s", g);
	while (node != NULL)
	{
		if (strcmp(g,node->name))
		{
			printf("%s		%s		%s\n\n", node->name, node->sex, node->dianhua);
			return;
		}
		node = node->next;
	}
	printf("没有查到房东的相关信息");
}
void chazhao()//查找
{
	int g;
	fang_node* node = headf->next;
	printf("请输入您像查看的房屋编码：\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->bianma)
		{
			printf("房屋编码	房屋地址    	房屋门牌号   	房屋价格     	 是否承租    	承租者姓名\n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%d		%lf  		%d		%s\n\n", node->bianma, node->dizhi, node->mengpaihao, node->price, node->AN, node->name);
			return;
		}
		node = node->next;
	}
	printf("没有查到房屋的相关信息");
}
void zuke()
{
	int z;
	int no = 1;
	while (no)
	{
		printf("************************************************\n");
		printf("*                承租者信息                    *\n");
		printf("************************************************\n\n");
		printf(" 1.添加承租者信息        2.修改承租者信息  \n\n");
		printf(" 3.删除承租者信息        4.显示承租者信息  \n\n");
		printf(" 5.查找承租者信息        6.返回主界面    \n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:add1();
			break;
		case 2:xiugai1();
			break;
		case 3:shanchu1();
			break;
		case 4:xianshi1();
			break;
		case 5:chazhao1();
			break;
		case 6:no = 0;
			break;
		}
	}

}
void add1()//添加
{
	int p = 1;
	char c;
	printf("现在录入数据\n\n");
	while (p)
	{

		zu_node* node = creat_znode();
		printf("请输入你想录入的承租者ID：\n");
		scanf("%d", &node->id);
		printf("请输入承租者姓名：\n\n");
		scanf("%s", node->name);
		printf("请输入承租者的籍贯：\n\n");
		scanf("%s", node->jiguan);
		printf("请输入承租者入住的时间：\n\n");
		scanf("%d", &node->shijian);
		printf("请输入租房者租的房子的房屋编码,没有请输入0\n\n");
		scanf("%d", &node->fangbian);
		insert_znode(node);
		while (getchar() != '\n');
		printf("是否继续录入？\n\n");
		scanf(" %c", &c);
		if(c == 'N'||c=='n')
		{
			p = 0;
			printf("输入完成！\n");
			break;
		}
	}
}

void xiugai1()//修改
{
	int z;
	char x[20], c[20];
	zu_node* node = headz->next;
	printf("请输入您想修改的承租者id：\n");
	scanf("%d", &z);
	if (node == NULL)
	{
		printf("没有任何住房信息，无法修改\n");
		return;
	}
	else
	{
		while (node != NULL)
		{
			if (z == node->id)
			{
				printf("请输入你想录入的承租者ID：\n");
				scanf("%d", &node->id);
				printf("请输入承租者姓名：\n\n");
				scanf("%s", x);
				strcpy(node->name, x);
				printf("请输入承租者的籍贯：\n\n");
				scanf("%s", c);
				strcpy(node->jiguan, c);
				printf("请输入承租者入住的时间：\n\n");
				scanf("%d", &node->shijian);
				printf("请输入租房者租的房子的房屋编码,没有请输入0\n\n");
				scanf("%d", &node->fangbian);

				return;
			}
			node = node->next;
		}
	}
	printf("没有找到您要修改的房屋信息\n");
}
void shanchu1()//删除
{
	int s;
	zu_node* node = headz;
	printf("请输入您想删除的承租者的id：\n");
	scanf("%d", &s);
	while (node->next != NULL)
	{
		if (s == node->next->id)
		{
			zu_node* temp = node->next;

			node->next = temp->next;
			free(temp);

			printf("已经成功删除\n\n");
			return;
		}
		node = node->next;
	}
	printf("没有该承租者的具体信息\n\n");
}
void xianshi1()//显示
{
	zu_node* node = headz->next;
	printf("租客id		租客姓名    	租客籍贯  	 租客入住时间    	房屋编号     \n");
	printf("------------------------------------------------------------------------------------------\n");
	while(node!=NULL)
	{
		printf("%d		%s		%s		%d  		%d		\n\n", node->id, node->name, node->jiguan, node->shijian, node->fangbian);
		node = node->next;
	}
	return;
}

void chazhao1()//查找
{
	int g, i;
	zu_node* node = headz->next;

	printf("请输入承租者的id：\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->id)
		{
			printf("租客id		租客姓名    	租客籍贯  	 租客入住时间    	房屋编号     \n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%s		%d  		%d		\n\n", node->id, node->name, node->jiguan, node->shijian, node->fangbian);
			return;
		}
		node = node->next;
	}
	printf("没有查到承租者的信息\n\n");
}//void ruzu()
void guanli()
{
	int r;
	int no = 1;
	while (no)
	{
		printf("************************************************\n");
		printf("*               入住管理                       *\n");
		printf("************************************************\n");
		printf("  1.输入房屋编号查询         2.输入客户ID查询  \n");
		printf("  3.返回主页面\n");
		scanf("%d", &r);
		switch (r)
		{
		case 1:cha1();
			break;
		case 2:cha2();
			break;
		case 3:no = 0;
			break;
		}
	}

}
void cha1()
{
	int g;
	fang_node* node = headf->next;
	printf("请输入您像查看的房屋编码：\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->bianma)
		{
			if (node->AN == 1)
			{
				printf("房屋编号		承租者\n\n");
				printf("%d		%s\n\n", node->bianma, node->name);
				return;
			}
			else
			{
				printf("没有任何承租信息\n\n");
			}
			return;
		}
		node = node->next;
	}
	printf("没有查到房屋的相关信息\n\n");

}
void cha2()
{
	int g, i;
	zu_node* node = headz->next;

	printf("请输入承租者的id：\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->id)
		{
			if (node->fangbian != 0)
			{
				printf("房屋编号		承租者\n\n");
				printf("%d		%s\n\n", node->fangbian, node->name);
				return;
			}
			else
			{
				printf("没有任何承租信息\n\n");
			}
			return;
		}
		node = node->next;
	}
	printf("没有查到承租者的信息\n\n");
}


void shoufei()
{
	zu_node* node = headz->next;
	fang_node* nodef = headf->next;
	int k=0;
	int id;
	char c;
	printf("输入承租者id:");
	scanf("%d", &id);
	printf("承租者    房价      是否缴费\n");
	while (node!=NULL)
	{
		if (id == node->id)
		{
			k = 1;
			nodef = headf->next;
			while (nodef != NULL)
			{
				if (nodef->bianma == node->fangbian)
				{
					k = 2;
					printf("%s\t\t%lf ", node->name, nodef->price);
					if (node->jiaofei == 1)
					{
						printf("\t\t已经缴费\n");
					}
					else
					{
						printf("没有缴费\n");
						printf("是否缴费？y/n");
						while (getchar() != '\n');
						c = getchar();
						if (c == 'Y' || c == 'y')
						{
							node->jiaofei = 1;
							printf("缴费成功\n");
							return;
						}
						else
						{
							return;
						}
					}
				}
				nodef = nodef->next;
			}
		}
		node = node->next;
	}
	if (k == 0)
	{
		printf("\n\n没有改承租者或房屋编号！！！\n");
	}
}


void tongji()
{
	int count = 0;
	double p;
	char dizhi[10];
	int lou;
	int m;
	int chose;
	fang_node* f = headf->next;
	printf("1.按价格统计\n");
	printf("2.按楼层统计\n");
	printf("3.按地段统计\n");
	while (1)
	{
		scanf("%d", &chose);
		if (chose < 1 || chose>3)
			printf("重新输入：");
		else
		{
			break;
		}
	}

	switch (chose)
	{
	case 1:
		printf("输入价格:");
		scanf("%lf", &p);
		while (f!=NULL)
		{
			if (f->price == p && f->AN == 1)
			{
				count++;
				printf("%d %s\n", f->bianma,f->dizhi);
			}
			f = f->next;
		}
		printf("\n有%d个\n", count);
		break;
	case 2:
		printf("输入楼层:");
		scanf("%d", &lou);

		while (f != NULL)
		{
			for (m = f->mengpaihao; m < 10 && m>0; m = m / 10)
			{
				if (m == lou && f->AN == 1)
				{
					count++;
					printf("\n%d %s\n", f->bianma, f->dizhi);
				}
			}

			f = f->next;
		}
		printf("\n有%d个\n", count);
		break;
	case 3:
		printf("输入地址：");
		scanf("%s", dizhi);
		printf("\n");
		while (f != NULL)
		{
			if(strcmp(dizhi, f->dizhi)==0 && f->AN == 1)
			{
				count++;
				printf("%d %s\n", f->bianma, f->dizhi);
			}

			f = f->next;
		}
		printf("\n有%d个\n", count);
		break;
	default:
		break;
	}
}