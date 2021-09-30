#include <stdio.h>
#include <time.h>

int main(){
  // essa variavel vai armazenar a função/método 'clock()' da lib time.h, que começa a contar o tempo a partir da execução do programa
    float timeRunning;
    // loop infinito que vai brekar quando atingir a condição do if
    while(1){
        // Contador de tempo
        timeRunning = clock() / CLOCKS_PER_SEC;
        if (timeRunning>=5.0){
            break;
        }
    }
    // sai do loope continua programa
    printf("aqui passou o tempo: %.1f Segundos\n",timeRunning);
    return(0);
    }