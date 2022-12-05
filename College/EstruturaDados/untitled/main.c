//////////////////////////////////////////////////////////////////////////////////////
//                        DUPLA: WELTON A. NOGUEIRA, JOÃO LUIZ BIONE                //
//////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

typedef struct node_t {
  struct node_t *left, *right;
  int freq;
  char c;
} * node;

int nodes = 0, end = 1;
struct node_t pool[256] = {{0}};
node queue[255], *q = queue - 1;
char *code[128] = {0}, buffer[1024];

// Criar nós
node createNode(int freq, char c, node a, node b) {
  node n = pool + nodes++;
  if (freq != 0) {
    n->c = c;
    n->freq = freq;
  } else {
    n->left = a, n->right = b;
    n->freq = a->freq + b->freq;
  }
  return n;
}

// Insirir nó na fila
void sortAdd(node n) {
  int j, i = end++;
  while ((j = i / 2)) {
    if (q[j]->freq <= n->freq)
      break;
    q[i] = q[j], i = j;
  }
  q[i] = n;
}

// Retornar primeiro nó da fila
node catchNode() {
  int i, l;
  node n = q[i = 1];

  if (end < 2)
    return 0;
  end--;
  while ((l = i * 2) < end) {
    if (l + 1 < end && q[l + 1]->freq < q[l]->freq)
      l++;
    q[i] = q[l], i = l;
  }
  q[i] = q[end];
  return n;
}

// Gerar código para cada caracter a partir da árvore de huffman
void createCode(node n, char *s, int len) {
  static char *out = buffer;
  if (n->c) {
    s[len] = 0;
    strcpy(out, s);
    code[(int)n->c] = out;
    out += len + 1;
    return;
  }

  s[len] = '0';
  createCode(n->left, s, len + 1);
  s[len] = '1';
  createCode(n->right, s, len + 1);
}

// Carregar tabela de frequencia a partir da leitura do arquivo
void loadFile(FILE *fp_in, unsigned int *freq) {
  char c, s[16] = {0};
  int i = 0;
  while ((c = fgetc(fp_in)) != EOF) {
    freq[(int)c]++;
  }
  for (i = 0; i < 128; i++)
    if (freq[i])
      sortAdd(createNode(freq[i], i, 0, 0));
  while (end > 2)
    sortAdd(createNode(0, 0, catchNode(), catchNode()));
  createCode(q[1], s, 0);
}

// Codifica o arquivo passando bit a bit do código gerado
void encode(FILE *fp_in, FILE *out, unsigned int *freq) {
  char in, c, temp[20] = {0};
  int i, j = 0, k = 0, lim = 0;
  rewind(fp_in);
  for (i = 0; i < 128; i++) {
    if (freq[i])
      lim += (freq[i] * strlen(code[i]));
  }
  fprintf(out, "%04d\n", lim);
  for (i = 0; i < lim; i++) {
    if (temp[j] == '\0') {
      in = fgetc(fp_in);
      strcpy(temp, code[in]);
      j = 0;
    }
    if (temp[j] == '1')
      c = c | (1 << (7 - k));

    else if (temp[j] == '0')
      c = c | (0 << (7 - k));

    else
      printf("ERRO: Entrada Inválida!\n");
    k++;
    j++;
    if (((i + 1) % 8 == 0) || (i == lim - 1)) {
      k = 0;
      fputc(c, out);
      c = 0;
    }
  }
  putchar('\n');
}

// Importa arquivo de frequencia
void import_table(FILE *fp_table, unsigned int *freq) {
  char c;
  int i = 0;

  while ((c = fgetc(fp_table)) != EOF) {
    freq[i++] = (unsigned char)
        c;
  }
  for (i = 0; i < 128; i++)
    if (freq[i])
      sortAdd(createNode(
          freq[i], i, 0,
          0));
  while (end > 2)
    sortAdd(createNode(0, 0, catchNode(), catchNode()));
}

// Decodifica o texto
void decode(FILE *tree, FILE *out) {
  int i = 0, lim = 0, j = 0;
  char c;
  node n = q[1];

  fscanf(tree, "%d", &lim);

  fseek(
      tree, 1,
      SEEK_CUR);
  
  for (i = 0; i < lim; i++) {
    if (j == 0)
      c = fgetc(tree);
    
    if (c & 128)
      n = n->right; 
    else
      n = n->left;      
    if (n->c) {
      fputc(n->c, out);
      n = q[1];
    }
    c = c << 1;
    if (++j > 7)
      j = 0;
  }

  putchar('\n');
  if (q[1] != n)
    printf("Lixo Limpo\n");

  printf("Arquivo Descompactado em: decoded.txt !");
}

// Função executada a partir do handle da main
void compress() {
  FILE *in, *out;
  char file_name[50] = {0};
  unsigned int freq[128] = {0}, i;

  printf("\n Insira o nome do arquivo: ");

  scanf("%s", file_name);

  if (!(in = fopen(file_name, "r"))) {
    printf("\nERRO: Falha ao ler arquivo!\n");
    return;
  }

  loadFile(in, freq);

  out = fopen("coded.kpz", "w");
  encode(in, out, freq);

  fclose(in);
  fclose(out);

  out = fopen("data.bin", "w");

  for (i = 0; i < 128; i++) {
    fprintf(out, "%c", (char)freq[i]);
  }

  fclose(out);
  printf("Arquivo Compactado em: coded.kpz !");
}

// Função executada a partir do handle da main
void unzip() {
  FILE *freqTable, *tree, *out;
  char file_name[50] = {0}, temp[50] = {0};
  unsigned int freq[128] = {0};

  printf("\n\tInsira o nome do arquivo: ");

  scanf("%s", file_name);
  
  if ((tree = fopen(file_name, "r")) == NULL) {
    printf("\nERRO: O arquivo não existe\n");
    return;
  }
  
  if ((freqTable = fopen("data.bin", "r")) == NULL) { 
    printf("\nERRO: Tabela de frequencia não encontrada\n");
    return;
  }
  import_table(freqTable, freq);

  if ((out = fopen("decoded.txt", "w")) == NULL) {
    printf("ERRO: Falha ao criar arquivo de decodificação\n");

    return;
  }
  decode(tree, out); 

  fclose(tree); 
  fclose(freqTable);
  fclose(out);
  
  return;
}

int main(int argc, char *argv[]) {
  int op = 0;

  printf("Insira o Operação Desejada:\n\t0 - SAIR\n\t1 - COMPACTAR\n\t2 - "
         "DESCOMPACTAR\n\t");
  scanf("%d", &op);

  switch (op) {
  case 0:
    printf("\n\tPrograma Finalizado!");
    break;
  case 1:
    compress();
    break;
  case 2:
    unzip();
    break;
  default:
    printf("Operação Inválida");
    break;
  }
  return 0;
}