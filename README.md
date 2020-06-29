# libasm

A basic assembly language project, to learn and practise the basics of assembly.

Re-write the following functions (basic C lib functions recoded in a previous 42 project) in x64 assembly, using the Intel syntax, and the NASM assembler:

```C
size_t    ft_strlen(const char *str);
char      *ft_strcpy(char *dst, const char *src);
int       ft_strcmp(const char *s1, const char *s2);
ssize_t   ft_write(int fd, const void *buf, size_t nbyte);
ssize_t   ft_read(int fd, void *buf, size_t nbyte);
char      *ft_strdup(const char *str);
```

Makefile also contains a 'test' rule which compiles and links ```tester_main.c``` which can be used to test the functions above.

## Resources

* [Nasm tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
* [x86_64 NASM Assembly Quick Reference](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
* [MacOS system calls](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)
