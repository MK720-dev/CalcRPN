#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <calculatorapp.h>

#define MAX_SIZE 100

#define DEG_TO_RAD (M_PI / 180)

// Stack for operators
char operator_stack[MAX_SIZE];
int operator_top = -1;

// Stack for functions
char function_stack[MAX_SIZE][MAX_SIZE];
int function_top = -1;

// Queue for output (postfix notation)
char output_queue[MAX_SIZE][MAX_SIZE];
int output_front = 0, output_rear = 0;

// Stack for evaluation of RPN
double eval_stack[MAX_SIZE];
int eval_top = -1;


// Helper functions for stack (used in postfix and evaluation)
void push_operator(char op) {
    operator_stack[++operator_top] = op;
}

char pop_operator() {
    return operator_stack[operator_top--];
}

char peek_operator() {
    return operator_stack[operator_top];
}

int is_operator_stack_empty() {
    return operator_top == -1;
}

void push_function(const char *func) {
    strcpy(function_stack[++function_top], func);
}

char* pop_function() {
    return function_stack[function_top--];
}

int is_function_stack_empty() {
    return function_top == -1;
}

void push_eval(double value) {
    eval_stack[++eval_top] = value;
}

double pop_eval() {
    return eval_stack[eval_top--];
}

int is_eval_stack_empty() {
    return eval_top == -1;
}

double peek_eval() {
    return eval_stack[eval_top];
}

// Helper functions for queue
void enqueue_output(const char *token) {
    strcpy(output_queue[output_rear++], token);
}

void dequeue_output(){

    // Clear the front element (optional)
    memset(output_queue[output_front], 0, sizeof(output_queue[output_front]));

    // Move the front pointer forward
    output_front = (output_front + 1) % 100; // Assuming circular queue, adjust as needed

    // Decrement the rear if the queue becomes empty after dequeue (optional)
    if (output_front == output_rear) {
        output_front = output_rear = 0; // Reset the queue if it's now empty
    }
}

// Get the front index of the output queue
int get_output_front() {
    return output_front;
}

// Get the rear index of the output queue
int get_output_rear() {
    return output_rear;
}

void print_output_queue() {
    for (int i = output_front; i < output_rear; i++) {
        printf("%s ", output_queue[i]);
    }
    printf("\n");
}

char* get_output_queue_as_string() {
    static char queue_string[MAX_SIZE * MAX_SIZE]; // Static buffer to store the string
    queue_string[0] = '\0'; // Initialize with an empty string

    for (int i = output_front; i < output_rear; i++) {
        strcat(queue_string, output_queue[i]); // Append the token
        strcat(queue_string, " ");            // Add a space after each token
    }

    return queue_string;
}

int is_output_queue_empty(){
    return output_rear == output_front;
}
void clear_output_queue() {
    // Logic to clear your queue
    // For example, if the queue is a std::queue, you can do:
    while (!is_output_queue_empty()) {
        dequeue_output();
    }
}

// Operator precedence
int precedence(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return -1; // Invalid operator
    }
}

// Check if a character is an operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Check if a token is a function
int is_function(const char *token) {
    const char *functions[] = {"sin", "cos", "log", "tan", "sqrt", "f", "g", "exp", NULL};
    for (int i = 0; functions[i] != NULL; i++) {
        if (strcmp(token, functions[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Handle operators
void handle_operator(char op) {
    while (!is_operator_stack_empty() && precedence(peek_operator()) >= precedence(op)) {
        char op_char[2];
        op_char[0] = pop_operator();
        op_char[1] = '\0';  // Null-terminate the string
        enqueue_output(op_char);
    }
    push_operator(op);
}

// Handle parentheses
int handle_parentheses(char ch) {
    if (ch == '(') {
        push_operator(ch); // Push '(' to the operator stack
    } else if (ch == ')') {
        while (!is_operator_stack_empty() && peek_operator() != '(') {
            char op_char[2];
            op_char[0] = pop_operator();
            op_char[1] = '\0';  // Null-terminate the string
            enqueue_output(op_char);
        }
        if (is_operator_stack_empty()) {
            return 0; // Mismatched parentheses
        }
        pop_operator(); // Pop '(' from the stack

        // If a function is on top of the function stack, pop it and enqueue it
        if (!is_function_stack_empty()) {
            enqueue_output(pop_function()); // Enqueue the function name
        }
    }
    return 1;
}

// Handle functions
void handle_function(const char *func) {
    push_function(func); // Push the function name onto the function stack
}

// Handle commas for function arguments
void handle_comma() {
    while (!is_operator_stack_empty() && peek_operator() != '(') {
        char op_char[2];
        op_char[0] = pop_operator();
        op_char[1] = '\0';  // Null-terminate the string
        enqueue_output(op_char);
    }
}


// Parse the expression into postfix (old parse function)
/*int parse_expression(const char *expression) {
    char token[MAX_SIZE];
    int i = 0, j;

    while (expression[i] != '\0') {
        if (isalpha(expression[i])) {
            // Extract function or variable name
            j = 0;
            while (isalpha(expression[i])) {
                token[j++] = expression[i++];
            }
            token[j] = '\0';

            if (is_function(token)) {
                handle_function(token); // Handle the function name
            } else {
                enqueue_output(token); // Treat as variable for now
            }
            continue;
        } else if (isdigit(expression[i])) {
            // Extract numbers (multi-digit)
            j = 0;
            while (isdigit(expression[i])) {
                token[j++] = expression[i++];
            }
            token[j] = '\0';
            enqueue_output(token);
            continue;
        } else if (is_operator(expression[i])) {
            handle_operator(expression[i]);
        } else if (expression[i] == '(' || expression[i] == ')') {
            if (!handle_parentheses(expression[i])) {
                return 0; // Parentheses mismatch
            }
        } else if (expression[i] == ',') {
            handle_comma();
        } else if (isspace(expression[i])) {
            // Ignore spaces
        } else {
            printf("Error: Invalid token '%c'\n", expression[i]);
            return 0;
        }
        i++;
    }

    // Pop remaining operators onto the output queue
    while (!is_operator_stack_empty()) {
        char op = pop_operator();
        if (op == '(' || op == ')') {
            printf("Error: Mismatched parentheses\n");
            return 0;
        }
        char op_char[2];
        op_char[0] = op;
        op_char[1] = '\0';  // Null-terminate the string
        enqueue_output(op_char);
    }

    return 1; // Success
}*/

// Parse the expression into postfix
int parse_expression(const char *expression) {
    char token[MAX_SIZE];
    int i = 0, j;

    while (expression[i] != '\0') {
        if (isalpha(expression[i])) {
            j = 0;
            while (isalpha(expression[i])) {
                token[j++] = expression[i++];
            }
            token[j] = '\0';

            if (is_function(token)) {
                handle_function(token);
            } else {
                enqueue_output(token);
            }
            continue;
        } else if (isdigit(expression[i]) || ((expression[i] == '-') && (expression[i-1]== '(' || expression[i-1] == ',' || i == 0))) {
            j = 0;
            if (expression[i] == '-') {
                token[j++] = expression[i++];
            }
            while (isdigit(expression[i])) {
                token[j++] = expression[i++];
            }
            if (expression[i] == '.') {
                token[j++] = expression[i++];
                while (isdigit(expression[i])) {
                    token[j++] = expression[i++];
                }
            }
            token[j] = '\0';
            enqueue_output(token);
            continue;
        } else if (is_operator(expression[i])) {
            handle_operator(expression[i]);
        } else if (expression[i] == '(' || expression[i] == ')') {
            if (!handle_parentheses(expression[i])) {
                return 0;
            }
        } else if (expression[i] == ',') {
            handle_comma();
        } else if (isspace(expression[i])) {
            // Ignore spaces
        } else {
            printf("Error: Invalid token '%c'\n", expression[i]);
            return 0;
        }
        i++;
    }

    while (!is_operator_stack_empty()) {
        char op = pop_operator();
        if (op == '(' || op == ')') {
            printf("Error: Mismatched parentheses\n");
            return 0;
        }
        char op_char[2];
        op_char[0] = op;
        op_char[1] = '\0';
        enqueue_output(op_char);
    }

    return 1;
}

// Define the f and g functions
double f(int num_args, double args[]) {
    double result = 0;
    for (int i = 0; i < num_args; i++) {
        result += args[i];
    }
    return result;
}

double g(int num_args, double args[]) {
    double result = 1;
    for (int i = 0; i < num_args; i++) {
        result *= args[i];
    }
    return result;
}

// Handle non-usual functions
double evaluate_non_usual_function(const char *func_name, int num_args) {
    double args[num_args];
    int args_counter = 0;
    while (!is_eval_stack_empty() && args_counter < num_args) {
        double arg = pop_eval();
        args[args_counter++] = arg;
    }

    if (strcmp(func_name, "f") == 0) {
        return f(num_args, args);
    } else if (strcmp(func_name, "g") == 0) {
        return g(num_args, args);
    } else {
        printf("Error: Undefined function '%s'\n", func_name);
        return 0;
    }
}

// Evaluate RPN expression
double evaluate_rpn() {
    for (int i = output_front; i < output_rear; i++) {
        char *token = output_queue[i];

        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push_eval(atof(token));
        } else if (is_operator(token[0])) {
            double operand2 = pop_eval();
            double operand1 = pop_eval();
            double result;
            switch (token[0]) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            case '^': result = pow(operand1, operand2); break;
            default: result = 0; break;
            }
            push_eval(result);
        } else if (is_function(token)) {
            double result;

            if (strcmp(token, "sin") == 0) {
                double operand = pop_eval();
                result = sin(operand*DEG_TO_RAD);
            } else if (strcmp(token, "cos") == 0) {
                double operand = pop_eval();
                result = cos(operand*DEG_TO_RAD);
            } else if (strcmp(token, "log") == 0) {
                double operand = pop_eval();
                result = log(operand);
            } else if (strcmp(token, "tan") == 0) {
                double operand = pop_eval();
                result = tan(operand*DEG_TO_RAD);
            } else if (strcmp(token, "sqrt") == 0) {
                double operand = pop_eval();
                result = sqrt(operand);
            } else if (strcmp(token, "exp") == 0) {
                double operand = pop_eval();
                result = exp(operand);
            } else {
                // Call the non-usual function (f or g)
                int num_args = 0;
                // Count arguments for the function
                for (int j = i - 1; j >= output_front; j--) {
                    if (isdigit(output_queue[j][0]) || (output_queue[j][0] == '-' && isdigit(output_queue[j][1]))) {
                        num_args++; // Increment for each preceding number
                    } else {
                        break; // Stop counting once encountering a non-numeric token
                    }
                }
                result = evaluate_non_usual_function(token, num_args);
            }
            push_eval(result);
        }
    }
    return pop_eval();
}

