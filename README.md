# vnctp
vnpy 使用 的vnctp 封装

## 使用方法

### 编译

``` 
mkdir build
cd build 
cmake ..
cmake build . --config release
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
