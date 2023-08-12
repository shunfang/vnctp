# vnctp
vnpy 使用 的ctp python封装, 重写了编译脚本，可以通过cmake进行编辑

## 使用方法

请先安装miniconda和msys2

### CMake编译

``` 
cmake .
make
```

### 手动编译

``` 
g++ -c -o vnctpmd.o src/vnctpmd/vnctpmd.cpp -I /c/ProgramData/miniconda3/include -I ./include/
g++ -shared -o vnctpmd.pyd vnctpmd.o -L ./lib -lthostmduserapi_se -L /c/ProgramData/miniconda3/ -lpython311

g++ -c -o vnctptd.o src/vnctptd/vnctptd.cpp -I /c/ProgramData/miniconda3/include -I ./include/
g++ -shared -o vnctptd.pyd vnctptd.o -L ./lib -lthosttraderapi_se -L /c/ProgramData/miniconda3/ -lpython311

```

### 使用

将vnctpmd.pyd 和 vnctptd.pyd 复制出来， 和 thostmduserapi_se.dll thosttraderapi_se.dll 放在同一目录。

```
from vnctpmd import MdApi
from vnctptd import TdApi
md = MdApi()
td = TdApi()
print(type(md))
print(type(td))
```

输出：

```
<class 'vnctpmd.MdApi'>
<class 'vnctptd.TdApi'>
```
