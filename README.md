# vnctp
vnpy 使用 的ctp python封装, 重写了编译脚本，可以通过cmake进行编辑

## 使用方法

Windows下编译请先安装miniconda、clang和msvc

Linux下编译请先安装python和gcc

### CMake编译

``` 
cmake .
make
```

### Windows手动编译

``` 
clang++ -c -o vnctpmd.o src/vnctpmd/vnctpmd.cpp -I C:/ProgramData/miniconda3/include -I ./include/
clang++ -shared -o vnctpmd.pyd vnctpmd.o -L ./lib -lthostmduserapi_se -L C:/ProgramData/miniconda3/libs

clang++ -c -o vnctptd.o src/vnctptd/vnctptd.cpp -I C:/ProgramData/miniconda3/include -I ./include/
clang++ -shared -o vnctptd.pyd vnctptd.o -L ./lib -lthosttraderapi_se -L C:/ProgramData/miniconda3/libs

```

### Linux手动编译

``` 
g++ -c -fPIC -o vnctpmd.o src/vnctpmd/vnctpmd.cpp -I /usr/include/python3.6/ -I ./include/
g++ -shared -o vnctpmd.so vnctpmd.o -L ./lib -lthostmduserapi_se

g++ -c -fPIC -o vnctptd.o src/vnctptd/vnctptd.cpp -I /usr/include/python3.6/ -I ./include/
g++ -shared -o vnctptd.so vnctptd.o -L ./lib -lthosttraderapi_se

```
### 使用

将vnctpmd.pyd 和 vnctptd.pyd 复制出来(Linux下是vnctpmd.so和vnctptd.so)，并和thostmduserapi_se.dll thosttraderapi_se.dll放在同一目录(Linux下是libthostmduserapi_se.so 和 libthosttraderapi_se.so)。

```
from vnctpmd import MdApi
from vnctptd import TdApi
md = MdApi()
td = TdApi()
print(md.GetApiVersion())
print(td.GetApiVersion())
```

输出：

```
v6.3.19_P1_20200106 15:21:32
v6.3.19_P1_20200106 15:21:32
```
