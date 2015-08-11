
PHP_ARG_ENABLE(phpmonitor, whether to enable phpmonitor support,
[ --enable-phpmonitor      Enable phpmonitor support])

if test "$PHP_PHPMONITOR" != "no"; then
  PHP_NEW_EXTENSION(phpmonitor, phpmonitor.c, $ext_shared)
fi
