#include "header.h"
int opcount=0;
int NumNode(Nodeptr root){
	static int count=0;
	opcount++;
	if(root){
		count++;
		NumNode(root->lchild);
		NumNode(root->rchild);
	}
	return count;
}
int main(){
	int x;
	Nodeptr root=NULL;
	printf("Enter root node: ");
	scanf("%d",&x);
	root=create(x);
	inorder(root);
	int n=NumNode(root);
	printf("\nNo of nodes: %d\n",n);
	printf("Opcount: %d\n",opcount);
}