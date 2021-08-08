<div style='text-align: center;' align='center'>
    <img style='max-width: 300px;' src='hermes_logo.png'/>
</div>

# Hermes
> A C-like scripting language.

## Example program
> Here is a small program that iterates and prints the contents of a list:
```C
list fruits = [
    "apple",
    "banana",
    "pear",
    "lemon"
];

iterate fruits with void @(string fruit) { print(fruit) };
```

## Linking a C program
> Hermes can execute functions written in C.
> To load a function written in C, you can use the `dload` method, to load
> a function from a shared object file (`.so`). Example:
```C
dload("librequests.so", "httpget");

string response = httpget("http://example.org")

print(response)
```
> Here, the `httpget` function was loaded from the `librequests.so` file.
> Read more about how to write C methods for Hermes [here](DLOAD.md).

## Available Data types
> Here is a list of implemented data types:
* list
* int
* bool
* float
* char
* string
* object
* source

### List example
```C
list colors = [
    "red",
    "green",
    "blue"
];
```

#### Built-in list methods
##### Add
> To add an item to a list:
```C
list names = [];

names.add("john");
```
### Remove
> To remove an item from a list by index
```C
list names = ["john"];

names.remove(0);
```

### Int example
> Everyone knows what an integer is.
```C
int age = 22;
```

### Bool example
> Everyone knows what a boolean is.
```C
bool x = 10 > 3;
```

### Float example
> Everyone knows what a float is.
```C
float x = 0.5;
```

### Char example
```C
char c = 'a';
```

### String example
> Everyone knows what a string is.
```C
string name = "John Doe";
```

### Object example
> Objects are sort of what you think they are.
```C
object person = {
    string name = "john";
    int age = 22;
};

print(person.name);
```

### Source example
> Sources are basically objects that represents a parsed source code.
```C
source s = include("examples/functions.he");
```
> To have hermes interpret the source, simply use the built-in `visit` method:
```C
visit(s);
```
> Now you can also dump that source to a serialized `.dat` file using the built-in `wad` method:
```C
wad(s, "functions");
```
> This will create a `functions.dat` file.
> To read the use case for these `.dat` files, please [read this](DAT.md).


## Built-in methods
* print
* aprint
* include
* wad
* lad
* visit
* fopen
* fputs
* fclose
* input
* time
* free

### print
> Prints whatever you gives it, example:
```C
print("hello world");
```

### aprint
> Prints the adress of a value, example:
```C
object person = {string name = "John Doe";};

aprint(person);
```

### include
> Loads an external source file, example:
```C
source s = include("examples/functions.he");
```

### wad
> Writes an AST compound to disk, example:
```C
source s = include("examples/functions.he");
wad(s, "functions");
```
> This creates a `functions.dat` file.

### lad
> Loads an AST compound from disk, example:
```C
source s = lad("functions");
```

### visit
> Visits and executes a source, example:
```C
source s = include("examples/functions.he");
visit(s);
```

### fopen
> Opens a file, here is an example to read the contents of a file:
```C
object file = fopen("examples/functions.he", "r");
string x = file.read();

print(x);
fclose(file);
```

### fputs
> Writes a string to file, example:
```C
object file = fopen("myfile.txt", "w+");

fputs("hello world", file);
fclose(file);
```

### fclose
> Close file, example:
```C
object file = fopen("myfile.txt", "w+");
fclose(file);
```

### input
> Read from user input, stdin:
```C
string a = input("Say something: ");

print("You said: " + a);
```

### time
> Get current timestamp
```C
object stamp = time();

print(stamp.seconds);
```

### free
> Deallocates a variable, example:
```
string x = "hello";
free(x);
```

## Anonymous functions
> To define an anonymous function, name it `@`; like this:
```C
void somefunction(void func)
{
    func();
}

somefunction(void @(){ print("Hello from anonymous function"); });
```

## Available statements
* new
* iterate
* break
* continue
* while
* for

### example of `new` keyword
```C
object get_person(string name)
{
    object o = {
        string name;    
    };

    o.name = name;

    return o;
}

object person = new get_person("Hanna");
```
> The `new` statement will always return a new address of whatever is to the
> right of the statement.

### example of `iterate` keyword
```C
void char_iterator(char c)
{
    print(c);
}

void list_iterator(string name)
{
    print(name);
}

string x = "john doe";
list y = ["john", "sarah", "hannah"];

iterate x with char_iterator;
iterate y with list_iterator;
```

### `iterate` with index example
```C
list fruits = ["banana", "apple", "pear"]

void fruit_iterator(string name, int index)
{
    print(index);
}

iterate fruits with fruit_iterator;
```

### example of `while` keyword
```C
int x = 0;
while (x < 10)
{
    print(x);
    x += 1;
}
```

### example of `for` keyword
```C
for (int i = 0; i < 10; i+=1)
{
    print(i);
}
```

## Available locals & globals / constants
* this

### example of `this` keyword
> The `this` variable exists within local scopes.
> Accessing `this` within a function will return the address of that function:
```C
void myfunc()
{
    print(this);
}

myfunc();  // 0x55824ee44970
```
> Accessing `this` within a function inside an object will return the address
> of the object:
```C
object person =
{
    void myfunc()
    {
        print(this);
    }
}

person.myfunc();  // { object }
```

## Compositions
> Hermes now also supports compositions like this:
```C
int add_2(int x)
{
    return x + 2;
}

int remove_1(int x)
{
    return x - 1;
}

int mycomp(int x) =
    add_2, remove_1;

int x = mycomp(10);

print(x);
```

## Notes
### Lists
> This might not be obvious, but lists can contain any sort of value. Example:
```C
list cool_stuff = [
    "this is a string",
    { string x = "Wow, this is an object"; },
    [
        "a string in a list in a list"
    ]
];
```

## Installing Hermes
> To install Hermes on your system, simply run:
```bash
make && sudo make install
```

## Extensions
* [curl](https://github.com/sebbekarlsson/hermes-curl)

> To use an extension please have a look at [here](DLOAD.md)

## Syntax Highlighting
* [Vim](https://github.com/sebbekarlsson/hermes-vim)
