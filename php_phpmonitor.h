#ifndef PHP_PHPMONITOR_H
#define PHP_PHPMONITOR_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"
#include "ext/standard/info.h" 

#define phpext_phpmonitor_ptr &phpmonitor_module_entry
//extern zend_module_entry phpmonitor_module_entry;


PHP_MINIT_FUNCTION(phpmonitor);
PHP_MSHUTDOWN_FUNCTION(phpmonitor);
PHP_RINIT_FUNCTION(phpmonitor);
PHP_RSHUTDOWN_FUNCTION(phpmonitor);
PHP_MINFO_FUNCTION(phpmonitor);

PHP_FUNCTION(phpmonitor_test);

#endif	/* PHP_PHPMONITOR_H */
