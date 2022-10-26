#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; 
};

#define EnderecoLength sizeof(Endereco)

int divideAndConquer(Endereco e, char* cep, int *start, int mid, int *end);

int main(int argc, char**argv)
{
	FILE *f;
	Endereco e;
	int c = 0;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
	//nome_do_arquivo_com_ceps_ordenados
	f = fopen("cep_ordenado.dat","rb");
	
	fseek(f, 0, SEEK_END);
	int end = ftell(f) / EnderecoLength;
	int start = 0;

	while (start <= end){
		c++;
		int mid = ((start + end) / 2);
		
		fseek(f, mid * EnderecoLength, SEEK_SET);
		fread(&e, EnderecoLength, 1, f);
		
		if(divideAndConquer(e, argv[1], &start, mid, &end) == 0) break;
	}

	printf("Total Lido: %d\n", c);

	fclose(f);
	return 0;
}

int divideAndConquer(Endereco e, char* cep, int *start, int mid, int *end){
	if (strncmp(cep, e.cep, 8) == 0){
            printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			return 0;
		} else if (strncmp(cep, e.cep, 8) > 0){
			*start = mid + 1;
			return 1;
		} else {
			*end = mid - 1;
			return 1;
		}
}
