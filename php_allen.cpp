#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif 
#include "php.h"
#include "php_allen.h"
#include "./src/allen.h"
static zend_function_entry allen_functions[] = {
    PHP_FE(say, NULL)
    {NULL, NULL, NULL}
};
zend_module_entry allen_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_HW_BEAUTY_EXTNAME,
    allen_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HW_BEAUTY_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
#ifdef COMPILE_DL_ALLEN
    ZEND_GET_MODULE(allen)
#endif

#if PHP_MAJOR_VERSION < 7
typedef int string_size_t;
#else
typedef size_t string_size_t;
#endif

PHP_FUNCTION(say)
{
    char* name = NULL;
    string_size_t name_len = 0;
    int argc = ZEND_NUM_ARGS();
    if (zend_parse_parameters(argc TSRMLS_CC, "s", &name, &name_len) == FAILURE)
    {
        php_error(E_WARNING, "say: parameter invalidate!");
        RETURN_NULL();
    }
    char* imgData = allen_say_to(name);
    char* result = estrdup(imgData);
    release_memory(imgData);
#if PHP_MAJOR_VERSION < 7
    RETURN_STRING(result, 0);
#else
    RETURN_STRING(result);
#endif
}
