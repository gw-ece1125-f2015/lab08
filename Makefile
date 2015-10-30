all: dict_tree dict_tree_full

dict_tree_full: dict_tree_full.c
	$(CC) -Wall -g -o $@ $< -lm

dict_tree: dict_tree.c
	$(CC) -Wall -g -o $@ $< -lm

clean:
	$(RM) dict_tree
