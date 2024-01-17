#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left,*right;
};

struct node* create(struct node* root) {
    struct node* newnode, * temp, * parent;
    int i, n, num;
    printf("Enter how many numbers do you want!\n");
    scanf("%d", &n);
    printf("Enter %d nodes in tree:\n",n);
    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        if (root == NULL) {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL) {
            parent = temp;
            if (num < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (num < parent->data) {
            parent->left = newnode;
        }
        else {
            parent->right = newnode;
        }
    }
    return root;
}
void preorder(struct node* root){
	struct node*temp=root;
    if (temp == NULL) {
        return;
    }
    printf("%d\t", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(struct node*root)
{
	struct node*temp=root;
	if(temp == NULL)
	{
		return ;
	}

	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);
}
void postorder(struct node*root)
{
	struct node*temp=root;
	if(temp == NULL)
	{
		return ;
	}

	postorder(temp->left);
	postorder(temp->right);
	printf("%d\t",temp->data);
}
int search(struct node*root,int key)
{
	if(root== NULL)
	{
		return 0;
	}
	if(root->data == key)
	{
		return 1;
	}
	else if(root->data >key)
	{
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}
void currentlevel(struct node*root,int level)
{
	if(root == NULL)
	{
		return;
	}
	if(level==1)
	{
		printf("%d ",root->data);
	}
	else if(level>1)
	{
		currentlevel(root->left,level-1);
		currentlevel(root->right,level-1);
	}
}
void insert(struct node*root,int key)
{
	struct node*prev;
	while(root != NULL)
	{
		prev=root;
		if(root->data == key)
		{
			printf("Cannot insert data\n");
			return;
		}
		else if(root->data >key)
		{
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=newnode->right=NULL;
	newnode->data=key;
	if(prev->data > key)
	{
		prev->left=newnode;
	}
	else{
		prev->right=newnode;
	}
}
void min(struct node*root)
{
	while(root->left!= NULL)
	{
		root =root->left;
	}
	printf("\nSmallest element in BST: %d\n",root->data);
}
void max(struct node*root)
{
	while(root->right!= NULL)
	{
		root =root->right;
	}
	printf("\nLargest element in BST: %d\n",root->data);
}
void mirror(struct node*root)
{
	if(root !=NULL)
	{
		mirror(root->left);
		mirror(root->right);
		
		struct node*temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	return ;
}
int totalnodes(struct node*root)
{
	static int cnt=0;
	struct node*temp=root;
	if(temp != NULL)
	{
		cnt++;
		totalnodes(temp->left);
        totalnodes(temp->right);		
	}
	return cnt;
}
int leafnodes(struct node*root)
{
	static int cnt=0;
	if(root)
	{
		if(root->left == NULL && root->right == NULL)
		{
			cnt++;
		}
		else
		{
			if(root->left){
				leafnodes(root->left);
			}
			if(root->right){
				leafnodes(root->right);
			}
		}		
	}
	return cnt;
}
int not_leafnodes(struct node*root)
{
	static int cnt=0;
	struct node*temp=root;
	if(temp != NULL)
	{
		if(temp->left != NULL || temp->right != NULL)
		{
			cnt++;
		}
		not_leafnodes(temp->left);
        not_leafnodes(temp->right);		
	}
	return cnt;
}

void main()
{
	struct node*root;
	int ch,x,i;
	do
	{
		printf("\n\n-----------MENU-------------\n\n");
		printf("\n1.create\n2.insert\n3.inorder\n4.preorder\n5.postorder");
		printf("\n6.search\n7.levelTraversal\n8.Min\n9.Max\n10.Mirror\n");
		printf("11.Total nodes\n12.Leaf nodes\n13.Non leaf nodes\n14.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=NULL;
			    root=create(root);
				break;
			case 2:
				printf("\nEnter data to insert in BST:");
				scanf("%d",&x);
				insert(root,x);
				break;
			case 3:
				printf("Inorder trevrece:\n");
				inorder(root);
				break;
			case 4:
				printf("\npreorder travrece:\n");
				preorder(root);
				break;
			case 5:
				printf("\npostorder travece:\n");
				postorder(root);
				break;
			case 6:
				printf("enter element do you want to search in tree:\n");
				scanf("%d",&x);
				if(search(root,x))
				{
					printf("element found:%d",x);
				}
				else{
				      printf("element not found\n");
				}
				break;
			case 7:
				printf("Element shows level wise:\n");
				for(i=1;i<=4;i++)
				{
					currentlevel(root,i);
				}
				break;
			case 8:
				min(root);
				break;
			case 9:
				max(root);
				break;
			case 10:
				printf("\nbefore mirror performing element:\n");
				inorder(root);
				mirror(root);
				printf("\nafter mirror performing element:\n");
				inorder(root);
				break;
			case 11:
				x=totalnodes(root);
				printf("\nTotal number of nodes in BST: %d",x);
				break;
			case 12:
				x=leafnodes(root);
				printf("\nTotal Leaf nodes in BST: %d",x);
				break;
			case 13:
				x=not_leafnodes(root);
				printf("\nTotal Non leaf nodes in BST: %d",x);
				break;
			default:
				printf("\nInvalid input\n");
		}
	}while(ch!=14);
}

