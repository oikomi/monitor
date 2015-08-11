


make clean

phpize

./configure

make && make install

pkill php-fpm

/mh/phphook/php/sbin/php-fpm -R

echo "done"
