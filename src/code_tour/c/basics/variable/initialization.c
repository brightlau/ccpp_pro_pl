/**
* @file              initialization.c
* @brief             初始化过程：对象的声明可以通过称为初始化的过程提供其初始值
* @version           0.1
* @author            brightl birigtl3016@outlook.com
* @date              2024.12.02
* @copyright         Copyright (c) 2024.
*
* @note              Revision History:
* <table>
* <tr><th>Date       <th>Version         <th>Author          <th>Description
* <tr><td>2024.12.02 <td>0.1             <td>brightl         <td>初始化方式、特性
* </table>
*/

#include "c/basics/variable/variable.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdbool.h>
#include <uchar.h>
#include <time.h>

/**
* @brief             对象的声明可以通过称为初始化的过程提供其初始值
*
* @note              对于每个声明符，如果初始化器未被省略，则它可以是以下之一：= 表达式、= {初始化式列表}、= {}（自C23起）	
*/
#define INITIALIZATION
/*
本页目录：
一、初始化- 初始化含义、初始化器、初始化器形式

// 初始化
// 显式初始化
// 隐式初始化
// 空初始化
// 标量初始化
// 数组初始化
// 结构体及联合体初始化
*/

int global_var;                                 // 静态存储期，隐式初始化为0
_Thread_local int thread_local_global_var = 0;  // 文件作用域的变量，_Thread_local变量，隐式初始化为0
int globalVar = 5;

/**
* @brief             c 初始化示例代码函数
* @return  int       Return Description
*
* @note              Revision History
*/
int initialization_fn(void) {
#ifdef INITIALIZATION
  print_purple("initialization start...\n");

/*****************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/*
一、初始化
初始化含义：
（1）在 C 语言中，对象的初始化是在声明时为变量提供初始值的过程

初始化器：
（1）初始化器用于指定这些初始值，其形式多样且灵活

初始化器基本形式：
（1）对于每个声明符，如果初始化器未被省略，则它可以是以下之一
（2）= 表达式
（3）= { 初始化器列表 } - 
（4）= { }（自C23起）


*/


  /*
  初始化 对象声明可以通过名为初始化的步骤提供其初始值
  解释 初始化式指定存储于一个对象中的初始值

  1、对于每个声明符，若不省略初始化式，则它可以是下列之一
  = 表达式	         (1)	
  = { 初始化式列表 }	(2)	
  = { }	            (3)	(C23起)
  其中 “初始化式列表” 是非空的逗号分隔 ”初始化式“ 列表（尾逗号可选），这里每个初始化式拥有三种可能形式之一
  表达式	           (1)	
  { 初始化器列表 }	  (2)
  { }	              (3)	(C23起)
  指派符列表 = 初始化式	(4)	(C99起) 其中 指派符列表 是形式为 [ 常量表达式 ] 的数组指派符的列表，或形式为 . 标识符 的结构体/联合体指派符的列表；见数组初始化和结构体初始化
  
  2、注意：除了初始化器，花括号环绕的 初始化器列表 亦可出现于复合字面量中，它是有下列形式的表达式
  (类型) { 初始化器列表 }
  (类型) { }		        (C23 起)
  复合字面量指构造一个指定类型的无名对象，在只需要一次数组、结构体或联合体变量时使用
  int *array = (int[]) {1, 2, 3, 4, 5}; (int[]) {1, 2, 3, 4, 5} 创建了一个匿名的整数数组，并将其初始化为 {1, 2, 3, 4, 5}。这个数组的地址被赋值给指针 array
  复合字面量在C语言中有许多实际应用，比如 传递临时对象：可以在函数调用时传递临时创建的对象、简化代码：避免定义临时变量，直接在表达式中创建和初始化对象、设置默认值：使用空初始化器列表设置默认值（C23起）
  */
  int a = 5;                      // 1、直接赋值，= 表达式 这是最常见的初始化形式，直接赋值一个表达式的计算结果给变量
  float b = 3.14;                 // 直接赋值
  char c = 'A';                   // 直接赋值
  int array[3] = {1, 2, 3};       // 初始化数组，= { 初始化器列表 } 对于数组、结构体、联合体，可以使用花括号 {} 包围的初始化器列表进行初始化。初始化器列表是一个非空的、以逗号分隔的表达式列表。尾逗号是可选的
  struct Point { int x; int y; };
  struct Point p = {10, 20};      // 初始化结构体 
  int arrayk[3] = { };            // 数组所有元素初始化为0 (C23起)，= { } (C23起) 从C23标准开始，允许使用空的花括号 {} 进行默认初始化。这种形式将所有成员或元素初始化为零或默认值
  struct Point pk = { };          // 结构体所有成员初始化为0 (C23起)
  int arrayz[5] = { [0] = 1, [2] = 2, [4] = 3 };  // 使用指派符初始化，指派符列表 = 初始化式 (C99起) 从C99标准开始，C语言引入了指派符（designator）语法，允许精确地初始化结构体或数组的特定成员或元素
  struct Point pz = { .x = 10, .y = 20 };         // 使用指派符初始化

  int *arrayf = (int[]) {1, 2, 3, 4, 5};          // 2、(struct Point) { .x = 10, .y = 20 } 创建了一个匿名的 struct Point 对象并将其初始化。这个对象被赋值给变量 p
  struct Point pf = (struct Point) { };           // (struct Point) { } 创建了一个匿名的 struct Point 对象，并将其默认初始化为零（即所有成员都为零）  

  /*
  显式初始化，即显式初始化是指在声明变量时直接为其提供一个初始值。根据变量的类型，显式初始化的方式有所不同
  若提供了“初始化式”，对于
  标量类型初始化，见标量初始化，标量类型包括基本类型（如int、float、char等）。显式初始化时直接赋值一个表达式给变量
  数组类型初始化，见数组初始化，数组类型的显式初始化使用花括号 {} 包围的初始化器列表
  结构体及联合体类型初始化，见结构体初始化，结构体和联合体类型的显式初始化也使用花括号 {} 包围的初始化器列表
  */
  int ab = 10;          // 标量类型初始化
  float bb = 3.14;      // 标量类型初始化
  char cb = 'A';        // 标量类型初始化  
  int arrayb[3] = {1, 2, 3};    // 数组类型初始化
  char strb[] = "Hello";        // 字符数组初始化（自动加上终止符 '\0'）
  struct Point pb = {10, 20};   // 结构体初始化
  /*
  隐式初始化，即隐式初始化是指在声明变量时未提供初始值。根据变量的存储期（storage duration），未初始化的变量会有不同的默认值
  若未提供”初始化式“
  拥有自动存储期的对象将被初始化为不确定值（可能是陷阱表示）
  拥有静态及线程局域存储期的对象被空初始化，即拥有静态存储期（static storage duration）或线程局域存储期（thread-local storage duration）的对象未显式初始化时，将被隐式初始化为零值

  自动存储期 拥有自动存储期（automatic storage duration，即局部变量，但不包括静态局部变量）的对象未显式初始化时，其值是不确定的，可能是垃圾值或陷阱表示
  静态存储期的对象 全局变量和使用 static 关键字声明的局部变量
  线程局域存储期的对象 使用 _Thread_local 关键字声明
  */
  int var;                                        // 局部变量自动存储期，其值是不确定的
  static int static_var;                          // 静态存储期，隐式初始化为0
  static _Thread_local int thread_local_var = 0;  // 函数内部的静态变量，线程局域存储期，隐式初始化为0
  print_purple("storage uninitialized int: %d\n", var);
  print_purple("Static storage uninitialized int: %d\n", static_var);
  print_purple("Static storage Thread-local storage uninitialized int: %d\n", thread_local_var);
  print_purple("Global uninitialized int: %d\n", global_var);
  print_purple("Global uninitialized _Thread_local int: %d\n", thread_local_global_var);
  /*
  空初始化
  若显式以初始化式 = {} 初始化对象，则它被空初始化 (C23起)

  一些情况下，若未显式初始化对象则它被空初始化，即
  指针被初始化成其类型的空指针值
  整数类型对象被初始化成无符号的零
  浮点类型对象被初始化成正零
  数组的所有元素、结构体的所有成员及联合体的首个成员递归地空初始化，外加将所有填充位初始化为零
  
  在空指针值和浮点零拥有全零位表示的平台上，静态对象的这种初始化形式普遍以将其分配到程序映像的 .bss 段来实现，
  即在许多平台上，静态对象（包括全局变量和静态局部变量）的空初始化通常通过将它们分配到程序映像的 .bss 段来实现。.bss 段（Block Started by Symbol）是一种存储未初始化的静态变量的内存区域。程序加载时，操作系统会将 .bss 段中的所有位置初始化为零
  静态对象的空初始化通常通过将它们分配到 .bss 段实现，程序加载时操作系统会自动将 .bss 段清零
  */
  int arraykx[] = { };            // 显式初始化式 = {} 初始化对象
  struct Point pkx = { };         // 显式初始化式 = {} 初始化对象
  static int *ptr;                       // 指针类型的变量未显式初始化时，它们会被初始化为“空指针值”（null pointer value）。空指针值对于任何指针类型都是相同的，用常量NULL表示
  if (ptr == NULL) {
    print_purple("Pointer is null.\n");
  }
  static int i;                          // 整数类型的变量未显式初始化时，它们会被初始化为零。对于无符号整数类型，这意味着初始化为无符号的零值
  static unsigned int u;
  print_purple("i: %d, u: %u\n", i, u);
  static float f;                        // 浮点类型的变量未显式初始化时，它们会被初始化为正零
  static double d;                       
  print_purple("f: %f, d: %f\n", f, d);
  static int arr[5];                     // 数组类型的变量未显式初始化时，数组的所有元素都会被递归地空初始化，即每个元素都被初始化为其类型的零值
  for (int i = 0; i < 5; i++) {
    print_purple("arr[%d]: %d\n", i, arr[i]);
  }
  static struct Point ps;                // 结构体和联合体类型的变量未显式初始化时，结构体的所有成员和联合体的首个成员都会被递归地空初始化，同时所有填充位也会被初始化为零
  print_purple("Point: x=%d, y=%d\n", ps.x, ps.y);  

  /*
  初始化注解
  1、在初始化静态或线程局域存储期的对象时，每个初始化式中的 表达式 都必须是常量表达式或字符串字面量，即在C语言中，静态存储期（static storage duration）和线程局域存储期（thread-local storage duration）的对象在初始化时，每个初始化式中的表达式都必须是常量表达式或字符串字面量。这一要求确保了这些对象在程序加载或线程启动时，可以被正确地初始化，因为它们的初始化值在编译时就已经确定
  相关存储期的对象
  静态存储期：包括全局作用域的变量和使用static关键字声明的局部变量，这些变量在程序的整个运行期间存在
  线程局域存储期：包括使用_Thread_local关键字声明的变量，这些变量在每个线程中都有独立的实例，并且在整个线程的生命周期内存在
  常量表达式 常量表达式是编译时就能求值的表达式，它们的值在编译阶段已经确定，不依赖于程序运行时的状态。常量表达式通常包括常量、枚举常量以及这些值经过编译时计算的结果
  字符串字面量 字符串字面量是用双引号括起来的一串字符，它们在编译时确定，并存储在程序的只读数据区中

  2、初始化式不能用于不完整类型的对象、VLA 及拥有链接的块作用域对象
  不完整类型（incomplete type）是指在声明时其大小未知的类型。例如，前向声明的结构体或联合体，以及未定义大小的数组。在这种情况下，编译器无法为对象分配内存，因此无法进行初始化
  可变长度数组（Variable Length Array, VLA）是在块作用域内声明的数组，其大小在运行时确定。由于VLA的大小在编译时未知，初始化式不能用于VLA
  具有链接的块作用域对象：根据C标准，具有外部链接的对象通常在翻译单元的其他地方定义和初始化。块作用域内的extern声明仅用于引用外部定义，不能在块作用域内同时进行定义和初始化
  不完整类型：不能为不完整类型（例如前向声明的结构体或未定义大小的数组）提供初始化式。
  可变长度数组（VLA）：不能为在块作用域内声明的可变长度数组提供初始化式。
  
  具有链接属性的块作用域对象：不能在块作用域内为具有链接属性（extern或static）的对象提供初始化式  
  块作用域对象是指在函数或代码块（例如，if语句、while循环、for循环等）内声明的变量。链接属性（linkage attributes）指的是变量的可见性和生存期属性，包括extern和static关键字
  链接属性和初始化的限制
  extern关键字：用于声明一个外部变量，这个变量在其他翻译单元中定义。使用extern声明的变量不能在块作用域内进行初始化，因为extern声明只是告诉编译器这个变量在别处定义
  static关键字：用于声明一个静态局部变量，这个变量在整个程序生命周期内存在，但其作用域仅限于声明它的函数或代码块。static局部变量在块作用域内可以初始化，但如果它在全局作用域内声明，则不能在extern关键字中初始化  
  
  3、函数形参的初值如同用从函数调用实参赋值，而非初始化一样建立
  在C语言中，函数形参的初值（即函数参数的值）是通过函数调用时传递的实参进行赋值的，而不是像变量初始化那样建立。这意味着形参在函数调用时获得其初始值，而不是在函数定义时
  赋值 vs 初始化
  初始化：在变量声明的同时赋予初始值。例如 int x = 10;  // 这是初始化
  赋值：在变量声明之后，给变量赋值。例如 int x; x = 10;  // 这是赋值
  
  函数形参赋值的过程 当函数被调用时，传递给函数的实际参数（实参）会被赋值给函数定义中的形式参数（形参）。这是一个赋值过程，而不是初始化
  形参赋值的性质
  赋值顺序：在函数调用时，实参从左到右依次赋值给对应的形参
  作用域：形参是在函数的局部作用域内有效，其值在函数调用时由实参赋值决定
  生命周期：形参的生命周期与函数执行周期相同，当函数返回时，形参的值就不再存在
  独立性：形参和实参是独立的变量，对形参的修改不会影响到实参（除非通过指针传递），指针传递的例外 当通过指针传递参数时，虽然形参和实参是独立的变量，但它们指向同一块内存区域，对形参的修改会影响实参指向的数据

  4、若将不确定值用作任何标准库调用的实参，则行为未定义。另外，任意牵涉到不确定值的表达式的值是不确定值（例如 int n;，n 可能与自身比较不相等，并且它在后续读取中的值可能出现更改）
  在C语言中，未初始化的变量包含不确定值（indeterminate value）。如果将这些不确定值用作标准库函数的实参，或在表达式中使用它们，会导致未定义行为（undefined behavior）。未定义行为意味着程序的结果是不可预测的，它可能崩溃、产生错误结果，甚至在不同的环境下表现出不同的行为
  
  不确定值 不确定值是指未初始化的变量可能包含的任意值。在下列情况下，变量会包含不确定值 当自动变量（局部变量）声明但未初始化时、当通过某些方式如未定义行为影响时
  未定义行为 
  如果使用包含不确定值的变量作为标准库函数的参数，则行为未定义
  不确定值在表达式中 任何包含不确定值的表达式，其结果也是不确定的。甚至，包含不确定值的变量在不同的读取操作中可能会得到不同的结果，即使它们在看似相同的条件下被读取

  安全编程实践 为了避免未定义行为和不确定值，应该始终确保变量在使用前被初始化

  5、C 中没有对应于 C++ 值初始化的专用语言构造；不过，可以代之以 = {0}（或复合字面量中的 (T){0}）(C99 起)，因为 C 标准不允许空结构体、空联合体或零长度的数组(C23前)，可以用空初始化式 = {}（或复合字面量中的 (T){}）来达成与 C++ 的值初始化相同的语义(C23起)
  C99 起：可以使用= {0}或复合字面量(T){0}来初始化变量，这样可以保证所有成员或变量本身都被初始化为零值
  C23 起：可以使用空初始化式= {}来达到与C++值初始化相同的效果
  这些初始化方式在编写C代码时可以提供更安全和更可预测的初始化行为
  */
  static int ac = 10;                   // 1、常量表达式
  static int bc = 5 + 5;                // 常量表达式
  static const int cc = 20;             // 常量表达式
  static int dc = cc;                   // 常量表达式，因为 cc 是 const 常量
  static char *str = "Hello, world!";   // 1、字符串字面量
  // int getValue();
  // static int agc = getValue();        // 错误：getValue()不是常量表达式

  // struct Incomplete;                  // 2、前向声明，不完整类型
  // struct Incomplete obj = {0};        // 错误：不能初始化不完整类型的对象，不完整类型：编译器无法确定对象的大小，因此无法分配内存和初始化
  // int vla[n];                         // 可变长度数组
  // vla = {1, 2, 3};                    // 错误：不能初始化可变长度数组，可变长度数组：数组大小在运行时确定，编译时无法提供初始化值
  // extern int x = 10;                  // 错误：extern int x具有外部链接属性，并且在块作用域内声明，因此不能在其声明时进行初始化
  extern int globalVar;                  // 声明外部变量，但不能初始化，在这个例子中，extern int globalVar;只是一个声明，它告诉编译器globalVar在其他地方定义（在这里是在全局作用域中定义的）。不能在这个声明中初始化globalVar
  globalVar = 10;                        // 可以在代码块中使用和修改这个变量
  // extern int globalVar = 10;          // 错误：不能为extern变量在块作用域内初始化
  static int localVar = 10;              // 正确：块作用域内的static变量可以初始化，对于块作用域内的static变量，它们可以在定义时进行初始化。static变量在整个程序生命周期内存在，但其作用域仅限于声明它的函数或代码块
  // extern int localVar = 20;           // 错误：不能在块作用域内使用extern初始化静态局部变量

  // void exampleFunction(int a, int b);    // 3、exampleFunction函数有两个形参a和b，在main函数中，exampleFunction被调用，并传递了实参x和y
  // int x = 5, y = 10;                     // 调用exampleFunction(x, y)时，实际发生的是，a被赋值为x的值，即5，b被赋值为y的值，即10
  // exampleFunction(x, y);                 // 函数调用，用实参 x 和 y

  int x;                                    // 4、x 未初始化，包含不确定值
  print_purple("%d\n", x);                  // 行为未定义，因为 x 未初始化，x未被初始化，直接使用它作为printf的参数会导致未定义行为
  int n;
  int m = n + 1;                            // m 的值是不确定的，因为 n 未初始化，由于n未初始化且包含不确定值，m的值也是不确定的。打印m的值会导致未定义行为
  print_purple("m = %d\n", m);

  struct Example { int a; float b; };
  struct Example e5 = {0};                  // 5、结构体的所有成员被初始化为零值
  int array5[10] = {0};                     // 数组的所有元素被初始化为零值
  int i5 = 0;                               // 基本数据类型被初始化为零值
  print_purple("e5.a = %d, e5.b = %f\n", e5.a, e5.b);
  print_purple("array5[0] = %d\n", array5[0]);
  print_purple("i5 = %d\n", i5);
  struct Example e6 = (struct Example){0};  // 使用复合字面量初始化结构体
  print_purple("e.a = %d, e.b = %f\n", e6.a, e6.b); 
  // struct Example e7 = {};                   // 使用空初始化式初始化结构体，C23 起：使用空初始化式 = {}，在C23之前，使用空初始化式可能会导致编译错误或未定义行为，因此推荐使用= {0}或复合字面量(T){0}来进行初始化
  // int array7[10] = {};                      // 使用空初始化式初始化数组
  // int i7 = {};                              // 使用空初始化式初始化基本数据类型 
  // print_purple("e7.a = %d, e7.b = %f\n", e7.a, e7.b);
  // print_purple("array7[0] = %d\n", array7[0]);
  // print_purple("i7 = %d\n", i7);  
  int i10;                                    // 初始化 i10 为不确定值
  static int j10;                             // 初始化 j10 为 0
  int k10 = 1;                                // 初始化 k10 为 1
  int x10[] = { 1, 3, 5 }, *p10 = x;          // 初始化 int x10[3] 为 1,3,5，初始化 int* p10 为 &x10[0]
  struct {int a[3], b;} w[] = {[0].a = {1}, [1].a[0] = 2}; // 初始化 w （二个结构体的数组）为 { { {1,0,0}, 0}, { {2,0,0}, 0} }  
  char* ptr10 = malloc(10);             // 函数调用表达式可用于局部变量初始化
  free(ptr10);
  // static char* ptr = malloc(10);           // 错误：拥有静态存储期的对象要求常量初始化器 
  // int vla[n] = {0};                        // 错误：不能初始化 VLA

  /*
  标量初始化
  标量类型：算术类型(布尔类型、字符类型、整数类型和浮点数类型) 和 指针类型以及 nullptr_t(C23起)
  类型组别
  对象类型：所有不是函数类型的类型
  字符类型：char、signed char、unsigned char
  整数类型：char、有符号整数类型、无符号整数类型、枚举类型
  实数类型：整数类型和实浮点数类型
  算术类型：整数类型和浮点数类型
  标量类型：算术类型和指针类型以及 nullptr_t(C23 起)
  聚合类型：数组类型和结构体类型
  派生声明符类型：数组类型、函数类型和指针类型

  在初始化标量类型对象时，初始化式必须是单个表达式
  标量（包含布尔和枚举类型的整数类型，包含复数和虚数的浮点类型，以及包含指向函数指针的指针类型对象）的初始化式必须是单个表达式，可选地以花括号环绕
  = 表达式	    (1)	
  = { 表达式 }	(2)	
  = { }	(3)	   (C23起)
  1,2) 表达式经过计算，在经过如同赋值转换为对象类型后，其值成为正在初始化的对象的初始值，即在标量初始化中，初始化式表达式的值被转换成待初始化对象的无限定类型，当你初始化一个标量类型（如int、float等）的变量时，初始化表达式的值会在赋值之前被转换为目标对象的类型。这是为了确保即使初始化表达式的类型和目标对象的类型不同，最终赋值的值是兼容的
  3) 空初始化对象，即对于算术或枚举类型对象初始化为数值零，或对指针类型对象初始化为空指针值

  标量初始化注解
  由于适用于赋值式转换的规则，在确定要将表达式转换为哪种类型时，声明类型上的 const 和 volatile 限定符将被忽略
  不使用初始化式时应用的规则见初始化，即隐式初始化
  同所有其他初始化，在初始化静态或线程局域存储期的对象时，表达式 必须为常量表达式，常量表达式是编译时就能求值的表达式，它们的值在编译阶段已经确定，不依赖于程序运行时的状态
  表达式 不能为逗号运算符（除非加括号），因为顶层的逗号会被转译为下个声明符的开始，在C语言中，如果使用逗号运算符进行初始化，必须小心，因为顶层的逗号可能会被解释为下一个声明符的开始，而不是逗号运算符的一部分。为了避免这种情况，可以使用括号将逗号运算符包围起来，使其明确表示为运算符，而不是声明符的分隔符

  在初始化浮点类型对象时，对所有拥有自动存储期的对象所作的计算如同在执行时进行，并受当前舍入影响；报告 math_errhandling 中指定的浮点错误。对于拥有静态和线程局域存储期的对象，计算如同在编译时进行，而且不引发异常
  在C语言中初始化浮点类型对象时，计算和错误处理的行为，具体取决于对象的存储期（storage duration）。存储期定义了对象在程序生命周期中的存在时间。C语言中有几种不同的存储期：自动存储期、静态存储期和线程局域存储期
  自动存储期通常与局部变量相关联，这些变量在函数调用期间存在，当函数返回时它们的生命周期结束，对于拥有自动存储期的浮点对象（如上例中的localVar），初始化表达式在运行时进行计算，并受当前的舍入模式影响。浮点计算的错误处理由宏math_errhandling指定
  静态存储期对象在程序的整个生命周期中都存在，这包括全局变量、具有static关键字的局部变量和函数内static变量，对于拥有静态存储期的浮点对象（如上例中的globalVar和staticLocalVar），初始化表达式在编译时进行计算。这意味着在程序执行之前，编译器已经计算并确定了初始化值。由于这些计算在编译时进行，它们不会受运行时舍入模式影响，也不会引发浮点异常  
  线程局域存储期 线程局域存储期对象在某个特定线程的整个生命周期内存在，这种存储期通常通过__thread或thread_local关键字实现（C11标准），对于拥有线程局域存储期的浮点对象（如上例中的threadVar），初始化表达式也在编译时进行计算。这些对象与静态存储期对象类似，在编译时进行计算，不会受运行时舍入模式影响，也不会引发浮点异常
  
  自动存储期的浮点对象：初始化表达式在运行时计算，受当前舍入模式影响，浮点错误按照math_errhandling宏的定义处理
  静态存储期的浮点对象：初始化表达式在编译时计算，不会受运行时舍入模式影响，也不会引发浮点异常
  线程局域存储期的浮点对象：初始化表达式在编译时计算，不会受运行时舍入模式影响，也不会引发浮点异常
  */
  float bf = 3.14;                  // 这里 3.14 是一个 double 常量，对于float bf = 3.14;，3.14是一个double类型的常量。在初始化f时，3.14会被转换为float类型
  int bi = 3.14;                    // 这里 3.14 是一个 double 常量，对于int bi = 3.14;，3.14仍然是一个double类型的常量。在初始化i时，3.14会被转换为int类型，结果变为3
  print_purple("bf = %f\n", bf);    // 输出：bf = 3.140000
  print_purple("bi = %d\n", bi);    // 输出：bi = 3 (double 值被转换为 int)
  double bd = 42;                   // 42 是一个 int 常量，对于double d = 42;，42是一个int类型的常量。在初始化d时，42会被转换为double类型
  char bcb = 1000;                  // 1000 是一个 int 常量，但超出 char 范围，对于char c = 1000;，1000是一个int类型的常量。由于char通常只能表示-128到127之间的数（假设是8位的char），1000会被截断并转换成char类型，结果可能是未定义的，但在很多实现中，结果是-24（因为1000 % 256 = 232，232在有符号char中的表示是-24）
  print_purple("bd = %f\n", bd);    // 输出：d = 42.000000
  print_purple("bcb = %d\n", bcb);  // 输出：c 的值取决于实现，通常为 -24（因为 1000 超出了 char 类型的范围，转换结果可能是未定义的）

  // int a, b, c;
  // a = (b = 1, c = 2);               // 使用括号明确表示这是一个逗号运算符表达式，在这个例子中，b先被赋值为1，然后c被赋值为2，最后整个表达式的值为c的值，亦即2，被赋值给a
  // int a = 1, 2;                     // 这是错误的语法，编译器会认为你在声明两个变量 a 和 2，编译错误，因为编译器会认为你在声明两个变量a和一个无效的变量2
  // int a = (1, 2);                   // 使用括号，逗号运算符表达式被正确解析，在这个例子中，括号中的逗号运算符首先计算1，然后计算2，并返回2作为整个表达式的值。因此，a被初始化为2
  // int a = (1, 2, 3);                // 逗号运算符表达式，返回最后一个值 3
  // printf("a = %d\n", a);            // 输出：a = 3  
  float flocalVar = 3.14159;           // flocalVar 具有自动存储期
  print_purple("localVar = %f\n", flocalVar); // 对于拥有自动存储期的浮点对象（如上例中的localVar），初始化表达式在运行时进行计算，并受当前的舍入模式影响。浮点计算的错误处理由宏math_errhandling指定。math_errhandling宏可以取以下两种值，MATH_ERRNO：错误会设置errno，MATH_ERREXCEPT：错误会引发浮点异常
  static float staticLocalVar = 2.71828;      // staticLocalVar 具有静态存储期
  print_purple("staticLocalVar = %f\n", staticLocalVar);  // 对于拥有静态存储期的浮点对象（如上例中的globalVar和staticLocalVar），初始化表达式在编译时进行计算。这意味着在程序执行之前，编译器已经计算并确定了初始化值。由于这些计算在编译时进行，它们不会受运行时舍入模式影响，也不会引发浮点异常
  static thread_local float threadVar = 1.61803;  // threadVar 具有线程局域存储期
  print_purple("threadVar = %f\n", threadVar);  // 对于拥有线程局域存储期的浮点对象（如上例中的threadVar），初始化表达式也在编译时进行计算。这些对象与静态存储期对象类似，在编译时进行计算，不会受运行时舍入模式影响，也不会引发浮点异常

  // #pragma STDC FENV_ACCESS ON        // 指示用于控制对浮点环境的访问和管理检测。它允许程序显式声明是否需要访问浮点环境，以便编译器进行相应的优化。这个指示只能出现在文件作用域或者复合语句的起始位置。如果你在其他位置使用这个指示，会导致编译错误。来看一下正确和错误的使用示例
  // static float v = 1.1e75;           // 不引发异常：静态初始化，v是一个具有静态存储期的浮点变量。静态存储期意味着它的初始化在编译时完成，因此不会在运行时引发浮点异常 
  // float u[] = { 1.1e75 };            // 引发 FE_INEXACT，u是一个具有自动存储期的浮点数组。自动存储期意味着它的初始化在运行时完成。如果数值1.1e75在表示为float时不能完全准确，将引发FE_INEXACT异常，因为需要舍入
  // float w = 1.1e75;                  // 引发 FE_INEXACT，同样，w是一个具有自动存储期的浮点变量，初始化时由于舍入可能会引发FE_INEXACT异常 
  // double x = 1.1e75;                 // 可能引发 FE_INEXACT（取决于 FLT_EVAL_METHOD），x是一个double类型的浮点变量。由于double通常有较高的精度，可能不会引发FE_INEXACT异常，但这取决于FLT_EVAL_METHOD。FLT_EVAL_METHOD决定了浮点表达式的计算方式，可能会影响是否引发异常
  // float y = 1.1e75f;                 // 可能引发 FE_INEXACT（取决于 FLT_EVAL_METHOD），y是一个float类型的浮点变量，但是使用了1.1e75f这个字面量。由于精度限制，初始化时可能会引发FE_INEXACT异常，这同样取决于FLT_EVAL_METHOD 
  // long double z = 1.1e75;            // 不引发异常（转换是准确的），z是一个long double类型的浮点变量。long double通常具有更高的精度和更大的范围，处理1.1e75这个数值时可以精确表示，因此不会引发FE_INEXACT异常  
  _Bool b11 = true;
  const double d11 = 3.14;
  int k11 = 3.15;                         // 从 double 转换到 int
  int n11 = {12},                         // 可选地花括号
  *p11 = &n11,                            // 对自动对象，非常量表达式 OK
  (*fp11)(void);
  enum {RED, BLUE} e11 = RED;             // 枚举亦是标量类型

  /*
  数组初始化
  初始化数组类型的对象时，初始化器必须是一个字符串字面量（可选地在花括号中），或是一个花括号环绕的被初始化数组成员列表
  = 字符串字面量	                    (1)，使用字符串字面量初始化字符数组
  = { 表达式 , ... }	               (2)	(C99前)，使用花括号包围的表达式列表初始化数组
  = { 指派符(可选) 表达式 , ... }	     (2)	(C99起)
  = { }	                            (3)	(C23起)，使用空初始化器 (C23起)

  1、从字符串初始化 字符串字面量（可选地在花括号中）可以用作匹配数组类型的初始化器，即初始化字符数组时，字符串字面量或宽字符串字面量可以直接用作初始化器
  通常字符串字面量及 UTF-8 字符串字面量 (C11起)可用于初始化任何字符类型（char、signed char、unsigned char）的数组
  L 前缀的宽字符串字面量可用于初始化任何与 wchar_t 兼容（忽略 cv 限定）的类型的数组、宽字符串字面量（带有 L 前缀）可以用于初始化与 wchar_t 兼容的类型的数组
  u 前缀宽字符串字面量可用于初始化任何与 char16_t 兼容（忽略 cv 限定）的类型的数组、U 前缀宽字符串字面量可用于初始化任何与 char32_t 兼容（忽略 cv 限定）的类型的数组，即带有 u 前缀的宽字符串字面量可以用于初始化与 char16_t 兼容的类型的数组，带有 U 前缀的宽字符串字面量可以用于初始化与 char32_t 兼容的类型的数组
  字符串字面量的连续字节，或宽字符串字面量的连续宽字符，包含空终止字节/字符，会初始化数组的元素

  可修改性 使用数组初始化可以创建一个在栈上的字符数组，它是可修改的，例如，char str[] = "abc"; 初始化的 str 是一个可修改的数组，可以对其元素进行更改，而 char *str = "abc"; 初始化的 str 是一个指向字符串常量的指针，不应被修改
  数组大小推断 当没有显式定义数组大小时，编译器会根据字符串字面量的长度自动推断，例如，char str[] = "abc"; 会推断为 char[4]，因为字符串 "abc" 包含 3 个字符加上一个终止符 \0
  超出数组大小 如果数组大小明确指定，但小于字符串字面量的长度，编译器会警告或报错，因为字符串无法完全装入数组，例如，char str[2] = "abc"; 会产生错误，因为字符串 "abc" 需要至少 char[4] 的空间

  2、从花括号环绕列表初始化 当数组使用花括号包围的初始化器列表进行初始化时，初始化遵循以下规则
  首个初始化器会初始化序号为零的数组元素（即第一个元素），除非使用了指派符（C99起）
  每个不包含指派符的后继初始化器会初始化序号比前一个初始化器多一的数组元素
  在使用初始化器列表初始化数组时，提供多于数组大小的初始化器是错误的，但有一些例外情况，例如使用字符串字面量初始化字符数组
  指派符导致接下来的初始化器初始化指派符所描述的数组元素。然后初始化以向前顺序持续，从指派符所描述元素的下一个元素开始，即指派符可以指定特定位置的元素初始化并影响后续元素的初始化顺序
  在初始化未知大小的数组时，指派初始化器的最大下标会确定所声明的数组大小  

  3、嵌套数组 
  当数组的元素是数组、结构体或联合体时，对应的花括号环绕的初始化器列表中的初始化器可以是任何对于这些成员合法的初始化器。此外，花括号可以在特定情况下省略，以简化初始化器的书写
  如果嵌套初始化器以左花括号开头，那么直到右花括号的整个嵌套初始化器将初始化相应的数组元素
  如果嵌套初始化器不以左花括号开头，那么列表中的初始化器仅会取足够数量的初始化器来考虑子数组、结构体或联合体的元素或成员；任何剩余的初始化器将留待初始化下一个数组元素，即嵌套初始化器不从左花括号开始的情况下，只有足够的初始化器用于当前元素，剩余的用于下一个元素
  数组指示符可以嵌套；嵌套数组的方括号常量表达式跟在外部数组的方括号常量表达式之后
  结构体和联合体的初始化遵循相同的规则

  4、注解
  在 C 语言中，数组初始化器中子表达式的求值顺序是不确定的（但自C++11起，在 C++ 中不是这样）
  在 C 中，初始化器的花括号列表不能为空（C23前）。 C++ 允许空列表、空初始化器能用于初始化数组 (C23 起)
  在 C 中，静态存储期和线程局域存储期的变量必须在编译时可以确定其初始值。因此，用于初始化这些变量的表达式必须是常量表达式（即编译时已知的表达式）

  静态存储期：静态存储期的变量在程序的整个生命周期内存在。全局变量和用 static 关键字声明的局部变量都是静态存储期变量
  线程局域存储期：线程局域存储期的变量在整个线程的生命周期内存在。用 __thread 或 thread_local 关键字声明的变量是线程局域存储期变量
  常量表达式是在编译时可以确定其值的表达式。例如，整数常量、枚举常量、sizeof 运算符的结果等都是常量表达式
  */
  char str1[] = "Hello, World!";                                // 字符串字面量初始化器仅适用于字符数组（char 或 wchar_t）、初始化字符数组，隐式包括末尾的空字符 '\0' 等价于 char str2[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  int arr1[5] = {1, 2, 3, 4, 5};                                // 在C99之前，花括号包围的表达式列表是初始化数组元素的标准方法，初始化整数数组，显式列出每个元素的值
  int arr2[5] = { [0] = 10, [2] = 20, [4] = 30 };               // C99引入了数组指派符，可以用常量表达式来指派特定的数组元素，使用数组指派符初始化数组的某些元素，其他元素会被默认初始化为0 等价于 int arr2[5] = {10, 0, 20, 0, 30};
  int arr3[5] = { };                                            // 在C23中，使用空初始化器来初始化所有元素为零，等价于 int arr3[5] = {0, 0, 0, 0, 0};
  int arr4[3] = {1, 2, 3};                                      // 已知大小的数组，可以使用花括号包围的表达式列表
  int arr5[] = {1, 2, 3, 4, 5};                                 // 未知大小的数组，编译器会根据初始化器自动推断大小
  // int vlan;
  // int vlaarr[vlan] = {1, 2, 3};                                 // 这是非法的 VLA不能使用初始化器
  // int vla_empty[vlan] = {};                                     // 在C23中，空初始化器可以用于VLA，这将初始化所有元素为0

  char str11[] = "Hello, World!";                // 1、初始化 char 数组 str1 拥有类型 char[14] 并保有 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'
  signed char str2[] = "Hello, World!";          // 初始化 signed char 数组 str2 拥有类型 signed char[14]
  unsigned char str3[] = "Hello, World!";        // 初始化 unsigned char 数组str3 拥有类型 unsigned char[14]
  wchar_t wstr1[] = L"猫";                       // 初始化 wchar_t 数组 wstr1 拥有类型 wchar_t[2] 并保有 L'猫', L'\0'
  char16_t ustr1[] = u"猫";                      // 初始化 char16_t 数组 ustr1 拥有类型 char16_t[2] 并保有 u'猫', u'\0'
  char32_t ustr2[] = U"猫";                      // 初始化 char32_t 数组 ustr2 拥有类型 char32_t[2] 并保有 U'猫', U'\0'
  wchar_t wstr[4] = L"猫";                       // wstr 拥有类型 wchar_t[4] 并保有 L'猫', L'\0', L'\0', L'\0'，如果指定了比宽字符串字面量长度多的数组大小，那么剩余的元素会被初始化为零
  char strc3[3] = "abc";     // strc3 拥有类型 char[3] 并保有 'a', 'b', 'c'，若数组大小已知，则它可以比字符串字面量的大小少一，此情况下空终止字符被忽略
  wchar_t wstr2[1] = L"猫";  // wstr2 的类型是 wchar_t[1]，包含 L'猫'、空终止字符 L'\0' 被忽略
  char16_t ustr3[1] = u"猫"; // ustr3 的类型是 char16_t[1]，包含 u'猫'、空终止字符 u'\0' 被忽略
  char32_t ustr4[1] = U"猫"; // ustr4 的类型是 char32_t[1]，包含 U'猫'、空终止字符 U'\0' 被忽略  

  int xi[] = {1,2,3};         // 2、xi 拥有类型 int[3] 并保有 1,2,3
  int yi[5] = {1,2,3};        // yi 拥有类型 int[5] 并保有 1,2,3,0,0 等价于 int yi[5] = { [0] = 1, [1] = 2, [2] = 3, [3] = 0, [4] = 0 };
  int zi[4] = {1};            // zi 拥有类型 int[4] 并保有 1,0,0,0
  int wi[3] = {0};            // wi 拥有类型 int[3] 并保有全零
  int arr44[3] = {1, 2, 3};    // 正确
  int arr55[3] = {1, 2, 3, 4}; // 错误，初始化器数量超过数组大小 当数组的大小已知时，初始化器的数量不能超过数组的大小。这意味着，如果数组大小是固定的，初始化器的数量必须在数组大小的范围内
  char str4[3] = "abc";       // 合法，'a', 'b', 'c'，但没有空终止符 字符数组可以使用字符串字面量进行初始化，即使字符串的长度（包括空终止字符 \0）超过数组的大小
  char str5[4] = "abc";       // 合法，'a', 'b', 'c', '\0' 
  int n5[5] = { [4] = 5, [0] = 1, 2, 3, 4 };                  // 等价于: int n[5] = { 1, 2, 3, 4, 5 }; 使用指派符进行初始化指派符用于初始化特定的数组元素。指派符后面的初始化器将初始化指派符所描述的数组元素，然后从该元素的下一个元素开始继续初始化
  #define MAX 6
  int a6[MAX] = { 1, 3, 5, 7, 9, [MAX-5] = 8, 6, 4, 2, 0 };   // 对于 MAX=6， 数组保有 1, 8, 6, 4, 2, 0，首先初始化 a[0] = 1, a[1] = 3, a[2] = 5, a[3] = 7, a[4] = 9。然后 [MAX-5] = 8 初始化 a[1] 为 8（覆盖掉之前的 3）。接着初始化 a[2] = 6, a[3] = 4, a[4] = 2, 和 a[5] = 0， 对于 MAX=13 数组保有 1, 3, 5, 7, 9, 0, 0, 0, 8, 6, 4, 2, 0（“稀疏数组”）
  int bbb[] = { [2] = 5, [0] = 1, 3 };                        // 等价于: int b[3] = { 1, 3, 5 };
  int n6[5] = {[4]=5, [0] = 1, 2, 3, 4};                      // 保有 1,2,3,4,5

  int yq[4][3] = {              // 3、完整的嵌套初始化器，如果嵌套的初始化器从左花括号开始，则整个直到其右花括号为止的初始化器会初始化对应的数组元素，如 4 个 3 个 int 的数组的数组（4*3 矩阵）
    { 1 },                      // { 1 } 0 行初始化 yq[0] 到 {1, 0, 0}
    { 0, 1 },                   // { 0, 1 } 1 行初始化 yq[2] 到 {0, 1, 0}
    { [2]=1 },                  // { [2]=1 } 2 行初始化 yq[3] 到 {0, 0, 1}
  };                            // 3 行初始化 yq[4] 到 {0, 0, 0}，y[3] 没有显式初始化，因此默认初始化为 {0, 0, 0}
  int yq1[4][3] = {             // 部分嵌套初始化器，如果嵌套的初始化器不从左花括号开始，则只有足够的初始化器会用于初始化子数组、结构体或联合体；剩余的初始化器会用于初始化下一个数组元素，如 4 个 3 个 int 的数组的数组（4*3 矩阵）
    1, 3, 5, 2, 4, 6, 3, 5, 7   // yq1[0] 被初始化为 {1, 3, 5}、yq1[1] 被初始化为 {2, 4, 6}、yq1[2] 被初始化为 {3, 5, 7}、yq1[3] 没有显式初始化，因此默认初始化为 {0, 0, 0}
  };
  struct { int a[3], b; } wq[] = { { 1 }, 2 };    // 结构体初始化，对于结构体数组的初始化，初始化器列表可以包含部分嵌套的初始化器，{ 1 } 被视为完整的初始化器，用于数组的第一个元素 wq[0] 被初始化为 {{1, 0, 0}, 0}、2 被视为数组的第二个元素的首个初始化器 wq[1] 被初始化为 {{2, 0, 0}, 0}
  int yq2[4][3] = {[0][0]=1, [1][1]=1, [2][0]=1}; // 数组指派符的嵌套，数组指派符可以嵌套使用，以更加明确地指定数组中的特定元素 yq2[0][0] 被初始化为 1，因此 yq2[0] 被初始化为 {1, 0, 0}、yq2[1][1] 被初始化为 1，因此 yq2[1] 被初始化为 {0, 1, 0}、yq2[2][0] 被初始化为 1，因此 yq2[2] 被初始化为 {1, 0, 0}、yq2[3] 没有显式初始化，因此默认初始化为 {0, 0, 0}

  int n7 = 1;
  int a7[2] = {n7++, n7++};         // 4、未指明，但是是良定义行为，n 自增二次（以任意顺序），a 初始化为 {1, 2} 和为 {2, 1} 均合法
  // puts((char[4]){'0'+n} + n++);  // 未定义行为，n 的自增和读取是无序的
  int a8[3] = {0};                  // C 与 C++ 中均为清零块作用域数组的合法途径
  int a9[3] = {};                   // C++ 中合法的清零块作用域数组的途径； C23 起合法
  // static char* p[2] = {malloc(1), malloc(2)}; // 错误，这是不合法的，因为 malloc(1) 和 malloc(2) 都是在运行时（即程序执行时）分配内存，而不是在编译时。因此，它们不是常量表达式，不能用于初始化静态存储期的变量
  static int sp[2] = {1, 2};                      // 合法，1 和 2 是常量表达式
  static char* sq[2] = {"abc", "def"};            // 合法，字符串字面量是常量表达式   
    
  enum { REDC, GREENC, BLUEC };
  const char *nmch[] = {                          // 下标能与枚举常量关联，使用带指派符的数组，定义了一个数组 每个数组得值为一个 char* 指针
    [REDC] = "red",
    [GREENC] = "green",
    [BLUEC] = "blue",
  };

  /*
  结构体及联合体初始化
  当初始化一个结构体或联合体类型的对象时，初始化器必须是一个非空的（C23前）用花括号括起来、用逗号分隔的成员初始化器列表
  = { 表达式 , ... }	            (1)	(C99前)
  = { 指派符(可选) 表达式 , ... }	  (2)	(C99起)
  = { }	                         (3)	(C23起)
  其中 指派符 是一序列（空白符分隔或相邻的）.成员 形式的单独成员指派符，和 [索引] 形式的数组指派符
  所有未显式初始化的成员都进行空初始化

  结构体及联合体初始化解释
  1、初始化联合体时，初始化式列表必须只有一个成员，它初始化联合体的首个成员，除非使用指派符初始化式(C99起)
  2、初始化一个结构体时，初始化列表中的第一个初始化器会初始化第一个声明的成员（除非指定了指示符）（C99起），并且所有后续没有指派符的初始化器（C99起）会初始化在由前一个表达式初始化的成员之后声明的结构体成员
  3、指定符使后面的初始化器初始化由该指定符描述的结构体成员。然后，初始化按照声明的顺序继续向前进行，从指定符所描述的成员之后声明的下一个元素开始
  4、提供的初始化器数量多于成员数量是错误的

  嵌套初始化
  如果结构体或联合体的成员是数组、结构体或联合体，那么花括号括起来的初始化列表中的相应初始化器是对这些成员有效的任何初始化器，只是可以省略它们的花括号，如下所示
  5、若嵌套初始化式以左花括号开始，则直到其右花括号为止的整个嵌套初始化式，初始化对应的成员对象，每个左开花括号建立一个新的当前对象。当前对象的成员以其自然顺序初始化，除非使用指派符(C99起)：数组以下标顺序、结构体成员以声明顺序、仅初始化任何联合体的首个被声明成员，空初始化当前对象内未由花括号显式初始化的对象
  如果嵌套初始化器以左花括号开头，那么从这个左花括号开始直到其对应的右花括号为止的整个嵌套初始化器将初始化相应的成员对象。每个左花括号会建立一个新的 “当前对象”。当前对象的成员将按照它们的自然顺序进行初始化，除非使用了指示符（自 C99 起）：数组元素按照下标顺序，结构体成员按照声明顺序，任何联合体中仅第一个声明的成员。当前对象中没有被右花括号显式初始化的子对象将被 “零初始化”
  
  嵌套初始化器：当你使用左花括号 { 时，你开始了一个新的嵌套初始化器、从这个左花括号到对应的右花括号 } 之间的内容用于初始化相应的成员对象
  当前对象：每当遇到一个左花括号 { 时，会建立一个新的“当前对象”、当前对象的成员将按照自然顺序进行初始化，除非使用了指示符
  初始化顺序：数组：按照下标顺序初始化、结构体：按照声明顺序初始化、联合体：只有第一个声明的成员会被初始化
  零初始化：如果当前对象的某些成员未被显式初始化，它们将被零初始化

  6、若嵌套初始化式不以左花括号开始，则仅从列表采用足够的初始化式，以用于该成员数组、结构体或联合体的元素或成员；任何剩下的初始化式留待初始化下个结构体成员
  如果嵌套初始化器不是以左花括号开头，那么列表中只有足够的初始化器用于考虑成员数组、结构体或联合体的元素或成员；任何剩余的初始化器将用于初始化下一个结构体成员

  非括号嵌套初始化器：如果嵌套初始化器不是以左花括号 { 开头，那么初始化器的列表将按顺序依次用于初始化当前对象的成员
  成员分配顺序：数组：按照元素下标顺序、结构体：按照成员声明顺序、联合体：只有第一个成员会被初始化
  剩余初始化器：如果当前对象的所有成员都已被初始化，任何剩余的初始化器将用于初始化下一个结构体成员

  7、嵌套指派符时，成员的指派符后随外围结构体/联合体/数组的指派符。在任何嵌套的方括号初始化式列表中，最外层指派符指代当前对象，而且只在当前对象中选择要初始化的子对象
  当指示符嵌套时，成员的指示符跟在封闭结构体 / 联合体 / 数组的指示符之后。在任何嵌套的括号初始化列表中，最外层的指示符指的是 “当前对象”，并且仅在 “当前对象” 中选择要初始化的子对象
  指示符（Designator）：指示符用于明确指定结构体的成员、数组的元素或联合体的成员、语法上，指示符通常使用点号 .（对于结构体成员）或方括号 []（对于数组元素）
  嵌套指示符：当嵌套使用初始化器时，指示符将按照层次结构进行嵌套、最外层的指示符用于选择当前对象的子对象
  当前对象：最外层的指示符指的是当前正在初始化的对象，在任何嵌套的括号初始化列表中，指示符将逐层指向具体的子对象

  8、若显式初始化任何子对象二次（在使用指派符时可能发生），则使用的初始化式，是较后出现于列表中的初始化式（可能不求值较早的初始化式）
  如果任何子对象被显式初始化两次（当使用指示符时可能会发生这种情况），则列表中后面出现的初始化器将被使用（前面的初始化器可能不会被求值计算）

  9、尽管任何未初始化的子对象都被隐式初始化，若子对象的显式初始化在初始化式列表中出现较早，则同一子对象的隐式初始化决不会覆盖显式初始化（选择 clang 以观察正确的输出）
  虽然任何未初始化的子对象会被隐式初始化，但如果在初始化列表中同一子对象的显式初始化先出现，那么该子对象的隐式初始化永远不会覆盖显式初始化（选择 clang 可以观察到正确的输出）
  
  显式初始化：通过直接在初始化列表中指定的初始化、显式初始化用于明确定义对象的值
  隐式初始化：对于未在初始化列表中显式指定的对象，编译器会将其隐式初始化为零、隐式初始化保证所有成员或元素会有一个初始值，即使未显式指定
  优先级：如果一个子对象在初始化列表中通过显式初始化被赋值，那么该显式初始化将优先于任何隐式初始化、隐式初始化不会覆盖已经被显式初始化的子对象

  10、当初始化式以左开花括号开始时，会完全重初始化其当前对象，并忽略其任何子对象的先前的显式初始化式
  当一个初始化器以左花括号开始时，它的当前对象会被完全重新初始化，并且任何先前对其任何子对象的显式初始化都会被忽略
  当使用大括号 {} 来初始化一个对象时，会完全初始化（或“重初始化”）该对象，对象的所有成员或元素都会被新的初始化值所覆盖、如果某些成员或元素未在大括号内显式指定，它们将被隐式初始化（通常为零）、任何之前对该对象的显式初始化都会被新的初始化所忽略或覆盖

  结构体及联合体初始化注解
  11、初始化式列表可拥有尾随的逗号，它会被忽略
  
  12、C 中初始化器的花括号列表不能为空（注意 C++ 允许空列表，并且注意 C 中结构体不能为空）(C23前)、与 C++ 相同 C 中初始化式列表可为空(C23起)
  
  13、在初始化任何存储期的聚合体时，初始化式列表中的每个表达式必须都是常量表达式，即在 C 语言和 C++ 中，聚合体（aggregates）包括数组和结构体（以及联合体）。当使用初始化列表来初始化这些聚合体时，初始化列表中的每个表达式通常需要是常量表达式。这意味着这些表达式的值必须在编译时就能确定，而不是在运行时计算
  常量表达式是指在编译时能够求值的表达式。可以是：字面常量（如整数、字符、浮点数）、常量表达式的组合（如常量之间的算术运算）、符号常量（如用 #define 定义的常量，或用 const 修饰的全局常量）
  
  14、同所有其他初始化，在初始化静态或线程局域(C11起)存储期的聚合体时，初始化式列表中的每个表达式必须为常量表达式	(C99前)
  
  15、任何初始化式中的子表达式求值顺序为非确定顺序（但 C++11 起的 C++ 中不同）
  */
  union { int x; char c[4]; }
  u1 = {1},                                      // 1、令 u.x 活跃，拥有值 1
  u2 = { .c={'\1'} };                            // 令 u2.c 活跃，拥有值 {'\1','\0','\0','\0'}
  
  struct point {double x,y,z;} pst = {1.2, 1.3}; // 2、p.x=1.2, p.y=1.3, p.z=0.0
  div_t answer = {.quot = 2, .rem = -1 };        // div_t 中的成员顺序可以不同
  struct {int sec, min, hour, day, mon, year;} z1 = {.day=31, 12, 2014, .sec=30, 15, 17};  // 3、初始化 z 为 {30,15,17,31,12,2014}
   
  struct example {
    struct addr_t {
      uint32_t port;
    } addr;
    union {
      uint8_t a8[4];
      uint16_t a16[2];
    } in_u;
  };
  struct example ex5 = {                  // 5、struct example 的初始化式列表开始
    {                                     // ex.addr 的初始化式列表开始
      80                                  // 初始化 struct addr_t 的唯一成员
    },                                    // ex.addr 的初始化式列表结束
    {                                     // ex.in_u 的初始化式列表开始
      {127,0,0,1}                         // 初始化 union in_u 的首个成员
    } 
  };

  struct example ex6 = {80, 127, 0, 0, 1}; // 6、80 初始化 ex.addr.port、127 初始化 ex.in_u.a8[0]、0 初始化 ex.in_u.a8[1]、0 初始化 ex.in_u.a8[2]、1 初始化 ex.in_u.a8[3]

  struct example ex2 = {                   // 7、当前对象为 ex2，指派符属于 struct example 的成员
    .in_u.a8[0]=127, 0, 0, 1, 
    .addr=80
  }; 
  struct Inner { int a; int b;  };
  struct Outer { struct Inner i; int c; };
  struct Outer o = {
    .i = {.a = 1, .b = 2},                // 使用嵌套指示符初始化 i.a 和 i.b
    .c = 3                                // 初始化 c
  };
  int matrix[2][2] = {                    // 嵌套数组初始化
    [0] = { [0] = 1, [1] = 2 },
    [1] = { [0] = 3, [1] = 4 }
  };
  struct Container { int values[3];  int other; };
  struct Container csc = {
    .values = { [0] = 1, [2] = 3 },      // 使用指示符初始化 values 的元素
    .other = 4                           // 初始化 other
  };  

  struct {int n;} s = {                  // 8、如果任何子对象被显式初始化两次（当使用指示符时可能会发生这种情况），则列表中后面出现的初始化器将被使用（前面的初始化器可能不会被求值计算）
    printf("a\n"),               // 可能打印或跳过它
    .n=printf("b\n")             // 始终打印
  };

  typedef struct { int k; int l; int a[2]; } T;         // 9、虽然任何未初始化的子对象都会被隐式初始化，但如果在初始化列表中同一子对象的显式初始化先出现，那么子对象的隐式初始化永远不会覆盖显式初始化（选择 clang 可以观察到正确的输出）
  typedef struct { int i; T t; } S;
  T xt = {.l = 43, .k = 42, .a[1] = 19, .a[0] = 18 };   // 初始化 x 为 {42, 43, {18, 19} }
  S l = { 
    1,                                  // 初始化 l.i 为 1
    .t = xt,                            // 初始化 l.t 为 {42, 43, {18, 19} }
    .t.l = 41,                          // 更改 l.t 为 {42, 41, {18, 19} }
    .t.a[1] = 17                        // 更改 l.t 为 {42, 41, {18, 17} }
  };
  print_purple("l.t.k is %d\n", l.t.k); // .t = x 显式设置 l.t.k 为 42，.t.l = 41 会隐式清零 l.t.k  

  struct fred { char s[4]; int n; };    // 10、当初始化式以左开花括号开始时，会完全重初始化其当前对象，并忽略其任何子对象的先前的显式初始化式
  struct fred xf[] = { 
    { { "abc" }, 1 },                   // 初始化 xf[0] 为 { {'a','b','c','\0'}, 1 }
    [0].s[0] = 'q'                      // 更改 xf[0] 为 { {'q','b','c','\0'}, 1 }
  };
  struct fred yf[ ] = { 
    { { "abc" }, 1 },                   // 初始化 yf[0] 为 { {'a','b','c','\0'}, 1 }
    [0] = { .s[0] = 'q' }               // 当前对象现在是整个 yf[0] 对象，以 { {'q','\0','\0','\0'}, 0 } 替换 yf[0]
  };

  struct {double x,y;} pw = {1.0, 2.0, }; // 11、尾随逗号 OK，它被忽略

  struct {int n;} sk17 = {0};           // OK，12、C 中，初始化器的花括号列表不能为空（注意 C++ 允许空列表，并且注意 C 中结构体不能为空）
  struct {int n;} sk23 = {};            // C23 前错误：初始化式列表不能为空，C23 起 OK：初始化 s.n 为 0

  // static struct {char* p} sst = {malloc(1)}; // 错误，14、在初始化静态或线程局域(C11 起)存储期的聚合体时，初始化式列表中的每个表达式必须为常量表达式
  // static struct {char* p} sst = {"sss"};     // OK

  int nsst = 1;                                 // 15、任何初始化式中的子表达式求值顺序为非确定顺序（但 C++11 起的 C++ 中不同）
  struct {int x,y;} psst = {nsst++, nsst++};    // 未指定，但是良定义的行为，nsst 以任意顺序自增二次，psst 等于 {1,2} 和 {2,1} 都是合法的

  char buff[70]; 
  struct tm my_time = { .tm_year=2012-1900, .tm_mon=9, .tm_mday=9, .tm_hour=8, .tm_min=10, .tm_sec=20 }; // 指派初始化式简化成员顺序未指定的结构体的使用
  strftime(buff, sizeof buff, "%A %c", &my_time);
  puts(buff);

#endif // INITIALIZATION initialization

  return 0;
}