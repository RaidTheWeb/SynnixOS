# Writing C methods for Hermes
> As mentioned before, Hermes can execute functions written in C, and you can
> load them using the `dload` method:
```C
dload("librequests.so", "httpget");
```

## Examples
> Lets say we want to write a method in C that gives us a float, and then
> we want to call this method from Hermes.
> Here is how we write that method:
```C
// main.c

#include <hermes/AST.h>
#include <hermes/dynamic_list.h>
#include <hermes/hermes_runtime.h>


AST_T* getpi(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    AST_T* float_ast = init_ast(AST_FLOAT);
    float_ast->float_value = 3.14;

    return float_ast;
}
```
> Now, you can compile this code like so:
```bash
gcc -g -Wall -rdynamic -shared -fPIC -o libgetpi.so main.c
```

> Now you can use the created `libgetpi.so` file in hermes like this:
```C
dload("libgetpi.so", "getpi");


float PI = getpi();
```
