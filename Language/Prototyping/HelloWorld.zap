$import [path: "{Zap}/IO.zap"]

[main] {
    IO.println("hello world, and welcome to %s. What is your name?\n",{"zap"});
    [String] Input = IO.Read();
    IO.println("Hello, %s.\n",{Input});
    [return: 0]
}