$import [path: "{Zap}/IO.zap"]

[main] {

    for ([int] ite in Fibonacci(10)){
        println("%i", ite);
    }

    [return: 0]
}

[array: int, ?] Fibonacci ([int] term){
    [static; array: int, ?] _temp;

    for ([int] i = 1; i <= term; i++) {
        _temp[i+1] = _temp[i] + _temp[i-1];
    }

    [return: _temp]
}
