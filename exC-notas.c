#include <stdio.h>

struct aluno {
    float nota1;
    float nota2;
    float nota3;
    float media;
};

float calcular_media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

const char* situacao_aluno(float media) {
    return media >= 7.0 ? "aprovado" : "reprovado";
}

void mostrar_resultado(struct aluno aluno, int numero) {
    printf("Aluno %d\n", numero);
    printf("Nota 1: %.1f\n", aluno.nota1);
    printf("Nota 2: %.1f\n", aluno.nota2);
    printf("Nota 3: %.1f\n", aluno.nota3);
    printf("Média: %.2f\n", aluno.media);
    printf("Situação: %s\n", situacao_aluno(aluno.media));
    printf("-----------------------------\n");
}

int main() {
    struct aluno alunos[3] = {
        {10, 3, 7, 0},
        {5, 8, 10, 0},
        {4, 9, 10, 0}
    };

    for (int i = 0; i < 3; i++) {
        alunos[i].media = calcular_media(alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);
        mostrar_resultado(alunos[i], i + 1);
    }

    return 0;
}
