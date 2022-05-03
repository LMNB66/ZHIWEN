#ifndef _SHOW_H_
#define _SHOW_H_

#include "sys.h"

typedef struct{
	
	u8 current;	//ҳ������
	u8 up;		//��һҳ
	u8 down;	//��һҳ
	u8 enter;	//ȷ��
	void (*current_operation)();//����ҳ�溯��ָ��
	
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
