# **CalcRPN**

This is a calculator project that implements **Reverse Polish Notation (RPN)** using a modified version of the **Shunting Yard algorithm**. The project was built in **C++** for the core logic and **Qt Creator** for the graphical user interface (GUI). It supports basic arithmetic operations, mathematical functions like sine, cosine, logarithms, and custom functions (`f`, `g`) using a stack-based evaluation approach.

---

## **Features**
- **RPN Evaluation:** Supports mathematical expressions in Reverse Polish Notation (postfix notation).
- **Shunting Yard Algorithm:** Parses infix expressions and converts them into postfix notation.
- **Mathematical Functions:** Includes built-in functions like `sin`, `cos`, `log`, `tan`, `sqrt`, `exp`, and user-defined functions (`f`, `g`).
- **Graphical User Interface (GUI):** Built using Qt, the interface provides buttons for numeric input, operators, functions, and a display for results and errors.
- **Expression History:** Displays the output queue of parsed expressions for debugging or review.
- **Error Handling:** Identifies and reports invalid expressions, mismatched parentheses, or unsupported operations.

---

## **Project Structure**
1. **C++ Logic:**
   - Implements the Shunting Yard algorithm and RPN evaluation.
   - Handles operator precedence, parentheses, and function evaluation.
2. **Qt GUI:**
   - Provides an interactive interface with buttons and output fields.
   - Displays results, errors, and the parsed output queue.
3. **Core Files:**
   - `calculatorapp.h` / `calculatorapp.cpp`: Main application logic and Qt connections.
   - `mathlogic.h` / `mathlogic.c`: Contains the core functions like `parse_expression` and `evaluate_rpn`.

---

## **Parsing Logic: `parse_expression`**

The `parse_expression` function processes a mathematical expression in infix notation (e.g., `3 + 4 * 2`) and converts it to postfix (RPN) format (e.g., `3 4 2 * +`) using the **Shunting Yard algorithm**.

### **Steps in Parsing**

1. **Initialization:**
   - Processes the input string character by character.
   - Identifies tokens such as numbers, operators, functions, and parentheses.

2. **Token Types:**
   - **Numbers:** Detects integers and floating-point numbers, including negative numbers, and adds them to the output queue.
   - **Operators:** Manages operator precedence and associativity (e.g., `+`, `-`, `*`, `/`, `^`).
   - **Parentheses:** Handles grouping and function arguments within parentheses.
   - **Commas:** Separates arguments in custom functions (e.g., `f(a, b, c)`).

3. **Error Handling:**
   - Identifies mismatched parentheses or invalid tokens.
   - Returns an error if parsing fails.

4. **Post-Processing:**
   - Ensures all operators and functions are added to the output queue.
   - Checks for any unresolved parentheses.

### **Extensions to Shunting Yard**
- **Custom Functions (`f`, `g`):** Supports user-defined functions with variable arguments.
- **Negative Numbers:** Validates the position of the `-` sign for proper interpretation.
- **Floating-Point Numbers:** Handles numbers with decimals.
- **Function Stack:** Keeps track of function calls until fully processed.

---

## **Evaluation Logic: `evaluate_rpn`**

The `evaluate_rpn` function evaluates the postfix (RPN) expression produced by `parse_expression`. It uses a stack to process tokens in the output queue.

### **Steps in Evaluation**
1. **Initialization:**
   - Creates an evaluation stack to store intermediate results.

2. **Processing Tokens:**
   - **Numbers:** Converts tokens to numeric values and pushes them onto the stack.
   - **Operators:** Pops the required operands from the stack, applies the operation, and pushes the result back.
   - **Functions:**
     - **Standard Functions:** Handles `sin`, `cos`, `log`, `tan`, `sqrt`, `exp`, etc., by popping one operand and applying the function.
     - **Custom Functions:** Pops the required arguments, evaluates the function using `evaluate_non_usual_function`, and pushes the result.

3. **Final Result:**
   - The result of the expression is the last value on the stack.

### **Key Features**
- **Standard Operators:** Supports `+`, `-`, `*`, `/`, and `^` for arithmetic calculations.
- **Built-in Functions:** Includes trigonometric and logarithmic functions, with angle-based functions assuming input in degrees.
- **Custom Functions:** Extends functionality with user-defined operations (e.g., `f(x, y, z)`).

---

## **Example Walkthrough**

### **1. Basic Example**
#### Input: `5 1 2 + 4 * + 3 -`  
*(RPN for `(5 + ((1 + 2) * 4)) - 3`)*

1. Push `5`, `1`, and `2` onto the stack.
2. Process `+`: `1 + 2 = 3`. Push `3`.
3. Push `4`. Process `*`: `3 * 4 = 12`. Push `12`.
4. Process `+`: `5 + 12 = 17`. Push `17`.
5. Push `3`. Process `-`: `17 - 3 = 14`.

**Result:** `14`

### **2. Custom Function Example**
#### Input: `f 1 2 3 , ,`
*(RPN for `f(1, 2, 3)` with `f` as a custom function)*

1. Push `1`, `2`, and `3` onto the stack.
2. Recognize `f` and count 3 arguments.
3. Call `evaluate_non_usual_function("f", 3)` to compute `f(1, 2, 3)`.
4. Push the result onto the stack.

**Result:** Computed value of `f(1, 2, 3)`.

---

## **Graphical User Interface (GUI)**

![CalculatorAppGui](https://github.com/user-attachments/assets/37f16b9e-5307-4f98-8921-bd1fa1736ece)

The Qt-based GUI provides:
- Buttons for numeric input, operators, and functions.
- A display area for entering expressions that supports keyboard input and servers for the result display as well.  
- An RPN button that would display the postfix notation for the mathematical expression after evaluation of the latter. The postfix notation would have the final    result  appended to it at the end as well. 
- A clean and intuitive layout for user interaction.
- Extra information about the RPN button as well as the f and g functions are displayed as you hover over their respective buttons.
- A clear all button 'C' to clear the input/output display. 

---

## **Contributing**
Feel free to suggest enhancements or contribute to the project. Pull requests are welcome for improving functionality, adding features, or optimizing the code.


