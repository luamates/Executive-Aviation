/*
Projeto da disciplina de Linguagem de Programação, do curso de Análise e Desenvolvimento de Sistemas da Fatec-Itu.

By: Lucas Amates de Oliveira

Todo o código possui comentários para melhor compreensão.

O projeto é da empresa de aviação:
 __                                                                
|  \                                                               
| $$       ______    ______   ______   _______        __   ______  
| $$      |      \  /      \ |      \ |       \      |  \ |      \ 
| $$       \$$$$$$\|  $$$$$$\ \$$$$$$\| $$$$$$$\      \$$  \$$$$$$\
| $$      /      $$| $$   \$$/      $$| $$  | $$     |  \ /      $$
| $$_____|  $$$$$$$| $$     |  $$$$$$$| $$  | $$     | $$|  $$$$$$$
| $$     \\$$    $$| $$      \$$    $$| $$  | $$     | $$ \$$    $$
 \$$$$$$$$ \$$$$$$$ \$$       \$$$$$$$ \$$   \$$__   | $$  \$$$$$$$
                                               |  \__/ $$          
                                                \$$    $$          
                                                 \$$$$$$           

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Declarando variáveis globais.
char ch[4][20]={"Embraer Legacy","Embraer Millennium","Cessna Skycourier","Citation Latitude"}; //Os aviões disponíveis
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;

//Declarando as funções a serem usadas na MAIN.
void avioes(); //Serve para listar os aviões disponíveis
void name_number(int booking,char numstr[100]);
void booking(); //Serve para comprar uma ou mais passagens
int read_number(int trno);//Para ler os numeros dos arquivos
void read_name(int trno);//Para ler os nomes nos arquivos
void status_1(int trno);//Serve para ter o status quando compra.

int main()
{
	setlocale(LC_ALL, "Portuguese");
	login();
    int num,i;
    
    do{
	    system("cls");
	    printf("\t\tLARANJA - AVIAÇÃO EXECUTIVA");
	    printf("\n\t\t        Menu principal \n");
	    printf("\t\t[1] Consultar os aviões disponíveis.\n\n");
	    printf("\t\t[2] Comprar uma passagem.\n\n");
	    printf("\t\t[5] Salvar e sair.\n\n"); //sai do programa
	    printf("\t\tSELECIONE UMA OPÇÃO: ");
	    scanf("%d",&num); //numero da opção
	    
	    switch(num) //Opções do menu
	    {
		    case 1:
		        avioes();//LISTAR OS AVIÕES
		        break;
		    case 2:
		        booking();//FAZER O BOOK DE ASSENTO
		        break;
	    }
		getch();
		
    } while(num != 5); //se num = 5, sai do programa.
    system("cls");
    system("pause");
    return 0;
}


void avioes() //Lista as aeronaves de acordo com a variável ch[4] [20] global.
{
    system("cls");
    printf("\t    AERONAVES DISPONIVEIS \n");
    printf("   [1]  =>  %s\n\n",ch[0]); //aviao 1 = ch[0] etc...
    printf("   [2]  =>  %s\n\n",ch[1]);
	printf("   [3]  =>  %s\n\n",ch[2]);
	printf("   [4]  =>  %s\n\n",ch[3]);
}

void booking() //Aqui é realizada a compra dos assentos (book)
{
	int i=0;
	char numstr[100];
	system("cls");
	printf("\n\n   __________________________________\n");
	printf("\t    COMPRAR UMA PASSAGEM");
	printf("\n   ___________________________________\n\n");
	
	avioes(); //Chama a função de lista de aeronaves (dos nomes e numeros)
	
	printf("   SELECIONE UMA AERONAVE: "); //Seleciona qual aeronave o cliente tem interesse em comprar uma passagem
	scanf("%d",&trno); //troca numero da aeronave escolhida
	system("cls");
	printf("\n\n   __________________________________\n");
	printf("\t    COMPRAR UMA PASSAGEM");
	printf("\n   ___________________________________\n\n");
	printf("O número da sua aeronave é %d ********** %s",trno,ch[trno-1]);
	status_1(trno); //apresenta o status
	FILE *f1, *fopen();//Serve para ler os assentos do usuário.
	char str1[80] = "32", str2[4], str3[4]; //questão dos assentos
	int seat1, seat2, booking = 0; //
	 
	 //if das aeronaves
	 
	if(trno == 1) //se 
	{
		 f1 = fopen("tr1.txt","r+"); //troca aeronave = 1, ou seja, o legacy etc...
		 fgets(str1,80,f1);
		 fclose(f1);
	} 
	else if(trno == 2)
	{
		 f1 = fopen("tr2.txt","r+");
		 fgets(str1,80,f1);
		 fclose(f1);
	} 
	else if(trno == 3)
	{
		 f1 = fopen("tr3.txt","r+");
		 fgets(str1,80,f1);
		 fclose(f1);
	}
	else if(trno == 4)
	{
	 f1 = fopen("tr4.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);
	}
	
	seat1 = atoi(str1); //transforma a string em números para contabilizar a quantidade de assentos
	
	if(seat1 <= 0) //caso não tenha seat é exibida a msg
	{
	 	printf("Não há assentos disponíveis nessa aeronave. "); 
	}
	else
	{
		printf("\n   ___________________________________________\n");
		printf("\n   ASSENTOS DISPONÍVEIS: %d\n",seat1); //mostra o numero de assentos disp. para booking do cliente
		printf("\n   NÚMERO DE PASSAGENS A COMPRAR: [Para voltar digite 0] "); //para 
		scanf("%d",&booking);
		printf("\n");
		
		seat1=seat1-booking;
		itoa(trno,numstr,10);
		name_number(booking,numstr);
		printf("   O valor total estimado da compra é US$ %d. Aproveite a promoção!",300 * booking); //Calcula o valor total da compra, considerando o valor de 300 dólares por assento.
		itoa(seat1, str1, 10);
		
		//Isso lê os assentos do usuário
		
		if(trno == 1)
		{
			 f1 = fopen("tr1.txt","w");
			 fputs(str1,f1);
			 fclose(f1);
		}
		else if(trno == 2)
		{
			 f1 = fopen("tr2.txt","w");
			 fputs(str1,f1);
			 fclose(f1);
		}
		else if(trno == 3)
		{
			 f1 = fopen("tr3.txt","w");
			 fputs(str1,f1);
			 fclose(f1);
		}
		else if(trno == 4)
		{
			 f1 = fopen("tr4.txt","w");
			 fputs(str1,f1);
			 fclose(f1);
		}
		else if(trno == 5)
		{
			 f1 = fopen("tr5.txt","w");
			 fputs(str1,f1);
			 fclose(f1);
		}
	}
}

void name_number(int booking,char numstr[100])
{
	char tempstr[100],tempstr1[32]="status",tempstr2[12]="number";
	int number;
	FILE *a,*b;
	int i=0;
	strcat(numstr,".txt");
	strcat(tempstr1,numstr);
	strcat(tempstr2,numstr);
	a = fopen(tempstr1,"a"); //abrir o arquivo e inserir o nome
	b = fopen(tempstr2,"a"); //abrir o arquivo e inserir o no
	
	for(i=0; i<booking; i++) //inserir o cliente e o assento no txt
	{
	      printf("   ___________________________ Agora, adicione os detalhes para a passagem numero %d ____________________________\n\n",i+1);
	      printf("   INSIRA O NÚMERO DO ASSENTO: ");
	      scanf("%d",&number);
	      printf("\n   INSIRA O NOME DO PASSAGEIRO: (Sem espaços) ");
	      scanf("%s",name[number-1]);
	      printf("\n\n   ___________________________________________________________\n");
	      printf("\n");
	      itoa(number, tempstr, 10);
	      fprintf(a,"%s ",name[number-1]);
	      fprintf(b,"%s ",tempstr);
	
	}
	fclose(a);
	fclose(b);
}

int read_number(int trno)//inserir os numeros
{
	char tempstr[100],tempstr2[32]="number";
	FILE *a,*b;
	char numstr[100];
	int i=0,j=0,k;
	itoa(trno,numstr,10);
	strcat(numstr,".txt");
	strcat(tempstr2,numstr);
	a = fopen(tempstr2,"a+");//inserir os nomes
	
	   while(!feof(a))
	   {
	      number[i][j] = fgetc(a);
	
	      if(number[i][j] == ' ')
	      {
	          j=0;
	          i++;
	      }
	      else
	      {
	      	j++;
	      }
	   }
	   k=i;
	   for(i=0; i<k; i++)
	   {
	       num1[i] = atoi(number[i]);
	   }
	   fclose(a);
	   return k;
}


void read_name(int trno)
{
	char tempstr1[32]="status";
	FILE *b;
	char numstr[100];
	int i=0,j=0,k=0;
	itoa(trno,numstr,10);
	strcat(numstr,".txt");
	strcat(tempstr1,numstr);
	b = fopen(tempstr1,"a+"); //escrever o nome
	
	   while(!feof(b))
	   {
	      name[i][j] = fgetc(b);
	
	      if(name[i][j] == ' ')
	      {
	          j=0;
	          i++;
	      }
	      else
	      {
	    	  j++;
	      }
	   }
	   name[i][j]='\0';
	   k=i;
	   fclose(b);
}

void status()
{
	system("cls");
    printf("\n\n   ______________________________________________\n");
    printf("\t\t      COMPRAR ASSENTO");
    printf("\n   ____________________________________________________________\n\n");
    
    int i,trno,index=0,j;
    
    printf("   INSIRA O NÚMERO DA AERONAVE: ");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    
    printf("\n   ____________________________________________________________\n");
    printf("\t\t   Aeronave No.%d: %s\n",trno,ch[trno-1]);
    printf("   _____________________________________________________________\n\n");
    
    //Nome temporário para cada assento do avião. No começo todos estão vazios, mas a medida que usa o programa eles se alteram pelo nome do cliente.
	char tempname[33][10]={"Vazio", "Vazio ","Vazio ","Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ",};
	
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
        {
        	printf("%d.%s\t",index+1,tempname[index+1]);
        	index++;
        }
        printf("\n");
    }
}

void status_1(int trno) //Esse é o status
{
    printf("O NÚMERO DA AERONAVE É %d ********** %s",trno,ch[trno-1]);
    system("cls");
    printf("\n\n   ___________________________________________________\n");
    printf("\t\t      RESERVA DE ASSENTO");
    printf("\n   ___________________________________________________\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
	char tempname[33][10]={"Vazio", "Vazio ","Vazio ","Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ", "Vazio ",};
	for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
        {
        	printf("%d.%s\t",index+1,tempname[index+1]);
        	index++;
        }
        printf("\n");
	}
}

//Login para entrar no programa

void login()
{
	int i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    
    do
	{
		system("cls");
	    printf("\n\n    _______________________________________\n");
	    printf("\t   SISTEMA LARANJA AIRLINES");
	    printf("\n    _______________________________________\n\n");
	    printf("    __________FORMULÁRIO DE LOGIN__________");
	    printf("\n\n   USUÁRIO: ");
		scanf("%s", &uname);
		printf(" \n   SENHA: ");
	
		while(i<10)
		{
		    pword[i]=getch(); //a senha é inserida uma por uma e exibida
		    c=pword[i];
		    if(c==13) break; //se o usuario digitar ENTER, é o fim da senha
		    else printf("*"); //diferente de ENTER, um * é exibido
		    i++;
		}
	
		pword[i]='\0';
		i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0) //testando a senha
		{
		    printf("\n    _________________________________________");
			printf("  \n\n   BEM VINDO!! \n\n   Carregando...");
			sleep(1);
			break;
		}
		else
		{
		    printf("\n    ______________________________________________");
			printf("\n\n   USUÁRIO OU SENHA INCORRETOS. TENTE NOVAMENTE!");
			getch();
		}
		
	} while(1);
	system("cls");
}

