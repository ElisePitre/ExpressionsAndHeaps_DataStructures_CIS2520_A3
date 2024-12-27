#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "a3q1_header.h"


Variable variables[10];
int varCount = 0; 

//Frees the tree
void freeTree(Node *root){
	if(root == NULL){
		return;
	}

	if(root->left != NULL){
		freeTree(root->left);
	}
	if(root->right != NULL){
		freeTree(root->right);
	}
	free(root);
}

// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node* createNode(char *data){
	Node *new_node;
	new_node = malloc(sizeof(Node));
	strcpy(new_node->data, data);
	new_node->left = NULL;
	new_node->right = NULL;
		
	return new_node;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.
// Returns NULL if the format of the expression string is incorrect
Node* parseExpression(char *expr){
	int left_brackets = 0; //total of left brackets read
	int right_brackets = 0; //total of right brackets read

	//If there's a space
	if(expr[0] == ' '){
		return NULL;
	}

	Node *parent_node = NULL;
	char data[10];

	//If there are no brackets in the given expression, meaning we are at the bottom of the tree
	if(expr[0] != '(' && strlen(expr) > 0 && strlen(expr) < 5){

		//Make sure it's a number or variable
		for(int i=0; i<strlen(expr); i++){
			if(isalnum(expr[i]) == 0 && expr[i] != '.'){
				return NULL;
			}
		}

		parent_node = createNode(expr);
		parent_node->left = NULL;
		parent_node->right = NULL;
		return parent_node;
	}

	if(expr[0] != '(' && strlen(expr) > 5){
		return NULL;
	}

	//Go through every element of inputed expression
	for(int i=0; i<strlen(expr); i++){
		//If there's a space
		if(expr[i] == ' '){
			return NULL;
		}

		if(expr[i] == '('){
			left_brackets++;
		}
		else if(expr[i] == ')'){
			right_brackets++;
		}

		if(left_brackets == (right_brackets + 1)){ // If there is currently one more left bracket read than right brackets
			if(expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*'){ // If the current character is an operand

				//If the format is invalid - nothing to the left and/or right of the operator
				if(1 > (i-1) || (strlen(expr) - 2) <= i ){
					return NULL;
				}

				//create left substring of expression
				char *left_sub_string = malloc(sizeof(char) * (i)); //includes space for null terminator
				if(left_sub_string == NULL){ //if problem with malloc
					free(left_sub_string);
					return NULL;
				}
				strncpy(left_sub_string, expr+1, i-1); //doesn't copy opening bracket
				left_sub_string[i-1] = '\0'; //include null terminator 

				//create right substring of expression
				char *right_sub_string = malloc(sizeof(char) * (strlen(expr) - i - 1)); //includes space for null terminator
				if(right_sub_string == NULL){ //if problem with malloc
					free(right_sub_string);
					return NULL;
				}
				strncpy(right_sub_string, expr+(i+1), strlen(expr) - i - 2); //doesn't copy closing bracket
				right_sub_string[strlen(expr) - i - 2] = '\0'; //include null terminator

				//Create node and children
				data[0] = expr[i];
				data[1] = '\0';
				parent_node = createNode(data);
				parent_node->left = parseExpression(left_sub_string);
				parent_node->right = parseExpression(right_sub_string);
				free(left_sub_string);
				free(right_sub_string);

			}
		}
	}

	// If the brackets are not equal
	if(left_brackets != right_brackets){
		freeTree(parent_node);
		return NULL;
	}

	// If the children were made successfully
	if(parent_node->left != NULL && parent_node->right != NULL){
		return parent_node;
	}

	//If the format is incorrect and the function should return NULL
	freeTree(parent_node);
	return NULL;
}

// The preOrder function prints tree nodes in preorder traversal.
void preorder(Node *root){
	printf("%s ", root->data);
	if(root->left != NULL){
		preorder(root->left);
	}
	if(root->right != NULL){
		preorder(root->right);
	}
}

// The inOrder function prints tree nodes in inorder traversal fully parenthesized.
void inorder(Node *root){
	printf("(");
	if(root->left != NULL){
		inorder(root->left);
	}
	printf("%s", root->data);
	if(root->right != NULL){
		inorder(root->right);
	}
	printf(")");
}

// The postOrder function prints tree nodes in postorder traversal.
void postorder(Node *root){
	if(root->left != NULL){
		postorder(root->left);
	}
	if(root->right != NULL){
		postorder(root->right);
	}
	printf("%s ", root->data);
}

// The promptVariables function prompts the user to assign values to each variable found in the expression tree. The values should be stored in the Variables struct.
void promptVariables(Node *root){
	float tempVal; 
	char *dummy;
	tempVal = strtof(root->data, &dummy);
	int inArray = 0;
	
	//dummy should be equal to root->data if it's a not float value
	if(strcmp(dummy, root->data) == 0){
		if(root->data[0] != '+' && root->data[0] != '-' && root->data[0] != '/' && root->data[0] != '*'){

			for(int i=0; i<varCount; i++){
				if(strcmp((variables[i]).varName, root->data) == 0){
					inArray = 1; // inArray is true
				}
			}

			if(inArray == 0){

				int validInput = 0;
				while(validInput == 0){
					printf("Please enter the value for %s: ", root->data);
					validInput = scanf("%f", &tempVal);
					if(validInput  == 0){
						int c;
						while((c = getchar()) != '\n' && c != EOF){}
						printf("Please enter a valid float in the format Y.YY!\n");
					}
				}

				strcpy(variables[varCount].varName, root->data);
				variables[varCount].value = tempVal;
				varCount++;
			}
		}
	}

	// Recursivly go through each node
	if(root->left != NULL){
		promptVariables(root->left);
	}
	if(root->right != NULL){
		promptVariables(root->right);
	}

}

// The calculate function calculates the expression and returns its result. Division by 0 and/or other error scenarios should be checked.
float calculate(Node *root){
	float tempVal; 
	char *dummy;
	int indexInArray = -1;
	float right;


	//Find if current node is in variable array
	for(int i=0; i<varCount; i++){
		if(strcmp((variables[i]).varName, root->data) == 0){
			indexInArray = i; // inArray is true
		}
	}

	//If we are at a variable
	if(indexInArray != -1 && root->left == NULL && root->right == NULL){
		return variables[indexInArray].value;
	}

	//if we are at a number
	if(root->left == NULL && root->right == NULL){
		tempVal = strtof(root->data, &dummy);
		return tempVal;
	}
	
	//If not a variable or number (must be operator)
	if((root->data)[0] == '*'){
		return calculate(root->left) * calculate(root->right);
	}
	else if((root->data)[0] == '+'){
		return calculate(root->left) + calculate(root->right);
	}
	else if((root->data)[0] == '-'){
		return calculate(root->left) - calculate(root->right);
	}
	else if((root->data)[0] == '/'){
		//CHECK FOR DIVIDE BY ZERO
		right = calculate(root->right);
		if(right == 0.0){
			printf("Your expression has a divide by zero error! This value will be replaced by 0, please note that the result is actually undefined.\n");
			return 0;
		}

		return calculate(root->left) / right;
	}


	//If it didn't work return 0
	printf("The variable %s was not found, the defult value of 0 will be used", root->data);
	return 0;
}