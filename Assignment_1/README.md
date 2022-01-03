# Programming Assignment #1: 
  Computation Application
## Objective
To develop a network application that performs computation
1) Develop client and server applications using the C programming language that implement 
the following protocol.

2) The client sends a computation request to the server which contains 10 double-precision 
floating point (real) numbers along with an integer that specifies the operation to be 
performed (OP_SUM=0, OP_MEAN=1, OP_MIN=2, OP_MAX=3). The following data structure should be used:
#define OP_SUM 0
#define OP_MEAN 1
#define OP_MIN 2
#define OP_MAX 3
typedef struct
{
 int operation;
 double numbers[10];
}

3) The server performs the requested computation and returns the double-precision floating point (real) number to the client.

4) Submit, via Blackboard, the deliverables described below. Use all lower case characters for your file names
## Deliverables:
 Submit clientapp.c and serverapp.c with good comments in a compressed tar file: 
  firstinitiallastname_prog1.tgz.
