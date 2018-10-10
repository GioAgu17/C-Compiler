
#include "symbolTable.h"
#include "ast.h"
#include "typecheck.h"
extern AstNode *program;
extern int yylineno;
extern SymbolTableStackEntryPtr symbolStackTop;
// Starts typechecking the AST  returns 1 on success
//use the global variable program
//

AstNodePtr currMethod;
int typecheck(){


      if(program!=NULL){
          currMethod = program;
          int check = typecheck_method(currMethod);
          return check;
      }
      else
        return 0;
}

// compares two types and returns the resulting type
// from the comparison

Type* type_equiv(Type *t1, Type *t2){
	if(t1->kind!=t2->kind)
		return NULL;
	else
		return t1;
}

// Typechecks a method and returns 1 on success
int typecheck_method(AstNode *method){
    int check;
    if(method->children[1]!=NULL){
      check = typecheck_stmt(method->children[1]);
    }
    if(check==1){
      method = method->sibling;
      if(method!=NULL){
        currMethod = method;
        typecheck_method(method);
      }
      }
      return 1;

}

// Typechecks a statement and returns 1 on success
int typecheck_stmt( AstNode* stmtNode){
  TypePtr tempType;
  AstNodePtr tempNode;
  int check;
  switch(stmtNode->sKind){
    case COMPOUND_STMT:
        tempNode = stmtNode->children[0];
        if(tempNode==NULL){
          check = 1;
        }
        else {
          check = typecheck_stmt(tempNode);
          while(check!=0 && tempNode->sibling!=NULL){
            check = typecheck_stmt(tempNode->sibling);
            tempNode = tempNode->sibling;
          }
        }
        if(check==1){
          if(tempNode!=NULL){
          if(tempNode->sKind != RETURN_STMT){
            printf("Last statement in the block must be a RETURN statement, line %d\n", tempNode->nLinenumber);
            return 0;
          }
        }else
          printf("Empty statement not permitted without a RETURN statement, line %d\n", stmtNode->nLinenumber);
        }
        return check;
    break;
    case RETURN_STMT:
      if(stmtNode->children[0]==NULL){
        if(currMethod->nType->function->kind == VOID)
            return 1;
        else{
          printf("Incompatible types in return statement, line %d, expected type %s, actual VOID\n",stmtNode->nLinenumber,fromint_tostr(currMethod->nType->function->kind) );
          return 0;
        }
      }
      else{
        TypePtr returnType =  typecheck_expr(stmtNode->children[0]);
        if(returnType!=NULL){

          if(type_equiv(returnType,currMethod->nType->function)==NULL){
            printf("Incompatible types in return statement, line %d\n",stmtNode->nLinenumber );
            return 0;
          }
          else
            return 1;
        }else
          return 0;
        }
    break;
    case IF_THEN_ELSE_STMT:
      tempType = typecheck_expr( stmtNode->children[0]);
      if(tempType!=NULL){
        if(tempType->kind == INT){
          if(stmtNode->children[1]!= NULL && stmtNode->children[2]!=NULL){
            return 1;
          }else
            return 0;
        }else {
            printf("Type of conditional expression in if statement not of type INT, line %d\n", stmtNode->children[0]->nLinenumber);
            return 0;
          }
      }else
        return 0;
      break;
    case WHILE_STMT:
        tempType = typecheck_expr( stmtNode->children[0]);
        if(tempType!=NULL){
          if(tempType->kind == INT){
            if(stmtNode->children[1]!= NULL){
              return 1;
            }else
              return 0;
          }else {
              printf("Type of conditional expression in while statement not of type INT, line %d\n", stmtNode->children[0]->nLinenumber);
              return 0;
            }
        }else
          return 0;
        break;
      case EXPRESSION_STMT:
          if(typecheck_expr(stmtNode->children[0])!=NULL)
            return 1;
          else
            return 0;
        break;

  }
  return check;
}

// Type checks a given expression and returns its type
//

Type* typecheck_expr (AstNode *exprNode){
    char message[14];
    strcpy(message,"multiplication");
    ElementPtr symbolMethod;
    AstNodePtr tempNode;
    AstNodePtr tempFormalVar;
    Type * left;
    Type * right;
    switch(exprNode->eKind){
      case CONST_EXP:
        return new_type(INT);
      break;
      case ASSI_EXP:
      if((exprNode->children[0]->eKind == VAR_EXP && exprNode->children[0]->nSymbolPtr->stype->kind != ARRAY)|| (exprNode->children[0]->eKind == ARRAY_EXP)){
        left = typecheck_expr(exprNode->children[0]);
        right = typecheck_expr(exprNode->children[1]);
        if(left==NULL || right == NULL){
          return NULL;
        }
        if(type_equiv(left,right) == NULL){
          printf("Incompatible types to assign in assignment expression, line %d\n",exprNode->nLinenumber);
        //  printf("%s\n", fromint_tostr(left->kind));
        //  printf("%s\n", fromint_tostr(right->kind));
          return NULL;
        }
      }else{
        printf("Left subexpression is not an l-value, line %d\n", exprNode->nLinenumber);
        return NULL;
      }

        break;
      case VAR_EXP:
        return exprNode->nSymbolPtr->stype;
        break;
      case ARRAY_EXP:
        if(exprNode->nSymbolPtr->stype->kind != ARRAY){
          printf("Variable %s is not of type ARRAY in array expression, line %d\n", exprNode->nSymbolPtr->id, exprNode->nLinenumber);
          return NULL;
        }else {
          left = typecheck_expr(exprNode->children[0]);
          if(left== NULL){
            return NULL;
          }
          else if(left->kind!=INT){
            printf("Expression inside square brackets is not of type INT, line %d\n", exprNode->nLinenumber);
            return NULL;
          }
          else
            return left;
        }
      case ADD_EXP:
        strcpy(message,"addition");
        goto Arithmetic;
      case SUB_EXP:
        strcpy(message,"subtraction");
        goto Arithmetic;
      case DIV_EXP:
        strcpy(message,"division");
      case MULT_EXP:
      Arithmetic:
        left = typecheck_expr(exprNode->children[0]);
        right = typecheck_expr(exprNode->children[1]);
        if(left==NULL || right == NULL){
          return NULL;
        }else{
          if(left->kind == INT && right->kind == INT)
            return left;
          else{
            if(type_equiv(left,right)!=NULL){
              printf("Only integers admitted in %s expression, line %d\n", message,exprNode->nLinenumber);
              return NULL;
            }
            else{
              printf("Incompatible types in %s expression, line %d\n", message,exprNode->nLinenumber);
              return NULL;
            }
          }
        }
          break;
        case GT_EXP:
        case LT_EXP:
        case GE_EXP:
        case LE_EXP:
          left = typecheck_expr(exprNode->children[0]);
          right = typecheck_expr(exprNode->children[1]);
          if(left==NULL || right == NULL)
            return NULL;
          if(left->kind == INT && right->kind == INT)
              return left;
          else{
            if(type_equiv(left,right) == NULL){
              printf("Incompatible types in relational expression, line %d\n", exprNode->nLinenumber);
              return NULL;
            }
            else{
              printf("In relational expression only INT is accepted as type, line %d\n",exprNode->nLinenumber);
              return NULL;
            }
          }
          break;
        case EQ_EXP:
        case NE_EXP:
        left = typecheck_expr(exprNode->children[0]);
        right = typecheck_expr(exprNode->children[1]);
        if(left==NULL || right == NULL)
          return NULL;
        if(type_equiv(left,right)==NULL){
          printf("Incompatible types at line %d\n", exprNode-> nLinenumber);
          return NULL;
        }
        else
          return new_type(INT);
        break;
        case CALL_EXP:

          symbolMethod = symLookup(exprNode->fname);
          AstNodePtr tempNode = exprNode->children[0];
          if(symbolMethod!=NULL){
              tempFormalVar = symbolMethod->snode->children[0];

              if(tempNode!=NULL && tempFormalVar==NULL){
                printf("Function %s has not parameters in call expression, line %d\n", exprNode->fname,exprNode->nLinenumber);
                return NULL;
              }
              if(tempNode==NULL && tempFormalVar!=NULL){
                printf("Function %s has one or more parameters in call expression, line %d\n", exprNode->fname, exprNode->nLinenumber);
                return NULL;
              }
              while(tempNode!=NULL && tempFormalVar!=NULL){
                if(tempNode->sibling==NULL && tempFormalVar->sibling!= NULL ){

                  printf("Incorrect number of parameters for call expression, line %d\n ", exprNode->nLinenumber);
                  return NULL;
                }
                if(tempNode->sibling!=NULL && tempFormalVar->sibling== NULL){
                  printf("Incorrect number of parameters for call expression, line %d\n ", exprNode->nLinenumber);
                  return NULL;
                }

                left = typecheck_expr(tempNode);
                right = tempFormalVar->nType;

                if(left == NULL)
                    return NULL;
                if(type_equiv(left,right)!=NULL){
                  tempNode = tempNode->sibling;
                  tempFormalVar = tempFormalVar->sibling;
                }else {
                  printf("Wrong type of an argument in call expression, line %d\n", exprNode->nLinenumber);
                  return NULL;
                }
              }

              return symbolMethod->stype->function;
          }else{
            printf("Function %s doesn't exist, line %d\n", exprNode->fname, exprNode->nLinenumber);
            return NULL;
          }
          break;
        }
    }
// Returns the type referred to the number of the enum
const char * fromint_tostr(unsigned int typeno){
  
  static char * types[] = {"VOID","INT","ARRAY","FUNCTION"};
  return types[typeno];
}
