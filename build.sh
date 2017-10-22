#!/bin/sh
#sudo apt install php5-dev
phpize
./configure --enable-allen
make
make test

sudo cp modules/allen.so /usr/local/lib/

echo "add extension=/usr/local/lib/allen.so to /etc/php5/cli/php.ini and /etc/php5/fpm/php.ini"

echo "and then restart web server and php-fpm. sudo /etc/init.d/nginx(apache) restart, sudo /etc/init.d/php-fpm restart"

echo "after that, using php test.php to test it."
