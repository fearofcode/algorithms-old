#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int id[N];
int sz[N];

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
    sz[i] = 1;
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

    printf("%d %d:\n", p, q);

    int p_root = root(p);
    int q_root = root(q);

    if(p_root == q_root) {
      printf("\n");
      continue;
    }

    if (sz[p_root] < sz[q_root]) {
      /* connect p to q */
      printf("connecting p to q\n");
      id[p_root] = id[q_root];
      sz[q_root] += sz[p_root];  
    } else {
      /* connect q to p */
      printf("connecting q to p\n");
      
      id[q_root] = id[p_root];
      sz[p_root] += sz[q_root];
    }

    printf("p_root = %d, q_root = %d\n", p_root, q_root);

    for(int i = 0; i < N; i++) {
      printf("id[%d] = %d, ", i, id[i]);
    }

    printf("  \n");

    for(int i = 0; i < N; i++) {
      printf("sz[%d] = %d, ", i, sz[i]);
    }

    printf("\n\n");
  }

  free(line);

  exit(EXIT_SUCCESS);
}