#include "ast.h"
#include "codegen.h"
#include "symbolTable.h"
#include "util.h"
extern AstNode * program;
extern SymbolTableStackEntryPtr symbolStackTop;
extern FILE *outfile;

int noOfVarsInScope;
int ret = 0;
int label = 0;
char labTemp1[20];
char labTemp2[20];
void emit_label(const char *label){
	fprintf(outfile, "%s: \n", label); 
}
void emit(const char *instr){
	fprintf(outfile, "\t%s\n", instr);
}

char *gen_new_label_1(){
	sprintf(labTemp1,"label%d",label);
	label++;
	
}
char *gen_new_label_2(){
	sprintf(labTemp2,"label%d",label);
	label++;
	
}

void code_gen_expr(AstNode *node){
	
	int offset;
	int arrOffset;
	int count = 0;
	AstNodePtr arg;
	if(node==NULL)
		return;
	switch(node->eKind){
		case CONST_EXP:
			fprintf(outfile,"\tli $v0, %d\n",node->nValue);
			break;
		case VAR_EXP:
			offset = node->nSymbolPtr->FPOffset;
			if(node->nSymbolPtr->global==1)
				fprintf(outfile,"\tlw $v0, %d($fp)\n",offset-4);
			else
				fprintf(outfile,"\tlw $v0, %d($gp)\n",offset);
			break;
		case ASSI_EXP:
			offset = node->children[0]->nSymbolPtr->FPOffset;
			if(node->children[0]->eKind == ARRAY_EXP && node->children[1]->eKind != ARRAY_EXP){
				code_gen_expr(node->children[0]->children[0]);
				emit("li $t1, 4");
				emit("mult $v0, $t1");
				emit("mflo $v0");
				if(node->children[0]->nSymbolPtr->global ==1){
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset-4);
					emit("add $t0, $fp, $v0");
				}
				else{
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset);
					emit("add $t0, $gp, $v0");
				}
					code_gen_expr(node->children[1]);
					emit("sw $v0, 0($t0)");
				
			}else if(node->children[0]->eKind == ARRAY_EXP && node->children[1]->eKind == ARRAY_EXP){
				code_gen_expr(node->children[0]->children[0]);
				emit("li $t3, 4");
				emit("mult $v0, $t3");
				emit("mflo $v0");
				if(node->children[0]->nSymbolPtr->global ==1){
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset-4);
					emit("add $t2, $fp, $v0");
				}
				else{
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset);
					emit("add $t2, $gp, $v0");
				}
					code_gen_expr(node->children[1]);
					emit("sw $v0, 0($t2)");	
				
			}else{
				code_gen_expr(node->children[1]);
				if(node->children[0]->nSymbolPtr->global==1)
					fprintf(outfile,"\tsw $v0, %d($fp)\n",offset-4);
				else
					fprintf(outfile,"\tsw $v0, %d($gp)\n",offset);
			}
			break;
		case ARRAY_EXP:
			offset = node->nSymbolPtr->FPOffset;
			if(node->children[0]){
				code_gen_expr(node->children[0]);
				emit("li $t1, 4");
				emit("mult $v0, $t1");
				emit("mflo $v0");
				if(node->nSymbolPtr->global ==1){
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset-4);
					emit("add $t0, $fp, $v0");
				}
				else{
					fprintf(outfile, "\taddi $v0, $v0, %d\n",offset);
					emit("add $t0, $gp, $v0");
				}
				emit("lw $v0, 0($t0)");
			}
			break;
		case ADD_EXP:
			code_gen_expr(node->children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node->children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("addu $v0, $v0, $v1");
			break;
		case SUB_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("sub $v0, $v1, $v0");
			break;
		case MULT_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("mult $v0, $v1");
			emit("mflo $v0"); 
			break;
		case DIV_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("div $v1, $v0");
			emit("mflo $v0"); 
			emit("mfhi $v1"); 
			break;
		case GT_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("sgt $v0, $v1, $v0"); 
			break;
		case LT_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("slt $v0, $v1, $v0"); 
			break;
		case EQ_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("seq $v0, $v0, $v1"); 
			break;
		case NE_EXP:
			code_gen_expr(node -> children[0]);
			emit("subu $sp, $sp, 4");
			emit("sw $v0, 0($sp)");
			code_gen_expr(node -> children[1]);
			emit("lw $v1, 0($sp)");
			emit("addu $sp, $sp, 4");
			emit("sne $v0, $v0, $v1"); 
			break;
		case CALL_EXP:
			if(strcmp(node->fname,"input") == 0){
				emit("li $v0, 5");
				emit("syscall");
			}
			else if(strcmp(node->fname,"output")==0){
				if(node->children[0]->eKind!=CONST_EXP)
					offset = node->children[0]->nSymbolPtr->FPOffset;
				if(node->children[0]->eKind == VAR_EXP ){
					emit("li $v0, 1");
					if(node->children[0]->nSymbolPtr->global ==1)
						fprintf(outfile,"\tlw $a0, %d($fp)\n",offset-4);
					else
						fprintf(outfile,"\tlw $a0, %d($gp)\n",offset);
				}else if(node->children[0]->eKind ==ARRAY_EXP ){
					
					code_gen_expr(node->children[0]->children[0]);
					emit("li $t1, 4");
					emit("mult $v0, $t1");
					emit("mflo $v0");
					if(node->children[0]->nSymbolPtr->global ==1){
						fprintf(outfile, "\taddi $v0, $v0, %d\n",offset-4);
						emit("add $t0, $fp, $v0");
					}
					else{
						fprintf(outfile, "\taddi $v0, $v0, %d\n",offset);
						emit("add $t0, $gp, $v0");
					}
					emit("li $v0, 1");
					emit("lw $a0, 0($t0)");	
				}else{
					
					emit("li $v0, 1");
					fprintf(outfile, "\tli $a0, %d\n", node->children[0]->nValue);
				}
				emit("syscall");
				emit("li $v0, 4");
				emit("la $a0, newline");
				emit("syscall");
					
			}else{
				arg = node->children[0]; // parameters from right to left				
				while(arg){
					count++;
					arg = arg->sibling;
				}
				count = count *4;
				fprintf(outfile, "\tsubu $sp, $sp, %d\n", count);
				arg = node->children[0];
				count = 0;
				while(arg){	
					
					code_gen_expr(arg);
					fprintf(outfile, "\tsw $v0, %d($sp)\n",count);
					count = count+4;
					arg = arg->sibling;
				}
				fprintf(outfile,"\tjal %s\n", node->fname);	
				// pop stack frame
				if(count!=0){
					fprintf(outfile, "\taddu $sp, $sp, %d\n",count);
				}		
			}
				
			break;
	}
}

void code_gen_stmt(AstNode *node){
	
	
	if(node==NULL)
		return;
	switch(node->sKind){
		case EXPRESSION_STMT:
			
			code_gen_expr(node->children[0]);
			break;
		case COMPOUND_STMT:
			noOfVarsInScope = allocate_var_space(node->nSymbolTabPtr, 1);
			fprintf(outfile, "\tsubu $sp, $sp, %d \n", noOfVarsInScope);
			code_gen_stmt(node -> children[0]);
			if(ret==0){
				if(noOfVarsInScope!=0)
					fprintf(outfile, "\taddu $sp, $sp, %d\n", noOfVarsInScope); // pop stack
			}else
				ret = 0;
			break;
		case RETURN_STMT:
			ret = 1;
			if(node->children[0]){
				code_gen_expr(node->children[0]);	
			}
			break;
		case IF_THEN_ELSE_STMT:
			
			code_gen_expr(node->children[0]);
			gen_new_label_1();
			emit("li $t0, 0");
			fprintf(outfile, "\tbeq $v0, $t0, %s\n", labTemp1);
			code_gen_stmt(node->children[1]);
			gen_new_label_2();
			fprintf(outfile, "\tjal %s\n", labTemp2);
			emit_label(labTemp1);
			code_gen_stmt(node->children[2]);
			emit_label(labTemp2);
			break;
		case WHILE_STMT:
			gen_new_label_1();
			gen_new_label_2();
			emit_label(labTemp1);
			code_gen_expr(node->children[0]);
			emit("li $t0, 0");
			fprintf(outfile, "\tbeq $v0, $t0, %s\n", labTemp2);
			code_gen_stmt(node->children[1]);
			fprintf(outfile, "\tjal %s\n",labTemp1);
			emit_label(labTemp2);
			break;
			
	}
	code_gen_stmt(node->sibling);
}

void code_gen_method(AstNode *node){
	AstNodePtr param;
	int count;
	if(node==NULL)	
		return;
	if(strcmp(node->nSymbolPtr->id,"input") != 0 && strcmp(node->nSymbolPtr->id,"output")!=0){
		emit_label(node->nSymbolPtr->id);
		emit("subu $sp, $sp, 8");
		emit("sw $fp, 4($sp)"); // store the value of $fp in $sp+4
		emit("sw $ra, 0($sp)");
		emit("addiu $fp, $sp, 4"); // assign the value of $fp to $sp + 4
		// gives the offset for the params
		param = node->children[0];
		while(param){	
			count = count+4;
			param->nSymbolPtr->FPOffset = count+4;
			param->nSymbolPtr->global = 1;
			param = param->sibling;
		}
		code_gen_stmt(node->children[1]);
		if(noOfVarsInScope!=0)
				fprintf(outfile, "\taddu $sp, $sp, %d\n", noOfVarsInScope); // pop stack
			emit("lw $fp, 4($sp)"); // restore value of frame pointer
			emit("lw $ra, 0($sp)"); // restore value of return address
			emit("addu $sp, $sp, 8");
			emit("jr $ra"); // return to caller
		code_gen_method(node->sibling); 
		
	}
}

void codegen(){
	emit(".data");
	emit_label("newline");
	emit("\t.asciiz \"\\n\"");
	emit(".text");
	emit(".align 2");
	emit("\n");
	
	global_vars();
	if(program){
		if(program->nKind == METHOD){
			code_gen_method(program);
		}
	}
	
	
	
 /* from now on call code gen on the main stmt in main */
}

void global_vars(){

	emit("sw $gp, 0($sp)");
	int space = allocate_var_space(symbolStackTop->symbolTablePtr, 0);
	fprintf(outfile,"\tsubu $sp, $sp, %d \n", space);
		

}

// determine space for variables at the given scope and gives also the offset
int allocate_var_space(SymbolTablePtr symbolTablePtr, int global){
	int result = 0;
	ElementPtr symelement = symbolTablePtr->queue;
   	 while(symelement)
      	{
		if(symelement->stype->kind == INT){
			result = result+4;
			symelement->FPOffset = -result;
			symelement->global = global;
		}else if(symelement->stype->kind == ARRAY){
			result = result + symelement->stype->dimension*4;
			symelement->FPOffset = -result; // first element of array put in the last space allocated for array
			symelement->global = global;
		}
		symelement = symelement->queue_next; 
	}
	
	return result;
}



	
