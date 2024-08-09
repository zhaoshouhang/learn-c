# 说明

## 代码

在 var.c 和 var1.c 中同时定义了 var 变量,print_var.c 中声明外部变量 var,且直接打印

## 编译

1. 使用`gcc print_var.c` 直接报错:

   ```bash
   PS > gcc print_var.c
    ...:
    undefined reference to `var'
   ```

2. 使用`gcc print_var.c var.c` 或者是 `gcc print_var.c var1.c` 可以成功编译,并可以执行程序.
3. 使用`gcc print_var.c var.c var1.c` 直接报错:

   ```bash
   PS > gcc .\print_var.c .\var.c .\var1.c
   ...:
   multiple definition of `var'; C:\Users\ADMINI~1\AppData\Local\Temp\cccLQiQg.o:var.c:(.data+0x0): first defined here
   collect2.exe: error: ld returned 1 exit status
   ```

   原因是出现多个定义的地方.
