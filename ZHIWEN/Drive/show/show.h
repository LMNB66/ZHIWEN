#ifndef _SHOW_H_
#define _SHOW_H_

#include "sys.h"

typedef struct{
	
	u8 current;	//页面索引
	u8 up;		//上一页
	u8 down;	//下一页
	u8 enter;	//确定
	void (*current_operation)();//索引页面函数指针
	
}menue_;

extern u8 func_index;

void menue_key(void);
void menue_0(void);
void menue_1(void);
void menue_2(void);
void menue_3(void);
void menue_4(void);
void menue_5(void);
void menue_6(void);
void menue_7(void);
void menue_8(void);
void menue_9(void);

#endif
