$["C"] {
    $include <stdio.h>
}

[namespace] IO {
    [void] println([String] s) { 
        ["C"] stdio.printf("%s\n", s);
    }
}