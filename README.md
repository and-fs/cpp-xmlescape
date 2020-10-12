# XML escape for C / C++

Recently I've got the problem to simply escape strings in C++ without using any frameworks, and of course lightweight an fast.
Due to my experience at working on machines with low memory (mainly at my C64 period) I reminded myself of the simple but fast translation table pattern.

How it works
------------

Its (mainly) easy - every ordinal of the character in the source sequence is the index in the translation table.
So you have simply to take every character, grab its translation in the translation table and instead of the character just use the string in the table:

```cpp
static const char* table[] = {
 ...
 "&amp;",     // ASCII-Code: 038, CHR: &
 ...
};

std::cout << table['&']; // &amp;
```

What about Multibyte
--------------------

t.b.c.

