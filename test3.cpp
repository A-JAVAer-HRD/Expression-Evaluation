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
		printf("           ����������Ϣϵͳ         *\n");
		printf("*************************************\n");
		printf("          1.������Ϣ                 \n");
		printf("          2.��������Ϣ               \n");
		printf("          3.��ס����                 \n");
		printf("          4.�˳�ϵͳ                 \n");
		printf("          5.������Ϣ\n");
		printf("          6.ͳ�Ƴ�������\n");
		printf("          7.�շѹ���\n");

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
			printf("��ӭ�´μ���ʹ��");
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
		printf("��ʼ��ʧ��");
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
		printf("��ʼ��ʧ��");
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
		printf("��ʼ��ʧ��");
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
		printf("             ������Ϣ                 \n");
		printf("**************************************\n");
		printf("            1.��ӷ�����Ϣ            \n\n");
		printf("            2.�޸ķ�����Ϣ            \n\n");
		printf("            3.ɾ��������Ϣ            \n\n");
		printf("            4.��ʾ������Ϣ            \n\n");
		printf("            5.���ҷ�����Ϣ            \n\n");
		printf("            6.������һ����            \n\n");
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
		printf("             ������Ϣ                 \n");
		printf("**************************************\n");
		printf("            1.��ӷ�����Ϣ            \n\n");
		printf("            2.�޸ķ�����Ϣ            \n\n");
		printf("            3.ɾ��������Ϣ            \n\n");
		printf("            4.��ʾ������Ϣ            \n\n");
		printf("            5.���ҷ�����Ϣ            \n\n");
		printf("            6.������һ����            \n\n");
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
		printf("����������\n");
		scanf("%s", node->name);
		printf("�����Ա�\n");
		scanf("%s", node->sex);
		printf("����绰\n");
		scanf("%s", node->dianhua);
		insert_fangdong(node);
		printf("�Ƿ����¼�룿y/n\n\n");
		while (getchar() != '\n');
		scanf(" %c", &c);
		if(c == 'N'||c=='n')
		{
			a = 0;
			printf("������ɣ�\n");
			break;
		}
	}
}
void add()//���
{
	int b = 1;
	char c;
	printf("����¼������\n\n");
	while (b)
	{
		fang_node* node = creat_fnode();
		printf("����������¼��ķ��ݱ��룺\n");
		scanf("%d", &node->bianma);
		printf("�����뷿�ݵ�ַ��\n\n");
		scanf("%s", node->dizhi);
		printf("�����뷿�ݵ����ƺţ�\n\n");
		scanf("%d", &node->mengpaihao);
		printf("�����뷿�ݵļ۸�\n\n");
		scanf("%lf", &node->price);
		printf("�����뷿���Ƿ����(��Ϊ1����Ϊ0)\n\n");
		scanf("%d", &node->AN);
		printf("�������ⷿ��������û�еĻ������ޣ�\n\n");
		scanf("%s", node->name);
		while (getchar() != '\n');
		insert_fnode(node);
		printf("�Ƿ����¼�룿y/n\n\n");
		scanf(" %c", &c);
		if (c == 'N' || c == 'n')
		{
			b = 0;
			printf("������ɣ�\n");
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
	printf("�����������޸ĵķ���������\n");
	scanf("%s",name);
	if (headfd->next == NULL)
	{
		printf("û���κ�ס����Ϣ���޷��޸�\n");
		return;
	}
	else
	{

		while (node != NULL)
		{
			if (strcmp(name,node->name)==0)
			{
				k++;
				printf("�޸ĺ��������\n");
				scanf("%s", node->name);
				printf("�Ա�\n");
				scanf("%s", node->sex);
				printf("�绰\n");
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
			printf("û���ҵ���Ҫ�޸ĵķ�����Ϣ\n");
		}
	}

}
void xiugai()//�޸�
{
	int k=0, z;
	char x[20], c[20];
	fang_node* node;
	node = headf->next;
	printf("�����������޸ĵķ��ݱ��룺\n");
	scanf("%d", &z);
	if (headf->next==NULL)
	{
		printf("û���κ�ס����Ϣ���޷��޸�\n");
		return;
	}
	else
	{

		while (node!=NULL)
		{
			if (z == node->bianma)
			{
				printf("����������¼��ķ��ݱ��룺\n");
				scanf("%d", &node->bianma);
				printf("�����뷿�ݵ�ַ��\n\n");
				scanf("%s", x);
				strcpy(node->dizhi, x);
				printf("�����뷿�ݵ����ƺţ�\n\n");
				scanf("%d", &node->mengpaihao);
				printf("�����뷿�ݵļ۸�\n\n");
				scanf("%f", &node->price);
				printf("�����뷿���Ƿ����(��Ϊ1����Ϊ0)\n\n");
				scanf("%d", &node->AN);
				printf("�������ⷿ��������û�еĻ������ޣ�\n\n");
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
			printf("û���ҵ���Ҫ�޸ĵķ�����Ϣ\n");
		}
	}

}
void shanchu_fangdong()
//ɾ��
{
	int k = 0;
	char s[10];
	fangdong_node* node = headfd;
	printf("����������ɾ���ķ���������\n");
	scanf("%s", s);

	while (node->next != NULL)
	{
		if (strcmp(node->name,s)==0)
		{
			fangdong_node* temp = node->next;
			node->next = temp->next;
			free(temp);
			k = -1;
			printf("ɾ���ɹ�\n\n");
			break;
		}
		node = node->next;
	}
	if (k == 0)
	{
		printf("û�и÷����ľ�����Ϣ\n\n");
	}
}
void shanchu()//ɾ��
{
	int k = 0, s;
	fang_node* node = headf;
	printf("����������ɾ���ķ��ݱ��룺\n");
	scanf("%d", &s);

	while (node->next!= NULL)
	{
		if (s == node->next->bianma)
		{
			fang_node* temp = node->next;
			node->next = temp->next;
			free(temp);
			k = -1;
			printf("ɾ���ɹ�\n\n");
			break;
		}
		node = node->next;
	}
	if (k == 0)
	{
		printf("û�и÷��ݵľ�����Ϣ\n\n");
	}
}

void xianshi_fangdong()
//��ʾ
{
	fangdong_node* node = headfd->next;
	printf("����	�Ա�    	�绰 \n");
	printf("------------------------------------------------------------------------------------------\n");
	while (node != NULL)
	{
		printf("%s		%s		%s\n\n",node->name,node->sex,node->dianhua);
		node = node->next;
	}
	return;
}
void xianshi()//��ʾ
{
	fang_node* node = headf->next;
	printf("���ݱ���	���ݵ�ַ    	�������ƺ�   	���ݼ۸�     	 �Ƿ����    	����������\n");
	printf("------------------------------------------------------------------------------------------\n");
	while (node != NULL)
	{
		printf("%d		%s		%d		%lf  		%d		%s\n\n", node->bianma, node->dizhi, node->mengpaihao, node->price, node->AN, node->name);
		node = node->next;
	}
	return;
}
void chazhao_fandong()
//����
{
	char g[10];
	fangdong_node* node = headfd->next;
	printf("����������鿴�ķ���������\n\n");
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
	printf("û�в鵽�����������Ϣ");
}
void chazhao()//����
{
	int g;
	fang_node* node = headf->next;
	printf("����������鿴�ķ��ݱ��룺\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->bianma)
		{
			printf("���ݱ���	���ݵ�ַ    	�������ƺ�   	���ݼ۸�     	 �Ƿ����    	����������\n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%d		%lf  		%d		%s\n\n", node->bianma, node->dizhi, node->mengpaihao, node->price, node->AN, node->name);
			return;
		}
		node = node->next;
	}
	printf("û�в鵽���ݵ������Ϣ");
}
void zuke()
{
	int z;
	int no = 1;
	while (no)
	{
		printf("************************************************\n");
		printf("*                ��������Ϣ                    *\n");
		printf("************************************************\n\n");
		printf(" 1.��ӳ�������Ϣ        2.�޸ĳ�������Ϣ  \n\n");
		printf(" 3.ɾ����������Ϣ        4.��ʾ��������Ϣ  \n\n");
		printf(" 5.���ҳ�������Ϣ        6.����������    \n");
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
void add1()//���
{
	int p = 1;
	char c;
	printf("����¼������\n\n");
	while (p)
	{

		zu_node* node = creat_znode();
		printf("����������¼��ĳ�����ID��\n");
		scanf("%d", &node->id);
		printf("�����������������\n\n");
		scanf("%s", node->name);
		printf("����������ߵļ��᣺\n\n");
		scanf("%s", node->jiguan);
		printf("�������������ס��ʱ�䣺\n\n");
		scanf("%d", &node->shijian);
		printf("�������ⷿ����ķ��ӵķ��ݱ���,û��������0\n\n");
		scanf("%d", &node->fangbian);
		insert_znode(node);
		while (getchar() != '\n');
		printf("�Ƿ����¼�룿\n\n");
		scanf(" %c", &c);
		if(c == 'N'||c=='n')
		{
			p = 0;
			printf("������ɣ�\n");
			break;
		}
	}
}

void xiugai1()//�޸�
{
	int z;
	char x[20], c[20];
	zu_node* node = headz->next;
	printf("�����������޸ĵĳ�����id��\n");
	scanf("%d", &z);
	if (node == NULL)
	{
		printf("û���κ�ס����Ϣ���޷��޸�\n");
		return;
	}
	else
	{
		while (node != NULL)
		{
			if (z == node->id)
			{
				printf("����������¼��ĳ�����ID��\n");
				scanf("%d", &node->id);
				printf("�����������������\n\n");
				scanf("%s", x);
				strcpy(node->name, x);
				printf("����������ߵļ��᣺\n\n");
				scanf("%s", c);
				strcpy(node->jiguan, c);
				printf("�������������ס��ʱ�䣺\n\n");
				scanf("%d", &node->shijian);
				printf("�������ⷿ����ķ��ӵķ��ݱ���,û��������0\n\n");
				scanf("%d", &node->fangbian);

				return;
			}
			node = node->next;
		}
	}
	printf("û���ҵ���Ҫ�޸ĵķ�����Ϣ\n");
}
void shanchu1()//ɾ��
{
	int s;
	zu_node* node = headz;
	printf("����������ɾ���ĳ����ߵ�id��\n");
	scanf("%d", &s);
	while (node->next != NULL)
	{
		if (s == node->next->id)
		{
			zu_node* temp = node->next;

			node->next = temp->next;
			free(temp);

			printf("�Ѿ��ɹ�ɾ��\n\n");
			return;
		}
		node = node->next;
	}
	printf("û�иó����ߵľ�����Ϣ\n\n");
}
void xianshi1()//��ʾ
{
	zu_node* node = headz->next;
	printf("���id		�������    	��ͼ���  	 �����סʱ��    	���ݱ��     \n");
	printf("------------------------------------------------------------------------------------------\n");
	while(node!=NULL)
	{
		printf("%d		%s		%s		%d  		%d		\n\n", node->id, node->name, node->jiguan, node->shijian, node->fangbian);
		node = node->next;
	}
	return;
}

void chazhao1()//����
{
	int g, i;
	zu_node* node = headz->next;

	printf("����������ߵ�id��\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->id)
		{
			printf("���id		�������    	��ͼ���  	 �����סʱ��    	���ݱ��     \n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%s		%d  		%d		\n\n", node->id, node->name, node->jiguan, node->shijian, node->fangbian);
			return;
		}
		node = node->next;
	}
	printf("û�в鵽�����ߵ���Ϣ\n\n");
}//void ruzu()
void guanli()
{
	int r;
	int no = 1;
	while (no)
	{
		printf("************************************************\n");
		printf("*               ��ס����                       *\n");
		printf("************************************************\n");
		printf("  1.���뷿�ݱ�Ų�ѯ         2.����ͻ�ID��ѯ  \n");
		printf("  3.������ҳ��\n");
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
	printf("����������鿴�ķ��ݱ��룺\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->bianma)
		{
			if (node->AN == 1)
			{
				printf("���ݱ��		������\n\n");
				printf("%d		%s\n\n", node->bianma, node->name);
				return;
			}
			else
			{
				printf("û���κγ�����Ϣ\n\n");
			}
			return;
		}
		node = node->next;
	}
	printf("û�в鵽���ݵ������Ϣ\n\n");

}
void cha2()
{
	int g, i;
	zu_node* node = headz->next;

	printf("����������ߵ�id��\n\n");
	scanf("%d", &g);
	while(node!=NULL)
	{
		if (g == node->id)
		{
			if (node->fangbian != 0)
			{
				printf("���ݱ��		������\n\n");
				printf("%d		%s\n\n", node->fangbian, node->name);
				return;
			}
			else
			{
				printf("û���κγ�����Ϣ\n\n");
			}
			return;
		}
		node = node->next;
	}
	printf("û�в鵽�����ߵ���Ϣ\n\n");
}


void shoufei()
{
	zu_node* node = headz->next;
	fang_node* nodef = headf->next;
	int k=0;
	int id;
	char c;
	printf("���������id:");
	scanf("%d", &id);
	printf("������    ����      �Ƿ�ɷ�\n");
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
						printf("\t\t�Ѿ��ɷ�\n");
					}
					else
					{
						printf("û�нɷ�\n");
						printf("�Ƿ�ɷѣ�y/n");
						while (getchar() != '\n');
						c = getchar();
						if (c == 'Y' || c == 'y')
						{
							node->jiaofei = 1;
							printf("�ɷѳɹ�\n");
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
		printf("\n\nû�иĳ����߻��ݱ�ţ�����\n");
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
	printf("1.���۸�ͳ��\n");
	printf("2.��¥��ͳ��\n");
	printf("3.���ض�ͳ��\n");
	while (1)
	{
		scanf("%d", &chose);
		if (chose < 1 || chose>3)
			printf("�������룺");
		else
		{
			break;
		}
	}

	switch (chose)
	{
	case 1:
		printf("����۸�:");
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
		printf("\n��%d��\n", count);
		break;
	case 2:
		printf("����¥��:");
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
		printf("\n��%d��\n", count);
		break;
	case 3:
		printf("�����ַ��");
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
		printf("\n��%d��\n", count);
		break;
	default:
		break;
	}
}