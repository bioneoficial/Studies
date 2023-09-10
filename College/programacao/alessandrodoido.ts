import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function askQuestion(query: string): Promise<string> {
  return new Promise((resolve) => {
    rl.question(query, (answer) => {
      resolve(answer);
    });
  });
}

type NodeType = 'OPERATOR' | 'OPERAND';

interface ExpressionNode {
  type: NodeType;
  value: string | number;
  left?: ExpressionNode;
  right?: ExpressionNode;
}

async function evaluateTree(node: ExpressionNode, variables: Record<string, number>): Promise<number> {
  if (node.type === 'OPERAND') {
    if (typeof node.value === 'number') {
      return node.value;
    } else if (node.value.match(/[A-Z]/)) {
      if (variables[node.value] === undefined) {
        const value = parseFloat(await askQuestion(`Entre com o valor de ${node.value}: `));
        variables[node.value] = value;
      }
      return variables[node.value];
    }
  } else if (node.type === 'OPERATOR') {
    const leftValue = await evaluateTree(node.left!, variables);
    const rightValue = await evaluateTree(node.right!, variables);

    switch (node.value) {
      case '+':
        return leftValue + rightValue;
      case '-':
        return leftValue - rightValue;
      case '*':
        return leftValue * rightValue;
      case '/':
        if (rightValue === 0) {
          throw new Error('Divisão por zero');
        }
        return leftValue / rightValue;
      default:
        throw new Error('Operador inválido');
    }
  }
  throw new Error('Nó inválido');
}

let currentIndex = 0;

function tokenize(expression: string): (string | number)[] {
  const tokens: (string | number)[] = [];
  let currentToken = '';

  for (const char of expression) {
    if (['+', '-', '*', '/', '(', ')'].includes(char)) {
      if (currentToken) {
        if (!isNaN(Number(currentToken))) {
          tokens.push(Number(currentToken));
        } else {
          tokens.push(currentToken);
        }
        currentToken = '';
      }
      tokens.push(char);
    } else if (char.match(/[A-Z0-9]/)) {
      currentToken += char;
    } else if (char.match(/\s/)) {
      continue;
    } else {
      throw new Error(`Expressão Inválida: Token Inválido`);
    }
  }

  if (currentToken) {
    if (!isNaN(Number(currentToken))) {
      tokens.push(Number(currentToken));
    } else {
      tokens.push(currentToken);
    }
  }

  return tokens;
}

function parse(tokens: (string | number)[]): ExpressionNode {
  return parseExpression(tokens);
}

function parseExpression(tokens: (string | number)[]): ExpressionNode {
  let left = parseTerm(tokens);

  while (currentIndex < tokens.length) {
    const operator = tokens[currentIndex];

    if (operator === '+' || operator === '-') {
      currentIndex++;
      const right = parseTerm(tokens);
      left = {
        type: 'OPERATOR',
        value: operator,
        left,
        right,
      };
    } else {
      break;
    }
  }

  return left;
}

function parseTerm(tokens: (string | number)[]): ExpressionNode {
  let left = parseFactor(tokens);

  while (currentIndex < tokens.length) {
    const operator = tokens[currentIndex];

    if (operator === '*' || operator === '/') {
      currentIndex++;
      const right = parseFactor(tokens);
      left = {
        type: 'OPERATOR',
        value: operator,
        left,
        right,
      };
    } else {
      break;
    }
  }

  return left;
}

function parseFactor(tokens: (string | number)[]): ExpressionNode {
  const token = tokens[currentIndex];

  if (token === '(') {
    currentIndex++;
    const node = parseExpression(tokens);
    if (tokens[currentIndex] === ')') {
      currentIndex++;
      return node;
    } else {
      throw new Error('Expressão Inválida: Uso Indevido de Parêntesis');
    }
  } else if (typeof token === 'number' || token.match(/[A-Z]/)) {
    currentIndex++;
    return {
      type: 'OPERAND',
      value: token,
    };
  } else {
    throw new Error('Expressão Inválida: Token Inválido');
  }
}

function buildExecutionTree(expression: string): ExpressionNode {
  const tokens = tokenize(expression);
  currentIndex = 0;
  return parse(tokens);
}

// const expression = 'A + (3 * B) - C'; // A:2  B:3 C:4 Output: 7
// const expression = 'A + (3 ### B) - C'; // Expressão Inválida: Token Inválido 
  // const expression = 'A + (3 * B - C'; // Expressão Inválida: Uso Indevido de Parêntesis
  // const expression = '(2 * 3) + ((4 * A) - 10)' // A:2 Output: 4
const variables: Record<string, number> = {};
(async () => {
  try {
    const executionTree = buildExecutionTree(expression);
    console.log('Árvore de Execução:', JSON.stringify(executionTree, null, 2));
    const result = await evaluateTree(executionTree, variables);
    console.log('Resultado Final:', result);
    process.exit(0);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
})();

