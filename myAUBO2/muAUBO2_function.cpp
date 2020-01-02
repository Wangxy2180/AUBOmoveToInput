#include"myAUBO2_function.h"
#include "rsdef.h"
#define M_PI 3.14159265235

#define ROBOT_ADDR "192.168.74.129"
#define ROBOT_PORT 8899

bool my_login(RSHD &rshd, const char *addr, int port)
{
	bool result = false;

	rshd = RS_FAILED;

	//��ʼ���ӿڿ�
	if (rs_initialize() == RS_SUCC)
	{
		//����������
		if (rs_create_context(&rshd) == RS_SUCC)
		{
			//��½��е�۷�����
			if (rs_login(rshd, addr, port) == RS_SUCC)
			{
				result = true;
				//��½�ɹ�
				std::cout << "login succ" << std::endl;
			}
			else
			{
				//��½ʧ��
				std::cerr << "login failed" << std::endl;
			}
		}
		else
		{
			//����������ʧ��
			std::cerr << "rs_create_context error" << std::endl;
		}
	}
	else
	{
		//��ʼ���ӿڿ�ʧ��
		std::cerr << "rs_initialize error" << std::endl;
	}

	return result;

}