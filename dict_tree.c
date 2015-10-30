#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};


void tree_print(struct tree_node *node)
{
	/* Paste and modify your code here. */
}

int tree_count(struct tree_node *node)
{
	return 0;
}

int tree_depth(struct tree_node *root)
{
	return 0;
}

int tree_items(struct tree_node *node, int *A, int idx)
{
	return 0;
}


int tree_sort(struct tree_node *root, int **p_A)
{
	int count = tree_count(root);

	if (count == 0) {
		return 0;
	}

	int *A = calloc(count, sizeof(int));
	if (A) {
		tree_items(root, A, 0);
		*p_A = A;
	}

	return count;
}

int tree_insert(struct tree_node **p_root, int data)
{
	/* Paste and modify your code here. */
}

void tree_destroy(struct tree_node *root)
{
	/* Paste and modify your code here. */
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: dict data_file.txt [lookup_commands.txt]\n");
		return 1;
	}

	FILE *fp_data = fopen(argv[1], "rb");
	if (fp_data == NULL) {
		fprintf(stderr, "Error opening %s\n", argv[1]);
		return 1;
	}

	FILE *fp_lookup = NULL;
	if (argc > 2) {
		fp_lookup = fopen(argv[2], "rb");
		if (fp_lookup == NULL) {
			fprintf(stderr, "Error opening lookups file %s\n", argv[2]);
			return 1;
		}
	}

	int data;
	struct tree_node *root = NULL;

	while (!feof(fp_data) && !ferror(fp_data)) {
		if (fscanf(fp_data, "%d", &data) != 1)
			continue;
		
		if (tree_insert(&root, data) < 0) {
			fprintf(stderr, "Error while inserting into tree: %s\n", strerror(errno));
		}
	}

	tree_print(root);
	printf("\n");

	int count = tree_count(root);
	int depth = tree_depth(root);

	int *A = NULL, i;
	int len = tree_sort(root, &A);

	for (i=0; i<len; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	printf("tree count is %d\n", count);
	printf("tree depth is %d\n", depth);

	free(A);
	tree_destroy(root);

	fclose(fp_data);

	if (fp_lookup) {
		fclose(fp_lookup);
	}

	return 0;
}
