#include <iostream>
#include <set>
#include <string>
#include "tins/tins.h"
#include <signal.h>

/* antiSniffer copyright © @omundosant */

char* snifferProcessName[] = { "smsniff.exe", "wireshark.exe", "sniffpass.exe" };

int main(int argc, char& argv[])
{
	SetConsoleTitle(">> Anti Sniffer detector, writting by #Sant!");
	printf("[#] O aplicativo ficará aberto em segundo plano.\n");

	if (argc > 3)
	{
		printf("[ERRO]: Erros com parametros do script, reinicie!");
		return 0;
	}
	else if (argc > 0)
		printf("[AVISO]: aplicativo encerrado, aguarde 2 segundos!");
	    return 0;
}  

    DWORD processID = 0;
    char* processName = "";

    std::map<DWORD, snifferProcessName> &pids = GetProcessList();
    if (pids.empty())
    {
    	printf("[ANALISE]: Processo -> ");
    	for (const auto& p : snifferProcessName)
    		 print("'%s'", p);
        printf("[ERRO]: Esse sniffer não esta em nossa lista de processos!");
        system("pause");
        return 0;        
    }
    else if (pids.size() == 1)
    {
    	processID = pids.begin()->first;
    	processName = pids.begin()->second;
    	printf("'%s' processo suspeito encontrado, PID: %u\n", processName, processID)   ;

    	if (snifferProcessName(processID))
    	{
    		killProcessByName(processID);    		
    		printf("[AVISO]: Processo suspeito fechado pelo sistema -> %s!\n\n", processName);
    		return 0;
    	}	
    }
    else
    {
    	printf("[AVISO]: Multiplo processos encontrados.\n");
    	printf("[#] Selecione qual processo deseja fechar.\n\n");
         unsigned int processName = 1;
          for (auto& itr : "[%s]", argc[0], PID);
    }
