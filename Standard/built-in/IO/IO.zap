$["C"] {
    $include <stdio.h>
}

[public] {
    [void] println([const: String] str, [...: ?] _) { 
        ["C"] stdio.printf(str, _);
    }

    [String] Read( [const, String] format){
        [String] _buffer;
        ["C"] stdio.scanf(format, &_buffer);
        [Return: _buffer]
    }
}