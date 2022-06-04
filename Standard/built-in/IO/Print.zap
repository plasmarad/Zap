$["C"] {
    $include <stdio.h>
}

[namespace] IO {
    [void] println([String] s) { 
        ["C"] stdio.printf("%s\n", s);
    }

    [String] Read([String] _BUFFER, [const: String] _format){
        [Return: ["C"] stdio.scanf(_format, _BUFFER)]
    }
}