#include <stdio.h>

struct cursos
{ int codigo;
char descricao[20];
int vagas;
int concorrenciaAnt;
};

struct candidatos
{ int num;
int codCurso;
char sexo;
};
#define QTDCURSO 2
#define QTDCAND 2
int main(){
  struct cursos curso[QTDCURSO]; // = { {1 , "matematica", 10, 5}, {2, "fisica", 10, 5}};
  for(int i = 0; i < QTDCURSO; i++){
    printf("Cod curso:\n");
    scanf("%d", &curso[i].codigo);
   // printf("curso[i].codigo = %d\n",curso[i].codigo);
    printf("Nome Curso:\n");
    scanf("%s", &curso[i].descricao);
   // printf("DESC = %s\n", curso[i].descricao);
    printf("Num Vagas:\n");
    scanf("%d", &curso[i].vagas);
   // printf("VAG = %d\n", curso[i].vagas);
    printf("Con Ant:\n");
    scanf("%d", &curso[i].concorrenciaAnt);
  //  printf("CON = %d\n",curso[i].concorrenciaAnt);
  }

  struct candidatos candidato[QTDCAND];
  float contF = 0;
for(int i = 0; i < QTDCAND; i++){
  candidato[i].num = i;
  printf("Num Cand = %d\n",candidato[i].num);
  for(int j = 0; j < QTDCURSO ; j++){
    printf(" curso %s = codigo %d:\n",curso[j].descricao,curso[j].codigo);
  }
  printf("escolha o codigo do curso pretendido\n");
   scanf("%d",&candidato[i].codCurso);
  printf("Sexo 'M' ou 'F' ?\n");
    scanf(" %c", &candidato[i].sexo);
    if(candidato[i].sexo == 'F')
      contF++;
    printf("sexo = %c cod = %d\n",candidato[i].sexo, candidato[i].codCurso);
}
  int cpv = 0, ultrapassou = 0;
  float mediaV = 0;
  int qtdH[QTDCURSO] = {0};
for(int i =0; i < QTDCURSO; i++){
  cpv = 0;
  mediaV = 0;
  for(int j = 0; j < QTDCAND; j++ ){
    if(candidato[j].codCurso == curso[i].codigo){
      cpv++;
      if(candidato[j].sexo == 'M')
        qtdH[i] += 1;
    }
  }
  mediaV = (float) (cpv /(float) curso[i].vagas);
  if(mediaV > curso[i].concorrenciaAnt)
    ultrapassou++;
  printf("Cadidato por vaga no curso %s = %.1f.\n", curso[i].descricao, mediaV);
}
contF = (contF * 100) / (float) QTDCAND;
  printf("Um total de %d curso(s) passou/ram conc. ano ant. Temos  %%%1.f Mulheres inscritas\n",ultrapassou,contF );
  int cursoH;
  for(int i =0; i < QTDCURSO; i++){
    if(i+1 == QTDCURSO)
      break;
    if(qtdH[i] > qtdH[i+1]){
      cursoH = curso[i].codigo;
    }else{
      cursoH = curso[i+1].codigo;
    }
  }
  printf("O cod do curso que + tem cand homens e = %d", cursoH);
  return 0;
}
/* Ler e armazenar as informações sobre cada curso; OK
b) Armazenar em estrutura as informações do candidato OK
c) Determinar o número de candidato por vaga em cada um dos cursos OK;
d) Determinar quantos cursos ultrapassaram a concorrência do ano anterior; OK
e) Determinar a porcentagem de mulheres inscritas no vestibular; OK
f) Determinar o código do curso que tem mais candidato homem. OK
*/