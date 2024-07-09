#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NR_DE_CLIENTES_NO_DIA 100
#define NR_DE_CADEIRAS 5

int cadeirasOcupadas = 0;
int clientesEsperando = 0;
int podeEntrar = 0;

time_t t;

//Mutex de cadeiras ocupadas

pthread_mutex_t mutexCadeiras = PTHREAD_MUTEX_INITIALIZER;

//Mutex de clientes esperando

pthread_mutex_t mutexEsperando = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t entradaLiberada = PTHREAD_COND_INITIALIZER;

pthread_cond_t cadeirasLivres = PTHREAD_COND_INITIALIZER;

void sentarCadeira(int idCliente) {

     printf("Sou o cliente %d e estou sentando no bar\n", idCliente);

}

void comerSushi(int idCliente) {

     printf("Sou o cliente %d e estou comendo sushi\n", idCliente);

     sleep(1);

}

void chegandoFila (void) {
    
    printf("Sou um cliente e estou chegando na fila");

}

void *comendo(void *arg){

     pthread_mutex_lock(&mutexCadeiras);

          while (cadeirasOcupadas < NR_DE_CADEIRAS)

               pthread_cond_wait(&cadeirasLivres,&mutexCadeiras);

     pthread_mutex_unlock(&mutexCadeiras);

     //Chama um cliente

     pthread_mutex_lock(&mutexEsperando);

          podeEntrar = 1;

     pthread_mutex_unlock(&mutexEsperando);

     pthread_cond_signal(&entradaLiberada);

     //Sentando na cadeira

     sentarCadeira(*(int *)arg);

     //Cliente come
     comerSushi(*(int *)arg);

     pthread_exit(NULL);

}

void *esperando(void *arg){

}

int main(){
    
}




