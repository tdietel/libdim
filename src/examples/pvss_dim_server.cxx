#include <dis.hxx>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct{
	int bitset;
	char boolval;
	int intval;
	float floatval;
	char stringval[128];
}COMPLEXDATA;

typedef struct{
	float farr[10];
	int intval;
	int iarr[3];
	char str[20];
	int intval1;
}COMPLEXDATA1;

class RecvCommand : public DimCommand
{
	int reset_flag;
	void commandHandler()
	{
		cout << "Size: " << getSize() << endl;
		cout << "Command " << getString() << " received" << endl;
		reset_flag = 1;
	}
public :
	RecvCommand(char *name) : DimCommand(name,"C") {reset_flag = 0;};
	int isReset() {return reset_flag;};
	void clearReset() {reset_flag = 0;};
};

class RecvCommandComplex : public DimCommand
{
	void commandHandler()
	{
		COMPLEXDATA *complexData;

		complexData = (COMPLEXDATA *)getData();
		cout << "Command " << complexData->intval 
			 << " received " << complexData->stringval << endl;
	}
public :
	RecvCommandComplex(char *name) : DimCommand(name,"I:1;C:1;I:1;F:1;C") {};
};

class RpcService : public DimRpc
{
	int val;

	void rpcHandler()
	{
		val = getInt();
		val++;
		setData(val);
	}
public:
	RpcService(char *name): DimRpc(name,"I","I") {val = 0;};
};

int main()
{
	COMPLEXDATA complexData;
	COMPLEXDATA1 cData;
	float simpleData;

	int index = 0;
	complexData.bitset = 0x1;
	complexData.boolval = 1;
	complexData.intval = index;
	complexData.floatval = (float)3.4;
	strcpy(complexData.stringval,"IDLE");

	cData.farr[0] = 1.2; 
	cData.farr[1] = 2.2; 
	cData.farr[2] = 3.2;
	cData.farr[3] = 0;
	cData.farr[4] = 0;
	cData.farr[5] = 0;
	cData.farr[6] = 0;
	cData.farr[7] = 0;
	cData.farr[8] = 0;
	cData.farr[9] = 0;
	cData.intval = 123;
	cData.iarr[0] = 12; 
	cData.iarr[1] = 13; 
	cData.iarr[2] = 14;
	cData.intval1 = 456;
	strcpy(cData.str,"hello");

	DimService cTestService("COMPLEX_SERVICE_TEST","F:10;I:1;I:3;C:20;I:1",
		(void *)&cData, sizeof(cData));

	DimService complexService("COMPLEX_SERVICE","I:1;C:1;I:1;F:1;C",
		(void *)&complexData, sizeof(complexData));

	simpleData = (float)1.23;

	DimService simpleService("SIMPLE_SERVICE", simpleData);
	simpleService.setQuality(1);

	RecvCommand recvCommand("SIMPLE_COMMAND");
	RecvCommandComplex recvCommandComplex("COMPLEX_COMMAND");

	RpcService rpc("RPC");

	DimServer::start("PVSS_DIM_TEST");

	while(1)
	{
		sleep(5);
		
		if( recvCommand.isReset() )
		{
			
			index = 0;
			complexData.bitset = 0x1;
			complexData.boolval = 1;
			complexData.intval = index;
			complexData.floatval = (float)3.4;
			strcpy(complexData.stringval,"IDLE");
			simpleData = (float)1.23;
			recvCommand.clearReset();
		}
		else
		{
			index++;
			complexData.bitset <<= 1;
			complexData.boolval = index;
			complexData.intval = index;
			complexData.floatval = index * (float)1.1;
			sprintf(complexData.stringval,"State %d", index);
			simpleData += (float)1.1;
		}
		
		complexService.updateService();

		simpleService.setQuality(complexData.bitset);
		simpleService.updateService();

		if(strlen(cData.str) < 16)
			strcat(cData.str," abc");
		cTestService.updateService();
	}
	return 0;
}
