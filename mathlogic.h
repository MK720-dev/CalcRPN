#ifndef MATHLOGIC_H
#define MATHLOGIC_H


int parse_expression(const char *expression);
double evaluate_rpn();
char* get_output_queue_as_string();
void clear_output_queue();


#endif // MATHLOGIC_H
