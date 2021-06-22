.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
istore 0
fstore 1
iload 0
fload 1
iadd
fload 1
iload 0
fsub
iload 0
fload 1
ldc 3
ldc 3.140000
iadd
ldc 3.000000
ldc 3.140000
fadd
iload 0
fload 1
irem
fload 1
ldc 3
irem
ldc 3
ldc 2
ldc 2
iadd
ldc 1.000000
ldc 1.000000
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(F)V
iload 0
ldc 1
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc 2.000000
ldc 2.000000
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(F)V
iload 0
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
	return
.end method
