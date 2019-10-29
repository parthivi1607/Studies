/*
Evaluating postfix expn :-

typedef enum{lparen,rparen,plus,mius,times,divide,mod,eos,operand}precedence;

int eval(void)
{
	precedence token;
	char symbol;
	int op1,op2; int n=0,top=-1;
	token=getToken(&symbol,&n);
	while(token!=eos)
	{
		if(token==operand) push(symbol-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case plus: push(op1+op2); break;
				case minus: push(op1-op2); break;
				case times: push(op1*op2); break;
				case divide: push(op1/op2); break;
				case mod: push(op1%op2); break;
			}
		}
		token=getToken(&symbol,&n);
	}
	return pop();
}

precedence getToken(char *symbol, int *n)
{
	*symbol=*expr((*n)++);
	switch(*symbol)
	{
		case '(': return lapren; break;
		case ')': return rparen; break;
		case '+': return plus; break;
		case '-': return minus; break;
		case '*': return times; break;
		case '/': return divide; break;
		case '%': return mod; break;
		default: return operand;
	}
}
*/

/*
Infix to postfix :-

typedef enum{lparen,rparen,plus,mius,times,divide,mod,eos,operand}precedence;
int isp = {0,19,12,12,13,13,13,0}; //stack precedence
int icp = {20,19,12,12,13,13,13,0}; //incoming precedence

void postfix(void)
{
	char symbol; precedence token;
	int n=0,top=0;
	stack[0]=eos;
	for(token=getToken(&symbol,&n);token!=eos;token=getToken(&symbol,&n))
	{
		if(token==operand) printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top!=lparen]) printToken(pop());
			pop(); //discard left paranthesis
		}
		else
		{
			//checking precedence of token
			while(isp[stack[top]]>=icp[token]) printToken(pop());
			push(token);
		}
		while((token=pop())!=eos) printToken(token);
		printf("\n");
	}
}
*/