# XML escape for C / C++

Recently I've got the problem to simply escape strings in C++ without using any frameworks, and of course lightweight and fast.
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

What about UTF8?
----------------

As this implementation looks only at characters with a ordinal < 128 this works for UTF8 because in this range UTF8 is equal to ASCII.
All of the variable width characters in UTF8 have their highest bit set and so are always bigger than 127.
Of course we could add a special treatment for such characters (e.g. stream them as hex), but currently it isn't necessary - feel free to add your own solution for this!
