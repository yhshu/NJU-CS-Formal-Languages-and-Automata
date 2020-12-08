# 形式语言与自动机 课程项目

2020 年 秋季

舒意恒 MF20330067 计算机科学与技术系

yhshu@smail.nju.edu.cn

## 构建，编译与运行

- 集成开发环境 CLion
- 构建工具 CMake 3.10 及以上版本，配置文件见 `CMakeList.txt`
- 编译器 gcc 9
- 操作系统支持 Ubuntu 20.04、macOS 11

## 解析器设计

解析器通过 `TuringMachine` 类的构造函数实现。解析器支持 `verbose` 模式，语法检查支持以下类型的错误：

- 判断图灵机程序所声明的初始状态、终止状态集合是否都定义在同一程序的状态集中；
- 判断图灵机程序所声明的空白符号是否属于其纸带符号集；
- 判断图灵机程序所声明的纸带数是否是一个非零自然数；
- 判断图灵机程序所声明的转移函数是否满足确定性图灵机的要求

## 模拟器设计

模拟器通过 `TuringMachine` 类的 `Run` 函数实现。模拟器支持 `verbose` 模式，语法检查将判断输入串中的所有字符是否均属于输入符号集。

## 代码

- `turing-project` 目录包含 C++ 源码
- `programs` 目录包含图灵机程序代码

## 测试

### 程序 1

| 用例编号 | 输入字符串 | 期望结果 |
| -------- | ---------- | -------- |
| 1        | abbabb     | true     |
| 2        | aabaab     | true     |
| 3        | ab         | false    |
| 4        | abbabbb    | false    |
| 5        | aabbabb    | false    |
| 6        | babb       | false    |
| 7        | abba       | false    |
| 8        | abbab      | false    |
| 9        | a          | false    |
| 10       | baabaa     | false    |
| 11       | aabb       | false    |

### 程序 2

| 用例编号 | 输入字符串    | 期望结果 |
| -------- | ------------- | -------- |
| 1        | 11x11=1111    | true     |
| 2        | 11x111=111111 | true     |
| 3        | 111x11=111111 | true     |
| 4        | 1x=1          | false    |
| 5        | x1=1          | false    |
| 6        | 1x1=1         | true     |
| 7        | x=            | false    |
| 8        | x=1           | false    |
| 9        | 1x=           | false    |
| 10       | x1=           | false    |
| 11       | 11x111=1111   | false    |
| 12       | 11x11=111     | false    |
| 13       | 11x11=11111   | false    |
| 14       | 1=1           | false    |
| 15       | 1=11          | false    |
| 16       | 11=1          | false    |
| 17       | x             | false    |
| 18       | =             | false    |
| 19       | 1=1x1         | false    |
| 20       | 11=111x111111 | false    |





