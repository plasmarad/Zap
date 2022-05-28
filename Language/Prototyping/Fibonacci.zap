$import [path: "{Zap}/IO.zap"]

[main] {

    IO.print("${fibonacci}");
    

    [return: 0]
}

[function: array(int) ] Fibonacci: [int] terms{
    [array(int):] temp  // create an array with no defined size, it changes dynamically

    for ([int] i = 1; i <= n; i++){
        temp[i+1] = temp[i] + temp[i-1]
    }

    [return: temp]
}

//TODO: Write Fibonacci
