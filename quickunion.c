#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int id[N];

int root(int i) {
  while(id[i] != i) {
    i = id[i];
  }

  return i;
}

int main(int argc, char **argv) {
  const char* INPUT_FILE = "resources/input.txt";

  FILE *fp;
  char *line = NULL;
  char *token;
  size_t len = 0;

  for(int i = 0; i < N; i++) {
    id[i] = i;
  }

  fp = fopen(INPUT_FILE, "r");
  
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  while (getline(&line, &len, fp) != -1) {
    token = strtok(line, " ");

    int p = atoi(token);

    token = strtok(NULL, " ");

    int q = atoi(token);

    printf("%d %d: ", p, q);

    int p_root = root(p);
    int q_root = root(q);

    if(p_root == q_root) {
      printf("\n");
      continue;
    }

    id[p_root] = q_root;

    printf("p_root = %d, q_root = %d. ", p_root, q_root);

    for(int i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }

    printf("\n");
  }

  free(line);

  exit(EXIT_SUCCESS);
}