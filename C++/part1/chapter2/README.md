# 运行结果
## es2.1
    32
    4294967264
    32
    -32
    0
    0
    4294967264
第一个没有问题，第二个是因为无符号在想减后要按照无符号输出故输出为4294967264

最后我加了一个 unsigned - int 由于隐式转换规则故转为unsigned

https://zh.cppreference.com/w/c/language/conversion

上链接为各种转换规则