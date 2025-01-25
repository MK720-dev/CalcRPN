# CalcRPN

This is a calculator project that implements the Reverse Polish Notation (RPN) using a modified version of the Shunting Yard algorithm. The project was built with C++ for the logic and Qt Creator for the graphical user interface (GUI). It supports basic arithmetic operations, mathematical functions like sine, cosine, natural logarithm, and custom functions (f, g) using a stack-based evaluation approach.

## Features
- <ins>RPN Evaluation:</ins> Supports mathematical expressions in Reverse Polish Notation (postfix notation).
- <ins>Shunting Yard Algorithm:</ins> Parses infix expressions to convert them into postfix (RPN) format.
- <ins>Mathematical Functions:</ins> Includes built-in functions like sin, cos, log, tan, sqrt, exp, and custom functions f and g.
- <ins>Graphical User Interface (GUI):</ins> Built using Qt, the interface features buttons for numeric input, operators, functions, and a text display for showing results and errors.
- <ins>Expression History:</ins> Users can view the output queue of the parsed expression.
- <ins>Error Handling:</ins> The calculator provides error messages for invalid expressions, such as mismatched parentheses or unsupported operations.

## Project Structure
- <ins>C++ Logic:</ins> The core calculation logic is implemented in C++, managing operator precedence, parsing, and function evaluation.
- <ins>Qt GUI:</ins> The interface is created using Qt Creator, which handles user input, displays results, and provides a clean layout with buttons and output fields.
- <ins>Header and Source Files:</ins>
    - calculatorapp.h / calculatorapp.cpp: Main Qt application logic and connections.
    - mathlogic.h / mathlogic.c: Contains the core functions like parse_expression, evaluate_rpn, and other utility functions for stack handling and function evaluation.
## Code Walkthrough
The logic is based on the shunting yard algorithm to convert infix expressions to postfix notation, which is then evaluated using a stack.

The two main parts of the code are the **parse_expression** and the **evaluate_rpn functions**.

### Parsing Logic: 

The parse_expression function is designed to parse a mathematical expression and produce an output in a format inspired by the Shunting Yard algorithm, developed by Edsger Dijkstra. The Shunting Yard algorithm converts infix notation (e.g., 3 + 4 * 2) into postfix (Reverse Polish Notation, RPN, e.g., 3 4 2 * +). The function processes tokens in the input string (expression) and determines how to handle them based on their type (number, operator, function, parentheses, etc.).

Here’s a step-by-step explanation of the parse_expression function:

1. <ins>Initialization and Setup:</ins>
   The input string expression is processed character by character.
   A token buffer is used to store intermediate strings, like numbers or function names, for further processing.
   
2. <ins>Token Parsing:</ins>

    - Numeric Tokens:

          If the character is numeric or a negative sign at a valid position (e.g., after a (, ,, or at the beginning), it identifies a number token.
          The function handles both integers and floating-point numbers by looking for a . character.
          The completed numeric token is enqueued into the output queue (enqueue_output(token)).
    - Operators:

          If the character is an operator (is_operator(expression[i])), it is processed using handle_operator(expression[i]). This function is expected to manage            operator precedence and associativity, determining how operators are pushed to or popped from the operator stack.
      
    - Parentheses:

          If the character is a parenthesis (( or )), handle_parentheses(expression[i]) is called to manage the precedence rules for expressions within                      parentheses.
          If there is an issue with mismatched parentheses, the function immediately returns 0 to signal an error.
      
    - Commas:

        If the character is a comma, it is handled by handle_comma(). This typically ensures that commas are used correctly as argument separators in functions.
        Spaces:

    - Whitespace characters are ignored.
   
    - Invalid Tokens:

        If any other character is encountered, it is treated as an invalid token, and an error message is printed. The function then returns 0 to signal a parsing         error.
      
3. <ins>Post-Processing:</ins>
    After the entire expression has been processed, the function ensures that the operator stack is empty.
    Operators remaining in the stack are popped and enqueued into the output queue. If a mismatched parenthesis (( or )) is found in the stack, an error is            reported, and the function returns 0.
   
4. <ins>Return Value:</ins>
    The function returns 1 if the expression is successfully parsed without errors.
    It returns 0 if any errors (e.g., invalid tokens or mismatched parentheses) are encountered.


### Key Concepts and Shunting Yard extensions:

    - <ins>Operator Precedence and Associativity</ins>:    
        Operators are pushed onto the stack, and their precedence and associativity determine when they are popped and added to the output queue.

    - <ins>Function Handling:</ins>
        In the original Shunting Yard algorithm, handling functions is not part of the core logic since it primarily deals with operators, numbers, and                    parentheses. By introducing a function stack, this implementation extends the algorithm to support functions like f or g (or other user-defined                    functions), which may take arguments and need special processing.

        Here’s an explanation of how the function stack is integrated into the extended algorithm:

            - <ins>Purpose of the Function Stack:</ins>
                The function stack is introduced to handle:

                    - Recognition of functions in the input (e.g., f(x), g(x, y)).
                    - Argument separation when multiple arguments are passed to functions (via commas ,).
                    - Post-processing when a function and its arguments have been fully processed (at the closing parenthesis )).
                    
            - <ins>Changes to the Shunting Yard Approach:</ins>
                The function stack modifies the algorithm in the following ways:

                    - Pushing Functions:
                        When a function token (e.g., f) is recognized in the input, the function name is pushed onto the function stack using push_function(func).
                        This ensures that the function name is stored until its arguments and inner operations are fully processed.
                    - Handling Parentheses:
                        When encountering a closing parenthesis ):
                            - The algorithm processes the operators inside the parentheses first, ensuring that all sub-expressions (like f(a + b)) are resolved                                 correctly.
                            - After encountering the matching opening parenthesis (, the function name on the top of the function stack is popped and enqueued                                   into the output queue (enqueue_output(pop_function())).
                        This step signifies that the function call is complete and ready to be evaluated in postfix notation.
                    - Handling Commas:
                            - Commas (,) inside parentheses indicate argument separation for functions. In the extended algorithm:
                            - The comma triggers the processing of any operators currently in the operator stack.
                            - This ensures that sub-expressions (e.g., f(a + b, c)) are resolved correctly for each argument.

        
    - <ins>Parentheses Management:</ins>
         Parentheses (( and )) control the grouping of operations. Operators inside parentheses are only processed when the closing parenthesis is encountered.
         
    - <ins>Output Queue:</ins>
        The final result of the parsing is stored in the output queue, which represents the expression in postfix notation.
        
    -<ins>Customizations and Features:</ins>
        The function extends the basic Shunting Yard algorithm by:
            - Supporting functions and their arguments (handled via commas).
            - Allowing negative numbers, specifically by checking for valid positions of the - sign.
            - Parsing floating-point numbers.
            - Including error handling for invalid tokens and mismatched parentheses.
            
The second important piece of the Calculator logic is the 

            
- <ins>GUI:</ins> The Qt interface contains buttons for the various operations, a text box for showing the current expression, and a display for showing the output.
Contributing

## Installation
Clone the repository:
bash
Copy
Edit
git clone https://github.com/yourusername/rpn-calculator.git
Install Qt Creator: If you haven't already, download and install Qt Creator.
Open the project: Open the .pro file in Qt Creator.
Build and Run: Build the project and run it through Qt Creator. The GUI will appear, and you can start evaluating mathematical expressions.
Usage
Enter an Expression: Type in a mathematical expression using the buttons on the GUI.
Evaluate: Press the = button to evaluate the expression.
Clear: Press the C button to clear the current expression and output.
Delete Last Input: Press the del button to remove the last character from the expression.
Output Queue: Press the "Show Queue" button to view the output queue of the current expression.
Supported Operations
Arithmetic: +, -, *, /, ^
Functions: sin, cos, log, tan, sqrt, exp, f (sum), g (product)
Example Input:
plaintext
Copy
Edit
3 4 + 2 * = 14
Example Output:
plaintext
Copy
Edit
Result: 14


## License
This project is licensed under the MIT License - see the LICENSE file for details.

Feel free to fork this repository, make improvements, and submit pull requests. Issues and suggestions are also welcome!
