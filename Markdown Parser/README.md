# Markdown Parser
## Description
一个粗糙 Markdown 解析器的 C++ 实现  
Markdown 样式来自于 **VS Code** 插件 [Markdown All in One](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one)


## Problems/To-do List
* 不支持列表/Latex 公式的解析  
* 段落标签的添加实现未完善   
* 鲁棒性可能不强
* 样式表/字符集不支持自定义


## Structure
markdown-parser  
├── CMakeLists.txt  
├── README.md  
├── include  
│   ├── file.h  
│   ├── parser.h  
│   └── pattern.h  
├── src  
│   ├── file.cpp  
│   ├── main.cpp  
│   ├── parser.cpp  
│   └── pattern.cpp  
└── test.md  

## Usage
```
markdown_parser.exe input_file [output_file]
input_file: markdown filename to parse
output_file: optional output html filename
```

## Test
`markdown_parser.exe test.md`

## LICENSE
[MIT License](https://mit-license.org/)
