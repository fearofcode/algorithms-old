#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(int argc, char **argv) {
  const char* INPUT_FILE = "resources/input.txt";

  FILE *fp;
  char *line = NULL;
  char *token;
  size_t len = 0;
  ssize_t read;

  int id[N];

  for(int i = 0; i < N; i++) {
    id[i] = i;
  }

  fp = fopen(INPUT_FILE, "r");
  
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    token = strtok(line, " ");

    int p = atoi(token);

    token = strtok(NULL, " ");

    int q = atoi(token);

    printf("%d %d: ", p, q);

    if(id[p] == id[q]) {
      printf("\n");
      continue;
    }

    int t = id[p];

    for(int i = 0; i < N; i++){
      if(id[i] == t) {
        id[i] = id[q];
      }
    }

    printf("%d %d\n", p, q);
  }

  free(line);

  exit(EXIT_SUCCESS);
}