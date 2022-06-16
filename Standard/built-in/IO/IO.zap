$["C"] {
    $include <stdio.h>
}

[public] {
    [void] println([const; String] str, [...: ?] _) { 
        ["C"] stdio.printf(str, _);
    }
    [String] Read( [const; String] format){
        [Return: ["C"] stdio.scanf(format, [ret])]
    }
}