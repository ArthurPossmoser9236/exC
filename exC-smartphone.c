#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    int nivel_bateria;
    int sms_recebidos;
    int ligacoes_recebidas;
    int ligacoes_realizadas;
    int operadora;
    float creditos;
    float dados_consumidos;
} Smartphone;

void atualizar_estado(Smartphone *phone) {
    phone->nivel_bateria -= rand() % 5 + 1;
    phone->creditos -= (float)(rand() % 200 + 50) / 100;
    phone->dados_consumidos += (float)(rand() % 100 + 10) / 100;
    phone->sms_recebidos += rand() % 4;
    phone->ligacoes_recebidas += rand() % 2;
    phone->ligacoes_realizadas += rand() % 2;

    if (phone->nivel_bateria < 0) phone->nivel_bateria = 0;
    if (phone->creditos < 0) phone->creditos = 0.0;
    if (phone->dados_consumidos > 10.0) phone->dados_consumidos = 10.0;
}

void recarregar_creditos(Smartphone *phone) {
    if (phone->creditos == 0.0) {
        phone->creditos = 10.0;
        printf("Recarga automática realizada: R$ 10.00\n");
    }
}

void mostrar_estado(Smartphone phone) {
    const char *operadoras[] = {"", "Tim", "Claro", "Vivo"};
    printf("Operadora: %s\n", operadoras[phone.operadora]);
    printf("Nível de Bateria: %d%%\n", phone.nivel_bateria);
    printf("SMS Recebidos: %d\n", phone.sms_recebidos);
    printf("Ligações Recebidas: %d\n", phone.ligacoes_recebidas);
    printf("Ligações Realizadas: %d\n", phone.ligacoes_realizadas);
    printf("Créditos: R$ %.2f\n", phone.creditos);
    printf("Dados Consumidos: %.2f GB\n", phone.dados_consumidos);
    printf("------------------------------\n");
}

int main() {
    Smartphone smartphone;
    smartphone.nivel_bateria = 100;
    smartphone.sms_recebidos = 0;
    smartphone.ligacoes_recebidas = 0;
    smartphone.ligacoes_realizadas = 0;
    smartphone.creditos = 10.0;
    smartphone.dados_consumidos = 0.0;

    printf("Escolha a operadora (1 - Tim, 2 - Claro, 3 - Vivo): ");
    scanf("%d", &smartphone.operadora);

    srand(time(NULL));

    while (smartphone.nivel_bateria > 0) {
        atualizar_estado(&smartphone);
        recarregar_creditos(&smartphone);
        mostrar_estado(smartphone);
        usleep(5000000);
    }

    printf("Simulação encerrada.\n");
    return 0;
}
