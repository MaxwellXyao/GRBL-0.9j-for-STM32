#ifndef __SIMUI2C_H
#define __SIMUI2C_H

/**********************************************************************************
	Copyright (C) 2016 SOL.lab <maxwellxyao@foxmail.com>

*File name:		simui2c.h
*Description:	模拟I2C协议
*Author:		MaxwellXyao
*Version:		V0.0.20160626
*Date:			2016-6-26 21:26:33
*History:		
[2016-6-26]	文件创建;

**********************************************************************************/

//###########################【定义】###########################
typedef struct _SimuI2C{				//I2C硬件管理块
	void (*PinSetSCL)(unsigned char);		//SCL引脚输出函数
	void (*PinSetSDA)(unsigned char);		//SDA引脚输出函数
	unsigned char (*PinGetSDA)();			//SDA引脚读取函数
	void (*Delayus)(unsigned int);		//us延时函数
}SimuI2C;								

//###########################【API】###########################
void SimuI2C_Start(SimuI2C *SimuI2C_Struct);			 	//产生IIC起始信号
void SimuI2C_Stop(SimuI2C *SimuI2C_Struct);			   		//产生IIC停止信号
unsigned char SimuI2C_WaitAck(SimuI2C *SimuI2C_Struct);		//等待应答信号到来
void SimuI2C_Ack(SimuI2C *SimuI2C_Struct);					//产生ACK应答
void SimuI2C_NAck(SimuI2C *SimuI2C_Struct);					//不产生ACK应答
void SimuI2C_WriteByte(SimuI2C *SimuI2C_Struct,unsigned char data);			//IIC发送一个字节
unsigned char SimuI2C_ReadByte(SimuI2C *SimuI2C_Struct,unsigned char ack);	//IIC读一个字节

#endif
