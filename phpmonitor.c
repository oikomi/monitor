/*
 * phpmonitor.c
 *
 *  Created on: 11/08/2015
 *      Author: miaohong(miaohong01@baidu.com)
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_phpmonitor.h"

/**
 * **********************
 * GLOBAL MACRO CONSTANTS
 * **********************
 */

/* phpmonitor version                           */
#define PHPMONITOR_VERSION       "0.0.1"
#define PHPMONITOR_NAME          "phpmonitor"

//module entry
zend_module_entry phpmonitor_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif
    PHPMONITOR_NAME, 
    NULL, /* Functions */
    PHP_MINIT(phpmonitor),               /* Module init callback */
  PHP_MSHUTDOWN(phpmonitor),           /* Module shutdown callback */
  PHP_RINIT(phpmonitor),               /* Request init callback */
  PHP_RSHUTDOWN(phpmonitor),           /* Request shutdown callback */

    NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHPMONITOR_VERSION, 
#endif
    STANDARD_MODULE_PROPERTIES
};
 
#ifdef COMPILE_DL_PHPMONITOR
ZEND_GET_MODULE(phpmonitor)
#endif

int time_of_minit;
PHP_MINIT_FUNCTION(phpmonitor)
{
    FILE *fp=fopen("/tmp/time_moduleinit.txt","a+");
    fprintf(fp,"%d\n",time(NULL));
    fclose(fp);
    time_of_minit=time(NULL);
    return SUCCESS;
}
 
int time_of_rinit;
PHP_RINIT_FUNCTION(phpmonitor)
{
    time_of_rinit=time(NULL);
    return SUCCESS;
}
 
PHP_RSHUTDOWN_FUNCTION(phpmonitor)
{
    FILE *fp=fopen("/tmp/time_rshutdown.txt","a+");
    fprintf(fp,"%d\n",time(NULL));
    fclose(fp);
    return SUCCESS;
}
 
PHP_MSHUTDOWN_FUNCTION(phpmonitor)
{
    FILE *fp=fopen("/tmp/time_mshutdown.txt","a+");
    fprintf(fp,"%d\n",time(NULL));
    fclose(fp);
    return SUCCESS;
}
 
/*
PHP_FUNCTION(phpmonitor_test)
{
    php_printf("%d&lt;br /&gt;",time_of_minit);
    php_printf("%d&lt;br /&gt;",time_of_rinit);
    return;
}
*/


