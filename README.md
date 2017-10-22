# php_cpp_plugin
using cpp to develop php plugin.


# build
chmod +x build.sh & ./build.sh

# setting
add this line below to tailf of /etc/php5/cli/php.ini, or other php.ini(php7 is supported).
```
extension=/usr/local/lib/allen.so
```

# run
php test.php
