#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/*
  '%'  -  37
  '('  -  40
  ')'  -  41
  '*'  -  42
  '+'  -  43
  '-'  -  45
  '/' -   47
  '^'  -  94
*/

#define MAX_ADT_SIZE 100 /* Max size of Stack and Queue */
typedef unsigned short ubyte_2;
typedef signed short byte_2;
typedef unsigned long long ubyte_8;
typedef signed long long byte_8;


/* Data type for numbers and operators */
typedef enum
{
    TOKEN_OPERATOR = 1,
    TOKEN_NUMBER
}token_type_e;

typedef struct
{
    token_type_e type;
    byte_8 val;
}token_t;

/* Extremely simple Stack and Queue, but good enough for our needs here.
 * Major drawback is in the Queue: its front increases with each dequeue, so it
 * will quickly become "empty" even though there really is room.
 */

/* For the stack we do not need to differentiate
 * between operators and numbers, as they will be used
 * independently
 */
typedef struct
{
    byte_2 pos;
    byte_8 data[MAX_ADT_SIZE];
} simple_stack_t;

/* For the queue we need to differentiate, to tell apart
 * the _number_ 43 from the operator '+' for example
 */
typedef struct
{
    byte_2 front;
    byte_2 back;
    token_t data[MAX_ADT_SIZE];
} simple_queue_t;


/* Stack declaration */
void stack_init(simple_stack_t *s);
void stack_push(byte_8 data, simple_stack_t *s);
byte_8 stack_pop(simple_stack_t *s);
byte_8 stack_peek(const simple_stack_t *s);
int stack_is_empty(const simple_stack_t *s);

/* Queue declaration */
void queue_init(simple_queue_t* q);
void queue_enqueue(token_t data, simple_queue_t* q);
token_t queue_dequeue (simple_queue_t* q);
int queue_is_empty(const simple_queue_t* q);


/* Functions */
void shunting_yard(const char* input, simple_stack_t* ops, simple_queue_t* output);
byte_8 compute_rpn(simple_queue_t *q);

#endif /* CALCULATOR_H_ */