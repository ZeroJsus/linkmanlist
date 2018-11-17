// 引入标准库
#include <stdio.h>                 // 输入和输出库
#include <stdlib.h>                // 通用工具库
#include <string.h>                // 操作字符数组的函数
#include <malloc.h>                // 得到指向大小为Size的内存区域的首字节的指针
#define LEN sizeof(struct linkman) // 计算链表的字节数
int len;                           // 记录当前已经记录的人数

// 构造一个名为联系人的链表
typedef struct linkman
{
  char username[30];    // 用户名称
  char address[30];     // 工作单位
  char phone[30];       // 联系电话
  char email[30];       // 电子邮件地址
  struct linkman *next; // 指针 指向下一个联系人
} linkman;

// 初始化一个链表 / 创建链表信息
linkman *create(linkman *linkmanlist){
  linkman *var1, *var2; // 初始化一个当前链表的指针
  char name[20]; // 限制姓名20个字符串长度
  len = 0;
  var1 = (linkman *)malloc(LEN); 
  var2 = var1;
  printf("请录入当前需要录入的人员信息！\n姓名输入0时代表结束创建\n");
  printf("请输入联系人姓名：");
  gets(name);
  if (strcmp(name,"0")!=0) { 
    strcpy(var1->username,name); 
    printf("请输入联系人工作单位:"); gets(var1->address); 
    printf("请输入联系人联系电话:"); gets(var1->phone); 
    printf("请输入联系人电子邮箱:"); gets(var1->email); 
    linkmanlist=NULL; 
    while(1) { 
      len=len+1;  //记录通讯录人数个数 
      if(len==1) 
        linkmanlist=var1; 
      else
        var2->next=var1; 
      var2=var1; 
      printf("请输入姓名:"); 
      gets(name); 
      if (strcmp(name,"0")==0) { 
        break; 
      } else { 
        var1=(linkman *)malloc(LEN); 
        strcpy(var1->username,name); 
        printf("请输入联系人工作单位:"); gets(var1->address); 
        printf("请输入联系人联系电话:"); gets(var1->phone); 
        printf("请输入联系人电子邮箱:"); gets(var1->email); 
      } 
    } 
    var2->next=NULL; 
    return linkmanlist;
  }
  else
    return linkmanlist;
};

// 插入函数
linkman *insert(linkman *linkmanlist) { 
  linkman *newnode = NULL;	

	if (!(newnode = (linkman *)malloc(sizeof(linkman)))) {
  	printf("malloc 错误");	
	}

	printf("请输入联系人姓名：");
	scanf("%s", newnode->username);
	printf("请输入联系人工作单位：");
	scanf("%s", &newnode->address);
	printf("请输入联系人电话号码：");
	scanf("%s", &newnode->phone);
	printf("请输入联系人邮箱地址：");
	scanf("%s", &newnode->email);
	printf("新增成功：");

  newnode->next = linkmanlist->next;
	linkmanlist->next = newnode;

  return linkmanlist;
}

// 删除
linkman *deleteItem(linkman *linkmanlist) {
  linkman *v1,*v2; 
  char phone[30]; 
  if (linkmanlist == NULL) { 
    printf("通讯录为空,无法显示!\n"); 
    return linkmanlist; 
  } 
  v1 = linkmanlist; 
  printf("请输入需要删除的人的电话号码:"); 
  gets(phone);
  if (strcmp(linkmanlist -> phone,phone)==0) { 
    linkmanlist = linkmanlist -> next; 
    free(v1); 
    printf("删除操作成功！\n"); 
    return linkmanlist; 
  } else {
    v2 = linkmanlist, v1 =linkmanlist->next; 
    while(v1!=NULL) { 
      if(strcmp(v1->username,phone)==0) {
        v2->next = v1->next; 
        free(v1); 
        printf("删除操作成功！\n"); 
        return linkmanlist; 
      } 
      v1 = v1->next; 
      v2 = v2->next; 
    } 
  }
}

// 记录进行修改
linkman *changeItem(linkman *linkmanlist){
  linkman *change = NULL;
  char phone[30];
  if (linkmanlist == NULL) { 
    printf("通讯录为空,无法显示!\n"); 
    return linkmanlist; 
  }
  printf("请输入需要修改的联系人电话号码:"); 
  gets(phone);

  change = linkmanlist;
  
  while (change != NULL) {
		if (0 == (strcmp(phone, change->phone))) {
			printf("请重新输入姓名:");
			scanf("%s", change->username);
			printf("请重新输入电话号码:");
			scanf("%s", change->phone);
			printf("修改成功!\n");
      return linkmanlist;
		} 
    printf("未找到电话号码为:%s的联系人\n", phone);
    return linkmanlist;
	}
  return linkmanlist;
}

// 展示 
linkman *showlist(linkman *linkmanlist){
  linkman *show = linkmanlist;
  if (show!=NULL) {
    printf("本通讯系统现在记录共有%d人:\n",len); 
    printf("====姓名======工作单位======手机====Email\n"); 
    printf("*************************************\n"); 
    do { 
      printf("%s",show->username); printf("    "); 
      printf("%s",show->address); printf("    "); 
      printf("%s",show->phone); printf("    "); 
      printf("%s",show->email); printf("    \n"); 
      show=show->next;
    } while (show!=NULL); 
    printf("*************************************\n"); 
  } 
  else
    printf("通讯记录为空!\n"); 
}

// 姓名查询函数 
linkman *search(linkman *linkmanlist) { 
  linkman *var1,*var2; 
  int m; 
  char choise[2], name[30], phone[13]; 
  if (linkmanlist==NULL) {
    printf("通讯录为空,无法分类查找!\n"); 
    return(linkmanlist); 
  }
  var1 = linkmanlist; 
  while(var1!=NULL) { 
    printf("********************************\n"); 
    printf("** 输入1按姓名查找，2按电话查找 **\n"); 
    printf("********************************\n");
    m=0;
    gets(choise);
    if (strcmp(choise,"1")==0){
      printf("请输入联系人姓名!\n");
      gets(name);
      while(strcmp(var1->username,name)!=0&&var1->next!=NULL) 
      { 
        var2=var1; 
        var1=var1->next; 
      } 
      if(strcmp(var1->username,name)==0) 
      { 
        m++; 
        printf("你查找的联系人是:\n"); 
        printf("+++++++++++++++++++++++++++++++++++\n"); 
        printf("++ %s    %s    %s    %s\n",var1->username,var1->address,var1->phone,var1->email); 
        printf("+++++++++++++++++++++++++++++++++++\n"); 
      } 
      var1=var1->next; 
    
      if(m==0) 
      { 
        printf("此人未录入到系统中!\n"); 
      } 
    }
    if(strcmp(choise,"2")==0){
      printf("请输入联系人联系电话!\n");
      gets(phone);
      while(strcmp(var1->phone,phone)!=0&&var1->next!=NULL) 
      { 
        var2=var1; 
        var1=var1->next; 
      } 
      if(strcmp(var1->phone,phone)==0) 
      { 
        m++; 
        printf("你查找联系人是:\n"); 
        printf("+++++++++++++++++++++++++++++++++++\n"); 
        printf("++ %s    %s    %s    %s\n",var1->username,var1->address,var1->phone,var1->email); 
        printf("+++++++++++++++++++++++++++++++++++\n"); 
      } 
      var1=var1->next;
      if(m==0) 
      { 
        printf("此人未录入到系统中!\n"); 
      }
    } 
    break; 
  }
  
  return(linkmanlist); 
}



void main() {
  struct linkman *linkmanlist = NULL; // 初始化链表指针为空
  char num[10]; // 定义输入数字
  printf("/******************************/\n");
  printf("/    通讯录管理系统(by 杨荣鑫)   /\n");
  printf("/******************************/\n");
  while (1) {
    printf("/******************************/\n");
    printf("/***      1、打开通讯录     ****/\n");
    printf("/***      2、新增联系人     ****/\n");
    printf("/***      3、删除联系人     ****/\n");
    printf("/***      4、修改联系人     ****/\n");
    printf("/***      5、查找联系人     ****/\n");
    printf("/***      6、退出此系统     ****/\n");
    printf("/******************************/\n");
    printf("/***  请输入您要进行的操作：  ***/\n");
    gets(num);
    switch (*num) {
      case '1': {
        showlist(linkmanlist);
      } break;
      case '2': {
        if (linkmanlist == NULL) {
          linkmanlist = create(linkmanlist); //创建
          showlist(linkmanlist);
        } else {
          linkmanlist = insert(linkmanlist); //插入
          showlist(linkmanlist);
        }
      } break;
      case '3': {
        linkmanlist = deleteItem(linkmanlist); //删除
        showlist(linkmanlist);
      } break;
      case '4': {
        linkmanlist = changeItem(linkmanlist); //修改
        showlist(linkmanlist);
      } break;
      case '5':
        search(linkmanlist);
        break;
      case '6':
        printf("退出当前系统!\n"); // 退出
        break;
      default:
        printf("操作错误，此项不存在!\n");
        break;
    }
    if (strcmp(num,"6")==0) {
      break;
    } 
  }
}
