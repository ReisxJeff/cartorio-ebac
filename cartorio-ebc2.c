#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> // biblioteca de alocação em memoria
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema  
{
	//inicio da criação de variáveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis / string
	printf("\tDigite o CPF a ser cadastrado:\n"); //coletando infomação do usuário
	scanf("%s", cpf); // %s refere-se as string
	
	strcpy(arquivo, cpf); //responsavl por copiar os valores dos string
	
	FILE *file; //criar aquivo
	file = fopen(arquivo, "w"); //criar o arquivo *w* significa escrever 
	fprintf(file, "\nCPF: ");// para indentificar a informação
	fprintf(file, cpf); //salvar o valor da variavel 
	fclose (file); //fechar o arquivo 
	
	file = fopen(arquivo, "a"); //atualização do arquivo *a* significa atualizar 
	fprintf(file, ",\nNOME: ");//separar e identificar a informção 
	fclose(file); //fechar o arquivo 
	
	printf("\t Digite o nome a ser cadastrado:\n");//coletando infomação do usuário
	scanf("%s", nome);// %s refere-se as string
	
	file = fopen(arquivo, "a");//atualização do arquivo *a* significa atualizar 
	fprintf(file, nome);//salvar o valor da variavel
	fclose(file); //fechar o arquivo 
	
	file = fopen(arquivo, "a");//atualização do arquivo *a* significa atualizar 
	fprintf(file, ",\nSOBRENOME: ");//separar e identificar a informção 
	fclose(file); //fechar o arquivo 
		
	printf("\t Digite o sobrenome a ser cdastrado:\n");//coletando infomação do usuário
	scanf("%s", sobrenome);// %s refere-se as string
	
	file = fopen(arquivo, "a");//atualização do arquivo *a* significa atualizar 
	fprintf(file, sobrenome);//salvar o valor da variavel
	fclose(file); //fechar o arquivo 
	
	file = fopen(arquivo, "a");//atualização do arquivo *a* significa atualizar 
	fprintf(file, ",\nCARGO: ");//separar e identificar a informção 
	fclose(file); //fechar o arquivo 
	
	printf("\t Digite o cargo a ser cadastrado:\n");//coletando infomação do usuário
	scanf("%s", cargo);// %s refere-se as string
	
	file = fopen(arquivo, "a");//atualização do arquivo *a* significa atualizar 
	fprintf(file, cargo);//salvar o valor da variavel
	fprintf(file, ".\n\n");//fechar a indentificação de informações e pular linha para deixar mais estético 
	fclose(file); //fechar o arquivo 
	
	system("pause");// pausar as informções para o usuário 
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	//inicio da criação de variáveis / string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis / string
	printf("\t Digite o CPF a ser consultado: \n");//comando para o usuário 
	scanf("%s", cpf);// %s refere-se as string
	
	FILE *file;//criar arquivo
	file = fopen(cpf,"r");//ler o arquivo *r* significar ler 
	
	
	if(file == NULL)//
	{
		printf("\tNão foi possivel abrir o arquivo,não localizado!.\n");
	}

    if(file != NULL)
    {
    	printf("\t Essas são as informações do usuário!\n");	
    while(fgets(conteudo , 200,file ) !=NULL)
        {
		    printf("%s", conteudo);
     	}
   	
   	}
	
    fclose(file);
    system("pause");
    	
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: \n");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}

	remove(cpf);

    if(file != NULL)
    {
    	printf("Usuário deletado com sucesso!.\n");
    	system("pause");
	}
   
}

int main()
{
    
    int opcao=0; //definindo variável 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls"); //responsavel por limpar a tela 
		setlocale(LC_ALL, "portuguese"); //definindo linguagem 
    
	    printf("\tCartório da EBAC\n\n"); // início do menu 
        printf("escolha a opção desejada no menu:\n\n ");
        printf("\t1 - Resgistrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - deletar nomes\n");
        printf("\t4 - sair do sistema\n\n");
	    printf( "Opção: ");// fim do menu 
    
        scanf("%d", &opcao);// armazenando a escolha do usuario 
    
        system("cls");//responsavel por limpar a tela 
        
        switch(opcao) // inicio de seleção do menu 
		{
			case 1:
				registro(); // chamada de funções
				break;
			case 2:
			    consulta ();
				break;
			case 3:
			    deletar();
			    break;
			case 4:
				printf("obrigado por utilizar o sistema");
				return 0;
				break;
			default:
				printf("\tEssa opção não está disponivel !\n");
				system ("pause");
				break;
		} //fim da seleção
    }
}