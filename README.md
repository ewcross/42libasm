# libasm

A basic assembly language project, to learn and practise the basics of assembly.

Re-write the following functions (from a previous c project) in x64 assembly, using the Intel syntax, and the NASM assembler:

```C
int       ft_strlen(const char *str);
char      *ft_strcpy(char *dst, const char *src);
int       ft_strcmp(const char *s1, const char *s2);
ssize_t   ft_write(int fd, const void *buf, size_t nbyte);
ssize_t   ft_read(int fd, void *buf, size_t nbyte);
char      *ft_strdup(const char *str);
```

Also included is a main (written in blah) which can be used to test the functions.

## Resources

[Nasm tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
[x86_64 NASM Assembly Quick Reference](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
[MacOS system calls](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)
