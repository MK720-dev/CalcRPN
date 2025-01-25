# CalcRPN

This is a calculator project that implements the Reverse Polish Notation (RPN) using a modified version of the Shunting Yard algorithm. The project was built with C++ for the logic and Qt Creator for the graphical user interface (GUI). It supports basic arithmetic operations, mathematical functions like sine, cosine, logarithms, and custom functions (f, g) using a stack-based evaluation approach.

## Features
- <ins>RPN Evaluation:<ins> Supports mathematical expressions in Reverse Polish Notation (postfix notation).
- <ins>Shunting Yard Algorithm:<ins> Parses infix expressions to convert them into postfix (RPN) format.
- <ins>Mathematical Functions:<ins> Includes built-in functions like sin, cos, log, tan, sqrt, exp, and custom functions f and g.
- <ins>Graphical User Interface (GUI):<ins> Built using Qt, the interface features buttons for numeric input, operators, functions, and a text display for showing results and errors.
- <ins>Expression History:<ins> Users can view the output queue of the parsed expression.
- <ins>Error Handling:<ins> The calculator provides error messages for invalid expressions, such as mismatched parentheses or unsupported operations.

## Project Structure
- C++ Logic: The core calculation logic is implemented in C, managing operator precedence, parsing, and function evaluation.
- Qt GUI: The interface is created using Qt Creator, which handles user input, displays results, and provides a clean layout with buttons and output fields.
- Header and Source Files:
    - calculatorapp.h / calculatorapp.cpp: Main Qt application logic and connections.
    - mathlogic.c: Contains the core functions like parse_expression, evaluate_rpn, and other utility functions for stack handling and function evaluation.
## Code Walkthrough
Logic: The logic is based on the shunting yard algorithm to convert infix expressions to postfix notation, which is then evaluated using a stack.
GUI: The Qt interface contains buttons for the various operations, a text box for showing the current expression, and a display for showing the output.
Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Issues and suggestions are also welcome!

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
